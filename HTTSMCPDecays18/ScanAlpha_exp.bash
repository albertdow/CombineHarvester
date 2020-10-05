#!/bin/bash
# $1 - workspace 
ulimit -s unlimited
combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges alpha=-90,90 --points 21 --redefineSignalPOIs alpha --robustFit 1 -d output/etau/${1}/125/ws.root --algo grid -t -1 --there -n .alpha --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/etau/${1}/125/higgsCombine.alpha.MultiDimFit.mH125.root --POI=alpha --output=alpha_exp --no-numbers --no-box --x_title="#alpha (#circ)" --y-max=2.0 --main-label="Expected" 

