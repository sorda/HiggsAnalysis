// -*- c++ -*-
#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_TopSelection_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_TopSelection_h

#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventCounter.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventWeight.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/JetSelection.h"

namespace edm {
  class ParameterSet;
}

class TH1;

namespace HPlus {
  class TopSelection;

  class TopSelection {
  public:
    /**
     * Class to encapsulate the access to the data members of
     * TauSelection. If you want to add a new accessor, add it here
     * and keep all the data of TauSelection private.
     */
    class Data {
    public:
      // The reason for pointer instead of reference is that const
      // reference allows temporaries, while const pointer does not.
      // Here the object pointed-to must live longer than this object.
      Data(const TopSelection *TopSelection, bool passedEvent);
      ~Data();

      bool passedEvent() const { return fPassedEvent; }
      //      const edm::PtrVector<pat::Jet>& getSelectedJets() const { return fTopSelection->fSelectedJets; }
      //      const int getBJetCount() const { return fTopSelection->iNBtags; }

    private:
      const TopSelection *fTopSelection;
      const bool fPassedEvent;
    };
    
    TopSelection(const edm::ParameterSet& iConfig, EventCounter& eventCounter, EventWeight& eventWeight);
    ~TopSelection();

    Data analyze(const edm::PtrVector<pat::Jet>& jets, const edm::PtrVector<pat::Jet>& bjets);

  private:
    // Input parameters
    const double fTopMassLow;
    const double fTopMassHigh;

    // Counters
    Count fTopMassCount;

    // EventWeight object
    EventWeight& fEventWeight;
    
    // Histograms
    TH1 *hPtjjb;
    TH1 *hPtmax;
    TH1 *hjjbMass;
    TH1 *htopMass;

    // Selected jets
    //    edm::PtrVector<pat::Jet> fSelectedJets;
  };
}

#endif