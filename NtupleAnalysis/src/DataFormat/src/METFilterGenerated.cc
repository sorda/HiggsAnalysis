
// -*- c++ -*-
// This file has been auto-generated with HiggsAnalysis/NtupleAnalysis/scripts/hplusGenerateDataFormats.py

#include "DataFormat/interface/METFilterGenerated.h"

void METFilterGenerated::setupBranches(BranchManager& mgr) {
  mgr.book("METFilter_Flag_CSCTightHaloFilter", &fFlag_CSCTightHaloFilter);
  mgr.book("METFilter_Flag_eeBadScFilter", &fFlag_eeBadScFilter);
  mgr.book("METFilter_Flag_goodVertices", &fFlag_goodVertices);
  mgr.book("METFilter_hbheIsoNoiseToken", &fHbheIsoNoiseToken);
  mgr.book("METFilter_hbheNoiseTokenRun2Loose", &fHbheNoiseTokenRun2Loose);
  mgr.book("METFilter_hbheNoiseTokenRun2Tight", &fHbheNoiseTokenRun2Tight);

}
