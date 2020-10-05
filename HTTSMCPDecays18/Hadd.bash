#!/bin/bash
# $1 - directory 
cd $1
rm higgsCombine_toys.GoodnessOfFit.mH125.root
hadd higgsCombine_toys.GoodnessOfFit.mH125.root *_toys_*root
cd ../
