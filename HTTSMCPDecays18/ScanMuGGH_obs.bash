#!/bin/bash
ulimit -s unlimited
combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges muV=1,5 --setParameterRanges muggH=-2,2 --points 41 --redefineSignalPOIs muggH -d output/$1/$2/125/ws.root --algo grid --there -n .muggH_obs --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/$1/$2/125/higgsCombine.muggH_obs.MultiDimFit.mH125.root --POI=muggH --output=muggH --no-numbers --no-box --x_title="#mu_{ggH}" --y-max=4.5 --main-label="#mu_{ggH}(obs.)"

