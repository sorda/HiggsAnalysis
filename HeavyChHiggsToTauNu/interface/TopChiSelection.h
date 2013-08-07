// -*- c++ -*-
#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_TopChiSelection_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_TopChiSelection_h

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TopSelectionBase.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventCounter.h"

namespace edm {
  class Event;
  class EventSetup;
  class ParameterSet;
}

namespace HPlus {
  class TopChiSelection: public TopSelectionBase {
  
  public:
    TopChiSelection(const edm::ParameterSet& iConfig, EventCounter& eventCounter, HistoWrapper& histoWrapper);
    ~TopChiSelection();

  private:
    Data privateAnalyze(const edm::Event& iEvent, const edm::EventSetup& iSetup, const edm::PtrVector<pat::Jet>& jets, const edm::PtrVector<pat::Jet>& bjets);
    void init();

    // Input parameters
    const double fTopMassLow;
    const double fTopMassHigh;
    const double fChi2Cut;

    // Counters
    Count fTopChiMassCount;

    edm::InputTag fSrc;
    
    // Histograms
    
    WrappedTH1 *hPtTopChiCut;
    WrappedTH1 *hPtTop;
    WrappedTH1 *hjjbMass;
    WrappedTH1 *htopMass;
    WrappedTH1 *htopMassMatch;
    WrappedTH1 *htopMassChiCut;
    WrappedTH1 *hWMass;
    WrappedTH1 *hWMassMatch;
    WrappedTH1 *hWMassChiCut;
    WrappedTH1 *hChi2Min;
    WrappedTH1 *htopMassBMatch;
    WrappedTH1 *hWMassBMatch;
    WrappedTH1 *htopMassQMatch;
    WrappedTH1 *hWMassQMatch;
    WrappedTH1 *htopMassMatchWrongB;
    WrappedTH1 *hWMassMatchWrongB;

  };
}

#endif
