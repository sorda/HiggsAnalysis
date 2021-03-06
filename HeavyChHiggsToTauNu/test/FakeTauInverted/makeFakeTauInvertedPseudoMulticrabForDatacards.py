#!/usr/bin/env python

import ROOT
ROOT.gROOT.SetBatch(True)
ROOT.PyConfig.IgnoreCommandLineOptions = True
import math
import sys
import os
import time
from optparse import OptionParser
import cProfile

import HiggsAnalysis.HeavyChHiggsToTauNu.tools.dataset as dataset
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.plots as plots
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.analysisModuleSelector as analysisModuleSelector
import HiggsAnalysis.HeavyChHiggsToTauNu.qcdInverted.qcdInvertedResult as qcdInvertedResult
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.ShellStyles as ShellStyles
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.pseudoMultiCrabCreator as pseudoMultiCrabCreator
import HiggsAnalysis.HeavyChHiggsToTauNu.qcdInverted.fakeRate as fakeRate
import HiggsAnalysis.HeavyChHiggsToTauNu.tools.systematics as systematics

myNormalizationFactorSource = "QCDInvertedNormalizationFactors.py"

myScalarUncertainties = {"xsect_tt_8TeV_forQCD" : systematics.getCrossSectionUncertainty("TTJets"), "lumi_forQCD" : systematics.getLuminosityUncertainty(), "probBtag" : systematics.getProbabilisticBtagUncertainty(), "lepton_veto" : systematics.getLeptonVetoUncertainty()}

def doNominalModule(myMulticrabDir,era,searchMode,optimizationMode,myOutputCreator,myShapeString,myNormFactors,myDisplayStatus,dataDrivenFakeTaus):
    # Construct info string of module
    myModuleInfoString = "%s_%s_%s"%(era, searchMode, optimizationMode)
    # Obtain dataset manager
    dsetMgrCreator = dataset.readFromMulticrabCfg(directory=myMulticrabDir)
    dsetMgr = dsetMgrCreator.createDatasetManager(dataEra=era,searchMode=searchMode,optimizationMode=optimizationMode)
    # Do the usual normalisation
    dsetMgr.updateNAllEventsToPUWeighted()
    dsetMgr.loadLuminosities()
    plots.mergeRenameReorderForDataMC(dsetMgr)
    dsetMgr.merge("EWK", ["TTJets","WJets","DYJetsToLL","SingleTop","Diboson"])

    # dataset manager with tt contribution in ewk separated
    dsetMgrSeparatedTT = dsetMgrCreator.createDatasetManager(dataEra=era,searchMode=searchMode,optimizationMode=optimizationMode)
    # Do the usual normalisation
    dsetMgrSeparatedTT.updateNAllEventsToPUWeighted()
    dsetMgrSeparatedTT.loadLuminosities()
    plots.mergeRenameReorderForDataMC(dsetMgrSeparatedTT)
    # TT separated
    dsetMgrSeparatedTT.merge("EWKNoTT", ["WJets","DYJetsToLL","SingleTop","Diboson"])
    dsetMgrSeparatedTT.merge("EWKTT", ["TTJets"])

    # Obtain luminosity
    myLuminosity = dsetMgr.getDataset("Data").getLuminosity()

    myFakeRateCalculator = fakeRate.FakeRateCalculator(dsetMgr, myShapeString, myNormFactors, myLuminosity, dataDrivenFakeTaus = dataDrivenFakeTaus)

    # Print info so that user can check that merge went correct
    if myDisplayStatus:
        dsetMgr.printDatasetTree()
        print "Luminosity = %f 1/fb"%(myLuminosity / 1000.0)
        print
        myDisplayStatus = False
    # Gather results
    # Create containers for results
    myModuleResults = pseudoMultiCrabCreator.PseudoMultiCrabModule(dsetMgr, era, searchMode, optimizationMode)
    myQCDNormalizationSystResults = pseudoMultiCrabCreator.PseudoMultiCrabModule(dsetMgr, era, searchMode, optimizationMode, "SystVarQCDNormSource")
    # Obtain results
    myResult = qcdInvertedResult.QCDInvertedResultManager(myShapeString, "AfterCollinearCuts", dsetMgr, myLuminosity, myModuleInfoString, myFakeRateCalculator.getTotalFakeRateProbabilities(), dataDrivenFakeTaus=dataDrivenFakeTaus, shapeOnly=False, displayPurityBreakdown=True, noRebin=True)
    # Store results
    myModuleResults.addShape(myResult.getShape(), myShapeString)
    myModuleResults.addShape(myResult.getShapeMCEWK(), myShapeString+"_MCEWK")
    myModuleResults.addShape(myResult.getShapePurity(), myShapeString+"_Purity")
    myModuleResults.addDataDrivenControlPlots(myResult.getControlPlots(),myResult.getControlPlotLabels())
    myOutputCreator.addModule(myModuleResults)
    # Up variation of QCD normalization (i.e. ctrl->signal region transition)
    # Note that only the source histograms for the shape uncert are stored
    # because the result must be calculated after rebinning
    # (and rebinning is no longer done here for flexibility reasons)
    numerator = myResult.getRegionSystNumerator()
    denominator = myResult.getRegionSystDenominator()
    #scale errors with weight at normalization point
    #norm_weight = myFakeRateWeightCalculatorAtNorm.getAverageWeight()
    average_weight = myFakeRateCalculator.getAverageWeight()
    #print average_weight
    fakeRate.scaleErrors(numerator, average_weight)
    fakeRate.scaleErrors(denominator, average_weight)
    myQCDNormalizationSystResults.addShape(numerator, myShapeString+"Numerator")
    myQCDNormalizationSystResults.addShape(denominator, myShapeString+"Denominator")
    myLabels = myResult.getControlPlotLabelsForQCDSyst()
    for i in range(0,len(myLabels)):
        myLabels[i] = myLabels[i]+"Numerator"
    myQCDNormalizationSystResults.addDataDrivenControlPlots(myResult.getRegionSystNumeratorCtrlPlots(),myLabels)
    for i in range(0,len(myLabels)):
        myLabels[i] = myLabels[i].replace("Numerator","Denominator")
    myQCDNormalizationSystResults.addDataDrivenControlPlots(myResult.getRegionSystDenominatorCtrlPlots(),myLabels)
    myOutputCreator.addModule(myQCDNormalizationSystResults)

    # Up variation of fake weighting
    myFakeWeightingSystResultsPlus = pseudoMultiCrabCreator.PseudoMultiCrabModule(dsetMgr, era, searchMode, optimizationMode, "SystVarFakeWeightingPlus")
    myResult_FakeWeightingPlus = qcdInvertedResult.QCDInvertedResultManager(myShapeString, "AfterCollinearCuts", dsetMgr, myLuminosity,myModuleInfoString, myFakeRateCalculator.getTotalFakeRateProbabilitiesSystVarUp(), dataDrivenFakeTaus=dataDrivenFakeTaus, shapeOnly=False, displayPurityBreakdown=True, noRebin=True)                                                                                           
    myFakeWeightingSystResultsPlus.addShape(myResult_FakeWeightingPlus.getShape(), myShapeString)
    myFakeWeightingSystResultsPlus.addShape(myResult_FakeWeightingPlus.getShapeMCEWK(), myShapeString+"_MCEWK")
    myFakeWeightingSystResultsPlus.addShape(myResult_FakeWeightingPlus.getShapePurity(), myShapeString+"_Purity")
    myFakeWeightingSystResultsPlus.addDataDrivenControlPlots(myResult_FakeWeightingPlus.getControlPlots(),myResult.getControlPlotLabels())
    myOutputCreator.addModule(myFakeWeightingSystResultsPlus)

    # Down variation of fake weighting
    myFakeWeightingSystResultsMinus = pseudoMultiCrabCreator.PseudoMultiCrabModule(dsetMgr, era, searchMode, optimizationMode, "SystVarFakeWeightingMinus")
    myResult_FakeWeightingMinus = qcdInvertedResult.QCDInvertedResultManager(myShapeString, "AfterCollinearCuts", dsetMgr, myLuminosity,myModuleInfoString, myFakeRateCalculator.getTotalFakeRateProbabilitiesSystVarDown(), dataDrivenFakeTaus=dataDrivenFakeTaus, shapeOnly=False, displayPurityBreakdown=True, noRebin=True)                                                                                           
    myFakeWeightingSystResultsMinus.addShape(myResult_FakeWeightingMinus.getShape(), myShapeString)
    myFakeWeightingSystResultsMinus.addShape(myResult_FakeWeightingMinus.getShapeMCEWK(), myShapeString+"_MCEWK")
    myFakeWeightingSystResultsMinus.addShape(myResult_FakeWeightingMinus.getShapePurity(), myShapeString+"_Purity")
    myFakeWeightingSystResultsMinus.addDataDrivenControlPlots(myResult_FakeWeightingMinus.getControlPlots(),myResult.getControlPlotLabels())
    myOutputCreator.addModule(myFakeWeightingSystResultsMinus)

    # Scalar uncertainties as shapes for MC EWK
    for scalarName in myScalarUncertainties.keys():
        if scalarName == "probBtag":
            myScalarDsetMgr = dsetMgrSeparatedTT
            uncertAffectsTT = False 
        else:
            myScalarDsetMgr = dsetMgr
            uncertAffectsTT = True
        # anti-correlation: flipped sign of variation
        upScalarFakeRateCalculator = fakeRate.FakeRateCalculator(myScalarDsetMgr, myShapeString, myNormFactors, myLuminosity, EWKUncertaintyFactor=1-myScalarUncertainties[scalarName].getUncertaintyUp(), UncertAffectsTT = uncertAffectsTT, dataDrivenFakeTaus = dataDrivenFakeTaus)
        downScalarFakeRateCalculator = fakeRate.FakeRateCalculator(myScalarDsetMgr, myShapeString, myNormFactors, myLuminosity, EWKUncertaintyFactor=1+myScalarUncertainties[scalarName].getUncertaintyDown(), UncertAffectsTT = uncertAffectsTT, dataDrivenFakeTaus = dataDrivenFakeTaus)
        #print "Scalar uncertainty:", scalarName, myScalarUncertainties[scalarName].getUncertaintyDown(), myScalarUncertainties[scalarName].getUncertaintyUp()
        upShape = qcdInvertedResult.QCDInvertedShape(upScalarFakeRateCalculator.getShape(), myModuleInfoString, upScalarFakeRateCalculator.getTotalFakeRateProbabilities(), optionPrintPurityByBins=False, optionDoNQCDByBinHistograms=False) # prev: .getFakeTauShape()
        downShape = qcdInvertedResult.QCDInvertedShape(downScalarFakeRateCalculator.getShape(), myModuleInfoString, downScalarFakeRateCalculator.getTotalFakeRateProbabilities(), optionPrintPurityByBins=False, optionDoNQCDByBinHistograms=False) # prev: .getFakeTauShape()
        # Up variation module
        myScalarSystPlus = pseudoMultiCrabCreator.PseudoMultiCrabModule(dsetMgr, era, searchMode, optimizationMode, "SystVar%sPlus"%scalarName)
        myScalarSystPlus.addShape(upShape.getResultShape(), myShapeString)
        myScalarSystPlus.addShape(upShape.getResultMCEWK(), myShapeString+"_MCEWK")
        myScalarSystPlus.addShape(upShape.getResultPurity(), myShapeString+"_Purity")
        #myScalarSystPlus.addDataDrivenControlPlots(myResult_FakeWeightingMinus.getControlPlots(),myResult.getControlPlotLabels())
        myOutputCreator.addModule(myScalarSystPlus)
        # Down variation module
        myScalarSystMinus = pseudoMultiCrabCreator.PseudoMultiCrabModule(dsetMgr, era, searchMode, optimizationMode, "SystVar%sMinus"%scalarName)
        myScalarSystMinus.addShape(downShape.getResultShape(), myShapeString)
        myScalarSystMinus.addShape(downShape.getResultMCEWK(), myShapeString+"_MCEWK")
        myScalarSystMinus.addShape(downShape.getResultPurity(), myShapeString+"_Purity")
        #myScalarSystMinus.addDataDrivenControlPlots(myResult_FakeWeightingMinus.getControlPlots(),myResult.getControlPlotLabels())
        myOutputCreator.addModule(myScalarSystMinus)

    # Clean up
    myResult.delete()
    dsetMgr.close()
    dsetMgrCreator.close()
    ROOT.gROOT.CloseFiles()
    ROOT.gROOT.GetListOfCanvases().Delete()
    ROOT.gDirectory.GetList().Delete()

def doSystematicsVariation(myMulticrabDir,era,searchMode,optimizationMode,syst,myOutputCreator,myShapeString,myNormFactors,dataDrivenFakeTaus):
    myModuleInfoString = "%s_%s_%s_%s"%(era, searchMode, optimizationMode,syst)
    dsetMgrCreator = dataset.readFromMulticrabCfg(directory=myMulticrabDir)
    systDsetMgr = dsetMgrCreator.createDatasetManager(dataEra=era,searchMode=searchMode,optimizationMode=optimizationMode,systematicVariation=syst)
    # Do the usual normalisation
    systDsetMgr.updateNAllEventsToPUWeighted()
    systDsetMgr.loadLuminosities()
    plots.mergeRenameReorderForDataMC(systDsetMgr)
    systDsetMgr.merge("EWK", ["TTJets","WJets","DYJetsToLL","SingleTop","Diboson"])
    myLuminosity = systDsetMgr.getDataset("Data").getLuminosity()

    myFakeRateCalculator = fakeRate.FakeRateCalculator(systDsetMgr, myShapeString, myNormFactors, myLuminosity, dataDrivenFakeTaus = dataDrivenFakeTaus)

    # Obtain results
    mySystModuleResults = pseudoMultiCrabCreator.PseudoMultiCrabModule(systDsetMgr, era, searchMode, optimizationMode, syst)
    mySystResult = qcdInvertedResult.QCDInvertedResultManager(myShapeString, "AfterCollinearCuts", systDsetMgr, myLuminosity, myModuleInfoString, myFakeRateCalculator.getTotalFakeRateProbabilities(), dataDrivenFakeTaus=dataDrivenFakeTaus, shapeOnly=False, displayPurityBreakdown=False, noRebin=True)
    mySystModuleResults.addShape(mySystResult.getShape(), myShapeString)
    mySystModuleResults.addShape(mySystResult.getShapeMCEWK(), myShapeString+"_MCEWK")
    mySystModuleResults.addShape(mySystResult.getShapePurity(), myShapeString+"_Purity")
    mySystModuleResults.addDataDrivenControlPlots(mySystResult.getControlPlots(),mySystResult.getControlPlotLabels())
    mySystResult.delete()
    ## Save module info
    myOutputCreator.addModule(mySystModuleResults)
    systDsetMgr.close()
    dsetMgrCreator.close()
    ROOT.gROOT.CloseFiles()
    ROOT.gROOT.GetListOfCanvases().Delete()
    ROOT.gDirectory.GetList().Delete()

def printTimeEstimate(globalStart, localStart, nCurrent, nAll):
    myLocalDelta = time.time() - localStart
    myGlobalDelta = time.time() - globalStart
    myEstimate = myGlobalDelta / float(nCurrent) * float(nAll-nCurrent)
    s = "%02d:"%(myEstimate/60)
    myEstimate -= int(myEstimate/60)*60
    s += "%02d"%(myEstimate)
    print "Module finished in %.1f s, estimated time to complete: %s"%(myLocalDelta, s)

if __name__ == "__main__":
    # Obtain normalization factors
    myNormFactors = None
    myNormFactorsSafetyCheck = None

    # Object for selecting data eras, search modes, and optimization modes
    myModuleSelector = analysisModuleSelector.AnalysisModuleSelector()
    # Parse command line options
    parser = OptionParser(usage="Usage: %prog [options]",add_help_option=True,conflict_handler="resolve")
    myModuleSelector.addParserOptions(parser)
    parser.add_option("--mdir", dest="multicrabDir", action="store", help="Multicrab directory")
    parser.add_option("--mtonly", dest="transverseMassOnly", action="store_true", default=False, help="Create only transverse mass plots")
    parser.add_option("--invmassonly", dest="invariantMassOnly", action="store_true", default=False, help="Create only invariant mass plots")
    parser.add_option("--test", dest="test", action="store_true", default=False, help="Make short test by limiting number of syst. variations")
    parser.add_option("--datadrivenfaketaus", dest="dataDrivenFakeTaus", action="store_true", default=False, help="Use data-driven fake tau measurement")
    # Add here parser options, if necessary, following line is an example
    #parser.add_option("--showcard", dest="showDatacard", action="store_true", default=False, help="Print datacards also to screen")

    # Parse options
    (opts, args) = parser.parse_args()

    # Obtain multicrab directory
    myMulticrabDir = "."
    if opts.multicrabDir != None:
        myMulticrabDir = opts.multicrabDir
    if not os.path.exists("%s/multicrab.cfg"%myMulticrabDir):
        raise Exception(ShellStyles.ErrorLabel()+"No multicrab directory found at path '%s'! Please check path or specify it with --mdir!"%(myMulticrabDir)+ShellStyles.NormalStyle())

    myShapes = ["mt","invmass"]
    if opts.transverseMassOnly != None and opts.transverseMassOnly:
        myShapes = ["mt"]
    elif opts.invariantMassOnly != None and opts.invariantMassOnly:
        myShapes = ["invmass"]

    dataDrivenFakeTaus = opts.dataDrivenFakeTaus

    # Obtain dsetMgrCreator and register it to module selector
    dsetMgrCreator = dataset.readFromMulticrabCfg(directory=myMulticrabDir)
    # Obtain systematics names
    mySystematicsNamesRaw = dsetMgrCreator.getSystematicVariationSources()
    mySystematicsNames = []
    for item in mySystematicsNamesRaw:
        mySystematicsNames.append("%sPlus"%item)
        mySystematicsNames.append("%sMinus"%item)
    if opts.test:
        mySystematicsNames = []

    myModuleSelector.setPrimarySource("analysis", dsetMgrCreator)
    # Select modules
    myModuleSelector.doSelect(opts)
    #dsetMgrCreator.close()
    # Loop over era/searchMode/optimizationMode combos
    myDisplayStatus = True
    myTotalModules = myModuleSelector.getSelectedCombinationCount() * (len(mySystematicsNames)+1) * len(myShapes)
    myModuleSelector.printSelectedCombinationCount()
    # Loop over era/searchMode/optimizationMode options

    # Create pseudo-multicrab creator
    myOutputCreator = pseudoMultiCrabCreator.PseudoMultiCrabCreator("QCDinverted", myMulticrabDir)
    n = 0
    myGlobalStartTime = time.time()
    for massType in myShapes:
        myShapeString = ""
        if massType == "mt":
            myShapeString = "shapeTransverseMass"
        elif massType == "invmass":
            myShapeString = "shapeInvariantMass"
        myOutputCreator.initialize(massType)
        print ShellStyles.HighlightStyle()+"Creating dataset for shape: %s%s"%(massType,ShellStyles.NormalStyle())
        for era in myModuleSelector.getSelectedEras():
            # Check if normalization coefficients are suitable for era
            #myNormFactorsSafetyCheck(era) #FIXME
            for searchMode in myModuleSelector.getSelectedSearchModes():
                for optimizationMode in myModuleSelector.getSelectedOptimizationModes():
                    if os.path.exists(myNormalizationFactorSource):
                        myNormFactorsImport = getattr(__import__(myNormalizationFactorSource.replace(".py","")), "QCDInvertedNormalization")
                        myNormFactorsSafetyCheck = getattr(__import__(myNormalizationFactorSource.replace(".py","")), "QCDInvertedNormalizationSafetyCheck")
                        #QCDInvertedNormalizationSafetyCheck(era) #FIXME
                        myNormFactorsSafetyCheck(era)
                        myNormFactors = myNormFactorsImport.copy()
                    else:
                        raise Exception(ShellStyles.ErrorLabel()+"Normalisation factors ('%s.py') not found!\nRun script InvertedTauID_Normalization.py to generate the normalization factors."%myNormalizationFactorSource)

                    myModuleInfoString = "%s_%s_%s"%(era, searchMode, optimizationMode)
                    n += 1
                    print ShellStyles.CaptionStyle()+"Module %d/%d: %s/%s%s"%(n,myTotalModules,myModuleInfoString,massType,ShellStyles.NormalStyle())
                    myStartTime = time.time()
                    doNominalModule(myMulticrabDir,era,searchMode,optimizationMode,myOutputCreator,myShapeString,myNormFactors,myDisplayStatus,dataDrivenFakeTaus)
                    printTimeEstimate(myGlobalStartTime, myStartTime, n, myTotalModules)
                    # Now do the rest of systematics variations
                    for syst in mySystematicsNames:
                        n += 1
                        print ShellStyles.CaptionStyle()+"Analyzing systematics variations %d/%d: %s/%s/%s%s"%(n,myTotalModules,myModuleInfoString,syst,massType,ShellStyles.NormalStyle())
                        myStartTime = time.time()
                        doSystematicsVariation(myMulticrabDir,era,searchMode,optimizationMode,syst,myOutputCreator,myShapeString,myNormFactors,dataDrivenFakeTaus)
                        printTimeEstimate(myGlobalStartTime, myStartTime, n, myTotalModules)
        print "\nPseudo-multicrab ready for mass %s...\n"%massType
    # Create rest of pseudo multicrab directory
    myOutputCreator.finalize()
    print "Average processing time of one module: %.1f s, total elapsed time: %.1f s"%((time.time()-myGlobalStartTime)/float(myTotalModules), (time.time()-myGlobalStartTime))
