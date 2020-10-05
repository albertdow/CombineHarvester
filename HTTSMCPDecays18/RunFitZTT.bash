#!/bin/bash
# $1 - workspace
# $2 - version
# $3 - rMin
# $4 - rMax
# $5 - batch queue

echo submitting fitting for workspace $1 for version $2

cat > fitting_${1}_${2}_r${3}to${4}.sh << EOF
#!/bin/sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cd ${CMSSW_BASE}/src
cmsenv
cd ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/
./FittingZTT.csh $1 $2 $3 $4
EOF
chmod u+x fitting_${1}_${2}_r${3}to${4}.sh
./HTC_submit_${5}.sh fitting_${1}_${2}_r${3}to${4}.sh fitting_${1}_${2}_r${3}to${4}
