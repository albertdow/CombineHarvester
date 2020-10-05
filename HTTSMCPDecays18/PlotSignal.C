#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include <map>
#include <vector>
//
void PlotSignal(TString workspace = "etau_htt_et_murho_2018_13TeV",
		TString WS = "htt_et_2018_3_13TeV",
		bool postFit = false,
		bool blind = true,
		bool logY = true) {

  float frameScale = 0.0;
  float scaleYupper = 50.;

  TString Header = "e+#pi";
  if (WS.Contains("_3_13TeV"))
    Header = "e+#rho";
  if (WS.Contains("_4_13TeV"))
    Header = "e+#pi";
  if (WS.Contains("_5_13TeV"))
    Header = "e+a_{1}(3-pr)";

  if (postFit)
    Header += ", postfit";
  else
    Header += ", prefit";

  SetStyle();
  //  gStyle->SetErrorX(0);

  TString xtitle("");
  TString ytitle("Events");

  TString shapesDir("shapes_prefit");
  if (postFit) {
    shapesDir = "shapes_fit_s";
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
  TH1F * ggHsm_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/ggH_sm_htt");
  TH1F * qqHsm_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/qqH_sm_htt");
  TH1F * ggHps_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/ggH_ps_htt");
  TH1F * qqHps_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/qqH_ps_htt");
  TH1F * TOTAL_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/total"); 

  if (ZTT_==NULL||ZLL_==NULL||Fakes_==NULL||TT_==NULL||VV_==NULL||ggHsm_==NULL||qqHsm_==NULL||ggHps_==NULL||qqHps_==NULL) 
    std::cout << "directory  " << shapesDir << "/" << WS << "  is absent in the file" << std::endl;

  ggHsm_->Add(ggHsm_,qqHsm_);
  ggHps_->Add(ggHps_,qqHps_);

  int nBins =  TOTAL_->GetNbinsX();
  
  std::cout << "nBins = " << nBins << std::endl;

  float scale = 1.0;
  if (WS=="htt_et_2017_1_13TeV") scale = 0.93;

  TH1F * ZTT   = new TH1F("ZTT","",nBins,0,nBins);
  TH1F * ZLL   = new TH1F("ZLL","",nBins,0,nBins);
  TH1F * Fakes = new TH1F("Fakes","",nBins,0,nBins);
  TH1F * TT    = new TH1F("TT","",nBins,0,nBins);
  TH1F * VV    = new TH1F("VV","",nBins,0,nBins);
  TH1F * Hsm   = new TH1F("ggH","",nBins,0,nBins);
  TH1F * Hps   = new TH1F("qqH","",nBins,0,nBins);
  TH1F * TOTAL = new TH1F("TOTAL","",nBins,0,nBins);
  for (int iB=1; iB<=nBins; ++iB) {
    ZTT->SetBinContent(iB,ZTT_->GetBinContent(iB));
    ZLL->SetBinContent(iB,ZLL_->GetBinContent(iB));
    Fakes->SetBinContent(iB,Fakes_->GetBinContent(iB));
    TT->SetBinContent(iB,TT_->GetBinContent(iB));
    VV->SetBinContent(iB,VV_->GetBinContent(iB));
    Hsm->SetBinContent(iB,ggHsm_->GetBinContent(iB));
    Hps->SetBinContent(iB,ggHps_->GetBinContent(iB));
          
    TOTAL->SetBinContent(iB,scale*TOTAL_->GetBinContent(iB));

    ZTT->SetBinError(iB,ZTT_->GetBinError(iB));
    ZLL->SetBinError(iB,ZLL_->GetBinError(iB));
    Fakes->SetBinError(iB,Fakes_->GetBinError(iB));
    TT->SetBinError(iB,TT_->GetBinError(iB));
    VV->SetBinError(iB,VV_->GetBinError(iB));
    TOTAL->SetBinError(iB,TOTAL_->GetBinError(iB));
  }

  TH1F * histData = (TH1F*)TOTAL->Clone();
  histData->SetTitle("");
  for (int iB=0; iB<nBins; ++iB) {
    float y = histGraph->GetY()[iB];
    float e = TMath::Sqrt(y);
    histData->SetBinContent(iB+1,y);
    histData->SetBinError(iB+1,e);
  }
  std::cout << std::endl;
  std::cout << "histData  : " << histData << std::endl;
  std::cout << "histZTT   : " << ZTT << std::endl;
  std::cout << "histFakes : " << Fakes << std::endl;
  std::cout << "histZLL   : " << ZLL << std::endl;
  std::cout << "histTT    : " << TT << std::endl;
  std::cout << "histVV    : " << VV << std::endl;
  std::cout << std::endl;
  float total  = ZTT->GetSum()+Fakes->GetSum()+ZLL->GetSum()+VV->GetSum()+TT->GetSum();


  std::cout << "ZTT   : " << ZTT->GetSum() << std::endl;
  std::cout << "Fakes : " << Fakes->GetSum() << std::endl;
  std::cout << "ZLL   : " << ZLL->GetSum() << std::endl;
  std::cout << "VV    : " << VV->GetSum() << std::endl;
  std::cout << "TT    : " << TT->GetSum() << std::endl;
  std::cout << "Sum   : " << total << std::endl;
  std::cout << "Bkgd  : " << TOTAL->GetSum() << std::endl;
  std::cout << "Data  : " << histData->GetSumOfWeights() << std::endl;
  std::cout << "Hsm   : " << Hsm->GetSumOfWeights() << std::endl;
  std::cout << "Hps   : " << Hps->GetSumOfWeights() << std::endl;

  TH1F * bkgdErr = (TH1F*)TOTAL->Clone("bkgdErr");
  bkgdErr->SetFillStyle(3013);
  bkgdErr->SetFillColor(1);
  bkgdErr->SetMarkerStyle(21);
  bkgdErr->SetMarkerSize(0);  
  
  VV->Add(VV,TT);
  ZLL->Add(ZLL,VV);
  Fakes->Add(Fakes,ZLL);
  ZTT->Add(ZTT,Fakes);

  for (int iB=1; iB<=nBins; ++iB) {  
    ZTT->SetBinError(iB,0.);
    Fakes->SetBinError(iB,0.);
    ZLL->SetBinError(iB,0.);
    VV->SetBinError(iB,0.);
    TT->SetBinError(iB,0.);
    Hps->SetBinError(iB,0.);
    Hsm->SetBinError(iB,0.);
  }

  InitData(histData);
  InitHist(ZTT,"","",TColor::GetColor("#FFCC66"),1001);
  InitHist(Fakes,"","",TColor::GetColor(192,232,100),1001);
  InitHist(ZLL,"","",TColor::GetColor("#4496C8"),1001);
  InitHist(VV,"","",TColor::GetColor("#DE5A6A"),1001);
  InitHist(TT,"","",TColor::GetColor("#9999CC"),1001);

  InitSignal(Hsm);
  InitSignal(Hps);
  Hsm->SetLineColor(2);
  Hsm->SetLineWidth(2);
  Hsm->SetLineStyle(1);
  Hps->SetLineColor(4);
  Hps->SetLineWidth(2);
  Hps->SetLineStyle(1);

  histData->GetXaxis()->SetTitle(xtitle);
  histData->GetYaxis()->SetTitle(ytitle);
  histData->GetYaxis()->SetLabelSize(0.03);
  histData->GetYaxis()->SetTitleOffset(1.35);
  histData->GetYaxis()->SetTitleSize(0.07);

  histData->SetMarkerSize(1.3);
  histData->GetXaxis()->SetLabelSize(0.);
  histData->GetYaxis()->SetLabelFont(42);
  histData->GetYaxis()->SetLabelSize(0.06);

  ZTT->GetXaxis()->SetTitle(xtitle);
  ZTT->GetYaxis()->SetTitle(ytitle);
  ZTT->GetYaxis()->SetLabelSize(0.03);
  ZTT->GetYaxis()->SetTitleOffset(1.35);
  ZTT->GetYaxis()->SetTitleSize(0.07);

  ZTT->SetMarkerSize(1.3);
  ZTT->GetXaxis()->SetLabelSize(0.);
  ZTT->GetYaxis()->SetLabelFont(42);
  ZTT->GetYaxis()->SetLabelSize(0.06);

  float frameYmin = 0;
  float frameYmax = scaleYupper*ZTT->GetMaximum();
  if (logY) {
    frameYmin = 0.5;
    frameYmax = scaleYupper*ZTT->GetMaximum();
  }
  histData->GetYaxis()->SetRangeUser(frameYmin,frameYmax);
  ZTT->GetYaxis()->SetRangeUser(frameYmin,frameYmax);

  TCanvas * canv1 = MakeCanvas("canv1", "", 600, 700);
  TPad * upper = new TPad("upper", "pad",0,0.31,1,1);
  upper->Draw();
  upper->cd();
  upper->SetFillColor(0);
  upper->SetBorderMode(0);
  upper->SetBorderSize(10);
  upper->SetTickx(1);
  upper->SetTicky(1);
  upper->SetLeftMargin(0.17);
  upper->SetRightMargin(0.05);
  upper->SetBottomMargin(0.02);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);
  upper->SetFrameFillStyle(0);
  upper->SetFrameLineStyle(0);
  upper->SetFrameLineWidth(2);
  upper->SetFrameBorderMode(0);
  upper->SetFrameBorderSize(10);

  if (blind) {
    ZTT->Draw("h");
  }
  else {
    histData->Draw("e1");
    ZTT->Draw("sameh");
  }
  Fakes->Draw("sameh");
  ZLL->Draw("sameh");
  //  VV->Draw("sameh");
  //  TT->Draw("sameh");
  bkgdErr->Draw("e2same");
  Hsm->Draw("hsame");
  Hps->Draw("hsame");
  if (!blind)
    histData->Draw("e1same");
  float chi2 = 0;
  for (int iB=1; iB<=nBins; ++iB) {
    float xData = histData->GetBinContent(iB);
    float xMC   = bkgdErr->GetBinContent(iB);
    float eData = histData->GetBinError(iB);
    float eMC   = bkgdErr->GetBinError(iB);
    if (xMC>1e-1) {
      float diff2 = (xData-xMC)*(xData-xMC);
      chi2 += diff2/(eData*eData+eMC*eMC);
    }
  }
  double prob = TMath::Prob(chi2,double(nBins-1));
  std::cout << std::endl;
  std::cout << "Chi2 = " << chi2 << "   p-value = " << prob << std::endl;
  std::cout << std::endl;

  TLegend * legTitle  = new TLegend(0.20,0.75,0.45,0.95);
  TLegend * leg  = new TLegend(0.20,0.68,0.45,0.88);
  TLegend * leg1 = new TLegend(0.47,0.68,0.75,0.88);
  SetLegendStyle(legTitle);
  SetLegendStyle(leg);
  SetLegendStyle(leg1);
  legTitle->SetTextSize(0.055);
  legTitle->SetHeader(Header);
  leg->SetTextSize(0.045);
  leg1->SetTextSize(0.045);
  leg->SetHeader("");
  leg1->SetHeader("");
  leg->AddEntry(histData,"Observed","lp");
  leg->AddEntry(ZTT,"Z#rightarrow#tau#tau","f");
  leg->AddEntry(Fakes,"jet#rightarrow#tau mis-id","f");
  leg1->AddEntry(ZLL,"rest","f");
  leg1->AddEntry(Hsm,"H(0^{+})","l");
  leg1->AddEntry(Hps,"H(0^{-})","l");
  legTitle->Draw();
  leg->Draw();
  leg1->Draw();
  writeExtraText = true;
  extraText = "Preliminary";
  CMS_lumi(upper,4,33); 
  //  plotchannel("#tau#nu");

  if (logY) upper->SetLogy(true);
    
  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  TH1F * ratioH = (TH1F*)histData->Clone("ratioH");
  TH1F * ratioErrH = (TH1F*)bkgdErr->Clone("ratioErrH");
  TH1F * ratioSMH = (TH1F*)Hsm->Clone("ratioSMH");
  TH1F * ratioPSH = (TH1F*)Hps->Clone("ratioPSH");
  ratioSMH->Add(ratioSMH,bkgdErr);
  ratioPSH->Add(ratioPSH,bkgdErr);

  ratioH->SetMarkerColor(1);
  ratioH->SetMarkerStyle(20);
  ratioH->SetMarkerSize(1.2);
  ratioH->SetLineColor(1);

  ratioH->GetYaxis()->SetNdivisions(205);
  ratioH->GetXaxis()->SetTitle(xtitle);
  ratioH->GetXaxis()->SetLabelFont(42);
  ratioH->GetXaxis()->SetLabelOffset(0.04);
  ratioH->GetXaxis()->SetLabelSize(0.14);
  ratioH->GetXaxis()->SetTickLength(0.07);
  ratioH->GetXaxis()->SetTitleOffset(1.2);
  ratioH->GetXaxis()->SetTitleSize(0.14);

  ratioH->GetYaxis()->SetTitle("Obs./Exp.");
  ratioH->GetYaxis()->SetLabelFont(42);
  ratioH->GetYaxis()->SetLabelSize(0.13);
  ratioH->GetYaxis()->SetTickLength(0.04);
  ratioH->GetYaxis()->SetLabelOffset(0.01);
  ratioH->GetYaxis()->SetTitleOffset(0.60);
  ratioH->GetYaxis()->SetTitleSize(0.15);

  ratioErrH->GetYaxis()->SetNdivisions(205);
  ratioErrH->GetXaxis()->SetTitle(xtitle);
  ratioErrH->GetXaxis()->SetLabelFont(42);
  ratioErrH->GetXaxis()->SetLabelOffset(0.04);
  ratioErrH->GetXaxis()->SetLabelSize(0.14);
  ratioErrH->GetXaxis()->SetTickLength(0.07);
  ratioErrH->GetXaxis()->SetTitleOffset(1.2);
  ratioErrH->GetXaxis()->SetTitleSize(0.14);

  ratioErrH->GetYaxis()->SetTitle("Obs./Exp.");
  ratioErrH->GetYaxis()->SetLabelFont(42);
  ratioErrH->GetYaxis()->SetLabelSize(0.13);
  ratioErrH->GetYaxis()->SetTickLength(0.04);
  ratioErrH->GetYaxis()->SetLabelOffset(0.01);
  ratioErrH->GetYaxis()->SetTitleOffset(0.60);
  ratioErrH->GetYaxis()->SetTitleSize(0.15);

  float yRatioMin = 0.7001;
  float yRatioMax = 1.2999;

  ratioH->GetYaxis()->SetRangeUser(yRatioMin,yRatioMax);
  ratioErrH->GetYaxis()->SetRangeUser(yRatioMin,yRatioMax);

  for (int iB=1; iB<=nBins; ++iB) {
    float x1 = histData->GetBinContent(iB);
    float x2 = bkgdErr->GetBinContent(iB);
    float xSM = ratioSMH->GetBinContent(iB);
    float xPS = ratioPSH->GetBinContent(iB);
    ratioErrH->SetBinContent(iB,1.0);
    ratioErrH->SetBinError(iB,0.0);
    float xBkg = bkgdErr->GetBinContent(iB);
    float errBkg = bkgdErr->GetBinError(iB);
    if (xBkg>0) {
      float relErr = errBkg/xBkg;
      ratioErrH->SetBinError(iB,relErr);
      float ratio = xSM/xBkg;
      ratioSMH->SetBinContent(iB,ratio);
      ratio = xPS/xBkg;
      ratioPSH->SetBinContent(iB,ratio);

    }
    if (x1>0&&x2>0) {
      float e1 = histData->GetBinError(iB);
      float ratio = x1/x2;
      float eratio = e1/x2;
      ratioH->SetBinContent(iB,ratio);
      ratioH->SetBinError(iB,eratio);
    }
    else {
      ratioH->SetBinContent(iB,1000);
    }
  }

  // ------------>Primitives in pad: lower
  TPad * lower = new TPad("lower", "pad",0,0,1,0.30);
  lower->Draw();
  lower->cd();
  lower->SetFillColor(0);
  lower->SetBorderMode(0);
  lower->SetBorderSize(10);
  lower->SetGridy();
  lower->SetTickx(1);
  lower->SetTicky(1);
  lower->SetLeftMargin(0.17);
  lower->SetRightMargin(0.05);
  lower->SetTopMargin(0.026);
  lower->SetBottomMargin(0.35);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);
  lower->SetFrameFillStyle(0);
  lower->SetFrameLineStyle(0);
  lower->SetFrameLineWidth(2);
  lower->SetFrameBorderMode(0);
  lower->SetFrameBorderSize(10);

  if (blind) {
    ratioErrH->Draw("e2");
  }
  else {
    ratioH->Draw("e1");
    ratioErrH->Draw("e2same");
  }
  ratioSMH->Draw("hsame");
  ratioPSH->Draw("hsame");

  lower->Modified();
  lower->RedrawAxis();
  canv1->cd();
  canv1->Modified();
  canv1->cd();
  canv1->SetSelected(canv1);
  canv1->Update();
  if (postFit) {
    canv1->Print("figures_stat/"+WS+"_postFit.png");
    //    canv1->Print("figures_stat/"+WS+"_postFit.pdf","pdf");
  }
  else {
    canv1->Print("figures_stat/"+WS+"_preFit.png");
    //    canv1->Print("figures_stat/"+WS+"_preFit.pdf","pdf");
  }

}
