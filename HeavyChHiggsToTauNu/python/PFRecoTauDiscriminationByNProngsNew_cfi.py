import FWCore.ParameterSet.Config as cms

from RecoTauTag.RecoTau.PFRecoTauQualityCuts_cfi import *
from RecoTauTag.RecoTau.TauDiscriminatorTools import requireLeadTrack

pfRecoTauDiscriminationByNProngsNew = cms.EDProducer("PFRecoTauDiscriminationByNProngsNew",
    PFTauProducer       = cms.InputTag('pfRecoTauProducer'), #tau collection to discriminate

    Prediscriminants    = requireLeadTrack,

    nProngs             = cms.uint32(0), # number of prongs required: 0=1||3, 1, 3
)