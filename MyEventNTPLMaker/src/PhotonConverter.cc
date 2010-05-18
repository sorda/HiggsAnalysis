#include "HiggsAnalysis/MyEventNTPLMaker/interface/PhotonConverter.h"
#include "HiggsAnalysis/MyEventNTPLMaker/interface/TrackConverter.h"
#include "HiggsAnalysis/MyEventNTPLMaker/interface/ImpactParameterConverter.h"
#include "HiggsAnalysis/MyEventNTPLMaker/interface/TrackEcalHitPoint.h"

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"

#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"

using reco::TrackRef;
using reco::TransientTrack;
using std::vector;

PhotonConverter::PhotonConverter(const TrackConverter& tc, const ImpactParameterConverter& ip, const TransientTrackBuilder& builder):
        trackConverter(tc),
        ipConverter(ip),
        transientTrackBuilder(builder)
{}
PhotonConverter::~PhotonConverter() {}

MyJet PhotonConverter::convert(const reco::Photon& recPhoton) const {
        MyJet photon(recPhoton.px(), recPhoton.py(), recPhoton.pz(), recPhoton.p()); // FIXME: should we use .energy() instead of .p()?
        photon.type = 0; //unconverted

        trackConverter.addTracksInCone(photon);

	tag(recPhoton, photon.tagInfo);

        return photon;
}
MyJet PhotonConverter::convert(const reco::Conversion& recPhoton) const {
        const GlobalVector& mom(recPhoton.pairMomentum());
        MyJet photon(mom.x(), mom.y(), mom.z(), mom.mag());
	photon.type = 1; //converted

	vector<TrackRef> associatedTracks = recPhoton.tracks();
	vector<TrackRef>::const_iterator iTrack;
        for(iTrack = associatedTracks.begin(); iTrack!= associatedTracks.end(); ++iTrack){
                const TransientTrack transientTrack = transientTrackBuilder.build(**iTrack);

                MyTrack track           = TrackConverter::convert(transientTrack);
                track.ip                = ipConverter.convert(transientTrack,recPhoton);
                track.trackEcalHitPoint = TrackEcalHitPoint::convert(transientTrack,recPhoton);
                photon.tracks.push_back(track);
        }

        tag(recPhoton, photon.tagInfo);

        return photon;
}

void PhotonConverter::tag(const reco::Photon& photon, TagType& tagInfo){
/*
	tagInfo["e5x5"]		= photon->e5x5();
	tagInfo["r19"]		= photon->r19();
	tagInfo["r9"]		= photon->r9();	
*/
/** 210_pre8 DQMOffline/EGamma/src/PhotonAnalyzer.cc
    float e3x3=   EcalClusterTools::e3x3(  *(   (*iPho).superCluster()->seed()  ), &ecalRecHitCollection, &(*topology));
    float r9 =e3x3/( (*iPho).superCluster()->rawEnergy()+ (*iPho).superCluster()->preshowerEnergy());
*/
/*
	tagInfo["EoverPIn"]      = electron->eSuperClusterOverP();
        tagInfo["DeltaEtaIn"]    = electron->deltaEtaSuperClusterTrackAtVtx();
        tagInfo["DeltaPhiIn"]    = electron->deltaPhiSuperClusterTrackAtVtx();
        tagInfo["HoverE"]        = electron->hadronicOverEm();
        tagInfo["EoverPOut"]     = electron->eSeedClusterOverPout();
        tagInfo["DeltaPhiOut"]   = electron->deltaPhiSuperClusterTrackAtVtx();
        tagInfo["InvEMinusInvP"] = (1./electron->caloEnergy())-(1./electron->trackMomentumAtVtx().R());
        tagInfo["BremFraction"]  = electron->trackMomentumAtVtx().R()-electron->trackMomentumOut().R();

//	const reco::ClusterShapeRef& shapeRef = getClusterShape(electron,iEvent);
        tagInfo["E9overE25"]     = shapeRef->e3x3()/shapeRef->e5x5();
        tagInfo["SigmaEtaEta"]   = shapeRef->covEtaEta();
        tagInfo["SigmaPhiPhi"]   = shapeRef->covPhiPhi();
*/
}

void PhotonConverter::tag(const reco::Conversion& photon, TagType& tagInfo){
	tagInfo["EoverP"]     		= photon.EoverP();
	tagInfo["nTracks"]     		= photon.nTracks();
        tagInfo["pairCotThetaSeparation"] = photon.pairCotThetaSeparation();
        tagInfo["pairInvariantMass"] 	= photon.pairInvariantMass();
//        tagInfo["pairMomentumX"] 	= photon->pairMomentum().x();
//        tagInfo["pairMomentumY"]        = photon->pairMomentum().y();
//        tagInfo["pairMomentumZ"]        = photon->pairMomentum().z();
	tagInfo["zOfPrimaryVertexFromTracks"] = photon.zOfPrimaryVertexFromTracks();
//        tagInfo["pairPtOverEtSC"] 	= photon->pairPtOverEtSC();
//        tagInfo["r9"]           	= photon->r9();
}