#!/bin/bash
# $1 - workspace
# $2 - model (KS, saturated)
# $3 - number of cycles
# $4 - number of toys per job


rm -rf ${1}_${2}_files
mkdir ${1}_${2}_files
cp ./HTC_submit_short.sh ${1}_${2}_files/
cd ${1}_${2}_files
combine -M GoodnessOfFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/ztt/${1}/125/ws.root --cminDefaultMinimizerStrategy=0 -m 125 --algo ${2} -n _obs

for i in `seq 1 $3`;
do
    echo submitting job $i for workspace $1
    random=$RANDOM
    cat > toys_${i}.sh << EOF2
#!/bin/sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cd ${CMSSW_BASE}/src
cmsenv
cd ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/${1}_${2}_files/
combine -M GoodnessOfFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/pas_2006/${1}/125/ws.root --cminDefaultMinimizerStrategy=0 -m 125 --algo ${2} -n _toys_${i} -t $4 -s ${random}
EOF2
    chmod u+x toys_${i}.sh
    ./HTC_submit_short.sh toys_${i}.sh toys_${i}
done
cd ../