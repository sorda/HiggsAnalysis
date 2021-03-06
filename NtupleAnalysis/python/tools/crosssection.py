## \package crosssection
# Background and signal cross sections
#
# All cross sections are in pb

########################################
# Background cross section table

## Cross section of a single process (physical dataset)
class CrossSection:
    ## Constructor
    #
    # \parma name              Name of the process
    # \param energyDictionary  Dictionary of energy -> cross section (energy as string in TeV, cross section as float in pb)
    def __init__(self, name, energyDictionary):
        self.name = name
        for key, value in energyDictionary.iteritems():
            setattr(self, key, value)

    ## Get cross section
    #
    # \param energy  Energy as string in TeV
    def get(self, energy):
        try:
            return getattr(self, energy)
        except AttributeError:
            raise Exception("No cross section set for process %s for energy %s" % (self.name, energy))

## List of CrossSection objects
class CrossSectionList:
    def __init__(self, *args):
        self.crossSections = args[:]

    def crossSection(self, name, energy):
        for obj in self.crossSections:
            #if name[:len(obj.name)] == obj.name:
            if name == obj.name:
                return obj.get(energy)
        return None

# Cross sections from
# [1] PREP
# [2] https://twiki.cern.ch/twiki/bin/view/CMS/ReProcessingSummer2011
# [3] from https://twiki.cern.ch/twiki/bin/view/CMS/CrossSections_3XSeries
# [4] https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSections
# [5] https://twiki.cern.ch/twiki/bin/view/CMS/SingleTopMC2011
# [6] https://twiki.cern.ch/twiki/bin/view/CMS/SingleTopSigma
# [7] https://twiki.cern.ch/twiki/bin/view/CMS/HiggsToTauTauWorkingHCP2012#53X_MC_Samples
# [8] https://twiki.cern.ch/twiki/bin/view/CMS/SingleTopSigma8TeV (other useful page https://twiki.cern.ch/twiki/bin/view/CMS/SingleTopMC2012)
# [9] https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat8TeV
# [10] http://arxiv.org/abs/1303.6254
# [11] https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorkingSummer2013
# [12] https://twiki.cern.ch/twiki/bin/view/CMS/TmdRecipes
# [13] https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV
# [14] https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSectionsat13TeV / GenXSecAnalyzer
# [15] McM

backgroundCrossSections = CrossSectionList(
    CrossSection("QCD_Pt_30to50", {
            "7": 5.312e+07, # [2]
            "8": 6.6285328e7, # [1]
            "13": 161500000., # [12]
            }),
    CrossSection("QCD_Pt_50to80", {
            "7": 6.359e+06, # [2]
            "8": 8148778.0, # [1]
            "13": 22110000., # [12]
            }),
    CrossSection("QCD_Pt_80to120", {
            "7": 7.843e+05, # [2]
            "8": 1033680.0, # [1]
            "13": 3000114.3, # [12]
            }),
    CrossSection("QCD_Pt_120to170", {
            "7": 1.151e+05, # [2]
            "8": 156293.3, # [1]
            "13": 493200., # [12] # McM: 471100
            }),
    CrossSection("QCD_Pt_170to300", {
            "7": 2.426e+04, # [2]
            "8": 34138.15, # [1]
            "13": 120300., # [12]
            }),
    CrossSection("QCD_Pt_300to470", {
            "7": 1.168e+03, # [2]
            "8": 1759.549, # [1]
            "13": 7475., # [12]
            }),
    CrossSection("QCD_Pt_470to600", {
            "13": 587.1, # [12]
            }),
    CrossSection("QCD_Pt_600to800", {
            "13": 167., # [12]
            }),
    CrossSection("QCD_Pt_800to1000", {
            "13": 28.25, # [12]
            }),
    CrossSection("QCD_Pt_1000to1400", {
            "13": 8.195, # [12]
            }),
    CrossSection("QCD_Pt_1400to1800", {
            "13": 0.7346, # [12] # McM: 0.84265
            }),
    CrossSection("QCD_Pt_1800to2400", {
            "13": 0.1091, # [12] # McM: 0.114943
            }),
    CrossSection("QCD_Pt_2400to3200", {
            "13": 0.00682981, # [15]
            }),
    CrossSection("QCD_Pt_3200toInf", {
            "13": 0.000165445 , # [15]
            }),
    CrossSection("QCD_Pt20_MuEnriched", {
            "7": 296600000.*0.0002855, # [2]
            "8": 3.64e8*3.7e-4, # [1]
            }),
    CrossSection("QCD_Pt_50to80_MuEnrichedPt5", {
            "13": 4.487e+05, # 4.487e+05 +- 1.977e+02 pb [14]
    }),
    CrossSection("QCD_Pt_80to120_MuEnrichedPt5", {
            "13": 1.052e+05, # 1.052e+05 +- 5.262e+01 [14]
    }),
    CrossSection("QCD_Pt_120to170_MuEnrichedPt5", {
            "13": 2.549e+04, # 2.549e+04 +- 1.244e+01 [14]
    }),
    CrossSection("QCD_Pt_170to300_MuEnrichedPt5", {
            "13": 8.644e+03, # 8.644e+03 +- 4.226e+00 [14]
    }),
    CrossSection("QCD_Pt_300to470_MuEnrichedPt5", {
            "13": 7.967e+02, # 7.967e+02 +- 3.845e-0 [14]
    }),
    CrossSection("WW", {
            "7": 43.0, # [3]
            "8": 54.838, # [9], took value for CTEQ PDF since CTEQ6L1 was used in pythia simulation
            "13": 118.7, # [13] NNLO QCD
            }),
    CrossSection("WZ", {
            "7": 18.2, # [3]
            "8": 33.21, # [9], took value for CTEQ PDF since CTEQ6L1 was used in pythia simulation
            "13": 29.8 + 18.6, # [13] W+ Z/a* + W- Z/a*, MCFM 6.6 m(l+l-) > 40 GeV
            }),
    CrossSection("ZZ", {
            "7": 5.9, # [3]
            "8": 17.654, # [9], took value for CTEQ PDF since CTEQ6L1 was used in pythia simulation, this is slightly questionmark, since the computed value is for m(ll) > 12
            "13": 15.4, # [13]
            }),
    CrossSection("TTJets_FullLept", {
            "8": 245.8* 26.1975/249.50, # [10], BR from [11]
            }),
    CrossSection("TTJets_SemiLept", {
            "8": 245.8* 109.281/249.50, # [10], BR from [11]
            }),
    CrossSection("TTJets_Hadronic", {
            "8": 245.8* 114.0215/249.50, # [10], BR from [11]
            }),
    CrossSection("TTJets", {
            "7": 172.0, # [10]
            "8": 245.8, # [10]
            "13": 831.76, # [13] top mass 172.5, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/TtbarNNLO
            }),
    CrossSection("TT", {
            "7": 172.0, # [10]
            "8": 245.8, # [10]
            "13": 831.76, # [13] top mass 172.5, https://twiki.cern.ch/twiki/bin/view/LHCPhysics/TtbarNNLO
            }),
    CrossSection("TTJets_HT600to800", {
            "13": 0.0, 
            }),
    CrossSection("TTJets_HT800to1200", {
            "13": 0.0, 
            }),
    CrossSection("TTJets_HT1200to2500", {
            "13": 0.0, 
            }),
    CrossSection("TTJets_HT2500toInf", {
            "13": 0.0, 
            }),
    #CrossSection("WJets", {
            #"7": 31314.0, # [2], NNLO
            #"8": 36703.2, # [9], NNLO
            #}),
    CrossSection("WJetsToLNu", {
            "13": 20508.9*3, # [13] 20508.9*3, McM for the MLM dataset: 5.069e4
            }),
    CrossSection("WJetsToLNu_HT_100To200", {
            "13": 1.293e+03*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("WJetsToLNu_HT_200To400", {
            "13": 3.86e+02*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("WJetsToLNu_HT_400To600", {
            "13": 47.9*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("WJetsToLNu_HT_600ToInf", {
            "13": 0.0, # Forcing to zero to avoid overlap
            }),
    CrossSection("WJetsToLNu_HT_600To800", {
            "13": 12.8*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("WJetsToLNu_HT_800To1200", {
            "13": 5.26*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("WJetsToLNu_HT_1200To2500", {
            "13": 1.33*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("WJetsToLNu_HT_2500ToInf", {
            "13": 3.089e-02*1.2138, # McM times NNLO/LO ratio of inclusive sample
            }),
    # PREP (LO) cross sections, for W+NJets weighting
    CrossSection("PREP_WJets", {
            "7": 27770.0,
            "8": 30400.0,
            }),
    CrossSection("PREP_W1Jets", {
            "7": 4480.0,
            "8": 5400.0,
            }),
    CrossSection("PREP_W2Jets", {
            "7": 1435.0,
            "8": 1750.0,
            }),
    CrossSection("PREP_W3Jets", {
            "7": 304.2,
            "8": 519.0,
            }),
    CrossSection("PREP_W4Jets", {
            "7": 172.6,
            "8": 214.0,
            }),
    # end W+Njets 
    CrossSection("DYJetsToLL_M_50", {
            "7": 3048.0, # [4], NNLO
            "8": 3531.9, # [9], NNLO
            "13": 2008.4*3.0 # [14]
            }),
    CrossSection("DYJetsToLL_M_50_TauHLT", {
            "7": 3048.0, # [4], NNLO
            "8": 3531.9, # [9], NNLO
            "13": 2008.4*3.0 # [14]
            }),
    CrossSection("DYJetsToLL_M_10to50", {
            "7": 9611.0, # [1]
            "8": 11050.0, # [1]
            "13" :3205.6*3.0, # [14]
            }),
    CrossSection("DYJetsToLL_M_50_HT_100to200", {
            "13": 139.4*1.231, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("DYJetsToLL_M_50_HT_200to400", {
            "13": 42.75*1.231, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("DYJetsToLL_M_50_HT_400to600", {
            "13": 5.497*1.231, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("DYJetsToLL_M_50_HT_600toInf", {
            "13": 2.21*1.231, # McM times NNLO/LO ratio of inclusive sample
            }),
    CrossSection("DYJetsToLL_M_100to200", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_200to400", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_400to500", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_500to700", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_700to800", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_800to1000", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_1000to1500", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_1500to2000", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYJetsToLL_M_2000to3000", {
            "13": 0.0, # FIXME
            }),
    CrossSection("DYToTauTau_M_20_", {
            "7": 4998, # [4], NNLO
            "8": 5745.25, # [9], NNLO
            }),
    CrossSection("DYToTauTau_M_100to200", {
            "7": 0, # []
            "8": 34.92, # [1]
	    "13": 2.307e+02, # [14]
            }),
    CrossSection("DYToTauTau_M_200to400", {
            "7": 0, # []      
            "8": 1.181, # [1]
            "13": 7.839e+00, # [14]
            }),
   CrossSection("DYToTauTau_M_400to500", {
            "13": 3.957e-01, # [14]
            }),
   CrossSection("DYToTauTau_M_500to700", {
            "13": 2.352e-01, # [14]
            }),
   CrossSection("DYToTauTau_M_700to800", {
            "13": 3.957e-02, # [14]
            }),
    CrossSection("DYToTauTau_M_400to800", {
            "7": 0, # []      
            "8": 0.08699, # [1]
            }),
    CrossSection("DYToTauTau_M_800", {
            "7": 0, # []      
            "8": 0.004527, # [1]
            }),
    CrossSection("GluGluHToTauTau_M125", {
            "13": 1, # dummy value, not really needed as this sample is not merged with anything else
            }),
    CrossSection("GluGluHToTauTau_M125_TauHLT", {
            "13": 1, # dummy value, not really needed as this sample is not merged with anything else
            }),
    CrossSection("T_t-channel", {
            "7": 41.92, # [5,6]
            "8": 56.4, # [8]
            }),
    CrossSection("Tbar_t-channel", {
            "7": 22.65, # [5,6]
            "8": 30.7, # [8]
            }),
    CrossSection("T_tW-channel", {
            "7": 7.87, # [5,6]
            "8": 11.1, # [8]
            }),
    CrossSection("Tbar_tW-channel", {
            "7": 7.87, # [5,6]
            "8": 11.1, # [8]
            }),
    CrossSection("T_s-channel", {
            "7": 3.19, # [5,6]
            "8": 3.79, # [8]
            }),
    CrossSection("Tbar_s-channel", {
            "7": 1.44, # [5,6]
            "8": 1.76, # [8]
            }),
    CrossSection("ST_tW_antitop_5f_inclusiveDecays", {
            "13": 35.85, # [13] https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleTopSigma
            }),
    CrossSection("ST_tW_top_5f_inclusiveDecays", {
            "13": 35.85, # [13] https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleTopSigma
            }),
    CrossSection("ST_t_channel_antitop_4f_leptonDecays", {
            "13": 80.95, # [13] https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleTopSigma
            }),
    CrossSection("ST_t_channel_top_4f_leptonDecays", {
            "13": 136.02, # [13] https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleTopSigma
            }),
    CrossSection("ST_s_channel_4f_leptonDecays", {
            "13": 10.32, # [13] https://twiki.cern.ch/twiki/bin/viewauth/CMS/SingleTopSigma
            }),
)

## Set background process cross sections
#
# \param datasets            dataset.DatasetManager object
# \param doWNJetsWeighting   Set W+Njets cross sections according to the weighting scheme
def setBackgroundCrossSections(datasets, doWNJetsWeighting=True, quietMode=False):
    for dset in datasets.getMCDatasets():
        setBackgroundCrossSectionForDataset(dset, doWNJetsWeighting, quietMode)

def setBackgroundCrossSectionForDataset(dataset, doWNJetsWeighting=True, quietMode=False):
    value = backgroundCrossSections.crossSection(dataset.getName().replace("_ext",""), dataset.getEnergy())
    if value is None:
        if "ChargedHiggs" in dataset.getName():
            value = 1.0 # Force signal xsection to 1 pb
        else:
            for wnJets in ["W1Jets", "W2Jets", "W3Jets", "W4Jets"]:
                if wnJets in dataset.getName():
                    inclusiveCrossSection = backgroundCrossSections.crossSection("WJets", dataset.getEnergy())
                    if doWNJetsWeighting:
                        # W+Njets, with the assumption that they are weighted (see
                        # src/WJetsWeight.cc)
                        value = inclusiveCrossSection
                    else:
                        inclusiveLO = backgroundCrossSections.crossSection("PREP_WJets", dataset.getEnergy())
                        wnJetsLO = backgroundCrossSections.crossSection("PREP_"+wnJets, dataset.getEnergy())
                        value = inclusiveCrossSection * wnJetsLO/inclusiveLO
                    break

    if value is not None:
        dataset.setCrossSection(value)
        msg = ""
        if value == 0:
            msg = "  *** Note: to set non-zero xsection; edit NtupleAnalysis/python/tools/crossection.py ***"
        if "ChargedHiggs" in dataset.getName():
            msg = "  *** Note: signal is forced at the moment to 1 pb in NtupleAnalysis/python/tools/crossection.py ***"
        if not quietMode:
            print "Setting %50s cross section to %10f pb %s" % (dataset.getName(), value, msg)
#    else:
#        print "Warning: no cross section for dataset %s with energy %s TeV (see python/tools/crosssection.py)" % (dataset.getName(), dataset.getEnergy())


########################################
# Signal cross section table

import HiggsAnalysis.LimitCalc.BRdataInterface as br

# Default value of MSSM mu parameter
defaultMu = 200

## Generic light H+ MSSM cross section
#
# \param function function to calculate the cross section from BR's
# \param mass     H+ mass
# \param tanbeta  tanbeta parameter
# \param mu       mu parameter
# \param energy   sqrt(s) in TeV as string
def lightCrossSectionMSSM(function, mass, tanbeta, mu, energy):
    br_tH = br.getBR_top2bHp(mass, tanbeta, mu)
    br_Htaunu = br.getBR_Hp2tau(mass, tanbeta, mu)
    return function(br_tH, br_Htaunu, energy)

## Heavy H+ MSSM cross section
#
# \param mass     H+ mass
# \param tanbeta  tanbeta parameter
# \param mu       mu parameter
# \param energy   sqrt(s) in TeV as string
def heavyCrossSectionMSSM(mass, tanbeta, mu, energy):
    raise Exception("No heavy H+ cross sections yet!")

## WH, H->tau nu cross section from BRs
#
# \param br_tH      BR(t -> b H+)
# \param br_Htaunu  BR(H+ -> tau nu)
# \param energy     sqrt(s) in TeV as string
def whTauNuCrossSection(br_tH, br_Htaunu, energy):
    ttCrossSection = backgroundCrossSections.crossSection("TTJets", energy)
    xsec = 2 * ttCrossSection * br_tH * (1-br_tH) * br_Htaunu
    return (xsec, br_tH)

## HH, H->tau nu cross section from BRs
#
# \param br_tH      BR(t -> b H+)
# \param br_Htaunu  BR(H+ -> tau nu)
# \param energy     sqrt(s) in TeV as string
def hhTauNuCrossSection(br_tH, br_Htaunu, energy):
    ttCrossSection = backgroundCrossSections.crossSection("TTJets", energy)
    xsec = ttCrossSection * br_tH*br_tH * br_Htaunu*br_Htaunu
    return (xsec, br_tH)

## Single H, H->tau nu cross section from BRs
#
# \param br_tH      BR(t -> b H+)
# \param br_Htaunu  BR(H+ -> tau nu)
# \param energy     sqrt(s) in TeV as string
# \param channel    channel as string
def hTauNuCrossSection(br_tH, br_Htaunu, energy, channel):
    tCrossSection  = backgroundCrossSections.crossSection("T_"+channel, energy)
    tCrossSection += backgroundCrossSections.crossSection("Tbar_"+channel, energy)
    xsec = tCrossSection * br_tH * br_Htaunu
    return (xsec, br_tH)

## Helper function to set a cross section of one signal dataset
#
# \param name     Name of the dataset
# \param mass     H+ mass
# \param datasets dataset.DatasetManager object
# \param function Function taking the mass and energy, and returning cross section and BR(t->H+)
def _setHplusCrossSectionsHelper(name, mass, datasets, function):
    if not datasets.hasDataset(name):
        return
    d = datasets.getDataset(name)
    (crossSection, BRtH) = function(mass, d.getEnergy())
    d.setCrossSection(crossSection)
    if BRtH is not None:
        d.setProperty("BRtH", BRtH)
    print "Setting %s cross section to %f pb" % (name, crossSection)

## Helper function to set cross sections of all signal datasets
#
# \param datasets     dataset.DatasetManager object
# \param whFunction   Function to calculate tt->WH cross section from
#                     mass and energy, and returning cross section and
#                     BR(t->H+)
# \param hhFunction   Function to calculate tt->HH cross section from
#                     mass and energy, and returning cross section and
#                     BR(t->H+)
# \param hFunction    Function to calculate t->H cross section from mass,
#                     energy, and channel, and returning cross section
#                     and BR(t->H+)
# \param heavyFunction  Function to calculate heavy H+ cross section
#                       from mass and energy, and returning cross
#                       section and BR(t->H+)
def _setHplusCrossSections(datasets, whFunction, hhFunction, hFunction, heavyFunction=None):
    import HiggsAnalysis.NtupleAnalysis.tools.plots as plots

    for mass in plots._lightHplusMasses:
        _setHplusCrossSectionsHelper("TTToHplusBWB_M%d"%mass, mass, datasets, whFunction)
        _setHplusCrossSectionsHelper("TTToHplusBHminusB_M%d"%mass, mass, datasets, hhFunction)

        for channel in ["s-channel", "t-channel", "tW-channel"]:
            _setHplusCrossSectionsHelper("Hplus_taunu_%s_M%d"%(channel, mass), mass, datasets, lambda mass, energy: hFunction(mass, energy, channel))

    if heavyFunction is not None:
        for mass in plots._heavyHplusMasses:
            _setHplusCrossSectionsHelper("HplusTB_M%d"%mass, mass, datasets, heavyFunction)


## Set signal dataset cross sections to ttbar cross section
#
# \param datasets  dataset.DatasetManager object
def setHplusCrossSectionsToTop(datasets):
    function = lambda mass, energy: (backgroundCrossSections.crossSection("TTJets", energy), None)
    _setHplusCrossSections(datasets, function, function)

## Set signal dataset cross sections to MSSM cross section
#
# \param datasets  dataset.DatasetManager object
# \param tanbeta   tanbeta parameter
# \param mu        mu parameter
def setHplusCrossSectionsToMSSM(datasets, tanbeta=20, mu=defaultMu):
    import HiggsAnalysis.NtupleAnalysis.tools.histograms as histograms
    histograms.createSignalText.set(tanbeta=tanbeta)
    if mu != defaultMu:
        histograms.createSignalText.set(mu=mu)

    def singleHhelper(mass, energy, channel):
        return lightCrossSectionMSSM(lambda br1, br2, en: hTauNuCrossSection(br1, br2, en, channel), mass, tanbeta, mu, energy)

    _setHplusCrossSections(datasets,
        lambda mass, energy: lightCrossSectionMSSM(whTauNuCrossSection, mass, tanbeta, mu, energy),
        lambda mass, energy: lightCrossSectionMSSM(hhTauNuCrossSection, mass, tanbeta, mu, energy),
        singleHhelper)
#       lambda mass, energy: heavyCrossSectionMSSM(mass, tanbeta, mu, energy)) # FIXME: uncomment when we get heavy H+ cross sections

## Set signal dataset cross sections to cross section via BR
#
# \param datasets   dataset.DatasetManager object
# \param br_tH      BR(t -> b H+)
# \param br_Htaunu  BR(H+ -> tau nu)
def setHplusCrossSectionsToBR(datasets, br_tH, br_Htaunu):
    import HiggsAnalysis.NtupleAnalysis.tools.histograms as histograms
    histograms.createSignalText.set(br_tH=br_tH)
    _setHplusCrossSections(datasets,
                           lambda mass, energy: whTauNuCrossSection(br_tH, br_Htaunu, energy),
                           lambda mass, energy: hhTauNuCrossSection(br_tH, br_Htaunu, energy),
                           lambda mass, energy, channel: hTauNuCrossSection(br_tH, br_Htaunu, energy, channel))

## Set signal dataset cross sections to cross section (deprecated, only for compatibility)
def setHplusCrossSections(datasets, tanbeta=20, mu=defaultMu, toTop=False):
    if toTop:
        setHplusCrossSectionsToTop(datasets)
    else:
        setHplusCrossSectionsToMSSM(tanbeta, mu)

## Print H+ cross sections for given tanbeta values
#
# \param tanbetas  List of tanbeta values
# \param mu        Mu parameter
# \param energy    sqrt(s) in TeV as string
def printHplusCrossSections(tanbetas=[10, 20, 30, 40], mu=defaultMu, energy="7"):
    ttCrossSection = backgroundCrossSections.crossSection("TTJets", energy)
    tCrossSection  = sum([backgroundCrossSections.crossSection("T_"+channel, energy)    for channel in ["s-channel", "t-channel", "tW-channel"]])
    tCrossSection += sum([backgroundCrossSections.crossSection("Tbar_"+channel, energy) for channel in ["s-channel", "t-channel", "tW-channel"]])
    print "ttbar cross section %.1f pb" % ttCrossSection
    print "single top cross section %.1f pb" % tCrossSection
    print "mu %.1f" % mu
    print
    for tanbeta in [10, 20, 30, 40]:
        print "="*98
        print "tan(beta) = %d" % tanbeta
        print "H+ M (GeV) | BR(t->bH+) | BR(H+->taunu) | sigma(tt->tbH+->tbtaunu) | sigma(tt->bbH+H-->bbtautau) | sigma(t->bH+->btau) |"
        for mass in [90, 100, 120, 140, 150, 155, 160]:
            br_tH = br.getBR_top2bHp(mass, tanbeta, mu)
            br_Htaunu = br.getBR_Hp2tau(mass, tanbeta, mu)

            xsec_wh = lightCrossSectionMSSM(whTauNuCrossSection, mass, tanbeta, mu, energy)[0]
            xsec_hh = lightCrossSectionMSSM(hhTauNuCrossSection, mass, tanbeta, mu, energy)[0]
            xsec_h = sum([lightCrossSectionMSSM(lambda br1, br2, en: hTauNuCrossSection(br1, br2, en, channel), mass, tanbeta, mu, energy)[0] for channel in ["s-channel", "t-channel", "tW-channel"]])

            print "%10d | %10f | %13f | %24f | %27f | %19f |" % (mass, br_tH, br_Htaunu, xsec_wh, xsec_hh, xsec_h)


if __name__ == "__main__":
    printHplusCrossSections(energy="7")
    printHplusCrossSections(energy="8")
