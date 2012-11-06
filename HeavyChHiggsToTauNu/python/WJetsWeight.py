import FWCore.ParameterSet.Config as cms

import HiggsAnalysis.HeavyChHiggsToTauNu.tools.pileupReweightedAllEvents as pileupReweightedAllEvents

class NEvents:
    def __init__(self, inclusive_v1, inclusive_v2, jet1, jet2, jet3, jet4):
        self.inclusive_v1 = inclusive_v1
        self.inclusive_v2 = inclusive_v2
        self.jet1 = jet1
        self.jet2 = jet2
        self.jet3 = jet3
        self.jet4 = jet4

    def construct8TeV(self, era, weightType):
        # The cross sections should the ones given by madgraph (LO, from PREP)
        pset = cms.EDProducer("HPlusWJetsWeightProducer",
            lheSrc = cms.InputTag("source", "", "LHE"),
            alias = cms.string("wjetsWeight"),
            enabled = cms.bool(True),
            sampleJetBin = cms.int32(-1),
            inclusiveCrossSection = cms.double(30400.0),
            jetBin1 = cms.PSet(
                exclusiveCrossSection = cms.double(5400.0),
            ),
            jetBin2 = cms.PSet(
                exclusiveCrossSection = cms.double(1750.0),
            ),
            jetBin3 = cms.PSet(
                exclusiveCrossSection = cms.double(519.0),
            ),
            jetBin4 = cms.PSet(
                exclusiveCrossSection = cms.double(214.0),
            ),
        )

        # Assume that if no era is given, on PU reweighting is done
        if era == None or len(era) == 0:
            pset.inclusiveNevents = cms.double(self.inclusive_v1 + self.inclusive_v2)
            for jetBin in [1, 2, 3, 4]:
                getattr(pset, "jetBin%d"%jetBin).exclusiveNevents = cms.double(getattr(self, "jet%d"%jetBin))

            return pset


        def weightedAllEvents(datasetName, unweighted):
            return pileupReweightedAllEvents.getWeightedAllEvents(datasetName, era).getWeighted(unweighted, weightType)

        pset.inclusiveNevents = cms.double(
            weightedAllEvents("WJets_TuneZ2star_v1_Summer12", self.inclusive_v1) +
            weightedAllEvents("WJets_TuneZ2star_v2_Summer12", self.inclusive_v2)
        )
        for jetBin in [1, 2, 3, 4]:
            getattr(pset, "jetBin%d"%jetBin).exclusiveNevents = cms.double(weightedAllEvents("W%dJets_TuneZ2star_Summer12"%jetBin, getattr(self, "jet%d"%jetBin)))

        return pset

# Non-pu-reweighted events
_wjetsNumberOfEvents = {
    "pattuple_v53_1_test1": NEvents(inclusive_v1=2504608,
                                    inclusive_v2=3458492,
                                    jet1=2314140,
                                    jet2=851120,
                                    jet3=317130,
                                    jet4=218488),
    "pattuple_v53_1": NEvents(inclusive_v1=18393090,
                              inclusive_v2=56094032,
                              jet1=23141596,
                              jet2=34044920,
                              jet3=15539503,
                              jet4=13382803),
}


def getWJetsWeight(dataVersion, options, inputWorkflow, era, suffix=""):
    weightType = {"": pileupReweightedAllEvents.PileupWeightType.NOMINAL,
                  "up": pileupReweightedAllEvents.PileupWeightType.UP,
                  "down": pileupReweightedAllEvents.PileupWeightType.DOWN
                  }[suffix]

    if not dataVersion.is53X():
        raise Exception("WJets weights are available only for 53X")

    pset = _wjetsNumberOfEvents[inputWorkflow].construct8TeV(era, weightType)
    pset.sampleJetBin = options.wjetBin
    return pset
