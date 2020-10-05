#!/bin/bash
combineTool.py -M HybridNew --testStat TEV --generateNuisances=0 --generateExternalMeasurements=1 --fitNuisances=1 --setParameters muV=1,alpha=0,muggH=1 --redefineSignalPOIs alpha --singlePoint 1.571 --fullBToys --clsAcc=0 -T 2 -s 1:100:1 --job-mode condor -d /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src/CombineHarvester/HTTSMCPDecays18/output/pas_2406_v2/cmb/125/ws.root
