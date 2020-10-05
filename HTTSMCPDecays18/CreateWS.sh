#!/bin/sh
# $1 - folder
# $2 - workspace
cd output/$1/$2/125
echo current directory ${PWD}
rm ws.root
rm ${2}.txt
combineCards.py *.txt > ${2}.txt
combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i ${2}.txt -o ws.root 
cd ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18