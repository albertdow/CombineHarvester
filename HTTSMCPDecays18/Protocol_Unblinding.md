
# Location of workspaces needed for statistical inference

Workspaces are located at 

/nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src/CombineHarvester/HTTSMCPDecays18/output'

Copy the directory with workspaces to your project area first

    `cp -R /nfs/dust/cms/user/rasp/CMSSW/CMSSW_10_2_13/src/CombineHarvester/HT\
TSMCPDecays18/output $CMSSW_BASE/src/CombineHarvester/HTTSMCPDecays18`
    
# Running GoF tests
    
To run GoF test execute command, e.g.

   `./RunGoF.bash etau htt_bkg_et saturated 100 50`

The first parameter is the name of the folder with the set of workspaces (etau). 

The second parameter is the name of subdirectory where workspace resides (htt_bkg_et). 

The third parameter is the test-statistics used in the GoF test (saturated).

The fourth parameter is the number of jobs to generate toys (100).

The fifth parameter is the number of toys per jobs (50).     

The script creates the folder named $1_$2_$3_files (example above will create directory etau_htt_bkg_et_saturated_files), where RooT file with the computed observed value of test-statistics and RooT files with toys are stored.

Check with condor_q command if all jobs finished, afterwards merge RooT files with toys using the following command

    `./Hadd.bash etau_htt_bkg_et_saturated_files`

Plots of GoF tests are produced with the RooT macro Compatibility.C. The macro takes as arguments the name of the directory without postfix _files (in example above it is etau_htt_bkg_et_saturated), number of bins in the histogram, upper and lower ranges of the histogram. These parameters need to be adjusted.

# Running ML fit 

You can run ML fit interactively using command

    `./Fitting.csh etau htt_bkg_et`

or submit job to condor system
   
    `./RunFit.csh etau htt_bkg_et medium`

the third argument is the batch queue (short, medium, long).

The script will create RooT file named fitDiagnostics_$1_$2.root (in example above - fitDiagnostics_etau_htt_bkg_et.root).

You can plot postfit and prefit distributions using the RooT macro Plot.C. 

And create pdf file with the postfit nuisance parameters using executable PlotNuisances

    `PlotNuisances fitDiagnostics_etau_htt_bkg_et fit_b`

The second argument is the name of the RooFitResults object where result of the ML fit is stored. You should specify fit_b for background-only and fit_s for the signal+background fit.
