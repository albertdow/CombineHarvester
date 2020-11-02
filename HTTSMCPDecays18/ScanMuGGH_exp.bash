#!/bin/bash
ulimit -s unlimited
combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges muV=0,4 --setParameterRanges muggH=-1,3 --points 41 --redefineSignalPOIs muggH -d output/$1/$2/125/ws.root --algo grid -t -1 --there -n .muggH_exp --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/$1/$2/125/higgsCombine.muggH_exp.MultiDimFit.mH125.root --POI=muggH --output=muggH_exp --no-numbers --no-box --x_title="#mu_{ggH}" --y-max=4.5 --main-label="#mu_{ggH}(exp.)"

