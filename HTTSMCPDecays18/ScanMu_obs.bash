#!/bin/bash
ulimit -s unlimited
#combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges mutautau=0,2 --freezeParameters muV,muggH,alpha --points 41 --redefineSignalPOIs mutautau  -d output/$1/$2/125/ws.root --algo grid --there -n .mu_obs --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/$1/$2/125/higgsCombine.mu_obs.MultiDimFit.mH125.root --POI=mutautau --output=mutautau --no-numbers --no-box --x_title="#mu" --y-max=4.5 --main-label="#mu(obs.)"

