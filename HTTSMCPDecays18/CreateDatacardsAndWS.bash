#!/bin/bash
# $1 - output directory
MorphingSMCPDecays18 --output_folder=$1 --input_folder_et="DESY" --input_folder_mt="DESY" --input_folder_tt="IC" --era=all --do_jetfakes=true --mergeXbbb=true --PolVec=true

combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_Combined_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_Combined_2016_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_Combined_2017_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_Combined_2018_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_mu0a1_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_mua1_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_murho_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_et_mupi_13TeV/* -o ws.root --parallel 8
#combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/htt_bkg_et/* -o ws.root --parallel 8
