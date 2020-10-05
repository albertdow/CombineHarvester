#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include <map>
#include <vector>
//
void ComputeYieldsFromDatacards(TString fileName = "output/etau/htt_bkg_et/common/htt_input",
				TString shapesDir = "htt_et_2018_2_13TeV",
				bool logY = false) {


  TFile * mlfit = new TFile(fileName+".root");
  if (mlfit->IsZombie()) {
    std::cout << "File " << fileName << ".root does not exists" << std::endl;
    return;
  }

  TH1F * Data_     = (TH1F*)mlfit->Get(shapesDir+"/data_obs");
  TH1F * ZTT_      = (TH1F*)mlfit->Get(shapesDir+"/EmbedZTT");
  TH1F * ZLL_      = (TH1F*)mlfit->Get(shapesDir+"/ZL");
  TH1F * Fakes_    = (TH1F*)mlfit->Get(shapesDir+"/jetFakes");
  TH1F * TT_       = (TH1F*)mlfit->Get(shapesDir+"/TTT");
  TH1F * VV_       = (TH1F*)mlfit->Get(shapesDir+"/VVT");
  if (ZTT_==NULL||ZLL_==NULL||Fakes_==NULL||TT_==NULL||VV_==NULL) 
    std::cout << "directory  " << shapesDir << "  is absent in the file" << std::endl;

  int nBins =  ZTT_->GetNbinsX();

  std::cout << "bin data ztt zll fakes tt vv" << std::endl;
  for (int iB=1; iB<=nBins; ++iB) {
    float data = Data_->GetBinContent(iB);
    //    float dataE = TMath::Sqrt(y);
    float ztt = ZTT_->GetBinContent(iB);
    float zll = ZLL_->GetBinContent(iB);
    float fakes = Fakes_->GetBinContent(iB);
    float tt = TT_->GetBinContent(iB);
    float vv = VV_->GetBinContent(iB);
    std::cout << iB << " " << data << " " << ztt << " " << zll << " " << fakes << " " << tt << " " << vv << std::endl;
  }


}
