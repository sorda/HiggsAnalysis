import FWCore.ParameterSet.Config as cms
from HiggsAnalysis.HeavyChHiggsToTauNu.HChOptions import getOptionsDataVersion

dataVersion="53XmcS10"
dataVersion="53Xdata24Aug2012" # Now we have multiple dataVersions for data too, see HChDataVersion for them

# Command line arguments (options) and DataVersion object
options, dataVersion = getOptionsDataVersion(dataVersion)

# Create Process
process = cms.Process("HChPatTuple")
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5) )

# Global tag
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string(dataVersion.getGlobalTag())
print "GlobalTag="+dataVersion.getGlobalTag()

################################################################################
# Source
process.source = cms.Source('PoolSource',
  fileNames = cms.untracked.vstring(
#    "rfio:/castor/cern.ch/user/w/wendland/FE2DEA23-15CA-DF11-B86C-0026189438BF.root" #AOD
#	"rfio:/castor/cern.ch/user/s/slehti/testData/TTToHplusBWB_M-90_7TeV-pythia6-tauola_Fall10-START38_V12-v1_RAW_RECO.root"
#	"rfio:/castor/cern.ch/user/s/slehti/testData/test_H120_100_1_08t_RAW_RECO.root"
#        dataVersion.getPatDefaultFileCastor()
        dataVersion.getPatDefaultFileMadhatter()
  )
)

################################################################################
# Load common stuff
process.load("HiggsAnalysis.HeavyChHiggsToTauNu.HChCommon_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
del process.TFileService
#process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
#process.Tracer = cms.Service("Tracer")

################################################################################
# In case of data, add trigger
myTrigger = options.trigger
if len(myTrigger) == 0:
    myTrigger = dataVersion.getDefaultSignalTrigger()

################################################################################
# Output module
process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('pattuple.root'),
    outputCommands = cms.untracked.vstring(
        "drop *",
        ),
    dropMetaData = cms.untracked.string("ALL"),
    # Save only those events which passed the path (for possible
    # trigger and event cleaning). See also for 'skimConfig' in the
    # end of this configuration.
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring("path")
    ),
)

################################################################################
# Add PAT sequences
from HiggsAnalysis.HeavyChHiggsToTauNu.HChPatTuple import *

options.doPat=1
(process.sPAT, c) = addPatOnTheFly(process, options, dataVersion,
                                   patArgs={"doTauHLTMatching": False,
                                            "matchingTauTrigger": myTrigger},
                                   doHBHENoiseFilter=False, # Only save the HBHE result to event, don't filter
                                   calculateEventCleaning=True, # This requires the tags from test/pattuple/checkoutTags.sh
                                   )

# Prune GenParticles
if dataVersion.isMC():
    process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
    process.genParticles = cms.EDProducer("GenParticlePruner",
        src = cms.InputTag("genParticles"),
        select = cms.vstring(
            "keep *",
            # Remove the soft photons from fragmentations (we have not needed them)
#            "drop pdgId() = {gamma} && mother().pdgId() = {pi0}"
            "drop++ pdgId() = {string}",
            "keep pdgId() = {string}",
            )
    )
    process.out.outputCommands.extend([
        "drop *_genParticles_*_*",
        "keep *_genParticles_*_"+process.name_(),
        ])

    process.sPAT.replace(process.patSequence, process.genParticles*process.patSequence)

#    process.load("HiggsAnalysis.HeavyChHiggsToTauNu.tauEmbedding.printGenParticles_cff")
#    process.sPAT *= process.printGenParticles

#if dataVersion.isMC():
#    process.genParticles = cms.EDProducer("GenParticlePruner",
#        src = cms.InputTag("genParticles"),
#        select = cms.vstring("keep *")
#    )
#    process.out.outputCommands.extend([
#        "drop *_genParticles_*_*",
#        "keep *_genParticles_*_"+process.name_(),
#        ])
#
#    process.sPAT.replace(process.patSequence, process.genParticles*process.patSequence)


################################################################################
# Take our skim, run it independently of the rest of the job, don't
# use it's result for selecting the events to save. It is used to just
# to get the decision, which is saved by the framework to the event,
# and it can be accessed later in the analysis stage.
process.load("HiggsAnalysis.Skimming.heavyChHiggsToTauNu_Sequences_cff")
process.heavyChHiggsToTauNuHLTFilter.TriggerResultsTag.setProcessName(dataVersion.getTriggerProcess())
process.heavyChHiggsToTauNuSequence.remove(process.heavyChHiggsToTauNuHLTrigReport)
if isinstance(myTrigger, basestring):
    myTrigger = [myTrigger]
process.heavyChHiggsToTauNuHLTFilter.HLTPaths = myTrigger
process.heavyChHiggsToTauNuHLTFilter.throw = False

#process.load("HiggsAnalysis.HeavyChHiggsToTauNu.HLTTauEmulation_cff")
#process.out.outputCommands.extend(["keep recoCaloTaus_caloTauHLTTauEmu_*_*"])
#process.out.outputCommands.extend(["keep *_l1extraParticles_*_*"])
#process.out.outputCommands.extend(["keep recoTracks_generalTracks_*_*"])
#process.out.outputCommands.extend(["keep recoCaloJets_ak5CaloJets_*_*"])

process.triggerObjects = cms.EDAnalyzer("HPlusPATTriggerPrinter",
    src = cms.InputTag("patTriggerEvent")
)

# Create paths
process.path    = cms.Path(
#    process.collisionDataSelection * # this is supposed to be empty for MC
#    process.HLTTauEmu * # Hopefully not needed anymore in 39X as the tau trigger should be fixed
    process.sPAT
#    process.sPF2PAT *
#    process.sPF2PATnoPU
    * process.triggerObjects
)
process.skimPath = cms.Path(
    process.heavyChHiggsToTauNuSequence
)

# In case of OR of many triggers, add event counts for each trigger separately
# Assume that if triggerThrow is false, the multiple triggers cover
# different run ranges without any overlaps, then this information is
# not interesting and can be neglected
if dataVersion.isData() and len(options.trigger) > 1 and options.triggerThrow != 0:
    import HLTrigger.HLTfilters.hltHighLevel_cfi as hltHighLevel
    for trig in options.trigger:
        name = trig.replace("_", "")

        mt = hltHighLevel.hltHighLevel.clone(
            HLTPaths = cms.vstring(trig)
        )
        mt.TriggerResultsTag.setProcessName(dataVersion.getTriggerProcess())
        setattr(process, "Trigger"+name, mt)

        mc1 = cms.EDProducer("EventCountProducer")
        setattr(process, "Counter"+name, mc1)

        mc2 = cms.EDProducer("EventCountProducer")
        setattr(process, "CounterScraping"+name, mc2)

        path = cms.Path(
#            process.hltPhysicsDeclared *
            mt * 
            mc1 *
            process.scrapingVeto *
            mc2
        )
        setattr(process, "Path"+name, path)

# If there is a need to apply some skim
if len(options.skimConfig) > 0:
    if len(options.skimConfig) == 1:
        print "Skimming with configuration ", options.skimConfig
    else:
        print "Skimming with OR of configurations ", " ".join(options.skimConfig)
    process.out.SelectEvents.SelectEvents = []
    for config in options.skimConfig:
        process.load("HiggsAnalysis.HeavyChHiggsToTauNu."+config)
        baseName = config.replace("_cff", "")
        baseName = baseName[0].lower() + baseName[1:] # Make the first letter lower case
        path = cms.Path(
            process.sPAT + # Ensure that PAT and the possible trigger selection have been run, framework ensures the modules are ran only once
            getattr(process, baseName+"Sequence")
        )
        setattr(process, baseName+"Path", path)
        process.out.SelectEvents.SelectEvents.append(baseName+"Path")

# Output module in EndPath
process.outpath = cms.EndPath(process.out)

if len(options.customizeConfig) > 0:
    print "Customizing with configurations ", ", ".join(options.customizeConfig)
    for config in options.customizeConfig:
        module = __import__("HiggsAnalysis.HeavyChHiggsToTauNu."+config, fromlist=[config])
        module.customize(process)

#f = open("configDump.py", "w")
#f.write(process.dumpPython())
#f.close()
