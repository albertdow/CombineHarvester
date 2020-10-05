#include "HttStylesNew.cc"
#include "CMS_lumi.C"
#include <map>
#include <vector>
void PlotFit_ZTT(TFile * mlfit  = NULL,
		 TString WS = "htt_mt_2018_50_13TeV",
		 bool postFit = false,
		 bool logY = false,
		 int pageType = 0) {

  float frameScale = 0.0;
  float scaleYupper = 300.;


  std::map<TString, TString> legHeader =
    { 
      {"htt_mt_2018_30_13TeV","#mu+#rho,  #alpha>#pi/4"},
      {"htt_mt_2018_3_13TeV" ,"#mu+#rho,  #alpha<#pi/4"},
      {"htt_mt_2018_40_13TeV","#mu+#pi,  #alpha>#pi/4"},
      {"htt_mt_2018_4_13TeV" ,"#mu+#pi,  #alpha<#pi/4"},
      {"htt_mt_2018_50_13TeV","#mu+a_{1}^{3pr},  #alpha>#pi/4"},
      {"htt_mt_2018_5_13TeV" ,"#mu+a_{1}^{3pr},  #alpha<#pi/4"},
      {"htt_mt_2018_60_13TeV","#mu+a_{1}^{1pr},  #alpha>#pi/4"},
      {"htt_mt_2018_6_13TeV" ,"#mu+a_{1}^{1pr},  #alpha<#pi/4"}
    };

  TString Header = legHeader[WS];
  if (postfit)
    Header += ",  postfit";
  else
    Header += ",  prefit";

  SetStyle();
  //  gStyle->SetErrorX(0);

  TString xtitle = "#phi_{CP}";
  
  TString shapesDir("shapes_prefit");
  if (postFit) {
    shapesDir = "shapes_fit_s";
  }
  if (WS.Contains("2016"))
    lumi_13TeV = "2016, 35.9 fb^{-1}";
  if (WS.Contains("2017")) 
    lumi_13TeV = "2017, 41.0 fb^{-1}";


  if (mlfit==NULL) {
    std::cout << "File " << mlfitFileName << " does not exists" << std::endl;
    return;
  }

  TGraphAsymmErrors * histGraph = (TGraphAsymmErrors*)mlfit->Get("shapes_prefit/"+WS+"/data");
  TH1F * ZTT_      = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/ZTT");
  TH1F * ZLL_      = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/ZL");
  TH1F * Fakes_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/jetFakes");
  TH1F * TT_       = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/TTT");
  TH1F * VV_       = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/VVT");
  TH1F * TOTAL_    = (TH1F*)mlfit->Get(shapesDir+"/"+WS+"/total"); 
  if (ZTT_==NULL||ZLL_==NULL||Fakes_==NULL||TT_==NULL||VV_==NULL) 
    std::cout << "directory  " << shapesDir << "/" << WS << "  is absent in the file" << std::endl;

  int nBins =  TOTAL_->GetNbinsX();
  float width = 2.0*TMath::Pi()/float(nBins);
  char width_char[5];
  sprintf(width_char,"%5.3f",width);
  TString width_string(width_char);
  TString ytitle = "Events/"+width_string;
  

  TH1F * ZTT = new TH1F("ZTT","",nBins,0.,2.0*TMath::Pi());
  TH1F * ZLL = new TH1F("ZLL","",nBins,0.,2.0*TMath::Pi());
  TH1F * Fakes = new TH1F("Fakes","",nBins,0.,2.0*TMath::Pi());
  TH1F * TT = new TH1F("TT","",nBins,0.,2.0*TMath::Pi());
  TH1F * VV = new TH1F("VV","",nBins,0.,2.0*TMath::Pi());
  TH1F * TOTAL = new TH1F("TOTAL","",nBins,0.,2.0*TMath::Pi());
  for (int iB=1; iB<=nBins; ++iB) {
    ZTT->SetBinContent(iB,ZTT_->GetBinContent(iB));
    ZLL->SetBinContent(iB,ZLL_->GetBinContent(iB));
    Fakes->SetBinContent(iB,Fakes_->GetBinContent(iB));
    TT->SetBinContent(iB,TT_->GetBinContent(iB));
    VV->SetBinContent(iB,VV_->GetBinContent(iB));
    TOTAL->SetBinContent(iB,TOTAL_->GetBinContent(iB));
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
  }

  InitData(histData);
  InitHist(ZTT,"","",TColor::GetColor("#FFCC66"),1001);
  InitHist(Fakes,"","",TColor::GetColor(192,232,100),1001);
  InitHist(ZLL,"","",TColor::GetColor("#4496C8"),1001);
  InitHist(VV,"","",TColor::GetColor("#DE5A6A"),1001);
  InitHist(TT,"","",TColor::GetColor("#9999CC"),1001);

  histData->GetXaxis()->SetTitle(xtitle);
  histData->GetYaxis()->SetTitle(ytitle);
  //  histData->GetYaxis()->SetTitleOffset(1.3);
  //  histData->GetYaxis()->SetTitleSize(0.06);

  histData->SetMarkerSize(1.3);
  histData->GetXaxis()->SetLabelSize(0.);
  histData->GetYaxis()->SetLabelFont(42);
  histData->GetYaxis()->SetLabelSize(0.06);
  //  histData->GetYaxis()->SetLabelSize(0.06);

  float frameYmin = 0;
  float frameYmax = 1.48*histData->GetMaximum();
  if (logY) {
    frameYmin = 1.0;
    frameYmax = scaleYupper*histData->GetMaximum();
  }
  histData->GetYaxis()->SetRangeUser(frameYmin,frameYmax);

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

  histData->Draw("e1");
  ZTT->Draw("sameh");
  Fakes->Draw("sameh");
  ZLL->Draw("sameh");
  //  VV->Draw("sameh");
  //  TT->Draw("sameh");
  bkgdErr->Draw("e2same");
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

  TLegend * legTitle  = new TLegend(0.20,0.79,0.45,0.99);
  TLegend * leg  = new TLegend(0.20,0.72,0.45,0.92);
  TLegend * leg1 = new TLegend(0.47,0.72,0.75,0.92);
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
  leg1->AddEntry(Fakes,"jet#rightarrow#tau mis-id","f");
  leg1->AddEntry(ZLL,"rest","f");
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
  ratioH->SetMarkerColor(1);
  ratioH->SetMarkerStyle(20);
  ratioH->SetMarkerSize(1.2);
  ratioH->SetLineColor(1);
  ratioH->GetYaxis()->SetNdivisions(205);

  ratioH->GetXaxis()->SetLabelFont(42);
  ratioH->GetXaxis()->SetLabelOffset(0.04);
  ratioH->GetXaxis()->SetLabelSize(0.14);
  ratioH->GetXaxis()->SetTickLength(0.07);
  ratioH->GetXaxis()->SetTitleOffset(3.5);

  ratioH->GetYaxis()->SetLabelFont(42);
  ratioH->GetYaxis()->SetLabelSize(0.13);
  ratioH->GetYaxis()->SetTickLength(0.04);
  ratioH->GetYaxis()->SetLabelOffset(0.01);
  ratioH->GetYaxis()->SetTitleOffset(2.0);

  ratioH->GetYaxis()->SetRangeUser(0.85,1.15);

  ratioH->GetYaxis()->SetTitle("Obs./Exp.");
  ratioH->GetXaxis()->SetTitle(xtitle);

  for (int iB=1; iB<=nBins; ++iB) {
    float x1 = histData->GetBinContent(iB);
    float x2 = bkgdErr->GetBinContent(iB);
    ratioErrH->SetBinContent(iB,1.0);
    ratioErrH->SetBinError(iB,0.0);
    float xBkg = bkgdErr->GetBinContent(iB);
    float errBkg = bkgdErr->GetBinError(iB);
    if (xBkg>0) {
      float relErr = errBkg/xBkg;
      ratioErrH->SetBinError(iB,relErr);

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

  ratioH->Draw("e1");
  ratioErrH->Draw("e2same");

  lower->Modified();
  lower->RedrawAxis();
  canv1->cd();
  canv1->Modified();
  canv1->cd();
  canv1->SetSelected(canv1);
  canv1->Update();
  if (pageType<0)
    canv1->Print("ZTT_validation_plots.pdf(","pdf");
  else if (pageType>0)
    canv1->Print("ZTT_validation_plots.pdf)","pdf");
  else
    canv1->Print("ZTT_validation_plots.pdf","pdf");
  
}
