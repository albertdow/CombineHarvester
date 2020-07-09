#!/bin/bash
# $1 - fit nuisances (0 or 1)
ulimit -s unlimited
cd separation
combine -M HybridNew --testStat TEV --generateNuisances=0 --generateExternalMeasurements=1 --fitNuisances=${1} --setParameters muV=1,alpha=0,muggH=1 --redefineSignalPOIs alpha --singlePoint 1.571 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/pas_2406_v2/cmb/125/ws.root -n _obs_fitNuisances${1}
cd ../