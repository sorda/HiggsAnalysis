#include "catch.hpp"

#include "test_createTree.h"

#include "Framework/interface/BranchManager.h"
#include "DataFormat/interface/Tau.h"

#include <algorithm>

TEST_CASE("Tau", "[DataFormat]") {
  SECTION("Default prefix") {
    std::unique_ptr<TTree> tree = createRealisticTree();

    BranchManager mgr;
    mgr.setTree(tree.get());

    TauCollection coll;
    coll.setupBranches(mgr);

    SECTION("TauCollection") {
      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
    }

    SECTION("Tau getters") {
      mgr.setEntry(0);
      auto p = coll[0];
      CHECK( p.pt()  == 50.f );
      CHECK( p.eta() == 0.1f );
      CHECK( p.phi() == -2.9f );
      CHECK( p.e()   == 60.f );
      CHECK( p.decayModeFinding() == true );

      p = coll[2];
      CHECK( p.decayModeFinding() == true );

      mgr.setEntry(2);
      p = coll[1];
      CHECK( p.decayModeFinding() == false );
    }

    SECTION("Conversion to std::vector") {
      mgr.setEntry(0);
      std::vector<Tau> vec = coll.toVector();
      REQUIRE( vec.size() == 4 );
      CHECK( vec[0].pt() == 50.f );
      CHECK( vec[3].decayModeFinding() == false );
    }

    SECTION("Iterators") {
      mgr.setEntry(0);

      auto iter = coll.begin();
      REQUIRE( iter != coll.end() );
      REQUIRE( iter == coll.begin() );
      CHECK( (*iter).pt() == coll[0].pt() );

      ++iter;
      REQUIRE( iter != coll.end() );
      CHECK( (*iter).pt() == coll[1].pt() );

      ++iter;
      REQUIRE( iter != coll.end() );
      CHECK( (*iter).pt() == coll[2].pt() );

      ++iter;
      REQUIRE( iter != coll.end() );
      CHECK( (*iter).pt() == coll[3].pt() );

      ++iter;
      REQUIRE( iter == coll.end() );
    }

    SECTION("Range-for") {
      mgr.setEntry(0);

      size_t i=0;
      for(Tau tau: coll) {
        CHECK( tau.pt() == coll[i].pt() );
        ++i;
      }
    }

    SECTION("Iterators for a selection") {
      mgr.setEntry(0);

      TauCollection::const_iterator found = coll.end();
      for(auto iTau = coll.begin(); iTau != coll.end(); ++iTau) {
        if((*iTau).pt() > 40) {
          if(found == coll.end()) {
            found = iTau;
          }
          else if((*iTau).pt() > (*found).pt()) {
            found = iTau;
          }
        }
      }

      REQUIRE( found != coll.end() );
      CHECK( (*found).index() == 0 );
    }

    SECTION("Iterators for a selection, nothing selected") {
      mgr.setEntry(0);

      TauCollection::const_iterator found = coll.end();
      for(auto iTau = coll.begin(); iTau != coll.end(); ++iTau) {
        if((*iTau).pt() > 80) {
          if(found == coll.end()) {
            found = iTau;
          }
          else if((*iTau).pt() > (*found).pt()) {
            found = iTau;
          }
        }
      }

      CHECK( found == coll.end() );
    }

    SECTION("Standard algorithms on iterators") {
      mgr.setEntry(0);

      std::vector<Tau> dst;
      std::copy_if(coll.begin(), coll.end(), std::back_inserter(dst),
                   [](Tau tau) {
                     return tau.decayModeFinding();
                   });
      REQUIRE( dst.size() == 2 );
      CHECK( dst[0].index() == 0 );
      CHECK( dst[1].index() == 2 );

      auto max = std::max_element(coll.begin(), coll.end(), [](Tau a, Tau b) {
          return a.pt() < b.pt();
        });
      REQUIRE( max != coll.end() );
      CHECK( (*max).index() == 0 );
    }
  }



  SECTION("Custom prefix") {
    std::unique_ptr<TTree> tree = createRealisticTree("Foos");

    BranchManager mgr;
    mgr.setTree(tree.get());

    SECTION("Invalid prefix") {
      TauCollection coll("Foo");
      coll.setupBranches(mgr);

      mgr.setEntry(0);
      REQUIRE_THROWS_AS( coll.size() , std::runtime_error );
    }


    TauCollection coll("Foos");
    coll.setupBranches(mgr);

    SECTION("TauCollection") {
      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
    }

    SECTION("Tau getters") {
      mgr.setEntry(0);
      auto p = coll[0];
      CHECK( p.pt()  == 50.f );
    }
  }



  SECTION("Systematic variations") {
    std::unique_ptr<TTree> tree = createRealisticTree();

    BranchManager mgr;
    mgr.setTree(tree.get());

    TauCollection coll;
    coll.setEnergySystematicsVariation("_systVarTESUp");
    coll.setupBranches(mgr);

    SECTION("TauCollection") {
      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
    }

    SECTION("Tau getters") {
      mgr.setEntry(0);
      auto p = coll[0];
      CHECK( p.pt()  == 50.f*1.03f );
      CHECK( p.eta() == 0.1f );
      CHECK( p.phi() == -2.9f );
      CHECK( p.e()   == 60.f*1.03f );
      CHECK( p.decayModeFinding() == true );
    }
  }

  SECTION("Configurable discriminators") {
    std::unique_ptr<TTree> tree = createRealisticTree();

    BranchManager mgr;
    mgr.setTree(tree.get());

    TauCollection coll;

    SECTION("One discriminator") {
      TauCollection fTauCollection;
      coll.setConfigurableDiscriminators(std::vector<std::string>{fTauCollection.getIsolationDiscriminatorNames()[0]});
      coll.setupBranches(mgr);

      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );
      CHECK( coll[0].configurableDiscriminators() == true );
      CHECK( coll[1].configurableDiscriminators() == true );
      CHECK( coll[2].configurableDiscriminators() == true );
      CHECK( coll[3].configurableDiscriminators() == false );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );
      CHECK( coll[0].configurableDiscriminators() == true );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
      CHECK( coll[0].configurableDiscriminators() == true );
      CHECK( coll[1].configurableDiscriminators() == true );
    }

    SECTION("Other discriminator") {
      TauCollection fTauCollection;
      coll.setConfigurableDiscriminators(std::vector<std::string>{fTauCollection.getAgainstMuonDiscriminatorNames()[0]});
      coll.setupBranches(mgr);

      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );
      CHECK( coll[0].configurableDiscriminators() == true );
      CHECK( coll[1].configurableDiscriminators() == true );
      CHECK( coll[2].configurableDiscriminators() == false );
      CHECK( coll[3].configurableDiscriminators() == true );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );
      CHECK( coll[0].configurableDiscriminators() == false );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
      CHECK( coll[0].configurableDiscriminators() == false );
      CHECK( coll[1].configurableDiscriminators() == false );
    }

    SECTION("Two discriminators") {
      TauCollection fTauCollection;
      coll.setConfigurableDiscriminators(std::vector<std::string>{fTauCollection.getIsolationDiscriminatorNames()[0],
        fTauCollection.getAgainstMuonDiscriminatorNames()[0]});
      coll.setupBranches(mgr);

      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );
      CHECK( coll[0].configurableDiscriminators() == true );
      CHECK( coll[1].configurableDiscriminators() == true );
      CHECK( coll[2].configurableDiscriminators() == false );
      CHECK( coll[3].configurableDiscriminators() == false );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );
      CHECK( coll[0].configurableDiscriminators() == false );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
      CHECK( coll[0].configurableDiscriminators() == false );
      CHECK( coll[1].configurableDiscriminators() == false );
    }

    SECTION("Two discriminators, other way around") {
      TauCollection fTauCollection;
      coll.setConfigurableDiscriminators(std::vector<std::string>{fTauCollection.getAgainstMuonDiscriminatorNames()[0],
        fTauCollection.getIsolationDiscriminatorNames()[0]});
      coll.setupBranches(mgr);

      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );
      CHECK( coll[0].configurableDiscriminators() == true );
      CHECK( coll[1].configurableDiscriminators() == true );
      CHECK( coll[2].configurableDiscriminators() == false );
      CHECK( coll[3].configurableDiscriminators() == false );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );
      CHECK( coll[0].configurableDiscriminators() == false );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
      CHECK( coll[0].configurableDiscriminators() == false );
      CHECK( coll[1].configurableDiscriminators() == false );
    }

    SECTION("Three discriminators") {
      TauCollection fTauCollection;
      coll.setConfigurableDiscriminators(std::vector<std::string>{fTauCollection.getIsolationDiscriminatorNames()[0],
        fTauCollection.getAgainstMuonDiscriminatorNames()[0], fTauCollection.getAgainstElectronDiscriminatorNames()[0]});
      coll.setupBranches(mgr);

      mgr.setEntry(0);
      REQUIRE( coll.size() == 4 );
      CHECK( coll[0].configurableDiscriminators() == true );
      CHECK( coll[1].configurableDiscriminators() == false );
      CHECK( coll[2].configurableDiscriminators() == false );
      CHECK( coll[3].configurableDiscriminators() == false );

      mgr.setEntry(1);
      REQUIRE( coll.size() == 1 );
      CHECK( coll[0].configurableDiscriminators() == false );

      mgr.setEntry(2);
      REQUIRE( coll.size() == 2 );
      CHECK( coll[0].configurableDiscriminators() == false );
      CHECK( coll[1].configurableDiscriminators() == false );
    }
  }
}
