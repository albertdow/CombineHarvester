#!/bin/csh
# $1 - workspace
# $2 - version
# $3 - rMin
# $4 - rMax
combine -M FitDiagnostics --rMin=${3} --rMax=${4} --saveNormalizations --saveShapes --saveWithUncertainties --saveNLL --cminDefaultMinimizerStrategy=0 -m 125 --expectSignal=1 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/${2}/${1}/125/ws.root -n _${1}_${2}_r${3}to${4} 
# --freezeParameters CMS_htt_zjXsec_13TeV
