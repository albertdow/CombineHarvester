#include "CombineHarvester/CombineTools/interface/PlotNuisances.h"
#include "TFile.h"
#include "RooFit.h"
#include "TH1.h"
#include <vector>
#include <string>
#include "RooFitResult.h"
#include "RooArgList.h"
#include "RooRealVar.h"
#include "TAxis.h"
#include <stdio.h>
#include <stdlib.h>
#include "TString.h"

int main(int argc, char** argv) {

  SetStyle();

  TString filename(argv[1]);

  std::vector<TString> index = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
    "32",
    "33",
    "34",
    "35",
    "36",
    "37",
    "38",
    "39",
    "40",
    "41",
    "42",
    "43",
    "44",
    "45",
    "46",
    "47",
    "48",
    "49",
    "50"
  };

  TFile * file = new TFile(filename+".root");
  if (file->IsZombie()) { 
    exit(-1);
  }

  RooFitResult * fitres = (RooFitResult*)file->Get("fit_b");
  RooArgList  list = fitres->floatParsFinal();

  std::string command = "mkdir " + std::string(argv[1]);

  system(command.c_str());
  
  int nPeriod = 30;

  int n = list.getSize();
  int nCycles = n/nPeriod;
  int remainder = n - nPeriod*nCycles;
  std::cout << std::endl;
  std::cout << "number of cycles = " << nCycles << " remainder = " << remainder << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  for (int iCycle=0; iCycle<=nCycles; ++iCycle) {
    std::cout << "Cycle = " << iCycle << std::endl;
    TCanvas * canv = MakeCanvas("canv","",1000,700);
    TH1D * hist = new TH1D("hist","",nPeriod,0,double(nPeriod));
    TH1D * histPull = new TH1D("histPull","",nPeriod,0,double(nPeriod)); 
    TH1D * histConst = new TH1D("histConst","",nPeriod,0,double(nPeriod)); 
    double xmin = 1e+3;
    double xmax = -1e+3;
    int iPmax = nPeriod;
    std::vector<double> centralPar; centralPar.clear();
    std::vector<double> errorPar; errorPar.clear();
    std::vector<TString> namePar; namePar.clear();
    if (iCycle==nCycles) iPmax = remainder;
    //    std::cout << "Here we are" << std::endl;
    for (int iP=0; iP<iPmax; ++iP) {
      int iPar = nPeriod*iCycle + iP;
      //      std::cout << "Beginning...... icycle = " << iCycle << "  iperiod = " << iP << "   index = " << iPar << std::endl;
      RooRealVar* var = (RooRealVar*)list.at(iPar);
      //      std::cout << "nuisance : " << var << std::endl; 
      if (var==NULL) continue;
      TString name = var->GetName();
      if (name=="muV"||name=="muggH"||name=="alpha"||name=="mutautau") continue;
      double central = var->getVal();
      double error = var->getError();
      std::cout << name << " = " << central << " +/- " << error << std::endl; 
      double lower = central - error;
      double upper = central + error;
      centralPar.push_back(central);
      errorPar.push_back(error);
      namePar.push_back(name);
      if (lower<xmin) xmin = lower;
      if (upper>xmax) xmax = upper;
      //      std::cout << "End...... icycle = " << iCycle << "  iperiod = " << iP << "   index = " << iPar << std::endl;
    }
    for (unsigned int iP=0; iP<centralPar.size(); ++iP) {
      //      std::cout << "iP = " << iP << std::endl;
      hist->SetBinContent(iP+1,centralPar.at(iP));
      hist->SetBinError(iP+1,errorPar.at(iP));
      hist->GetXaxis()->SetBinLabel(iP+1,namePar.at(iP));
      bool strangePull = TMath::Abs(centralPar.at(iP))/TMath::Abs(errorPar.at(iP))>1.0;
      bool strangeConst = TMath::Abs(errorPar.at(iP))<0.5;
      if (strangePull) {
	histPull->SetBinContent(iP+1,centralPar.at(iP));
	histPull->SetBinError(iP+1,errorPar.at(iP));
      }
      if (strangeConst) {
	histConst->SetBinContent(iP+1,centralPar.at(iP));
	histConst->SetBinError(iP+1,errorPar.at(iP));
      }
    }    

    float range = 1.2*TMath::Max(TMath::Abs(xmin),TMath::Abs(xmax));
    InitData(hist);

    hist->SetMarkerSize(1.1);
    hist->GetXaxis()->SetLabelSize(16);
    hist->GetYaxis()->SetRangeUser(-range,range);
    hist->LabelsOption("v");

    InitData(histPull);
    histPull->SetMarkerSize(1.1);
    histPull->GetXaxis()->SetLabelSize(16);
    histPull->GetYaxis()->SetRangeUser(-range,range);
    histPull->SetLineColor(2);
    histPull->SetMarkerColor(2);
    //    histPull->LabelsOption("v");

    InitData(histConst);
    histConst->SetMarkerSize(1.1);
    histConst->SetLineColor(4);
    histConst->SetMarkerColor(4);
    histConst->GetXaxis()->SetLabelSize(16);
    histConst->GetYaxis()->SetRangeUser(-range,range);
    //    histConst->LabelsOption("v");

    hist->Draw();
    histPull->Draw("e1same");
    histConst->Draw("e1same");
    TLine * line = new TLine(0.,0.,float(nPeriod),0.);
    line->SetLineColor(4);
    line->Draw();
    hist->Draw("e1same");
    histPull->Draw("e1same");
    histConst->Draw("e1same");

    canv->Update();
    canv->Print(filename+"/nuisances_"+index.at(iCycle)+".png");
    delete line;
    delete hist;
    delete canv;
    std::cout << "----------------------------------------------------------" << std::endl;
  }
  


  //  RooRealVar*

}
