#!/usr/bin/env python

import os
import sys

import HiggsAnalysis.NtupleAnalysis.tools.dataset as dataset
import HiggsAnalysis.NtupleAnalysis.tools.tdrstyle as tdrstyle
import HiggsAnalysis.NtupleAnalysis.tools.styles as styles
import HiggsAnalysis.NtupleAnalysis.tools.plots as plots
import HiggsAnalysis.NtupleAnalysis.tools.histograms as histograms
import HiggsAnalysis.NtupleAnalysis.tools.aux as aux

plotDir = "Plots"
formats = [".pdf",".png",".C"]

def usage():
    print "\n"
    print "### Usage:   "+sys.argv[0]+" <multicrab dir>\n"
    print "\n"
    sys.exit()

def removeNegatives(histo):
    for bin in range(histo.GetNbinsX()):
        if histo.GetBinContent(bin) < 0:
            histo.SetBinContent(bin,0.)

def main():

    if len(sys.argv) < 2:
        usage()

    paths = [sys.argv[1]]
    analysis = "SignalAnalysis"
    hName = "HNAME"
    plotname = analysis+"_"+hName

    datasetsTT = dataset.getDatasetsFromMulticrabDirs(paths,analysisName=analysis)
    print "test\n"

#    style = tdrstyle.TDRStyle()

#    dataset1 = datasetsTT.getDataset("ChargedHiggs_HplusTB_HplusToTauB_M_200").getDatasetRootHisto(hName)

if __name__ == "__main__":
    main()
