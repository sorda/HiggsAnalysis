## \package multicrabDatasetsMCSummer11
#
# Dataset definitions for Summer11 MC production (CMSSW 42X)
#
# \see multicrab

import multicrabDatasetsCommon as common

# For pattuples: ~10kev/job (~20-30 kB/event on average, depending on the process)
# For analysis: ~500kev/job

# Default signal cross section taken the same as ttbar

## Dataset definitions
datasets = {
    # Signal WH
    "TTToHplusBWB_M80_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-80_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-80_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-80_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M90_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-90_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M100_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-100_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-100_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-100_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M120_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19b-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
            "pattuple_v20_test1": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v20_test1-88557732962dcf8166a136160b7c6f9d/USER",
                "number_of_jobs": 1
            },
            "pattuple_v18_2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18_2-937060476733aae3809db343c5c3f70e/USER",
                "number_of_jobs": 1
            },
            "pattuple_v18_3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18_3-19a6aba0d02bf9b1ea043fa267f42c77/USER",
                "number_of_jobs": 2
            },
        }
    },
    "TTToHplusBWB_M140_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-140_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-140_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-140_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M150_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-150_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-150_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-150_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M155_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-155_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-155_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-155_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBWB_M160_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBWB_M-160_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    # Signal HH
    "TTToHplusBHminusB_M80_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-80_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-80_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-80_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M90_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-90_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-90_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-90_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M100_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-100_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-100_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-100_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M120_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-120_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-120_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M140_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-140_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-140_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-140_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M150_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-150_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-150_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-150_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M155_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-155_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-155_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-155_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "TTToHplusBHminusB_M160_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/TTToHplusBHminusB_M-160_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-160_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTToHplusBHminusB_M-160_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },

    # Signal heavy
    "HplusTB_M180_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/HplusTB_M-180_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-180_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-180_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "HplusTB_M190_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/HplusTB_M-190_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-190_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
        }
    },
    "HplusTB_M200_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/HplusTB_M-200_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-200_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-200_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "HplusTB_M220_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/HplusTB_M-220_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-220_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-220_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "HplusTB_M250_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/HplusTB_M-250_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-250_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-250_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },
    "HplusTB_M300_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165,
        "data": {
            "AOD": {
                "datasetpath": "/HplusTB_M-300_7TeV-pythia6-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 50, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-300_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/HplusTB_M-300_7TeV-pythia6-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        }
    },

    # QCD backgrounds
    # Cross sections are from https://twiki.cern.ch/twiki/bin/view/CMS/ReProcessingSummer2011
    "QCD_Pt15to30_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 8.159e+08,
        "data": {
           "AOD": {
               "datasetpath": "/QCD_Pt-15to30_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
               "number_of_jobs": 490, # Adjusted for PATtuple file size
           },
        },
    },
    "QCD_Pt30to50_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 5.312e+07,
        "data": {
           "AOD": {
               "datasetpath": "/QCD_Pt-30to50_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
               "number_of_jobs": 490, # Adjusted for PATtuple file size
           },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-30to50_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 5
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-30to50_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 5
            },
        },
    },
    "QCD_Pt50to80_TuneZ2_Summer11": {
        "dataVersion":  "42XmcS4",
        "crossSection": 6.359e+06,
        "data": {
           "AOD": {
               "datasetpath": "/QCD_Pt-50to80_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
               "number_of_jobs": 490, # Adjusted for PATtuple file size
           },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-50to80_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 5
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-50to80_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 5
            },
        },
    },
    "QCD_Pt80to120_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 7.843e+05,
        "data": {
           "AOD": {
               "datasetpath": "/QCD_Pt-80to120_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
               "number_of_jobs": 490, # Adjusted for PATtuple file size
           },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-80to120_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 5
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-80to120_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 5
            },
        },
    },
    "QCD_Pt120to170_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 1.151e+05,
        "data": {
            "AOD": {
                "datasetpath": "/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 490, # Adjusted for PATtuple file size
            },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 5
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-120to170_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 5
            },
        },
    },
    "QCD_Pt170to300_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 2.426e+04,
        "data": {
            "AOD": {
                "datasetpath": "/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 490, # Adjusted for PATtuple file size
            },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 5
            },
           "pattuple_v18_2": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18_2-937060476733aae3809db343c5c3f70e/USER",
                "number_of_jobs": 5
            },
           "pattuple_v18_3": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18_3-19a6aba0d02bf9b1ea043fa267f42c77/USER",
                "number_of_jobs": 10
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-170to300_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 5
            },
        },
    },
    "QCD_Pt300to470_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 1.168e+03,
        "data": {
            "AOD": {
                "datasetpath": "/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 490 # Adjusted for PATtuple file size
            },
           "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 5
            },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-300to470_TuneZ2_7TeV_pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 5
            },
        }
    },
    "QCD_Pt20_MuEnriched_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 296600000.*0.0002855,
        "data": {
            "AOD": {
                "datasetpath": "/QCD_Pt-20_MuEnrichedPt-15_TuneZ2_7TeV-pythia6/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 2000,  # Adjusted for PATtuple file size
            },
           "pattuple_v18_1": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-20_MuEnrichedPt-15_TuneZ2_7TeV-pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18_1-5c1fe2e0ac511ee6db9df3b7fb33ca32/USER",
                "number_of_jobs": 50
           },
           "pattuple_v18_1": {
              "fallback": "pattuplev18_1"
           },
           "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/QCD_Pt-20_MuEnrichedPt-15_TuneZ2_7TeV-pythia6/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19b-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 50
           },
        },
    },
    

    # EWK pythia
    # Cross sections https://twiki.cern.ch/twiki/bin/view/CMS/CrossSections_3XSeries
    "WW_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 43,
        "data": {
            "AOD": {
                "datasetpath": "/WW_TuneZ2_7TeV_pythia6_tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 450, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/WW_TuneZ2_7TeV_pythia6_tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 4
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/WW_TuneZ2_7TeV_pythia6_tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 4
            },
        },
    },
    "WZ_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 18.2,
        "data": {
            "AOD": {
                "datasetpath": "/WZ_TuneZ2_7TeV_pythia6_tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 450, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/WZ_TuneZ2_7TeV_pythia6_tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 4
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/WZ_TuneZ2_7TeV_pythia6_tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 4
            },
        },
    },
    "ZZ_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 5.9,
        "data": {
            "AOD": {
                "datasetpath": "/ZZ_TuneZ2_7TeV_pythia6_tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 300, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/ZZ_TuneZ2_7TeV_pythia6_tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 4
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/ZZ_TuneZ2_7TeV_pythia6_tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 4
            },
        },
    },


    # EWK MadGraph
    # Cross sections from
    # [1] https://twiki.cern.ch/twiki/bin/view/CMS/CrossSections_3XSeries
    # [2] https://twiki.cern.ch/twiki/bin/viewauth/CMS/StandardModelCrossSections
    "TTJets_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 165, # [1,2], approx. NNLO
        "data": {
            "AOD": {
                "datasetpath": "/TTJets_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 400, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTJets_TuneZ2_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 4
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/TTJets_TuneZ2_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 4
            },
        },
    },
    "WJets_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 31314, # [2], NNLO
        "data": {
            "AOD": {
                "datasetpath": "/WJetsToLNu_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 5000, # Adjusted for PATtuple file size.
                "se_white_list": ["T2_FI_HIP"],
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/WJetsToLNu_TuneZ2_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 65
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/WJetsToLNu_TuneZ2_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 65
            },
        },
    },
    "W1Jet_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 0, # Not known yet
        "data": {
            "AOD": {
                "datasetpath": "/W1Jet_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 5000, # Adjusted for PATtuple file size.
            },
        },
    },
    "W3Jets_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 0, # Not known yet
        "data": {
            "AOD": {
                "datasetpath": "/W3Jets_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 490, # Adjusted for PATtuple file size.
            },
        },
    },
    "W4Jets_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 0, # Not known yet
        "data": {
            "AOD": {
                "datasetpath": "/W4Jets_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 1000, # Adjusted for PATtuple file size.
            },
        },
    },
    "W3Jets_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 0, # now known yet
        "data": {
            "AOD": {
                "datasetpath": "/W3Jets_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 490, # Adjusted for PATtuple file size.
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/W3Jets_TuneZ2_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 16
            },
        },
    },
    "W3Jets_TuneZ2_Summer11": {
        "dataVersion": "42XmcS4",
        "crossSection": 304.2*31314/27770.0, # value from PREP multiplied by the NNLO/PREP of inclusive WJets, see the following hypernews threads for more informatio
        # https://hypernews.cern.ch/HyperNews/CMS/get/generators/1313.html
        # https://hypernews.cern.ch/HyperNews/CMS/get/generators/1324.html
        "data": {
            "AOD": {
                "datasetpath": "/W3Jets_TuneZ2_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 490, # Adjusted for PATtuple file size.
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/W3Jets_TuneZ2_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18_1-5c1fe2e0ac511ee6db9df3b7fb33ca32/USER",
                "number_of_jobs": 16
            },
        },
    },
    "DYJetsToLL_M50_TuneZ2_Summer11": { # Z+jets
        "dataVersion": "42XmcS4",
        "crossSection": 3048, # [2], NNLO
        "data": {
            "AOD": {
                "datasetpath": "/DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 2000, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 30
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19b-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 30
            },
        }
    },

    # SingleTop Powheg
    # Cross sections from
    # https://twiki.cern.ch/twiki/bin/view/CMS/SingleTopMC2011
    # https://twiki.cern.ch/twiki/bin/view/CMS/SingleTopSigma
    "T_t-channel_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 41.92,
        "data": {
            "AOD": {
                "datasetpath": "/T_TuneZ2_t-channel_7TeV-powheg-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 400, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/T_TuneZ2_t-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 4
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/T_TuneZ2_t-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 4
            },
        },
    },
    "Tbar_t-channel_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 22.65,
        "data": {
            "AOD": {
                "datasetpath": "/Tbar_TuneZ2_t-channel_7TeV-powheg-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 200, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tbar_TuneZ2_t-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 4
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tbar_TuneZ2_t-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        },
    },
    "T_tW-channel_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 7.87,
        "data": {
            "AOD": {
                "datasetpath": "/T_TuneZ2_tW-channel-DR_7TeV-powheg-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 80, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/T_TuneZ2_tW-channel-DR_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/T_TuneZ2_tW-channel-DR_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        },
    },
    "Tbar_tW-channel_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 7.87,
        "data": {
            "AOD": {
                "datasetpath": "/Tbar_TuneZ2_tW-channel-DR_7TeV-powheg-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 80, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tbar_TuneZ2_tW-channel-DR_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tbar_TuneZ2_tW-channel-DR_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        },
    },
    "T_s-channel_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 3.19,
        "data": {
            "AOD": {
                "datasetpath": "/T_TuneZ2_s-channel_7TeV-powheg-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 30, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/T_TuneZ2_s-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/T_TuneZ2_s-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        },
    },
    "Tbar_s-channel_TuneZ2_Summer11": {
        "dataVersion": "42Xmc",
        "crossSection": 1.44,
        "data": {
            "AOD": {
                "datasetpath": "/Tbar_TuneZ2_s-channel_7TeV-powheg-tauola/Summer11-PU_S4_START42_V11-v1/AODSIM",
                "number_of_jobs": 15, # Adjusted for PATtuple file size
            },
            "pattuple_v18": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tbar_TuneZ2_s-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v18-8eea754df021b160abed50fa738aa521/USER",
                "number_of_jobs": 1
            },
            "pattuple_v19": {
                "dbs_url": common.pattuple_dbs,
                "datasetpath": "/Tbar_TuneZ2_s-channel_7TeV-powheg-tauola/local-Summer11_PU_S4_START42_V11_v1_AODSIM_pattuple_v19-9436cd413e1f831f4594f528a53faac6/USER",
                "number_of_jobs": 1
            },
        },
    },

}
