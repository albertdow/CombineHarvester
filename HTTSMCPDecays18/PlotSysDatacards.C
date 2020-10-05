#include "HttStylesNew.cc"
// category : htt_et_2016_1_13TeV
//            htt_et_2016_2_13TeV
//            htt_et_2017_1_13TeV
//            htt_et_2017_2_13TeV
//            htt_et_2018_1_13TeV
//            htt_et_2018_2_13TeV
// histName : EmbedZTT, ZL, jetFakes, VVT, TTT, ggH_sm_htt125
// sysName  : CMS_scale_t_1prong_2016,
//          : CMS_scale_t_3prong_2016,
//          : CMS_scale_t_1prong1pizero_2016
//          : CMS_scale_embedded_t_1prong_2016
//          : CMS_scale_embedded_t_3prong_2016
//          : CMS_scale_embedded_t_1prong1pizero_2016
//          : CMS_efake_et_MVADM0_2016
//          : CMS_efake_et_MVADM1_2016
//          : CMS_efake_et_MVADM2_2016
//          : CMS_efake_et_MVADM10_2016
//          : CMS_efake_et_MVADM0_2017
//          : CMS_efake_et_MVADM1_2017
//          : CMS_efake_et_MVADM2_2017
//          : CMS_efake_et_MVADM10_2017
//          : CMS_efake_et_MVADM0_2018
//          : CMS_efake_et_MVADM1_2018
//          : CMS_efake_et_MVADM2_2018
//          : CMS_efake_et_MVADM10_2018

void PlotSysDatacards(TString fileName = "output/etau/htt_bkg_et/common/htt_input.root",
		      TString histName = "ZL",
		      TString sysName  = "CMS_efake_et_MVADM0_2018",
		      TString category = "htt_et_2018_2_13TeV",
		      float rangeRatio = 0.02,
		      float upRange = -100,
		      TString pageType = "") {

  TString header  = category;
  TString header1 = histName;
  TString header2 = sysName;
  TString SysLeg = sysName;
  TString ytitle("Events");
  TString xtitle("DNN score"); 

  SetStyle();
  gStyle->SetErrorX(0);
  TFile * file = new TFile(fileName);
  TH1D * histNominal = (TH1D*)file->Get(category+"/"+histName);
  TH1D * histUp = (TH1D*)file->Get(category+"/"+histName+"_"+sysName+"Up");
  TH1D * histDown = (TH1D*)file->Get(category+"/"+histName+"_"+sysName+"Down");
  std::cout << histNominal << " " <<  histUp << " " << histDown << std::endl;

  int nBins = histNominal->GetNbinsX(); 
  float xmax = histNominal->GetBinLowEdge(nBins+1)-0.01;

  InitData(histNominal);
  for (int iB=1; iB<=nBins; ++iB) {
    double x = histNominal->GetBinContent(iB);
    double ex = TMath::Sqrt(x);
    histNominal->SetBinError(iB,ex);
  }

  histNominal->GetXaxis()->SetTitleSize(0.0);
  histNominal->GetXaxis()->SetTitleOffset(1.2);

  histNominal->GetYaxis()->SetTitleSize(0.07);
  histNominal->GetYaxis()->SetTitleOffset(1.0);
  histNominal->GetYaxis()->SetLabelSize(0.045);

  histNominal->GetYaxis()->SetRangeUser(0.01,1.2*histUp->GetMaximum());
  histNominal->SetLineColor(1);
  histUp->SetLineColor(2);
  histDown->SetLineColor(4);
  histDown->SetLineStyle(3);
  histNominal->SetMarkerColor(1);
  histUp->SetMarkerColor(2);
  histDown->SetMarkerColor(4);
  histNominal->SetMarkerSize(1.3);
  histNominal->GetYaxis()->SetTitle(ytitle);
  histNominal->GetXaxis()->SetTitle(xtitle);
  histUp->GetYaxis()->SetTitle(ytitle);
  histUp->GetXaxis()->SetTitle(xtitle);
  histDown->GetYaxis()->SetTitle(ytitle);
  histDown->GetXaxis()->SetTitle(xtitle);
  histUp->SetLineWidth(2);
  histDown->SetLineWidth(2);
  TH1D * ratioUp = (TH1D*)histUp->Clone("ratioUp");
  TH1D * ratioDown = (TH1D*)histDown->Clone("ratioDown");
  TH1D * ratioCentral = (TH1D*)histNominal->Clone("ratioCentral");
  //  ratioCentral->SetFillStyle(3013);
  //  ratioCentral->SetFillColor(1);
  //  ratioCentral->SetMarkerStyle(21);
  //  ratioCentral->SetMarkerSize(0);


  for (int iB=1; iB<=nBins; ++iB) {
    histUp->SetBinError(iB,0); 
    histDown->SetBinError(iB,0); 
    float xUp = histUp->GetBinContent(iB);
    float xDown = histDown->GetBinContent(iB);
    float xCentral = histNominal->GetBinContent(iB);
    float xratioUp = 1;
    float xratioDown = 1;
    if (xCentral>0) {
      xratioUp   = xUp/xCentral;
      xratioDown = xDown/xCentral;
    }
    ratioUp->SetBinContent(iB,xratioUp);
    ratioDown->SetBinContent(iB,xratioDown);
    ratioUp->SetBinError(iB,0);
    ratioDown->SetBinError(iB,0);
    ratioCentral->SetBinContent(iB,1);
    ratioCentral->SetBinError(iB,0);
    if (histNominal->GetBinContent(iB)>0)
      ratioCentral->SetBinError(iB,histNominal->GetBinError(iB)/histNominal->GetBinContent(iB));
  }



  if (upRange>0) 
    histUp->GetYaxis()->SetRangeUser(0.1,upRange);

  histUp->GetYaxis()->SetTitleOffset(1.4);

  TCanvas * canv1 = MakeCanvas("canv1", "", 800, 700);
  TPad *upper = new TPad("upper", "pad",0,0.31,1,1);
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

  histNominal->Draw("pe");
  histUp->Draw("hsame");
  histDown->Draw("hsame");

  TLegend * leg = new TLegend(0.2,0.78,0.92,0.90);
  SetLegendStyle(leg);
  leg->SetHeader(header);
  leg->SetTextSize(0.035);
  //  leg->AddEntry(histNominal,"  Central","ep");
  //  leg->AddEntry(histUp,SysLeg+" Up","l");
  //  leg->AddEntry(histDown,SysLeg+" Down","l");
  leg->Draw();

  TLegend * leg1 = new TLegend(0.2,0.72,0.92,0.84);
  SetLegendStyle(leg1);
  leg1->SetHeader(header1);
  leg1->SetTextSize(0.035);
  leg1->Draw();

  TLegend * leg2 = new TLegend(0.2,0.66,0.92,0.78);
  SetLegendStyle(leg2);
  leg2->SetHeader(header2);
  leg2->SetTextSize(0.035);
  leg2->Draw();

  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  ratioUp->SetTitle("");
  ratioUp->GetYaxis()->SetRangeUser(1.0-rangeRatio,1.0+rangeRatio);
  ratioUp->GetYaxis()->SetNdivisions(505);
  ratioUp->GetXaxis()->SetLabelFont(42);
  ratioUp->GetXaxis()->SetLabelOffset(0.04);
  ratioUp->GetXaxis()->SetLabelSize(0.10);
  ratioUp->GetXaxis()->SetTitleSize(0.13);
  ratioUp->GetXaxis()->SetTitleOffset(1.2);
  ratioUp->GetYaxis()->SetTitle("ratio");
  ratioUp->GetYaxis()->SetLabelFont(42);
  ratioUp->GetYaxis()->SetLabelOffset(0.015);
  ratioUp->GetYaxis()->SetLabelSize(0.1);
  ratioUp->GetYaxis()->SetTitleSize(0.14);
  ratioUp->GetYaxis()->SetTitleOffset(0.5);
  ratioUp->GetXaxis()->SetTickLength(0.07);
  ratioUp->GetYaxis()->SetTickLength(0.04);
  ratioUp->GetYaxis()->SetLabelOffset(0.01);

  // ------------>Primitives in pad: lower
  TPad * lower = new TPad("lower", "pad",0,0,1,0.32);
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

  ratioUp->Draw("h");
  ratioDown->Draw("hsame");
  ratioCentral->Draw("e1same");

  lower->Modified();
  lower->RedrawAxis();
  canv1->cd();
  canv1->Modified();
  canv1->cd();
  canv1->Print(category+"-"+histName+"-"+sysName+".png");
  //  canv1->Print(category+"_"+histName+pageType+".pdf"+pageType,"pdf");

} 
