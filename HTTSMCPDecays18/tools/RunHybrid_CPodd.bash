#!/bin/bash
# $1 - number of jobs
# $2 - number of toys per job
# 
ulimit -s unlimited
cd separation
for i in `seq 1 $1`;
do
    echo submitting job toys_CPodd_$i 
    random=$RANDOM
    cat > toys_CPodd_${i}.bash << EOF2
#!/bin/bash
ulimit -s unlimited
cd /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cmsenv
cd /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src/CombineHarvester/HTTSMCPDecays18/separation
combine -M HybridNew --testStat TEV --generateNuisances=0 --generateExternalMeasurements=1 --fitNuisances=1 --setParameters muV=1,alpha=1.571,muggH=1 --redefineSignalPOIs alpha --singlePoint 1.571 --saveToys --saveHybridResult -t $2 -d /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src/CombineHarvester/HTTSMCPDecays18/output/pas_2406_v2/cmb/125/ws.root --saveToys --saveHybridResult
EOF2
    chmod u+x toys_CPodd_${i}.bash
#    ./HTC_submit_medium.sh toys_CPodd_${i}.bash toys_CPodd_${i}
done
cd ../