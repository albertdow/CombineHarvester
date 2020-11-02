#include "PlotSys.C"
// +++++++++ systematics +++++++++ 
// CMS_htt_boson_reso_met_13TeV
// CMS_htt_boson_scale_met_13TeV
// CMS_scale_e_13TeV
// CMS_scale_t_1prong_13TeV
// CMS_scale_t_1prong1pizero_13TeV
// CMS_scale_t_3prong_13TeV
// CMS_scale_j_FlavorQCD_13TeV
// CMS_scale_j_RelativeBal_13TeV
// CMS_scale_j_HF_13TeV
// CMS_scale_j_BBEC1_13TeV
// CMS_scale_j_EC2_13TeV
// CMS_scale_j_Absolute_13TeV
// CMS_scale_j_Absolute_2018_13TeV
// CMS_scale_j_HF_2018_13TeV
// CMS_scale_j_EC2_2018_13TeV
// CMS_scale_j_RelativeSample_2018_13TeV
// CMS_scale_j_BBEC1_2018_13TeV
// CMS_res_j_13TeV
//
// ++++++++++ Directories ++++++++++++++
// /nfs/dust/cms/user/rasp/storage/cardinia/2016/OutputDNNet/Sep1-PUB/predictions_2016
// /nfs/dust/cms/user/rasp/storage/cardinia/2017/OutputDNNet/Sep1-PUB/predictions_2017
// /nfs/dust/cms/user/rasp/storage/cardinia/2018/OutputDNNet/Sep1-PUB/predictions_2018
//
// +++++++ Templates +++++++
// et-NOMINAL_ntuple_DY.root      
// et-NOMINAL_ntuple_TT.root     
// et-NOMINAL_ntuple_data.root
// et-NOMINAL_ntuple_DYonly.root  
// et-NOMINAL_ntuple_VV.root     
// et-NOMINAL_ntuple_EWKZ.root 
// et-NOMINAL_ntuple_ggH125.root
// et-NOMINAL_ntuple_EMB.root 
// et-NOMINAL_ntuple_W.root 
// et-NOMINAL_ntuple_qqH125.root
// et-NOMINAL_ntuple_WH125.root
// et-NOMINAL_ntuple_HToWW.root   
// et-NOMINAL_ntuple_ZH125.root
//
// ++++++++ Variables ++++++++++++
// predicted_prob
// predicted_class
// njets
// puppimet
void PlotSysSeq() {

  TString era("2018");
  TString process("ggH125");
  TString varName("predicted_prob");
  TString xtitle("DNN score");
  TString ytitle("Events");
  int nbins = 10;
  float xmin = 0;
  float xmax = 1;
  TString sysName("CMS_scale_e_13TeV");
  //  TString catCut("&&predicted_class==0&&dmMVA_2==0&&IP_signif_RefitV_with_BS_1>1.5");
  //  TString catCut("&&predicted_class==0");
  TString catCut("");
  bool outputPdf = false;
  TString pageType("");

  TString fileName = "/nfs/dust/cms/user/rasp/storage/cardinia/"+era+"/OutputDNNet/Sep1-PUB/predictions_"+era+"/et-NOMINAL_ntuple_"+process+".root";
  TFile * file = new TFile(fileName);
  std::cout << file << std::endl;

  PlotSys(file,era,process,varName,xtitle,ytitle,nbins,xmin,xmax,sysName,catCut,outputPdf,pageType);

}
