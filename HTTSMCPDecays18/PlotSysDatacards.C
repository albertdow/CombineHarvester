#include "HttStylesNew.cc"
// +++ systematics (datacards) +++ 
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
// +++++++++ systematics (workspace) ++++++++++++
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
// ++++++++++++++++++++++++++++++++++++
// Problematic systematics:
//            CMS_scale_t_1prong_2018(13TeV)
//            CMS_scale_met_unclustered_2018(13TeV)
//            CMS_htt_boson_reso_met_2018(13TeV)
//            CMS_scale_j_FlavorQCD(13TeV)
//            CMS_scale_j_Absolute(13TeV)
//            CMS_scale_embedded_t_1prong_2016(13TeV)
//            CMS_res_j_2018(13TeV)
//            CMS_scale_j_HF(13TeV)
// ----------------------------------------------------
// category : workspace             - datacards 
//            htt_et_[year]_1_13TeV - et_ztt_[year]
//            htt_et_[year]_2_13TeV - et_fakes_[year]
//            htt_et_[year]_3_13TeV - et_murho_sig_[year]
//            htt_et_[year]_4_13TeV - et_mupi_sig_[year]
//            htt_et_[year]_5_13TeV - et_mua1_sig_[year]
//            htt_et_[year]_6_13TeV - et_mu0a1_[year]
// histName : EmbedZTT ZL TTT VVT jetFakes 
//            qqH_sm_htt125 qqH_ps_htt125 qqH_mm_htt125 
//            WH_sm_htt125 WH_ps_htt125 WH_mm_htt125 
//            ZH_sm_htt125 ZH_ps_htt125 ZH_mm_htt125 
//            ggH_sm_htt125 ggH_ps_htt125 ggH_mm_htt125
// filename : 
// output/all_Oct12/htt_et_Combined_13TeV/common/htt_input.root
// shapes/DESY/2018/htt_et.inputs-sm-13TeV-mergeXbins.root
// shapes/DESY/2018/htt_et.inputs-sm-13TeV.root
void PlotSysDatacards(
		      TFile * file = NULL,
		      TString histName = "ggH_sm_htt125",
		      TString sysName  = "CMS_scale_j_FlavorQCD_13TeV",
		      TString category = "et_mu0a1_sig_2018",
		      float rangeRatio = 0.10,
		      float upRange = -1,
		      bool outputPdf = false,
		      TString pageType = ""
		      ) {

  if (file==NULL) {
    std::cout << "NULL pointer to file..." << std::endl;
    return;
  }

  TString header  = category + ":" + histName;
  TString header1 = sysName;
  TString ytitle("Events");
  TString xtitle("DNN score"); 

  SetStyle();
  gStyle->SetErrorX(0);
  TH1D * histNominal = (TH1D*)file->Get(category+"/"+histName);
  TH1D * histUp = (TH1D*)file->Get(category+"/"+histName+"_"+sysName+"Up");
  TH1D * histDown = (TH1D*)file->Get(category+"/"+histName+"_"+sysName+"Down");
  std::cout << histNominal << " " <<  histUp << " " << histDown << std::endl;
  if (histNominal==NULL) {
    std::cout << "NULL pointer to histogram " << category << "/" << histName << std::endl; 
    return;
  }
  if (histUp==NULL||histDown==NULL) {
    std::cout << "NULL pointer to histogram " << category << "/" << histName << "_" << sysName << "Up[Down]" << std::endl; 
    return;
  }


  int nBins = histNominal->GetNbinsX(); 
  float xmax = histNominal->GetBinLowEdge(nBins+1)-0.01;

  InitData(histNominal);

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

  upper->Draw("SAME");
  upper->RedrawAxis();
  upper->Modified();
  upper->Update();
  canv1->cd();

  double xDown = histDown->GetSum()/histNominal->GetSum();
  double xUp = histUp->GetSum()/histNominal->GetSum();
  std::cout << std::endl;
  printf("lnN    %5.3f/%5.3f \n",xDown,xUp);
  std::cout << std::endl;

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

  if (outputPdf)
    canv1->Print("figures_sysCards/systematics.pdf"+pageType,"pdf");
  else
    canv1->Print("figures_sysCards/"+category+"-"+histName+"-"+sysName+".png");

} 
