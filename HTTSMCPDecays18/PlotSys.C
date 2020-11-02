#include "HttStylesNew.cc"
// +++++++++ systematics +++++++++ 
// CMS_htt_boson_reso_met_13TeV
// CMS_htt_boson_scale_met_13TeV
// CMS_scale_met_unclustered_13TeV
// CMS_scale_e_13TeV
// CMS_scale_t_1prong_13TeV
// CMS_scale_t_1prong1pizero_13TeV
// CMS_scale_t_3prong_13TeV
// CMS_res_j_13TeV
// CMS_scale_j_FlavorQCD_13TeV
// CMS_scale_j_RelativeBal_13TeV
// CMS_scale_j_HF_13TeV
// CMS_scale_j_BBEC1_13TeV
// CMS_scale_j_EC2_13TeV
// CMS_scale_j_Absolute_13TeV
// CMS_scale_j_Absolute_[year]_13TeV
// CMS_scale_j_HF_[year]_13TeV
// CMS_scale_j_EC2_[year]_13TeV
// CMS_scale_j_RelativeSample_[year]_13TeV
// CMS_scale_j_BBEC1_[year]_13TeV
//
// ++++++++++ Directories ++++++++++++++
// /nfs/dust/cms/user/rasp/storage/cardinia/2016/OutputDNNet/Sep1-PUB/predictions_2016
// /nfs/dust/cms/user/rasp/storage/cardinia/2017/OutputDNNet/Sep1-PUB/predictions_2017
// /nfs/dust/cms/user/rasp/storage/cardinia/2018/OutputDNNet/Sep1-PUB/predictions_2018
//
// +++++++ Templates +++++++
// et-NOMINAL_ntuple_DY.root      
// et-NOMINAL_ntuple_TT.root     
// et-NOMINAL_ntuple_VV.root     
// et-NOMINAL_ntuple_EWKZ.root 
// et-NOMINAL_ntuple_ggH125.root
// et-NOMINAL_ntuple_EMB.root 
// et-NOMINAL_ntuple_W.root 
// et-NOMINAL_ntuple_qqH125.root
// et-NOMINAL_ntuple_WH125.root
// et-NOMINAL_ntuple_HToWW.root   
// et-NOMINAL_ntuple_ZH125.root
void getHistoParameters(TString variable, int &nbins, float &xmin, float &xmax) {
  if (variable=="jpt1"||variable=="jpt2") {
    nbins = 25;
    xmin = 30;
    xmax = 530;
  }
  if (variable=="puppimet") {
    nbins = 30;
    xmin = 0;
    xmax = 300;
  }
  if (variable=="njets") {
    nbins = 8;
    xmin = -0.5;
    xmax = 7.5;
  }
}
bool ProcessSystematics(TString process, TString sysName) {
  bool isExist = true;
  if (process=="EMB") { 
    if (sysName.Contains("CMS_scale_j"))
      isExist = false;
    if (sysName.Contains("CMS_res_j"))
      isExist = false;
    if (sysName.Contains("CMS_htt_boson"))
      isExist = false;
    if (sysName.Contains("CMS_scale_met"))
      isExist = false;
  }
  if (process=="TT"&&process=="VV") {
    if (sysName.Contains("CMS_htt_boson"))
      isExist = false;
  }
  if (process=="DY"||process=="W"||process=="ggH125"||process=="qqH125") {
    if (sysName.Contains("CMS_scale_met"))
      isExist = false;    
  }
  return isExist;
} 

void PlotSys(TFile * file = NULL,
	     TString era = "2018",
	     TString process = "EMB",
	     TString varName = "predicted_prob",
	     TString xtitle = "DNN",
	     TString ytitle = "Events",
	     int nBins =      20,
	     float xmin =      0,
	     float xmax =      1,
	     TString sysName = "CMS_scale_e_13TeV",
	     TString categoryCut = "",
	     bool outputPdf = false,
	     TString pageType = "") {

  TString header = sysName;
  TString Weight("weight*");
  TString Cuts("trg_singleelectron>0.5&&pt_1>26&&TMath::Abs(eta_1)<2.1&&pt_2>20&&TMath::Abs(eta_2)<2.3&&os>0.5&&puppimt_1<50");

  if (era=="2017") 
    Cuts = "pt_1>25&&TMath::Abs(eta_1)<2.1&&pt_2>20&&TMath::Abs(eta_2)<2.3&&os>0.5&&puppimt_1<50&&((trg_singleelectron>0.5&&pt_1>28)||(trg_etaucross>0.5&&pt_1>25&&pt_2>35&&TMath::Abs(eta_2)<2.1))";
  if (era=="2018")
    Cuts = "pt_1>25&&TMath::Abs(eta_1)<2.1&&pt_2>20&&TMath::Abs(eta_2)<2.3&&os>0.5&&puppimt_1<50&&((trg_singleelectron>0.5&&pt_1>33)||(trg_etaucross>0.5&&pt_1>25&&pt_2>35&&TMath::Abs(eta_2)<2.1))";

  Cuts += "&&nbtag==0";
  Cuts += categoryCut;

  if (varName=="jpt_1"||varName=="jeta_1") {
    Cuts += "&&njets>0";
  }
  if (varName=="jpt_2"||varName=="jeta_2"||varName=="mjj"||varName=="jdeta") {
    Cuts += "&&njets>1";
  }


  SetStyle();
  gStyle->SetErrorX(0);

  TTree * treeNominal = (TTree*)file->Get("TauCheck");
  TTree * treeUp = (TTree*)file->Get("TauCheck_"+sysName+"Up");
  TTree * treeDown = (TTree*)file->Get("TauCheck_"+sysName+"Down");

  TH1D * histNominal = new TH1D("histNominal","",nBins,xmin,xmax);
  TH1D * histUp = new TH1D("histUp","",nBins, xmin,xmax);
  TH1D * histDown = new TH1D("histDown","",nBins, xmin,xmax);

  TCanvas * dummy = new TCanvas("dummy","",600,600);
  treeNominal->Draw(varName+">>histNominal",Cuts);
  treeUp->Draw(varName+">>histUp",Cuts);
  treeDown->Draw(varName+">>histDown",Cuts);
  float yMax = histUp->GetMaximum();
  if (histNominal->GetMaximum()>yMax)
    yMax = histNominal->GetMaximum();
  if (histDown->GetMaximum()>yMax)
    yMax = histDown->GetMaximum();

  delete dummy;

  float xUp = histUp->GetSum()/histNominal->GetSum();
  float xDown = histDown->GetSum()/histNominal->GetSum();

  std::cout << std::endl;
  printf("lnN   %5.3f/%5.3f\n",xUp,xDown);
  std::cout << std::endl;

  histUp->GetYaxis()->SetRangeUser(0.01,1.1*yMax);
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
  TH1D * ratioUp = (TH1D*)histUp->Clone("ratioUp");
  TH1D * ratioDown = (TH1D*)histDown->Clone("ratioDown");
  TH1D * ratioCentral = (TH1D*)histNominal->Clone("ratioCentral");
  //  ratioCentral->SetFillStyle(3013);
  //  ratioCentral->SetFillColor(1);
  //  ratioCentral->SetMarkerStyle(21);
  //  ratioCentral->SetMarkerSize(0);

  float ratioMax = -1;
  float ratioMin = 10000;
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
    if (xratioUp>ratioMax) ratioMax = xratioUp;
    if (xratioDown>ratioMax) ratioMax = xratioDown;
    if (xratioUp<ratioMin) ratioMin = xratioUp;
    if (xratioDown<ratioMin) ratioMin = xratioDown;
    ratioUp->SetBinError(iB,0);
    ratioDown->SetBinError(iB,0);
    ratioCentral->SetBinContent(iB,1);
    ratioCentral->SetBinError(iB,0);
    if (histNominal->GetBinContent(iB)>0)
      ratioCentral->SetBinError(iB,histNominal->GetBinError(iB)/histNominal->GetBinContent(iB));
  }
  float diffMax = TMath::Abs(ratioMax-1.0);
  float diffMin = TMath::Abs(ratioMin-1.0);
  float diff = 1.1*TMath::Max(diffMax,diffMin);

  histUp->GetYaxis()->SetTitleOffset(1.4);

  TCanvas * canv1 = MakeCanvas("canv1", "", 700, 800);
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

  histUp->Draw("h");
  histNominal->Draw("pesame");
  histDown->Draw("hsame");
  TLegend * leg = new TLegend(0.55,0.65,0.92,0.9);
  leg->SetHeader(header);
  leg->SetFillColor(0);
  leg->SetTextSize(0.04);
  leg->AddEntry(histNominal,"Central","l");
  leg->AddEntry(histUp,"Up","l");
  leg->AddEntry(histDown,"Down","l");
  //  leg->Draw();
  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  ratioUp->GetYaxis()->SetRangeUser(1.0-diff,1.0+diff);
  ratioUp->GetYaxis()->SetNdivisions(505);
  ratioUp->GetXaxis()->SetLabelFont(42);
  ratioUp->GetXaxis()->SetLabelOffset(0.04);
  ratioUp->GetXaxis()->SetLabelSize(0.1);
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

  if (outputPdf)
    canv1->Print("figures_sysDNN/"+process+"_"+era+".pdf"+pageType,"pdf");
  else
    canv1->Print("figures_sysDNN/"+process+"_"+varName+"_"+sysName+"_"+era+".png");


} 
