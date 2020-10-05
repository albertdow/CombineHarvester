#!/bin/bash
ulimit -s unlimited
combineTool.py -m 125 -M MultiDimFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 --setParameterRanges alpha=-90,90 --points 31 --redefineSignalPOIs alpha  -d output/pas_2406_v2/cmb/125/ws.root --algo grid --there -n .alpha_obs --alignEdges 1 --cminDefaultMinimizerStrategy=0 

python scripts/plot1DScan.py --main=output/pas_2406_v2/cmb/125/higgsCombine.alpha_obs.MultiDimFit.mH125.root --POI=alpha --output=alpha --no-numbers --no-box --x_title="#alpha (#circ)" --y-max=10.0

