#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include <map>
#include <vector>
//
void ComputeYields(TString workspace = "etau_htt_bkg_et",
		   TString WS = "htt_et_2018_2_13TeV",
		   bool postFit = false,
		   bool logY = false) {

  float frameScale = 0.0;
  float scaleYupper = 1.4;
  if (WS.Contains("_2_13TeV"))
    scaleYupper = 1.6;
  if (logY)
    scaleYupper = 5000.;

  std::map<TString, TString> legHeader =
    { 
      {"htt_et_2016_1_13TeV","ztt"},
      {"htt_et_2016_2_13TeV" ,"jetFakes"},
      {"htt_et_2017_1_13TeV","ztt"},
      {"htt_et_2017_2_13TeV" ,"jetFakes"},
      {"htt_et_2018_1_13TeV","ztt"},
      {"htt_et_2018_2_13TeV" ,"jetFakes"},
    };

  TString Header = legHeader[WS];
  if (postFit)
    Header += ",  postfit";
  else
    Header += ",  prefit";

  SetStyle();
  //  gStyle->SetErrorX(0);

  TString xtitle("DNN score");

  TString shapesDir("shapes_prefit");
  if (postFit) {
    shapesDir = "shapes_fit_b";
  }
  if (WS.Contains("2016"))
    lumi_13TeV = "2016, 35.9 fb^{-1}";
  if (WS.Contains("2017")) 
    lumi_13TeV = "2017, 41.0 fb^{-1}";


  TFile * mlfit = new TFile("fitDiagnostics_"+workspace+".root");
  if (mlfit->IsZombie()) {
    std::cout << "File " << workspace << " does not exists" << std::endl;
    return;
  }

  TGraphAsymmErrors * histGraph = (TGraphAsymmErrors*)mlfit->Get("shapes_prefit/"+WS+"/data");
  TH1F * ZTT_      = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/EmbedZTT");
  TH1F * ZLL_      = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/ZL");
  TH1F * Fakes_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/jetFakes");
  TH1F * TT_       = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/TTT");
  TH1F * VV_       = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/VVT");
  TH1F * TOTAL_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/total"); 
  if (ZTT_==NULL||ZLL_==NULL||Fakes_==NULL||TT_==NULL||VV_==NULL) 
    std::cout << "directory  " << shapesDir << "/" << WS << "  is absent in the file" << std::endl;

  int nBins =  ZTT_->GetNbinsX();

  std::cout << "bin data ztt zll fakes tt vv" << std::endl;
  for (int iB=1; iB<=nBins; ++iB) {
    float data = histGraph->GetY()[iB-1];
    //    float dataE = TMath::Sqrt(y);
    float ztt = ZTT_->GetBinContent(iB);
    float zll = ZLL_->GetBinContent(iB);
    float fakes = Fakes_->GetBinContent(iB);
    float tt = TT_->GetBinContent(iB);
    float vv = VV_->GetBinContent(iB);
    std::cout << iB << " " << data << " " << ztt << " " << zll << " " << fakes << " " << tt << " " << vv << std::endl;
  }


}
