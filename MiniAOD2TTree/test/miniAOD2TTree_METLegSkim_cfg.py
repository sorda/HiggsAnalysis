import FWCore.ParameterSet.Config as cms
import HiggsAnalysis.MiniAOD2TTree.tools.git as git #HiggsAnalysis.HeavyChHiggsToTauNu.tools.git as git
from HiggsAnalysis.HeavyChHiggsToTauNu.HChOptions import getOptionsDataVersion

process = cms.Process("TTreeDump")

dataVersion = "74Xmc"
#dataVersion = "74Xdata"

options, dataVersion = getOptionsDataVersion(dataVersion)
print dataVersion


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1000)
)

process.load("FWCore/MessageService/MessageLogger_cfi")
process.MessageLogger.categories.append("TriggerBitCounter")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000 # print the event number for every 100th event
process.MessageLogger.cerr.TriggerBitCounter = cms.untracked.PSet(limit = cms.untracked.int32(10)) # print max 100 warnings

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#       '/store/mc/RunIISpring15DR74/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/00000/022B08C4-C702-E511-9995-D4856459AC30.root',
#       '/store/data/Run2015D/Tau/MINIAOD/PromptReco-v3/000/256/630/00000/1E7E1004-225F-E511-AC7D-02163E011F9B.root',
       '/store/mc/RunIISpring15MiniAODv2/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/74X_mcRun2_asymptotic_v2-v3/60000/007C8451-206A-E511-85ED-0025905A6136.root',
    )
)

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, str(dataVersion.getGlobalTag()), '')
print "GlobalTag="+dataVersion.getGlobalTag()

# Set up electron ID (VID framework)
# https://twiki.cern.ch/twiki/bin/view/CMS/MultivariateElectronIdentificationRun2
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
switchOnVIDElectronIdProducer(process, DataFormat.MiniAOD)
# define which IDs we want to produce and add them to the VID producer
for idmod in ['RecoEgamma.ElectronIdentification.Identification.mvaElectronID_PHYS14_PU20bx25_nonTrig_V1_cff']:
    setupAllVIDIdsInModule(process, idmod, setupVIDElectronSelection)
    
# Set up HBHE noise filter
# https://twiki.cern.ch/twiki/bin/viewauth/CMS/MissingETOptionalFiltersRun2
print "Setting up HBHE noise filter"
process.load('CommonTools.RecoAlgos.HBHENoiseFilterResultProducer_cfi')
process.HBHENoiseFilterResultProducer.minZeros = cms.int32(99999)
process.HBHENoiseFilterResultProducer.IgnoreTS4TS5ifJetInLowBVRegion=cms.bool(False)
process.HBHENoiseFilterResultProducer.defaultDecision = cms.string("HBHENoiseFilterResultRun2Loose")
# Do not apply EDfilters for HBHE noise, the discriminators for them are saved into the ttree

TrgResultsSource = "TriggerResults::PAT"
if dataVersion.isData():
    TrgResultsSource = "TriggerResults::RECO"
print "Trigger source has been set to:",TrgResultsSource

process.load("HiggsAnalysis/MiniAOD2TTree/PUInfo_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/TopPt_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/Tau_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/Electron_cfi") 
process.load("HiggsAnalysis/MiniAOD2TTree/Muon_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/Jet_cfi")
process.load("HiggsAnalysis/MiniAOD2TTree/MET_cfi")

process.dump = cms.EDFilter('MiniAOD2TTreeFilter',
    OutputFileName = cms.string("miniaod2tree.root"),
    PUInfoInputFileName = process.PUInfo.OutputFileName,
    TopPtInputFileName = process.TopPtProducer.OutputFileName,
    CodeVersion = cms.string(git.getCommitId()),
    DataVersion = cms.string(str(dataVersion.version)),
    CMEnergy = cms.int32(13),
    Skim = cms.PSet(
	Counters = cms.VInputTag(
	    "skimCounterAll",
            "skimCounterPassed"
        ),
    ),
    EventInfo = cms.PSet(
        PileupSummaryInfoSrc = process.PUInfo.PileupSummaryInfoSrc, 
	OfflinePrimaryVertexSrc = cms.InputTag("offlineSlimmedPrimaryVertices"),
        TopPtProducer = cms.InputTag("TopPtProducer"),
    ),
    Trigger = cms.PSet(
	TriggerResults = cms.InputTag("TriggerResults::HLT"),
	TriggerBits = cms.vstring(
	    "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v",
            "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v",
            "HLT_LooseIsoPFTau50_Trk30_eta2p1_v",
            "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_JetIdCleaned_v",
            "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_JetIdCleaned_v",
        ),
	L1Extra = cms.InputTag("l1extraParticles:MET"),
	TriggerObjects = cms.InputTag("selectedPatTrigger"),
	filter = cms.untracked.bool(False)
    ),
    METNoiseFilter = cms.PSet(
        triggerResults = cms.InputTag(TrgResultsSource),
        printTriggerResultsList = cms.untracked.bool(False), 
        filtersFromTriggerResults = cms.vstring(
            "Flag_CSCTightHaloFilter",
            "Flag_goodVertices",
            "Flag_eeBadScFilter",
        ),
        hbheNoiseTokenRun2LooseSource = cms.InputTag('HBHENoiseFilterResultProducer','HBHENoiseFilterResultRun2Loose'),
        hbheNoiseTokenRun2TightSource = cms.InputTag('HBHENoiseFilterResultProducer','HBHENoiseFilterResultRun2Tight'),
        hbheIsoNoiseTokenSource = cms.InputTag('HBHENoiseFilterResultProducer','HBHEIsoNoiseFilterResult'),
    ),
    Taus      = process.Taus,
    Electrons = process.Electrons,
    Muons     = process.Muons,
    Jets      = process.Jets,
    METs      = process.METs,
    GenWeights = cms.VPSet(
        cms.PSet(
            branchname = cms.untracked.string("GenWeights"),
            src = cms.InputTag("generator"),
            filter = cms.untracked.bool(False)
        )
    ),
)

process.load("HiggsAnalysis.MiniAOD2TTree.METLegSkim_cfi")
process.skim.GenWeights = process.dump.GenWeights

process.skimCounterAll        = cms.EDProducer("HplusEventCountProducer")
process.skimCounterMETFilters = cms.EDProducer("HplusEventCountProducer")
process.skimCounterPassed     = cms.EDProducer("HplusEventCountProducer")

# === Setup customizations
from HiggsAnalysis.MiniAOD2TTree.CommonFragments import produceCustomisations
produceCustomisations(process) # This produces process.CustomisationsSequence which needs to be included to path
            
# module execution
process.runEDFilter = cms.Path(process.PUInfo*
                               process.skimCounterAll*  
                               process.skim*
                               process.skimCounterPassed*
                               process.CustomisationsSequence*
                               process.dump)

#process.output = cms.OutputModule("PoolOutputModule",
#    outputCommands = cms.untracked.vstring(
#        "keep *",
#    ),
#    fileName = cms.untracked.string("CMSSW.root")
#)
#process.out_step = cms.EndPath(process.output)
