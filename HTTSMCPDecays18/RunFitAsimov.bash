#!/bin/bash
# $1 - workspace
# $2 - version
# $3 - batch queue

echo submitting fitting for workspace $1 for version $2

cat > fitting_${1}_${2}_asimov.sh << EOF
#!/bin/sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cd ${CMSSW_BASE}/src
cmsenv
cd ${CMSSW_BASE}/src/CombineHarvester/HTTSMCPDecays18/
./FittingAsimov.csh $1 $2
EOF
chmod u+x fitting_${1}_${2}_asimov.sh
./HTC_submit_${3}.sh fitting_${1}_${2}_asimov.sh fitting_${1}_${2}_asimov
