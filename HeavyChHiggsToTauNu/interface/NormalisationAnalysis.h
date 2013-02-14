// -*- c++ -*-
#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_NormalisationAnalysis_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_NormalisationAnalysis_h

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TriggerSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/VertexSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TauSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/FakeTauIdentifier.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/VetoTauSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/ElectronSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/MuonSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/JetSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/METSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/BTagging.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/TopChiSelection.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EvtTopology.h"

#include <string>
#include <vector>

namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

namespace HPlus {
  class HistoWrapper;
  class WrappedTH1;
  class WrappedTH2;

  /**
   * Class to check normalisation of certain backgrounds and to derive normalisation scale factors
   */
  class NormalisationAnalysis {
  public:
    NormalisationAnalysis(EventCounter& eventCounter, HistoWrapper& histoWrapper);
    NormalisationAnalysis(const edm::ParameterSet& iConfig, EventCounter& eventCounter, HistoWrapper& histoWrapper);
    ~NormalisationAnalysis();

    /**
     * Does tag and probe for a selected electron and the selected tau using Z->ee mass as a constraint.
     * Derives normalisation scale factors in bins of tau pT and tau decay mode
     */
    void analyseEToTauFakes(const VertexSelection::Data& vertexData,
                            const TauSelection::Data& tauData,
                            const FakeTauIdentifier::Data& fakeTauData,
                            const ElectronSelection::Data& electronData);

  protected:
    /// Creates histograms
    void createHistograms();
    /// Event counter object
    EventCounter& fEventCounter;
    /// HistoWrapper object
    HistoWrapper& fHistoWrapper;

    // Input parameters

    // Counters - needed or not?

    // Histograms ------------------------------------------
    // e -> tau fakes
    WrappedTH1* hEtoTauZmassAll;
    WrappedTH1* hEtoTauZmassDecayMode0;
    WrappedTH1* hEtoTauZmassDecayMode1;
    WrappedTH1* hEtoTauZmassDecayMode2;
    WrappedTH1* hEtoTauTauPtAll;
    WrappedTH1* hEtoTauTauPtDecayMode0;
    WrappedTH1* hEtoTauTauPtDecayMode1;
    WrappedTH1* hEtoTauTauPtDecayMode2;

  };
}

#endif