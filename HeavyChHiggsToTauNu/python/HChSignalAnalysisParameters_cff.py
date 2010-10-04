import FWCore.ParameterSet.Config as cms

trigger = cms.untracked.PSet(
    src = cms.untracked.InputTag("patTriggerEvent"),
    trigger = cms.untracked.string("HLT_SingleLooseIsoTau20")
)

tauSelection = cms.untracked.PSet(
    #src = cms.untracked.InputTag("selectedPatTausCaloRecoTau"),
    src = cms.untracked.InputTag("selectedPatTausFixedConePFTau"),
    #src = cms.untracked.InputTag("selectedPatTausShrinkingConePFTau"),
    ptCut = cms.untracked.double(20),
    etaCut = cms.untracked.double(2.4),
    leadingTrackPtCut = cms.untracked.double(10)
)

jetSelection = cms.untracked.PSet(
    src = cms.untracked.InputTag("selectedPatJets"),
    #src = cms.untracked.InputTag("selectedPatJetsAK5JPT"),
    cleanTauDR = cms.untracked.double(0.5),
    ptCut = cms.untracked.double(20),
    etaCut = cms.untracked.double(2.4),
    minNumber = cms.untracked.uint32(3)
)

bTagging = cms.untracked.PSet(
    discriminator = cms.untracked.string("trackCountingHighEffBJetTags"),
    discriminatorCut = cms.untracked.double(1.5),
    minNumber = cms.untracked.uint32(1)
)

MET = cms.untracked.PSet(
    src = cms.untracked.InputTag("patMETs"), # calo MET
    #src = cms.untracked.InputTag("patMETsPF"), # PF MET
    #src = cms.untracked.InputTag("patMETsTC"), # tc MET
    METCut = cms.untracked.double(40)
)

