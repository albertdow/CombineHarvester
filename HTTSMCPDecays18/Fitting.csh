#!/bin/csh
# $1 - folder
# $2 - workspace
combine -M FitDiagnostics --plots --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --setParameters alpha=0,muggH=0,muV=0 --robustFit 1 --cminDefaultMinimizerStrategy=0 -m 125 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/${1}/${2}/125/ws.root -n _${1}_${2}
