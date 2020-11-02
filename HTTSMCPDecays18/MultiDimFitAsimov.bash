#!/bin/bash
# $1 - folder containing the set of workspaces related to a given channel (e.g. etau)
# $2 - folder with a worskapce to be tested (e.g. htt_bkg_et)

combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges alpha=-90,90 --setParameterRanges muV=1,5 --setParameterRanges muggH=-1,2 --redefineSignalPOIs alpha -d output/$1/$2/125/ws.root --algo none --there -n .asimov.bestfit --cminDefaultMinimizerStrategy=0 -t -1 --saveFitResult

#PostFitShapesFromWorkspace -m 125 -d output/$1/$2/125/combined.txt.cmb -w output/$1/$2/125/ws.root -o shapes_$1_$2.root --print --postfit --sampling 1 --total-shapes-bin=true -f output/$1/$2/125/multidimfit.bestfit.root:fit_mdf 
