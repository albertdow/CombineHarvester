#include "PlotSysDatacards.C"
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
// category : htt_et_[year]_1_13TeV - et_ztt_[year]
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
void PlotSysDatacardsSeq() {

  TString era("2018");
  //  TString fileName = "shapes/DESY/"+era+"/htt_et.inputs-sm-13TeV-mergeXbins.root";
  TString fileName = "shapes/IC/"+era+"/htt_tt.inputs-sm-13TeV-mergeXbins.root";
    
  TFile * file = new TFile(fileName);
  TString histName = "qqH_sm_htt125";
  TString sysName = "CMS_scale_t_1prong1pizero_13TeV";
  TString category = "tt_2018_zttEmbed";
  float rangeRatio = 0.10;
  float upRange = -1;
  bool outputPdf = false;
  TString pageType = "";
  PlotSysDatacards(file,histName,sysName,category,rangeRatio,upRange,outputPdf,pageType);

}
