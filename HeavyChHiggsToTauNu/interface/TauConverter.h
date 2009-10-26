// -*- c++ -*-
#ifndef HiggsAnalysis_HeavyChHiggsToTauNu_TauConverter_h
#define HiggsAnalysis_HeavyChHiggsToTauNu_TauConverter_h

#include "DataFormats/Common/interface/Handle.h"

#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/MyJet.h"

#include<vector>
#include<map>
#include<string>

namespace reco { 
  class IsolatedTauTagInfo;
  class CaloTau;
  class PFTau;
  class CaloJet;
}
namespace pat { class Tau; }
class TransientTrackBuilder;
class TauJetCorrector;

class MyCaloTower;
class TrackConverter;
class ImpactParameterConverter;
class TrackEcalHitPoint;
class CaloTowerConverter;
class EcalClusterConverter;

class TauConverter {
public:
  TauConverter(const TrackConverter&, const ImpactParameterConverter&, TrackEcalHitPoint&, const CaloTowerConverter&,
               const EcalClusterConverter&,
               const TransientTrackBuilder&, const TauJetCorrector&);
  ~TauConverter();

  template <class T> MyJet convert(edm::Handle<T>& handle, size_t i) {
    return convert((*handle)[i]);
  }

  MyJet convert(const reco::CaloTau& recTau);
  MyJet convert(const reco::IsolatedTauTagInfo& recTau);
  MyJet convert(const pat::Tau& recTau);
  MyJet convert(const reco::PFTau& recTau);

  typedef std::map<std::string, double> TagType;

  static void tag(const reco::IsolatedTauTagInfo&, TagType&);
  static void tag(const reco::CaloTau&, TagType&);
  static void tag(const pat::Tau&, TagType&);
  static void tag(const reco::PFTau&, TagType&);

private:
  void caloTowers(const reco::CaloJet&, std::vector<MyCaloTower>&);

  const TrackConverter& trackConverter;
  const ImpactParameterConverter& ipConverter;
  TrackEcalHitPoint& trackEcalHitPoint;
  const CaloTowerConverter& caloTowerConverter;
  const EcalClusterConverter& ecalClusterConverter;
  const TransientTrackBuilder& transientTrackBuilder;
  const TauJetCorrector& tauJetCorrection;
};

#endif