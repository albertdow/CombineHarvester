#!/bin/bash
ulimit -s unlimited
combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges alpha=-90,90 --points 31 --redefineSignalPOIs alpha  -d output/$1/$2/125/ws.root --algo grid --there -n .alpha_exp -t -1 --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/$1/$2/125/higgsCombine.alpha_exp.MultiDimFit.mH125.root --POI=alpha --output=alpha_exp --no-numbers --no-box --x_title="#alpha (#circ)" --y-max=3.0 --main-label="expected "

