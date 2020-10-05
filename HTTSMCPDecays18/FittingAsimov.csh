#!/bin/csh
# $1 - folder
# $2 - workspace
combine -M FitDiagnostics --setParameters alpha=0,muggH=0,muV=0 --robustFit 1 --cminDefaultMinimizerStrategy=0 -m 125 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/${1}/${2}/125/ws.root -t -1 -n _${1}_${2}_asimov
