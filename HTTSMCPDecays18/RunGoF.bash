#!/bin/bash
# $1 - folder
# $2 - workspace
# $3 - model (KS, saturated)
# $4 - number of cycles
# $5 - number of toys per job

rm -rf ${1}_${2}_${3}_files
mkdir ${1}_${2}_${3}_files
cp ./HTC_submit_medium.sh ${1}_${2}_${3}_files/
cd ${1}_${2}_${3}_files
combine -M GoodnessOfFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/${1}/${2}/125/ws.root --cminDefaultMinimizerStrategy=0 -m 125 --algo ${3} -n _obs

for i in `seq 1 $4`;
do
    echo submitting job $i for folder $1 and workspace $2
    random=$RANDOM
    cat > toys_${i}.sh << EOF2
#!/bin/sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cd ${CMSSW_BASE}/src
cmsenv
cd ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/${1}_${2}_${3}_files/
combine -M GoodnessOfFit --setParameters muV=1,alpha=0,muggH=1,mutautau=1 -d ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/output/${1}/${2}/125/ws.root --cminDefaultMinimizerStrategy=0 -m 125 --algo ${3} -n _toys_${i} -t $5 -s ${random}
EOF2
    chmod u+x toys_${i}.sh
    ./HTC_submit_medium.sh toys_${i}.sh toys_${i}
done
cd ../