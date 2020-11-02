#!/bin/bash
combineTool.py -M T2W -P CombineHarvester.CombinePdfs.CPMixtureDecays:CPMixtureDecays -i output/$1/$2/* -o ws.root --parallel 8
