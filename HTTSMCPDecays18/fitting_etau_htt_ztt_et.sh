#!/bin/sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc700
cd /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src
cmsenv
cd /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src/CombineHarvester/HTTSMCPDecays18/
./Fitting.csh etau htt_ztt_et
