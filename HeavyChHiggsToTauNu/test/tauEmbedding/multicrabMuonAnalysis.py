#!/usr/bin/env python

from HiggsAnalysis.HeavyChHiggsToTauNu.tools.multicrab import *

multicrab = Multicrab("../crab_analysis.cfg", "muonAnalysis_cfg.py")

aodDatasets = [
    # Data
    "Mu_135821-144114",
    "Mu_146240-147116",
    "Mu_147196-149442",
    # Signal MC (Fall10)
#    "TT",
    "TTJets",
    # Background MC (Fall10)
    "QCD_Pt20_MuEnriched",
    "DYJetsToLL", # Z+jets
    "TToBLNu_s-channel",
    "TToBLNu_t-channel",
    "TToBLNu_tW-channel",
    # Background MC (Summer10)
#    "ZJets",
#    "SingleTop_sChannel",
#    "SingleTop_tChannel",
#    "SingleTop_tWChannel",
    ]
patDatasets = [
    # Signal MC
#    "TT",
#    "TTJets", # Fall10
    "WJets", # Summer10
    # Background MC
    "QCD_Pt30to50_Fall10",
    "QCD_Pt50to80_Fall10",
    "QCD_Pt80to120_Fall10",
    "QCD_Pt120to170_Fall10",
    "QCD_Pt170to300_Fall10",
]

usePatTuples = True
#usePatTuples = False

if not usePatTuples:
    aodDatasets.extend(patDatasets)
if len(aodDatasets) > 0:
    multicrab.addDatasets("AOD", aodDatasets)
if usePatTuples and len(patDatasets) > 0:
    multicrab.addDatasets("pattuple_v6", patDatasets)

multicrab.setDataLumiMask("../Cert_132440-149442_7TeV_StreamExpress_Collisions10_JSON.txt")

decaySeparate = ["TTJets",
                 "WJets",
                 "TToBLNu_s-channel",
                 "TToBLNu_t-channel",
                 "TToBLNu_tW-channel"]
def modify(dataset):
    if dataset.getName() in aodDatasets:
        dataset.addArg("doPat=1")
    if dataset.getName() in decaySeparate:
        dataset.addArg("WDecaySeparate=1")
    if dataset.getName() == "TTJets":
        dataset.setNumberOfJobs(40)

multicrab.forEachDataset(modify)

#multicrab.modifyLumisPerJobAll(lambda nlumis: nlumis*0.5)
#multicrab.modifyNumberOfJobsAll(lambda njobs: njobs*2)

multicrab.createTasks()
#multicrab.createTasks(configOnly=True)