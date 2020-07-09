#!/bin/csh
# $1 - workspace
# $2 - version
combine -M FitDiagnostics --plots --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --setParameters alpha=0,muggH=0,muV=0 --robustFit 1 --cminDefaultMinimizerStrategy=0 -m 125 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/${2}/${1}/125/ws.root -n _${1}_${2}
