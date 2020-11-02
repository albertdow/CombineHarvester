//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Oct 17 18:27:36 2020 by ROOT version 6.12/07
// from TTree TauCheck/TauCheck
// found on file: /nfs/dust/cms/user/rasp/storage/cardinia/2018/OutputDNNet/Sep1-PUB/predictions_2018/et-NOMINAL_ntuple_VV.root
//////////////////////////////////////////////////////////

#ifndef TauCheck_h
#define TauCheck_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class TauCheck {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMax__index_ = 1;

   // Declaration of leaf types
   Long64_t        index;
   Long64_t        run;
   Long64_t        evt;
   Float_t         pt_1;
   Float_t         eta_1;
   Float_t         phi_1;
   Long64_t        gen_match_1;
   Float_t         iso_1;
   Float_t         puppimt_1;
   Float_t         ipx_1;
   Float_t         ipy_1;
   Float_t         ipz_1;
   Double_t        IP_signif_PV_with_BS_1;
   Double_t        IP_signif_RefitV_with_BS_1;
   Double_t        IP_signif_RefitV_with_BS_uncorr_1;
   Float_t         pt_2;
   Float_t         eta_2;
   Float_t         phi_2;
   Long64_t        gen_match_2;
   Float_t         puppimt_2;
   Long64_t        tau_decay_mode_2;
   Float_t         dmMVA_2;
   Float_t         ipx_2;
   Float_t         ipy_2;
   Float_t         ipz_2;
   Double_t        IP_signif_PV_with_BS_2;
   Double_t        IP_signif_RefitV_with_BS_2;
   Double_t        IP_signif_RefitV_with_BS_uncorr_2;
   Bool_t          trg_singlemuon;
   Bool_t          trg_mutaucross;
   Bool_t          trg_singleelectron;
   Bool_t          trg_etaucross;
   Bool_t          is_SingleLepTrigger;
   Bool_t          is_CrossTrigger;
   Bool_t          is_Trigger;
   Float_t         embweight;
   Float_t         trigweight;
   Float_t         trigweight_1;
   Float_t         trigweight_2;
   Float_t         mcweight;
   Float_t         effweight;
   Float_t         puweight;
   Float_t         topptweight;
   Double_t        zptweight;
   Float_t         etaufakeweight;
   Float_t         etaufakeweight_dm;
   Float_t         weight;
   Float_t         weight_CMS_PreFire_13TeVUp;
   Float_t         weight_CMS_PreFire_13TeVDown;
   Long64_t        njets;
   Float_t         mjj;
   Float_t         jdeta;
   Float_t         dijetpt;
   Float_t         jpt_1;
   Float_t         jpt_2;
   Float_t         jeta_1;
   Float_t         jeta_2;
   Float_t         m_vis;
   Float_t         pt_tt;
   Float_t         mt_tot;
   Float_t         m_sv;
   Float_t         pt_sv;
   Float_t         m_fast;
   Float_t         pt_fast;
   Float_t         puppimet;
   Float_t         puppimetphi;
   Long64_t        os;
   Long64_t        nbtag;
   Float_t         byVVVLooseDeepTau2017v2p1VSjet_2;
   Float_t         byMediumDeepTau2017v2p1VSjet_2;
   Float_t         acotautau_refitbs_00;
   Float_t         acotautau_refitbs_01;
   Float_t         acotautau_helix_00;
   Float_t         acotautau_helix_01;
   Float_t         acotautau_bs_00;
   Float_t         acotautau_bs_01;
   Float_t         acotautau_00;
   Float_t         acotautau_01;
   Float_t         acotautau_refitbs_uncorr_00;
   Float_t         acotautau_refitbs_uncorr_01;
   Float_t         acotautau_helix_uncorr_00;
   Float_t         acotautau_helix_uncorr_01;
   Float_t         alpha_IP_1;
   Float_t         alpha_IP_uncorr_1;
   Float_t         alpha_plane_1;
   Float_t         alpha_IP_2;
   Float_t         alpha_IP_uncorr_2;
   Float_t         alpha_plane_2;
   Float_t         alphaminus;
   Float_t         alphaminus_uncorr;
   Float_t         xsec_lumi_weight;
   Float_t         prefiring_weight;
   Long64_t        htxs_reco_flag_ggh;
   Long64_t        htxs_reco_flag_qqh;
   Float_t         ff_nom;
   Float_t         ff_mva;
   Float_t         ff_sys;
   Double_t        gen_sm_htt125;
   Double_t        gen_ps_htt125;
   Double_t        gen_mm_htt125;
   Float_t         weight_CMS_htt_dyShape_13TeVDown;
   Float_t         weight_CMS_htt_dyShape_13TeVUp;
   Float_t         weight_CMS_htt_ttbarShape_13TeVDown;
   Float_t         weight_CMS_htt_ttbarShape_13TeVUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Up;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Up;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Down;
   Float_t         weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Down;
   Float_t         weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Up;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Up;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Down;
   Float_t         weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Down;
   Float_t         weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Down;
   Float_t         weight_ff_mt_qcd_met_closure_systUp;
   Float_t         weight_ff_mt_wjets_met_closure_systUp;
   Float_t         weight_ff_mt_ttbar_met_closure_systUp;
   Float_t         weight_ff_mt_qcd_met_closure_systDown;
   Float_t         weight_ff_mt_wjets_met_closure_systDown;
   Float_t         weight_ff_mt_ttbar_met_closure_systDown;
   Float_t         weight_ff_mt_qcd_l_pt_closure_systUp;
   Float_t         weight_ff_mt_qcd_l_pt_closure_systDown;
   Float_t         weight_ff_mt_wjets_l_pt_closure_systUp;
   Float_t         weight_ff_mt_wjets_l_pt_closure_systDown;
   Float_t         weight_ff_mt_qcd_systUp;
   Float_t         weight_ff_mt_qcd_systDown;
   Float_t         weight_ff_mt_wjets_systUp;
   Float_t         weight_ff_mt_wjets_systDown;
   Float_t         weight_ff_mt_ttbar_systUp;
   Float_t         weight_ff_mt_ttbar_systDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm1Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm1Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm1Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm1Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm1Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm1Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm2Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm2Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm2Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm2Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm2Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm2Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm10Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm10Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm10Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm10Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm10Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm10Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm11Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm11Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm11Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm11Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm11Up;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm11Up;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm1Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm1Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm1Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm1Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm1Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm1Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm2Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm2Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm2Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm2Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm2Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm2Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm10Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm10Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm10Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm10Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm10Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm10Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets0_mvadm11Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets0_mvadm11Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets1_mvadm11Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets1_mvadm11Down;
   Float_t         weight_ff_et_wjets_stat_unc1_njets2_mvadm11Down;
   Float_t         weight_ff_et_qcd_stat_unc1_njets2_mvadm11Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltUp;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtUp;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm1Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm1Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm1Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm1Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm1Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm1Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm2Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm2Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm2Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm2Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm2Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm2Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm10Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm10Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm10Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm10Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm10Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm10Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm11Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm11Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm11Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm11Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm11Up;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm11Up;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltDown;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtDown;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm1Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm1Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm1Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm1Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm1Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm1Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm2Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm2Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm2Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm2Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm2Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm2Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm10Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm10Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm10Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm10Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm10Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm10Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets0_mvadm11Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets0_mvadm11Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets1_mvadm11Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets1_mvadm11Down;
   Float_t         weight_ff_et_wjets_stat_unc2_njets2_mvadm11Down;
   Float_t         weight_ff_et_qcd_stat_unc2_njets2_mvadm11Down;
   Float_t         weight_ff_et_qcd_met_closure_systUp;
   Float_t         weight_ff_et_wjets_met_closure_systUp;
   Float_t         weight_ff_et_ttbar_met_closure_systUp;
   Float_t         weight_ff_et_qcd_met_closure_systDown;
   Float_t         weight_ff_et_wjets_met_closure_systDown;
   Float_t         weight_ff_et_ttbar_met_closure_systDown;
   Float_t         weight_ff_et_qcd_l_pt_closure_systUp;
   Float_t         weight_ff_et_qcd_l_pt_closure_systDown;
   Float_t         weight_ff_et_wjets_l_pt_closure_systUp;
   Float_t         weight_ff_et_wjets_l_pt_closure_systDown;
   Float_t         weight_ff_et_qcd_systUp;
   Float_t         weight_ff_et_qcd_systDown;
   Float_t         weight_ff_et_wjets_systUp;
   Float_t         weight_ff_et_wjets_systDown;
   Float_t         weight_ff_et_ttbar_systUp;
   Float_t         weight_ff_et_ttbar_systDown;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM0_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM1_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM2_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM10_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM11_13TeVUp;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM0_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM1_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM2_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM10_13TeVDown;
   Float_t         weight_CMS_eff_Xtrigger_et_MVADM11_13TeVDown;
   Float_t         weight_CMS_eff_t_pTlow_MVADM0_13TeVUp;
   Float_t         weight_CMS_eff_t_pTlow_MVADM1_13TeVUp;
   Float_t         weight_CMS_eff_t_pTlow_MVADM2_13TeVUp;
   Float_t         weight_CMS_eff_t_pTlow_MVADM10_13TeVUp;
   Float_t         weight_CMS_eff_t_pTlow_MVADM11_13TeVUp;
   Float_t         weight_CMS_eff_t_pThigh_MVADM0_13TeVUp;
   Float_t         weight_CMS_eff_t_pThigh_MVADM1_13TeVUp;
   Float_t         weight_CMS_eff_t_pThigh_MVADM2_13TeVUp;
   Float_t         weight_CMS_eff_t_pThigh_MVADM10_13TeVUp;
   Float_t         weight_CMS_eff_t_pThigh_MVADM11_13TeVUp;
   Float_t         weight_CMS_eff_t_pTlow_MVADM0_13TeVDown;
   Float_t         weight_CMS_eff_t_pTlow_MVADM1_13TeVDown;
   Float_t         weight_CMS_eff_t_pTlow_MVADM2_13TeVDown;
   Float_t         weight_CMS_eff_t_pTlow_MVADM10_13TeVDown;
   Float_t         weight_CMS_eff_t_pTlow_MVADM11_13TeVDown;
   Float_t         weight_CMS_eff_t_pThigh_MVADM0_13TeVDown;
   Float_t         weight_CMS_eff_t_pThigh_MVADM1_13TeVDown;
   Float_t         weight_CMS_eff_t_pThigh_MVADM2_13TeVDown;
   Float_t         weight_CMS_eff_t_pThigh_MVADM10_13TeVDown;
   Float_t         weight_CMS_eff_t_pThigh_MVADM11_13TeVDown;
   Float_t         weight_CMS_mufake_mt_MVADM0_13TeVUp;
   Float_t         weight_CMS_mufake_mt_MVADM1_13TeVUp;
   Float_t         weight_CMS_mufake_mt_MVADM2_13TeVUp;
   Float_t         weight_CMS_mufake_mt_MVADM10_13TeVUp;
   Float_t         weight_CMS_mufake_mt_MVADM11_13TeVUp;
   Float_t         weight_CMS_mufake_mt_MVADM0_13TeVDown;
   Float_t         weight_CMS_mufake_mt_MVADM1_13TeVDown;
   Float_t         weight_CMS_mufake_mt_MVADM2_13TeVDown;
   Float_t         weight_CMS_mufake_mt_MVADM10_13TeVDown;
   Float_t         weight_CMS_mufake_mt_MVADM11_13TeVDown;
   Float_t         weight_CMS_efake_et_MVADM0_13TeVUp;
   Float_t         weight_CMS_efake_et_MVADM1_13TeVUp;
   Float_t         weight_CMS_efake_et_MVADM2_13TeVUp;
   Float_t         weight_CMS_efake_et_MVADM10_13TeVUp;
   Float_t         weight_CMS_efake_et_MVADM11_13TeVUp;
   Float_t         weight_CMS_efake_et_MVADM0_13TeVDown;
   Float_t         weight_CMS_efake_et_MVADM1_13TeVDown;
   Float_t         weight_CMS_efake_et_MVADM2_13TeVDown;
   Float_t         weight_CMS_efake_et_MVADM10_13TeVDown;
   Float_t         weight_CMS_efake_et_MVADM11_13TeVDown;
   Float_t         weight_CMS_scale_gg_13TeVUp;
   Float_t         weight_CMS_scale_gg_13TeVDown;
   Float_t         weight_CMS_PS_ISR_ggH_13TeVUp;
   Float_t         weight_CMS_PS_ISR_ggH_13TeVDown;
   Float_t         weight_CMS_PS_FSR_ggH_13TeVUp;
   Float_t         weight_CMS_PS_FSR_ggH_13TeVDown;
   Double_t        event_weight;
   Long64_t        target;
   Double_t        train_weight;
   Double_t        predicted_class;
   Double_t        predicted_prob;
   Long64_t        __index__;

   // List of branches
   TBranch        *b_index;   //!
   TBranch        *b_run;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_pt_1;   //!
   TBranch        *b_eta_1;   //!
   TBranch        *b_phi_1;   //!
   TBranch        *b_gen_match_1;   //!
   TBranch        *b_iso_1;   //!
   TBranch        *b_puppimt_1;   //!
   TBranch        *b_ipx_1;   //!
   TBranch        *b_ipy_1;   //!
   TBranch        *b_ipz_1;   //!
   TBranch        *b_IP_signif_PV_with_BS_1;   //!
   TBranch        *b_IP_signif_RefitV_with_BS_1;   //!
   TBranch        *b_IP_signif_RefitV_with_BS_uncorr_1;   //!
   TBranch        *b_pt_2;   //!
   TBranch        *b_eta_2;   //!
   TBranch        *b_phi_2;   //!
   TBranch        *b_gen_match_2;   //!
   TBranch        *b_puppimt_2;   //!
   TBranch        *b_tau_decay_mode_2;   //!
   TBranch        *b_dmMVA_2;   //!
   TBranch        *b_ipx_2;   //!
   TBranch        *b_ipy_2;   //!
   TBranch        *b_ipz_2;   //!
   TBranch        *b_IP_signif_PV_with_BS_2;   //!
   TBranch        *b_IP_signif_RefitV_with_BS_2;   //!
   TBranch        *b_IP_signif_RefitV_with_BS_uncorr_2;   //!
   TBranch        *b_trg_singlemuon;   //!
   TBranch        *b_trg_mutaucross;   //!
   TBranch        *b_trg_singleelectron;   //!
   TBranch        *b_trg_etaucross;   //!
   TBranch        *b_is_SingleLepTrigger;   //!
   TBranch        *b_is_CrossTrigger;   //!
   TBranch        *b_is_Trigger;   //!
   TBranch        *b_embweight;   //!
   TBranch        *b_trigweight;   //!
   TBranch        *b_trigweight_1;   //!
   TBranch        *b_trigweight_2;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_effweight;   //!
   TBranch        *b_puweight;   //!
   TBranch        *b_topptweight;   //!
   TBranch        *b_zptweight;   //!
   TBranch        *b_etaufakeweight;   //!
   TBranch        *b_etaufakeweight_dm;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_weight_CMS_PreFire_13TeVUp;   //!
   TBranch        *b_weight_CMS_PreFire_13TeVDown;   //!
   TBranch        *b_njets;   //!
   TBranch        *b_mjj;   //!
   TBranch        *b_jdeta;   //!
   TBranch        *b_dijetpt;   //!
   TBranch        *b_jpt_1;   //!
   TBranch        *b_jpt_2;   //!
   TBranch        *b_jeta_1;   //!
   TBranch        *b_jeta_2;   //!
   TBranch        *b_m_vis;   //!
   TBranch        *b_pt_tt;   //!
   TBranch        *b_mt_tot;   //!
   TBranch        *b_m_sv;   //!
   TBranch        *b_pt_sv;   //!
   TBranch        *b_m_fast;   //!
   TBranch        *b_pt_fast;   //!
   TBranch        *b_puppimet;   //!
   TBranch        *b_puppimetphi;   //!
   TBranch        *b_os;   //!
   TBranch        *b_nbtag;   //!
   TBranch        *b_byVVVLooseDeepTau2017v2p1VSjet_2;   //!
   TBranch        *b_byMediumDeepTau2017v2p1VSjet_2;   //!
   TBranch        *b_acotautau_refitbs_00;   //!
   TBranch        *b_acotautau_refitbs_01;   //!
   TBranch        *b_acotautau_helix_00;   //!
   TBranch        *b_acotautau_helix_01;   //!
   TBranch        *b_acotautau_bs_00;   //!
   TBranch        *b_acotautau_bs_01;   //!
   TBranch        *b_acotautau_00;   //!
   TBranch        *b_acotautau_01;   //!
   TBranch        *b_acotautau_refitbs_uncorr_00;   //!
   TBranch        *b_acotautau_refitbs_uncorr_01;   //!
   TBranch        *b_acotautau_helix_uncorr_00;   //!
   TBranch        *b_acotautau_helix_uncorr_01;   //!
   TBranch        *b_alpha_IP_1;   //!
   TBranch        *b_alpha_IP_uncorr_1;   //!
   TBranch        *b_alpha_plane_1;   //!
   TBranch        *b_alpha_IP_2;   //!
   TBranch        *b_alpha_IP_uncorr_2;   //!
   TBranch        *b_alpha_plane_2;   //!
   TBranch        *b_alphaminus;   //!
   TBranch        *b_alphaminus_uncorr;   //!
   TBranch        *b_xsec_lumi_weight;   //!
   TBranch        *b_prefiring_weight;   //!
   TBranch        *b_htxs_reco_flag_ggh;   //!
   TBranch        *b_htxs_reco_flag_qqh;   //!
   TBranch        *b_ff_nom;   //!
   TBranch        *b_ff_mva;   //!
   TBranch        *b_ff_sys;   //!
   TBranch        *b_gen_sm_htt125;   //!
   TBranch        *b_gen_ps_htt125;   //!
   TBranch        *b_gen_mm_htt125;   //!
   TBranch        *b_weight_CMS_htt_dyShape_13TeVDown;   //!
   TBranch        *b_weight_CMS_htt_dyShape_13TeVUp;   //!
   TBranch        *b_weight_CMS_htt_ttbarShape_13TeVDown;   //!
   TBranch        *b_weight_CMS_htt_ttbarShape_13TeVUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_mt_qcd_met_closure_systUp;   //!
   TBranch        *b_weight_ff_mt_wjets_met_closure_systUp;   //!
   TBranch        *b_weight_ff_mt_ttbar_met_closure_systUp;   //!
   TBranch        *b_weight_ff_mt_qcd_met_closure_systDown;   //!
   TBranch        *b_weight_ff_mt_wjets_met_closure_systDown;   //!
   TBranch        *b_weight_ff_mt_ttbar_met_closure_systDown;   //!
   TBranch        *b_weight_ff_mt_qcd_l_pt_closure_systUp;   //!
   TBranch        *b_weight_ff_mt_qcd_l_pt_closure_systDown;   //!
   TBranch        *b_weight_ff_mt_wjets_l_pt_closure_systUp;   //!
   TBranch        *b_weight_ff_mt_wjets_l_pt_closure_systDown;   //!
   TBranch        *b_weight_ff_mt_qcd_systUp;   //!
   TBranch        *b_weight_ff_mt_qcd_systDown;   //!
   TBranch        *b_weight_ff_mt_wjets_systUp;   //!
   TBranch        *b_weight_ff_mt_wjets_systDown;   //!
   TBranch        *b_weight_ff_mt_ttbar_systUp;   //!
   TBranch        *b_weight_ff_mt_ttbar_systDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc1_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc1_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtUp;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm1Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm2Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm10Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm11Up;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtDown;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm1Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm2Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm10Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets0_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets1_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_wjets_stat_unc2_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_stat_unc2_njets2_mvadm11Down;   //!
   TBranch        *b_weight_ff_et_qcd_met_closure_systUp;   //!
   TBranch        *b_weight_ff_et_wjets_met_closure_systUp;   //!
   TBranch        *b_weight_ff_et_ttbar_met_closure_systUp;   //!
   TBranch        *b_weight_ff_et_qcd_met_closure_systDown;   //!
   TBranch        *b_weight_ff_et_wjets_met_closure_systDown;   //!
   TBranch        *b_weight_ff_et_ttbar_met_closure_systDown;   //!
   TBranch        *b_weight_ff_et_qcd_l_pt_closure_systUp;   //!
   TBranch        *b_weight_ff_et_qcd_l_pt_closure_systDown;   //!
   TBranch        *b_weight_ff_et_wjets_l_pt_closure_systUp;   //!
   TBranch        *b_weight_ff_et_wjets_l_pt_closure_systDown;   //!
   TBranch        *b_weight_ff_et_qcd_systUp;   //!
   TBranch        *b_weight_ff_et_qcd_systDown;   //!
   TBranch        *b_weight_ff_et_wjets_systUp;   //!
   TBranch        *b_weight_ff_et_wjets_systDown;   //!
   TBranch        *b_weight_ff_et_ttbar_systUp;   //!
   TBranch        *b_weight_ff_et_ttbar_systDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM0_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM1_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM2_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM10_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM11_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM0_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM1_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM2_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM10_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_Xtrigger_et_MVADM11_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM0_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM1_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM2_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM10_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM11_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM0_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM1_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM2_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM10_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM11_13TeVUp;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM0_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM1_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM2_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM10_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pTlow_MVADM11_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM0_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM1_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM2_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM10_13TeVDown;   //!
   TBranch        *b_weight_CMS_eff_t_pThigh_MVADM11_13TeVDown;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM0_13TeVUp;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM1_13TeVUp;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM2_13TeVUp;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM10_13TeVUp;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM11_13TeVUp;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM0_13TeVDown;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM1_13TeVDown;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM2_13TeVDown;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM10_13TeVDown;   //!
   TBranch        *b_weight_CMS_mufake_mt_MVADM11_13TeVDown;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM0_13TeVUp;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM1_13TeVUp;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM2_13TeVUp;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM10_13TeVUp;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM11_13TeVUp;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM0_13TeVDown;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM1_13TeVDown;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM2_13TeVDown;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM10_13TeVDown;   //!
   TBranch        *b_weight_CMS_efake_et_MVADM11_13TeVDown;   //!
   TBranch        *b_weight_CMS_scale_gg_13TeVUp;   //!
   TBranch        *b_weight_CMS_scale_gg_13TeVDown;   //!
   TBranch        *b_weight_CMS_PS_ISR_ggH_13TeVUp;   //!
   TBranch        *b_weight_CMS_PS_ISR_ggH_13TeVDown;   //!
   TBranch        *b_weight_CMS_PS_FSR_ggH_13TeVUp;   //!
   TBranch        *b_weight_CMS_PS_FSR_ggH_13TeVDown;   //!
   TBranch        *b_event_weight;   //!
   TBranch        *b_target;   //!
   TBranch        *b_train_weight;   //!
   TBranch        *b_predicted_class;   //!
   TBranch        *b_predicted_prob;   //!
   TBranch        *b___index__;   //!

   TauCheck(TTree *tree=0);
   virtual ~TauCheck();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef TauCheck_cxx
TauCheck::TauCheck(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/nfs/dust/cms/user/rasp/storage/cardinia/2018/OutputDNNet/Sep1-PUB/predictions_2018/et-NOMINAL_ntuple_VV.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/nfs/dust/cms/user/rasp/storage/cardinia/2018/OutputDNNet/Sep1-PUB/predictions_2018/et-NOMINAL_ntuple_VV.root");
      }
      f->GetObject("TauCheck",tree);

   }
   Init(tree);
}

TauCheck::~TauCheck()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t TauCheck::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t TauCheck::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void TauCheck::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("index", &index, &b_index);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("pt_1", &pt_1, &b_pt_1);
   fChain->SetBranchAddress("eta_1", &eta_1, &b_eta_1);
   fChain->SetBranchAddress("phi_1", &phi_1, &b_phi_1);
   fChain->SetBranchAddress("gen_match_1", &gen_match_1, &b_gen_match_1);
   fChain->SetBranchAddress("iso_1", &iso_1, &b_iso_1);
   fChain->SetBranchAddress("puppimt_1", &puppimt_1, &b_puppimt_1);
   fChain->SetBranchAddress("ipx_1", &ipx_1, &b_ipx_1);
   fChain->SetBranchAddress("ipy_1", &ipy_1, &b_ipy_1);
   fChain->SetBranchAddress("ipz_1", &ipz_1, &b_ipz_1);
   fChain->SetBranchAddress("IP_signif_PV_with_BS_1", &IP_signif_PV_with_BS_1, &b_IP_signif_PV_with_BS_1);
   fChain->SetBranchAddress("IP_signif_RefitV_with_BS_1", &IP_signif_RefitV_with_BS_1, &b_IP_signif_RefitV_with_BS_1);
   fChain->SetBranchAddress("IP_signif_RefitV_with_BS_uncorr_1", &IP_signif_RefitV_with_BS_uncorr_1, &b_IP_signif_RefitV_with_BS_uncorr_1);
   fChain->SetBranchAddress("pt_2", &pt_2, &b_pt_2);
   fChain->SetBranchAddress("eta_2", &eta_2, &b_eta_2);
   fChain->SetBranchAddress("phi_2", &phi_2, &b_phi_2);
   fChain->SetBranchAddress("gen_match_2", &gen_match_2, &b_gen_match_2);
   fChain->SetBranchAddress("puppimt_2", &puppimt_2, &b_puppimt_2);
   fChain->SetBranchAddress("tau_decay_mode_2", &tau_decay_mode_2, &b_tau_decay_mode_2);
   fChain->SetBranchAddress("dmMVA_2", &dmMVA_2, &b_dmMVA_2);
   fChain->SetBranchAddress("ipx_2", &ipx_2, &b_ipx_2);
   fChain->SetBranchAddress("ipy_2", &ipy_2, &b_ipy_2);
   fChain->SetBranchAddress("ipz_2", &ipz_2, &b_ipz_2);
   fChain->SetBranchAddress("IP_signif_PV_with_BS_2", &IP_signif_PV_with_BS_2, &b_IP_signif_PV_with_BS_2);
   fChain->SetBranchAddress("IP_signif_RefitV_with_BS_2", &IP_signif_RefitV_with_BS_2, &b_IP_signif_RefitV_with_BS_2);
   fChain->SetBranchAddress("IP_signif_RefitV_with_BS_uncorr_2", &IP_signif_RefitV_with_BS_uncorr_2, &b_IP_signif_RefitV_with_BS_uncorr_2);
   fChain->SetBranchAddress("trg_singlemuon", &trg_singlemuon, &b_trg_singlemuon);
   fChain->SetBranchAddress("trg_mutaucross", &trg_mutaucross, &b_trg_mutaucross);
   fChain->SetBranchAddress("trg_singleelectron", &trg_singleelectron, &b_trg_singleelectron);
   fChain->SetBranchAddress("trg_etaucross", &trg_etaucross, &b_trg_etaucross);
   fChain->SetBranchAddress("is_SingleLepTrigger", &is_SingleLepTrigger, &b_is_SingleLepTrigger);
   fChain->SetBranchAddress("is_CrossTrigger", &is_CrossTrigger, &b_is_CrossTrigger);
   fChain->SetBranchAddress("is_Trigger", &is_Trigger, &b_is_Trigger);
   fChain->SetBranchAddress("embweight", &embweight, &b_embweight);
   fChain->SetBranchAddress("trigweight", &trigweight, &b_trigweight);
   fChain->SetBranchAddress("trigweight_1", &trigweight_1, &b_trigweight_1);
   fChain->SetBranchAddress("trigweight_2", &trigweight_2, &b_trigweight_2);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("effweight", &effweight, &b_effweight);
   fChain->SetBranchAddress("puweight", &puweight, &b_puweight);
   fChain->SetBranchAddress("topptweight", &topptweight, &b_topptweight);
   fChain->SetBranchAddress("zptweight", &zptweight, &b_zptweight);
   fChain->SetBranchAddress("etaufakeweight", &etaufakeweight, &b_etaufakeweight);
   fChain->SetBranchAddress("etaufakeweight_dm", &etaufakeweight_dm, &b_etaufakeweight_dm);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("weight_CMS_PreFire_13TeVUp", &weight_CMS_PreFire_13TeVUp, &b_weight_CMS_PreFire_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_PreFire_13TeVDown", &weight_CMS_PreFire_13TeVDown, &b_weight_CMS_PreFire_13TeVDown);
   fChain->SetBranchAddress("njets", &njets, &b_njets);
   fChain->SetBranchAddress("mjj", &mjj, &b_mjj);
   fChain->SetBranchAddress("jdeta", &jdeta, &b_jdeta);
   fChain->SetBranchAddress("dijetpt", &dijetpt, &b_dijetpt);
   fChain->SetBranchAddress("jpt_1", &jpt_1, &b_jpt_1);
   fChain->SetBranchAddress("jpt_2", &jpt_2, &b_jpt_2);
   fChain->SetBranchAddress("jeta_1", &jeta_1, &b_jeta_1);
   fChain->SetBranchAddress("jeta_2", &jeta_2, &b_jeta_2);
   fChain->SetBranchAddress("m_vis", &m_vis, &b_m_vis);
   fChain->SetBranchAddress("pt_tt", &pt_tt, &b_pt_tt);
   fChain->SetBranchAddress("mt_tot", &mt_tot, &b_mt_tot);
   fChain->SetBranchAddress("m_sv", &m_sv, &b_m_sv);
   fChain->SetBranchAddress("pt_sv", &pt_sv, &b_pt_sv);
   fChain->SetBranchAddress("m_fast", &m_fast, &b_m_fast);
   fChain->SetBranchAddress("pt_fast", &pt_fast, &b_pt_fast);
   fChain->SetBranchAddress("puppimet", &puppimet, &b_puppimet);
   fChain->SetBranchAddress("puppimetphi", &puppimetphi, &b_puppimetphi);
   fChain->SetBranchAddress("os", &os, &b_os);
   fChain->SetBranchAddress("nbtag", &nbtag, &b_nbtag);
   fChain->SetBranchAddress("byVVVLooseDeepTau2017v2p1VSjet_2", &byVVVLooseDeepTau2017v2p1VSjet_2, &b_byVVVLooseDeepTau2017v2p1VSjet_2);
   fChain->SetBranchAddress("byMediumDeepTau2017v2p1VSjet_2", &byMediumDeepTau2017v2p1VSjet_2, &b_byMediumDeepTau2017v2p1VSjet_2);
   fChain->SetBranchAddress("acotautau_refitbs_00", &acotautau_refitbs_00, &b_acotautau_refitbs_00);
   fChain->SetBranchAddress("acotautau_refitbs_01", &acotautau_refitbs_01, &b_acotautau_refitbs_01);
   fChain->SetBranchAddress("acotautau_helix_00", &acotautau_helix_00, &b_acotautau_helix_00);
   fChain->SetBranchAddress("acotautau_helix_01", &acotautau_helix_01, &b_acotautau_helix_01);
   fChain->SetBranchAddress("acotautau_bs_00", &acotautau_bs_00, &b_acotautau_bs_00);
   fChain->SetBranchAddress("acotautau_bs_01", &acotautau_bs_01, &b_acotautau_bs_01);
   fChain->SetBranchAddress("acotautau_00", &acotautau_00, &b_acotautau_00);
   fChain->SetBranchAddress("acotautau_01", &acotautau_01, &b_acotautau_01);
   fChain->SetBranchAddress("acotautau_refitbs_uncorr_00", &acotautau_refitbs_uncorr_00, &b_acotautau_refitbs_uncorr_00);
   fChain->SetBranchAddress("acotautau_refitbs_uncorr_01", &acotautau_refitbs_uncorr_01, &b_acotautau_refitbs_uncorr_01);
   fChain->SetBranchAddress("acotautau_helix_uncorr_00", &acotautau_helix_uncorr_00, &b_acotautau_helix_uncorr_00);
   fChain->SetBranchAddress("acotautau_helix_uncorr_01", &acotautau_helix_uncorr_01, &b_acotautau_helix_uncorr_01);
   fChain->SetBranchAddress("alpha_IP_1", &alpha_IP_1, &b_alpha_IP_1);
   fChain->SetBranchAddress("alpha_IP_uncorr_1", &alpha_IP_uncorr_1, &b_alpha_IP_uncorr_1);
   fChain->SetBranchAddress("alpha_plane_1", &alpha_plane_1, &b_alpha_plane_1);
   fChain->SetBranchAddress("alpha_IP_2", &alpha_IP_2, &b_alpha_IP_2);
   fChain->SetBranchAddress("alpha_IP_uncorr_2", &alpha_IP_uncorr_2, &b_alpha_IP_uncorr_2);
   fChain->SetBranchAddress("alpha_plane_2", &alpha_plane_2, &b_alpha_plane_2);
   fChain->SetBranchAddress("alphaminus", &alphaminus, &b_alphaminus);
   fChain->SetBranchAddress("alphaminus_uncorr", &alphaminus_uncorr, &b_alphaminus_uncorr);
   fChain->SetBranchAddress("xsec_lumi_weight", &xsec_lumi_weight, &b_xsec_lumi_weight);
   fChain->SetBranchAddress("prefiring_weight", &prefiring_weight, &b_prefiring_weight);
   fChain->SetBranchAddress("htxs_reco_flag_ggh", &htxs_reco_flag_ggh, &b_htxs_reco_flag_ggh);
   fChain->SetBranchAddress("htxs_reco_flag_qqh", &htxs_reco_flag_qqh, &b_htxs_reco_flag_qqh);
   fChain->SetBranchAddress("ff_nom", &ff_nom, &b_ff_nom);
   fChain->SetBranchAddress("ff_mva", &ff_mva, &b_ff_mva);
   fChain->SetBranchAddress("ff_sys", &ff_sys, &b_ff_sys);
   fChain->SetBranchAddress("gen_sm_htt125", &gen_sm_htt125, &b_gen_sm_htt125);
   fChain->SetBranchAddress("gen_ps_htt125", &gen_ps_htt125, &b_gen_ps_htt125);
   fChain->SetBranchAddress("gen_mm_htt125", &gen_mm_htt125, &b_gen_mm_htt125);
   fChain->SetBranchAddress("weight_CMS_htt_dyShape_13TeVDown", &weight_CMS_htt_dyShape_13TeVDown, &b_weight_CMS_htt_dyShape_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_htt_dyShape_13TeVUp", &weight_CMS_htt_dyShape_13TeVUp, &b_weight_CMS_htt_dyShape_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_htt_ttbarShape_13TeVDown", &weight_CMS_htt_ttbarShape_13TeVDown, &b_weight_CMS_htt_ttbarShape_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_htt_ttbarShape_13TeVUp", &weight_CMS_htt_ttbarShape_13TeVUp, &b_weight_CMS_htt_ttbarShape_13TeVUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltUp", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltUp, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltUp", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltUp, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltUp", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltUp, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltUp", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltUp, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltUp", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltUp, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltUp", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltUp, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtUp", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtUp, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtUp", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtUp, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtUp", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtUp, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtUp", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtUp, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtUp", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtUp, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtUp", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtUp, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Up", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Up, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Up", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Up, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Up", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Up, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Up", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Up, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Up", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Up, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Up", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Up, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Up", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Up, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Up", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Up, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Up", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Up, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Up", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Up, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Up", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Up, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Up", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Up, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Up", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Up, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Up", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Up, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Up", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Up, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Up", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Up, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Up", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Up, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Up", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Up, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Up", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Up, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Up", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Up, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Up", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Up, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Up", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Up, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Up", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Up, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Up", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Up, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltDown", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltDown, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltDown", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltDown, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltDown", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltDown, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltDown", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltDown, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltDown", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltDown, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltDown", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltDown, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtDown", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtDown, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtDown", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtDown, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtDown", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtDown, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtDown", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtDown, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtDown", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtDown, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtDown", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtDown, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Down", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Down, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Down", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Down, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Down", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Down, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Down", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Down, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Down", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Down, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Down", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Down, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Down", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Down, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Down", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Down, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Down", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Down, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Down", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Down, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Down", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Down, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Down", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Down, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Down", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Down, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Down", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Down, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Down", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Down, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Down", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Down, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Down", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Down, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Down", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Down, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Down", &weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Down, &b_weight_ff_mt_wjets_stat_unc1_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Down", &weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Down, &b_weight_ff_mt_qcd_stat_unc1_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Down", &weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Down, &b_weight_ff_mt_wjets_stat_unc1_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Down", &weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Down, &b_weight_ff_mt_qcd_stat_unc1_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Down", &weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Down, &b_weight_ff_mt_wjets_stat_unc1_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Down", &weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Down, &b_weight_ff_mt_qcd_stat_unc1_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltUp", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltUp, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltUp", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltUp, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltUp", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltUp, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltUp", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltUp, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltUp", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltUp, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltUp", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltUp, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtUp", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtUp, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtUp", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtUp, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtUp", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtUp, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtUp", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtUp, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtUp", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtUp, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtUp", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtUp, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Up", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Up, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Up", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Up, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Up", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Up, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Up", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Up, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Up", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Up, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Up", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Up, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Up", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Up, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Up", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Up, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Up", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Up, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Up", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Up, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Up", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Up, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Up", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Up, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Up", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Up, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Up", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Up, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Up", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Up, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Up", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Up, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Up", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Up, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Up", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Up, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Up", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Up, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Up", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Up, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Up", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Up, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Up", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Up, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Up", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Up, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Up", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Up, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltDown", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltDown, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltDown", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltDown, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltDown", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltDown, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltDown", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltDown, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltDown", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltDown, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltDown", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltDown, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtDown", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtDown, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtDown", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtDown, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtDown", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtDown, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtDown", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtDown, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtDown", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtDown, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtDown", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtDown, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Down", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Down, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Down", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Down, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Down", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Down, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Down", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Down, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Down", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Down, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Down", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Down, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Down", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Down, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Down", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Down, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Down", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Down, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Down", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Down, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Down", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Down, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Down", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Down, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Down", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Down, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Down", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Down, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Down", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Down, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Down", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Down, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Down", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Down, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Down", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Down, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Down", &weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Down, &b_weight_ff_mt_wjets_stat_unc2_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Down", &weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Down, &b_weight_ff_mt_qcd_stat_unc2_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Down", &weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Down, &b_weight_ff_mt_wjets_stat_unc2_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Down", &weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Down, &b_weight_ff_mt_qcd_stat_unc2_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Down", &weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Down, &b_weight_ff_mt_wjets_stat_unc2_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Down", &weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Down, &b_weight_ff_mt_qcd_stat_unc2_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_mt_qcd_met_closure_systUp", &weight_ff_mt_qcd_met_closure_systUp, &b_weight_ff_mt_qcd_met_closure_systUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_met_closure_systUp", &weight_ff_mt_wjets_met_closure_systUp, &b_weight_ff_mt_wjets_met_closure_systUp);
   fChain->SetBranchAddress("weight_ff_mt_ttbar_met_closure_systUp", &weight_ff_mt_ttbar_met_closure_systUp, &b_weight_ff_mt_ttbar_met_closure_systUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_met_closure_systDown", &weight_ff_mt_qcd_met_closure_systDown, &b_weight_ff_mt_qcd_met_closure_systDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_met_closure_systDown", &weight_ff_mt_wjets_met_closure_systDown, &b_weight_ff_mt_wjets_met_closure_systDown);
   fChain->SetBranchAddress("weight_ff_mt_ttbar_met_closure_systDown", &weight_ff_mt_ttbar_met_closure_systDown, &b_weight_ff_mt_ttbar_met_closure_systDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_l_pt_closure_systUp", &weight_ff_mt_qcd_l_pt_closure_systUp, &b_weight_ff_mt_qcd_l_pt_closure_systUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_l_pt_closure_systDown", &weight_ff_mt_qcd_l_pt_closure_systDown, &b_weight_ff_mt_qcd_l_pt_closure_systDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_l_pt_closure_systUp", &weight_ff_mt_wjets_l_pt_closure_systUp, &b_weight_ff_mt_wjets_l_pt_closure_systUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_l_pt_closure_systDown", &weight_ff_mt_wjets_l_pt_closure_systDown, &b_weight_ff_mt_wjets_l_pt_closure_systDown);
   fChain->SetBranchAddress("weight_ff_mt_qcd_systUp", &weight_ff_mt_qcd_systUp, &b_weight_ff_mt_qcd_systUp);
   fChain->SetBranchAddress("weight_ff_mt_qcd_systDown", &weight_ff_mt_qcd_systDown, &b_weight_ff_mt_qcd_systDown);
   fChain->SetBranchAddress("weight_ff_mt_wjets_systUp", &weight_ff_mt_wjets_systUp, &b_weight_ff_mt_wjets_systUp);
   fChain->SetBranchAddress("weight_ff_mt_wjets_systDown", &weight_ff_mt_wjets_systDown, &b_weight_ff_mt_wjets_systDown);
   fChain->SetBranchAddress("weight_ff_mt_ttbar_systUp", &weight_ff_mt_ttbar_systUp, &b_weight_ff_mt_ttbar_systUp);
   fChain->SetBranchAddress("weight_ff_mt_ttbar_systDown", &weight_ff_mt_ttbar_systDown, &b_weight_ff_mt_ttbar_systDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltUp", &weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltUp, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltUp", &weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltUp, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltUp", &weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltUp, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltUp", &weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltUp, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltUp", &weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltUp, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltUp", &weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltUp, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtUp", &weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtUp, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtUp", &weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtUp, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtUp", &weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtUp, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtUp", &weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtUp, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtUp", &weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtUp, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtUp", &weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtUp, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm1Up", &weight_ff_et_wjets_stat_unc1_njets0_mvadm1Up, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm1Up", &weight_ff_et_qcd_stat_unc1_njets0_mvadm1Up, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm1Up", &weight_ff_et_wjets_stat_unc1_njets1_mvadm1Up, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm1Up", &weight_ff_et_qcd_stat_unc1_njets1_mvadm1Up, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm1Up", &weight_ff_et_wjets_stat_unc1_njets2_mvadm1Up, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm1Up", &weight_ff_et_qcd_stat_unc1_njets2_mvadm1Up, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm2Up", &weight_ff_et_wjets_stat_unc1_njets0_mvadm2Up, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm2Up", &weight_ff_et_qcd_stat_unc1_njets0_mvadm2Up, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm2Up", &weight_ff_et_wjets_stat_unc1_njets1_mvadm2Up, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm2Up", &weight_ff_et_qcd_stat_unc1_njets1_mvadm2Up, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm2Up", &weight_ff_et_wjets_stat_unc1_njets2_mvadm2Up, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm2Up", &weight_ff_et_qcd_stat_unc1_njets2_mvadm2Up, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm10Up", &weight_ff_et_wjets_stat_unc1_njets0_mvadm10Up, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm10Up", &weight_ff_et_qcd_stat_unc1_njets0_mvadm10Up, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm10Up", &weight_ff_et_wjets_stat_unc1_njets1_mvadm10Up, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm10Up", &weight_ff_et_qcd_stat_unc1_njets1_mvadm10Up, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm10Up", &weight_ff_et_wjets_stat_unc1_njets2_mvadm10Up, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm10Up", &weight_ff_et_qcd_stat_unc1_njets2_mvadm10Up, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm11Up", &weight_ff_et_wjets_stat_unc1_njets0_mvadm11Up, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm11Up", &weight_ff_et_qcd_stat_unc1_njets0_mvadm11Up, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm11Up", &weight_ff_et_wjets_stat_unc1_njets1_mvadm11Up, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm11Up", &weight_ff_et_qcd_stat_unc1_njets1_mvadm11Up, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm11Up", &weight_ff_et_wjets_stat_unc1_njets2_mvadm11Up, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm11Up", &weight_ff_et_qcd_stat_unc1_njets2_mvadm11Up, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltDown", &weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltDown, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltDown", &weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltDown, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltDown", &weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltDown, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltDown", &weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltDown, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltDown", &weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltDown, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltDown", &weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltDown, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtDown", &weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtDown, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtDown", &weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtDown, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtDown", &weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtDown, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtDown", &weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtDown, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtDown", &weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtDown, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtDown", &weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtDown, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm1Down", &weight_ff_et_wjets_stat_unc1_njets0_mvadm1Down, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm1Down", &weight_ff_et_qcd_stat_unc1_njets0_mvadm1Down, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm1Down", &weight_ff_et_wjets_stat_unc1_njets1_mvadm1Down, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm1Down", &weight_ff_et_qcd_stat_unc1_njets1_mvadm1Down, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm1Down", &weight_ff_et_wjets_stat_unc1_njets2_mvadm1Down, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm1Down", &weight_ff_et_qcd_stat_unc1_njets2_mvadm1Down, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm2Down", &weight_ff_et_wjets_stat_unc1_njets0_mvadm2Down, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm2Down", &weight_ff_et_qcd_stat_unc1_njets0_mvadm2Down, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm2Down", &weight_ff_et_wjets_stat_unc1_njets1_mvadm2Down, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm2Down", &weight_ff_et_qcd_stat_unc1_njets1_mvadm2Down, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm2Down", &weight_ff_et_wjets_stat_unc1_njets2_mvadm2Down, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm2Down", &weight_ff_et_qcd_stat_unc1_njets2_mvadm2Down, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm10Down", &weight_ff_et_wjets_stat_unc1_njets0_mvadm10Down, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm10Down", &weight_ff_et_qcd_stat_unc1_njets0_mvadm10Down, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm10Down", &weight_ff_et_wjets_stat_unc1_njets1_mvadm10Down, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm10Down", &weight_ff_et_qcd_stat_unc1_njets1_mvadm10Down, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm10Down", &weight_ff_et_wjets_stat_unc1_njets2_mvadm10Down, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm10Down", &weight_ff_et_qcd_stat_unc1_njets2_mvadm10Down, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets0_mvadm11Down", &weight_ff_et_wjets_stat_unc1_njets0_mvadm11Down, &b_weight_ff_et_wjets_stat_unc1_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets0_mvadm11Down", &weight_ff_et_qcd_stat_unc1_njets0_mvadm11Down, &b_weight_ff_et_qcd_stat_unc1_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets1_mvadm11Down", &weight_ff_et_wjets_stat_unc1_njets1_mvadm11Down, &b_weight_ff_et_wjets_stat_unc1_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets1_mvadm11Down", &weight_ff_et_qcd_stat_unc1_njets1_mvadm11Down, &b_weight_ff_et_qcd_stat_unc1_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc1_njets2_mvadm11Down", &weight_ff_et_wjets_stat_unc1_njets2_mvadm11Down, &b_weight_ff_et_wjets_stat_unc1_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc1_njets2_mvadm11Down", &weight_ff_et_qcd_stat_unc1_njets2_mvadm11Down, &b_weight_ff_et_qcd_stat_unc1_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltUp", &weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltUp, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltUp", &weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltUp, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltUp", &weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltUp, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltUp", &weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltUp, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltUp", &weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltUp, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltUp", &weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltUp, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtUp", &weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtUp, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtUp", &weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtUp, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtUp", &weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtUp, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtUp", &weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtUp, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtUp", &weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtUp, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtUp", &weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtUp, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm1Up", &weight_ff_et_wjets_stat_unc2_njets0_mvadm1Up, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm1Up", &weight_ff_et_qcd_stat_unc2_njets0_mvadm1Up, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm1Up", &weight_ff_et_wjets_stat_unc2_njets1_mvadm1Up, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm1Up", &weight_ff_et_qcd_stat_unc2_njets1_mvadm1Up, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm1Up", &weight_ff_et_wjets_stat_unc2_njets2_mvadm1Up, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm1Up", &weight_ff_et_qcd_stat_unc2_njets2_mvadm1Up, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm1Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm2Up", &weight_ff_et_wjets_stat_unc2_njets0_mvadm2Up, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm2Up", &weight_ff_et_qcd_stat_unc2_njets0_mvadm2Up, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm2Up", &weight_ff_et_wjets_stat_unc2_njets1_mvadm2Up, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm2Up", &weight_ff_et_qcd_stat_unc2_njets1_mvadm2Up, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm2Up", &weight_ff_et_wjets_stat_unc2_njets2_mvadm2Up, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm2Up", &weight_ff_et_qcd_stat_unc2_njets2_mvadm2Up, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm2Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm10Up", &weight_ff_et_wjets_stat_unc2_njets0_mvadm10Up, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm10Up", &weight_ff_et_qcd_stat_unc2_njets0_mvadm10Up, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm10Up", &weight_ff_et_wjets_stat_unc2_njets1_mvadm10Up, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm10Up", &weight_ff_et_qcd_stat_unc2_njets1_mvadm10Up, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm10Up", &weight_ff_et_wjets_stat_unc2_njets2_mvadm10Up, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm10Up", &weight_ff_et_qcd_stat_unc2_njets2_mvadm10Up, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm10Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm11Up", &weight_ff_et_wjets_stat_unc2_njets0_mvadm11Up, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm11Up", &weight_ff_et_qcd_stat_unc2_njets0_mvadm11Up, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm11Up", &weight_ff_et_wjets_stat_unc2_njets1_mvadm11Up, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm11Up", &weight_ff_et_qcd_stat_unc2_njets1_mvadm11Up, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm11Up", &weight_ff_et_wjets_stat_unc2_njets2_mvadm11Up, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm11Up", &weight_ff_et_qcd_stat_unc2_njets2_mvadm11Up, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm11Up);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltDown", &weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltDown, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltDown", &weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltDown, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltDown", &weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltDown, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltDown", &weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltDown, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltDown", &weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltDown, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltDown", &weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltDown, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_ltDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtDown", &weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtDown, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtDown", &weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtDown, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtDown", &weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtDown, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtDown", &weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtDown, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtDown", &weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtDown, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtDown", &weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtDown, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm0_sig_gtDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm1Down", &weight_ff_et_wjets_stat_unc2_njets0_mvadm1Down, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm1Down", &weight_ff_et_qcd_stat_unc2_njets0_mvadm1Down, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm1Down", &weight_ff_et_wjets_stat_unc2_njets1_mvadm1Down, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm1Down", &weight_ff_et_qcd_stat_unc2_njets1_mvadm1Down, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm1Down", &weight_ff_et_wjets_stat_unc2_njets2_mvadm1Down, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm1Down", &weight_ff_et_qcd_stat_unc2_njets2_mvadm1Down, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm1Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm2Down", &weight_ff_et_wjets_stat_unc2_njets0_mvadm2Down, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm2Down", &weight_ff_et_qcd_stat_unc2_njets0_mvadm2Down, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm2Down", &weight_ff_et_wjets_stat_unc2_njets1_mvadm2Down, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm2Down", &weight_ff_et_qcd_stat_unc2_njets1_mvadm2Down, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm2Down", &weight_ff_et_wjets_stat_unc2_njets2_mvadm2Down, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm2Down", &weight_ff_et_qcd_stat_unc2_njets2_mvadm2Down, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm2Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm10Down", &weight_ff_et_wjets_stat_unc2_njets0_mvadm10Down, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm10Down", &weight_ff_et_qcd_stat_unc2_njets0_mvadm10Down, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm10Down", &weight_ff_et_wjets_stat_unc2_njets1_mvadm10Down, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm10Down", &weight_ff_et_qcd_stat_unc2_njets1_mvadm10Down, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm10Down", &weight_ff_et_wjets_stat_unc2_njets2_mvadm10Down, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm10Down", &weight_ff_et_qcd_stat_unc2_njets2_mvadm10Down, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm10Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets0_mvadm11Down", &weight_ff_et_wjets_stat_unc2_njets0_mvadm11Down, &b_weight_ff_et_wjets_stat_unc2_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets0_mvadm11Down", &weight_ff_et_qcd_stat_unc2_njets0_mvadm11Down, &b_weight_ff_et_qcd_stat_unc2_njets0_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets1_mvadm11Down", &weight_ff_et_wjets_stat_unc2_njets1_mvadm11Down, &b_weight_ff_et_wjets_stat_unc2_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets1_mvadm11Down", &weight_ff_et_qcd_stat_unc2_njets1_mvadm11Down, &b_weight_ff_et_qcd_stat_unc2_njets1_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_wjets_stat_unc2_njets2_mvadm11Down", &weight_ff_et_wjets_stat_unc2_njets2_mvadm11Down, &b_weight_ff_et_wjets_stat_unc2_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_stat_unc2_njets2_mvadm11Down", &weight_ff_et_qcd_stat_unc2_njets2_mvadm11Down, &b_weight_ff_et_qcd_stat_unc2_njets2_mvadm11Down);
   fChain->SetBranchAddress("weight_ff_et_qcd_met_closure_systUp", &weight_ff_et_qcd_met_closure_systUp, &b_weight_ff_et_qcd_met_closure_systUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_met_closure_systUp", &weight_ff_et_wjets_met_closure_systUp, &b_weight_ff_et_wjets_met_closure_systUp);
   fChain->SetBranchAddress("weight_ff_et_ttbar_met_closure_systUp", &weight_ff_et_ttbar_met_closure_systUp, &b_weight_ff_et_ttbar_met_closure_systUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_met_closure_systDown", &weight_ff_et_qcd_met_closure_systDown, &b_weight_ff_et_qcd_met_closure_systDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_met_closure_systDown", &weight_ff_et_wjets_met_closure_systDown, &b_weight_ff_et_wjets_met_closure_systDown);
   fChain->SetBranchAddress("weight_ff_et_ttbar_met_closure_systDown", &weight_ff_et_ttbar_met_closure_systDown, &b_weight_ff_et_ttbar_met_closure_systDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_l_pt_closure_systUp", &weight_ff_et_qcd_l_pt_closure_systUp, &b_weight_ff_et_qcd_l_pt_closure_systUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_l_pt_closure_systDown", &weight_ff_et_qcd_l_pt_closure_systDown, &b_weight_ff_et_qcd_l_pt_closure_systDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_l_pt_closure_systUp", &weight_ff_et_wjets_l_pt_closure_systUp, &b_weight_ff_et_wjets_l_pt_closure_systUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_l_pt_closure_systDown", &weight_ff_et_wjets_l_pt_closure_systDown, &b_weight_ff_et_wjets_l_pt_closure_systDown);
   fChain->SetBranchAddress("weight_ff_et_qcd_systUp", &weight_ff_et_qcd_systUp, &b_weight_ff_et_qcd_systUp);
   fChain->SetBranchAddress("weight_ff_et_qcd_systDown", &weight_ff_et_qcd_systDown, &b_weight_ff_et_qcd_systDown);
   fChain->SetBranchAddress("weight_ff_et_wjets_systUp", &weight_ff_et_wjets_systUp, &b_weight_ff_et_wjets_systUp);
   fChain->SetBranchAddress("weight_ff_et_wjets_systDown", &weight_ff_et_wjets_systDown, &b_weight_ff_et_wjets_systDown);
   fChain->SetBranchAddress("weight_ff_et_ttbar_systUp", &weight_ff_et_ttbar_systUp, &b_weight_ff_et_ttbar_systUp);
   fChain->SetBranchAddress("weight_ff_et_ttbar_systDown", &weight_ff_et_ttbar_systDown, &b_weight_ff_et_ttbar_systDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVUp", &weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVUp, &b_weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVUp", &weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVUp, &b_weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVUp", &weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVUp, &b_weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVUp", &weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVUp, &b_weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVUp", &weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVUp, &b_weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVDown", &weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVDown, &b_weight_CMS_eff_Xtrigger_mt_MVADM0_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVDown", &weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVDown, &b_weight_CMS_eff_Xtrigger_mt_MVADM1_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVDown", &weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVDown, &b_weight_CMS_eff_Xtrigger_mt_MVADM2_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVDown", &weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVDown, &b_weight_CMS_eff_Xtrigger_mt_MVADM10_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVDown", &weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVDown, &b_weight_CMS_eff_Xtrigger_mt_MVADM11_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM0_13TeVUp", &weight_CMS_eff_Xtrigger_et_MVADM0_13TeVUp, &b_weight_CMS_eff_Xtrigger_et_MVADM0_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM1_13TeVUp", &weight_CMS_eff_Xtrigger_et_MVADM1_13TeVUp, &b_weight_CMS_eff_Xtrigger_et_MVADM1_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM2_13TeVUp", &weight_CMS_eff_Xtrigger_et_MVADM2_13TeVUp, &b_weight_CMS_eff_Xtrigger_et_MVADM2_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM10_13TeVUp", &weight_CMS_eff_Xtrigger_et_MVADM10_13TeVUp, &b_weight_CMS_eff_Xtrigger_et_MVADM10_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM11_13TeVUp", &weight_CMS_eff_Xtrigger_et_MVADM11_13TeVUp, &b_weight_CMS_eff_Xtrigger_et_MVADM11_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM0_13TeVDown", &weight_CMS_eff_Xtrigger_et_MVADM0_13TeVDown, &b_weight_CMS_eff_Xtrigger_et_MVADM0_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM1_13TeVDown", &weight_CMS_eff_Xtrigger_et_MVADM1_13TeVDown, &b_weight_CMS_eff_Xtrigger_et_MVADM1_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM2_13TeVDown", &weight_CMS_eff_Xtrigger_et_MVADM2_13TeVDown, &b_weight_CMS_eff_Xtrigger_et_MVADM2_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM10_13TeVDown", &weight_CMS_eff_Xtrigger_et_MVADM10_13TeVDown, &b_weight_CMS_eff_Xtrigger_et_MVADM10_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_Xtrigger_et_MVADM11_13TeVDown", &weight_CMS_eff_Xtrigger_et_MVADM11_13TeVDown, &b_weight_CMS_eff_Xtrigger_et_MVADM11_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM0_13TeVUp", &weight_CMS_eff_t_pTlow_MVADM0_13TeVUp, &b_weight_CMS_eff_t_pTlow_MVADM0_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM1_13TeVUp", &weight_CMS_eff_t_pTlow_MVADM1_13TeVUp, &b_weight_CMS_eff_t_pTlow_MVADM1_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM2_13TeVUp", &weight_CMS_eff_t_pTlow_MVADM2_13TeVUp, &b_weight_CMS_eff_t_pTlow_MVADM2_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM10_13TeVUp", &weight_CMS_eff_t_pTlow_MVADM10_13TeVUp, &b_weight_CMS_eff_t_pTlow_MVADM10_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM11_13TeVUp", &weight_CMS_eff_t_pTlow_MVADM11_13TeVUp, &b_weight_CMS_eff_t_pTlow_MVADM11_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM0_13TeVUp", &weight_CMS_eff_t_pThigh_MVADM0_13TeVUp, &b_weight_CMS_eff_t_pThigh_MVADM0_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM1_13TeVUp", &weight_CMS_eff_t_pThigh_MVADM1_13TeVUp, &b_weight_CMS_eff_t_pThigh_MVADM1_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM2_13TeVUp", &weight_CMS_eff_t_pThigh_MVADM2_13TeVUp, &b_weight_CMS_eff_t_pThigh_MVADM2_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM10_13TeVUp", &weight_CMS_eff_t_pThigh_MVADM10_13TeVUp, &b_weight_CMS_eff_t_pThigh_MVADM10_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM11_13TeVUp", &weight_CMS_eff_t_pThigh_MVADM11_13TeVUp, &b_weight_CMS_eff_t_pThigh_MVADM11_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM0_13TeVDown", &weight_CMS_eff_t_pTlow_MVADM0_13TeVDown, &b_weight_CMS_eff_t_pTlow_MVADM0_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM1_13TeVDown", &weight_CMS_eff_t_pTlow_MVADM1_13TeVDown, &b_weight_CMS_eff_t_pTlow_MVADM1_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM2_13TeVDown", &weight_CMS_eff_t_pTlow_MVADM2_13TeVDown, &b_weight_CMS_eff_t_pTlow_MVADM2_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM10_13TeVDown", &weight_CMS_eff_t_pTlow_MVADM10_13TeVDown, &b_weight_CMS_eff_t_pTlow_MVADM10_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pTlow_MVADM11_13TeVDown", &weight_CMS_eff_t_pTlow_MVADM11_13TeVDown, &b_weight_CMS_eff_t_pTlow_MVADM11_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM0_13TeVDown", &weight_CMS_eff_t_pThigh_MVADM0_13TeVDown, &b_weight_CMS_eff_t_pThigh_MVADM0_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM1_13TeVDown", &weight_CMS_eff_t_pThigh_MVADM1_13TeVDown, &b_weight_CMS_eff_t_pThigh_MVADM1_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM2_13TeVDown", &weight_CMS_eff_t_pThigh_MVADM2_13TeVDown, &b_weight_CMS_eff_t_pThigh_MVADM2_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM10_13TeVDown", &weight_CMS_eff_t_pThigh_MVADM10_13TeVDown, &b_weight_CMS_eff_t_pThigh_MVADM10_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_eff_t_pThigh_MVADM11_13TeVDown", &weight_CMS_eff_t_pThigh_MVADM11_13TeVDown, &b_weight_CMS_eff_t_pThigh_MVADM11_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM0_13TeVUp", &weight_CMS_mufake_mt_MVADM0_13TeVUp, &b_weight_CMS_mufake_mt_MVADM0_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM1_13TeVUp", &weight_CMS_mufake_mt_MVADM1_13TeVUp, &b_weight_CMS_mufake_mt_MVADM1_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM2_13TeVUp", &weight_CMS_mufake_mt_MVADM2_13TeVUp, &b_weight_CMS_mufake_mt_MVADM2_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM10_13TeVUp", &weight_CMS_mufake_mt_MVADM10_13TeVUp, &b_weight_CMS_mufake_mt_MVADM10_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM11_13TeVUp", &weight_CMS_mufake_mt_MVADM11_13TeVUp, &b_weight_CMS_mufake_mt_MVADM11_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM0_13TeVDown", &weight_CMS_mufake_mt_MVADM0_13TeVDown, &b_weight_CMS_mufake_mt_MVADM0_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM1_13TeVDown", &weight_CMS_mufake_mt_MVADM1_13TeVDown, &b_weight_CMS_mufake_mt_MVADM1_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM2_13TeVDown", &weight_CMS_mufake_mt_MVADM2_13TeVDown, &b_weight_CMS_mufake_mt_MVADM2_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM10_13TeVDown", &weight_CMS_mufake_mt_MVADM10_13TeVDown, &b_weight_CMS_mufake_mt_MVADM10_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_mufake_mt_MVADM11_13TeVDown", &weight_CMS_mufake_mt_MVADM11_13TeVDown, &b_weight_CMS_mufake_mt_MVADM11_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM0_13TeVUp", &weight_CMS_efake_et_MVADM0_13TeVUp, &b_weight_CMS_efake_et_MVADM0_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM1_13TeVUp", &weight_CMS_efake_et_MVADM1_13TeVUp, &b_weight_CMS_efake_et_MVADM1_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM2_13TeVUp", &weight_CMS_efake_et_MVADM2_13TeVUp, &b_weight_CMS_efake_et_MVADM2_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM10_13TeVUp", &weight_CMS_efake_et_MVADM10_13TeVUp, &b_weight_CMS_efake_et_MVADM10_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM11_13TeVUp", &weight_CMS_efake_et_MVADM11_13TeVUp, &b_weight_CMS_efake_et_MVADM11_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM0_13TeVDown", &weight_CMS_efake_et_MVADM0_13TeVDown, &b_weight_CMS_efake_et_MVADM0_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM1_13TeVDown", &weight_CMS_efake_et_MVADM1_13TeVDown, &b_weight_CMS_efake_et_MVADM1_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM2_13TeVDown", &weight_CMS_efake_et_MVADM2_13TeVDown, &b_weight_CMS_efake_et_MVADM2_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM10_13TeVDown", &weight_CMS_efake_et_MVADM10_13TeVDown, &b_weight_CMS_efake_et_MVADM10_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_efake_et_MVADM11_13TeVDown", &weight_CMS_efake_et_MVADM11_13TeVDown, &b_weight_CMS_efake_et_MVADM11_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_scale_gg_13TeVUp", &weight_CMS_scale_gg_13TeVUp, &b_weight_CMS_scale_gg_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_scale_gg_13TeVDown", &weight_CMS_scale_gg_13TeVDown, &b_weight_CMS_scale_gg_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_PS_ISR_ggH_13TeVUp", &weight_CMS_PS_ISR_ggH_13TeVUp, &b_weight_CMS_PS_ISR_ggH_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_PS_ISR_ggH_13TeVDown", &weight_CMS_PS_ISR_ggH_13TeVDown, &b_weight_CMS_PS_ISR_ggH_13TeVDown);
   fChain->SetBranchAddress("weight_CMS_PS_FSR_ggH_13TeVUp", &weight_CMS_PS_FSR_ggH_13TeVUp, &b_weight_CMS_PS_FSR_ggH_13TeVUp);
   fChain->SetBranchAddress("weight_CMS_PS_FSR_ggH_13TeVDown", &weight_CMS_PS_FSR_ggH_13TeVDown, &b_weight_CMS_PS_FSR_ggH_13TeVDown);
   fChain->SetBranchAddress("event_weight", &event_weight, &b_event_weight);
   fChain->SetBranchAddress("target", &target, &b_target);
   fChain->SetBranchAddress("train_weight", &train_weight, &b_train_weight);
   fChain->SetBranchAddress("predicted_class", &predicted_class, &b_predicted_class);
   fChain->SetBranchAddress("predicted_prob", &predicted_prob, &b_predicted_prob);
   fChain->SetBranchAddress("__index__", &__index__, &b___index__);
   Notify();
}

Bool_t TauCheck::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void TauCheck::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t TauCheck::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef TauCheck_cxx
