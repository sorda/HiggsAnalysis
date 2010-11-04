// -*- c++ -*-
#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_GlobalElectronVeto_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_GlobalElectronVeto_h

#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventCounter.h"
#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/EventWeight.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include <DataFormats/BeamSpot/interface/BeamSpot.h>
#include "DataFormats/Scalers/interface/DcsStatus.h"
#include "RecoEgamma/EgammaTools/interface/ConversionFinder.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include <MagneticField/Engine/interface/MagneticField.h>
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackExtra.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h" 

namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

class TH1;
#include "TH2.h"

namespace HPlus {
  class GlobalElectronVeto {
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
      Data(const GlobalElectronVeto *globalElectronVeto, bool passedEvent);
      ~Data();

      bool passedEvent() const { return fPassedEvent; }
      const float getSelectedElectronPt() const { return fGlobalElectronVeto->fSelectedElectronPt; }
      const float getSelectedElectronEta() const { return fGlobalElectronVeto->fSelectedElectronEta; }

    private:
      const GlobalElectronVeto *fGlobalElectronVeto;
      const bool fPassedEvent;
    };

    GlobalElectronVeto(const edm::ParameterSet& iConfig, EventCounter& eventCounter, EventWeight& eventWeight);
    ~GlobalElectronVeto();

    Data analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
   
  private:
    bool ElectronSelection(const edm::Event& iEvent, const edm::EventSetup& iSetup);

    // Input parameters
    edm::InputTag fElecCollectionName;
    const std::string fElecSelection;
    const double fElecPtCut;
    const double fElecEtaCut;
    
    // Counter
    Count fGlobalElectronVetoCounter;
    // Sub-Counter to Counter
    Count fElecSelectionSubCountElectronPresent;
    Count fElecSelectionSubCountElectronHasGsfTrkOrTrk;
    Count fElecSelectionSubCountPtCut;
    Count fElecSelectionSubCountEtaCut;
    // Count fElecSelectionSubCountElectronSelection; // yes if eID used
    Count fElecSelectionSubCountNLostHitsInTrkerCut;
    Count fElecSelectionSubCountmyElectronDeltaCotThetaCut;
    Count fElecSelectionSubCountmyElectronDistanceCut;
    Count fElecSelectionSubCountTransvImpactParCut;
    Count fElecSelectionSubCountDeltaRFromGlobalOrTrkerMuonCut;
    Count fElecSelectionSubCountRelIsolationR03Cut;
    // Sub-Counter (ElectronID) - just for my information
    Count fElecIDSubCountAllElectronCandidates;
    Count fElecIDSubCountElecIDRobustHighEnergy;
    Count fElecIDSubCountElecIDRobustLoose;
    Count fElecIDSubCountElecIDRobustTight;
    Count fElecIDSubCountElecIDdLoose;
    Count fElecIDSubCountElecIDTight;
    Count fElecIDSubCountElecNoID;
    Count fElecIDSubCountElecAllIDs;
    Count fElecIDSubCountOther;

    // EventWeight object
    EventWeight& fEventWeight;

    // Histograms
    TH1 *hElectronPt;
    TH1 *hElectronEta;
    TH1 *hElectronPt_gsfTrack;
    TH1 *hElectronEta_gsfTrack;
    TH1 *hElectronPt_AfterSelection;
    TH1 *hElectronEta_AfterSelection;
    TH1 *hElectronPt_gsfTrack_AfterSelection;
    TH1 *hElectronEta_gsfTrack_AfterSelection;

    // pt and eta of highest pt electron passing the selection
    float fSelectedElectronPt;
    float fSelectedElectronEta;
  };
}

#endif
