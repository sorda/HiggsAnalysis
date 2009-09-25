#include "HiggsAnalysis/HeavyChHiggsToTauNu/interface/MyEventConverter.h"
/*
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/METCollection.h"
*/
MyMET MyEventConverter::getPATMET(const edm::Event& iEvent){

	MyMET met;
/*
        Handle<reco::CaloMETCollection> caloMET;
        try{
            iEvent.getByLabel("met",caloMET);
        }catch(...) {;}

        if(caloMET.isValid()){
          reco::CaloMETCollection::const_iterator imet = caloMET->begin();
          met.x = imet->px();
          met.y = imet->py();
        }

        cout << " calo MET : " << met.value()
             << "  x : " << met.getX()
             << "  y : " << met.getY() << endl;


        for(unsigned int iCorr = 0; iCorr < metCollections.size(); ++iCorr){
                edm::Handle<reco::CaloMETCollection> metHandle;
		try{
                  iEvent.getByLabel(metCollections[iCorr],metHandle);
		}catch(...) {;}

                if(metHandle.isValid()){
		  MyGlobalPoint correction;
		  correction.name = metCollections[iCorr].label();
		  
                  reco::CaloMETCollection::const_iterator imet = metHandle->begin();
		  correction.x = imet->px() - met.x;
		  correction.y = imet->py() - met.y;

		  cout << "     MET " << correction.name << " : " 
                       << correction.x << " "
                       << correction.y << endl;

		  met.corrections.push_back(correction);
                }
        }


	Handle<reco::PFMETCollection> pfMET;
        try{
            iEvent.getByLabel("pfMet",pfMET);
        }catch(...) {;}

	if(pfMET.isValid()){
	  MyGlobalPoint correction;
	  correction.name = "PFMET";

	  reco::PFMETCollection::const_iterator imet = pfMET->begin();
          correction.x = imet->px() - met.x;
          correction.y = imet->py() - met.y;

          cout << "     PF MET : " << correction.x << " "
                                   << correction.y << endl;

          met.corrections.push_back(correction);
	}


	// track corrected MET
	Handle<reco::METCollection> tcMET;
	try{
		iEvent.getByLabel("tcMet",tcMET);
	}catch(...) {;}

        if(tcMET.isValid()){
          MyGlobalPoint correction;
          correction.name = "tcMET";

          reco::METCollection::const_iterator imet = tcMET->begin();
          correction.x = imet->px() - met.x;
          correction.y = imet->py() - met.y;

          cout << "     track corrected MET : " << correction.x << " "
                                                << correction.y << endl;

          met.corrections.push_back(correction);
        }
*/

        return met;
}