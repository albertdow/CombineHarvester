#!/bin/bash
ulimit -s unlimited
combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges muV=-1,3 --points 41 --redefineSignalPOIs muV -d output/$1/$2/125/ws.root --algo grid --there -n .muV_exp -t -1 --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/$1/$2/125/higgsCombine.muV_exp.MultiDimFit.mH125.root --POI=muV --output=muV_exp --no-numbers --no-box --x_title="#mu_{V}" --y-max=4.5 --main-label="#mu_{V}(exp.)"

