#!/bin/bash
# EmbedZTT ZL TTT VVT jetFakes 
#grep -i "CMS_scale_e " output/all_Oct20/htt_et_Combined_13TeV/125/*.txt
grep -i $1 output/all_Oct20/htt_et_Combined_13TeV/125/*.txt > $1.sys
#grep -i $1 output/all_Oct20/htt_et_Combined_13TeV/125/*.txt
