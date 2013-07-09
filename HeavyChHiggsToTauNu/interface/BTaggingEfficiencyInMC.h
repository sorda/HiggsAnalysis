// -*- c++ -*-                                                                                                                                          

// New code for calculating the b-tagging efficiency in MC. Responsible persons in Summer 2013: Shih-Yen and Stefan.
/*
TODO:
* Read BTagging::Data
* Modify BTagging::Data to contain the number of genuine b quarks



*/

#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_BTaggingEfficiencyInMC_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_BTaggingEfficiencyInMC_h

#include "FWCore/Utilities/interface/InputTag.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/BaseSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TauSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/BTagging.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/METSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TopChiSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/GenParticleAnalysis.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Candidate/interface/Candidate.h"

namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

namespace HPlus {
  class HistoWrapper;
  class WrappedTH1;

  class BTaggingEfficiencyInMC: public BaseSelection {
  public:
    class Data {
    public:
      Data();
      ~Data();
      // in-line getters

      friend class BTaggingEfficiencyInMC;
    private:
      // private member variables
      int fSomeDataMember;
    };

    BTaggingEfficiencyInMC(const edm::ParameterSet& iConfig, EventCounter& eventCounter, HistoWrapper& histoWrapper); // constructor
    ~BTaggingEfficiencyInMC(); // destructor

    // Analyzers
    Data silentAnalyze(const edm::Event& iEvent);
    Data analyze(const edm::Event& iEvent);

  private:
    Data privateAnalyze(const edm::Event& iEvent);
    // All the private member functions

    // All the private member variables

    // Possibly counters and histograms

  };
}

#endif
