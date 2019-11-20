#include "CombineHarvester/HTTSMCP2016/interface/HttSystematics_SMRun2.h"
#include <vector>
#include <string>
#include "CombineHarvester/CombineTools/interface/Systematics.h"
#include "CombineHarvester/CombineTools/interface/Process.h"
#include "CombineHarvester/CombineTools/interface/Utilities.h"

using namespace std;

namespace ch {
    
    using ch::syst::SystMap;
    using ch::syst::SystMapAsymm;
    using ch::syst::era;
    using ch::syst::channel;
    using ch::syst::bin_id;
    using ch::syst::process;
    using ch::syst::bin;
    using ch::JoinStr;
    
    void __attribute__((optimize("O0"))) AddSMRun2Systematics(CombineHarvester & cb, int control_region, bool ttbar_fit, bool no_jec_split) {
        // Create a CombineHarvester clone that only contains the signal
        // categories
        //
        // cb_sig is unused at the moment, (was it ever used in this analysis?) delete?
        //CombineHarvester cb_sig = cb.cp();
        //
        //
        
        
        std::vector<std::string> sig_procs = {"ggH_htt","qqH_htt","WH_htt","ZH_htt","ggHsm_htt", "ggHps_htt", "ggHmm_htt","qqHsm_htt", "qqHps_htt", "qqHmm_htt","qqH_htt125","qqHsm_htt125", "qqHps_htt", "qqHmm_htt","WH_htt125","ZH_htt125","WHsm_htt125","ZHsm_htt125", "WHps_htt","ZHps_htt","WHmm_htt","ZHmm_htt","WHsm_htt","ZHsm_htt","WHps_htt","ZHps_htt","WHmm_htt","ZHmm_htt", "ggHsm_jhu_htt","ggHps_jhu_htt","ggHmm_jhu_htt","ggH_ph_htt"};
        std::vector<std::string> ggH_sig_procs = {"ggH_htt","ggHsm_htt", "ggHps_htt", "ggHmm_htt","ggHsm_jhu_htt","ggHps_jhu_htt","ggHmm_jhu_htt","ggH_ph_htt"};
        std::vector<std::string> qqH_sig_procs = {"qqH_htt","qqHsm_htt", "qqHps_htt", "qqHmm_htt", "qqH_htt125","qqHsm_htt125", "qqHps_htt", "qqHmm_htt"};
        
        // N.B. when adding this list of backgrounds to a nuisance, only
        // the backgrounds that are included in the background process
        // defined in MorphingSM2016.cpp are included in the actual DCs
        // This is a list of all MC based backgrounds
        // QCD is explicitly excluded
        std::vector<std::string> all_mc_bkgs = {
            "ZL","ZLL","ZJ","ZTT","TTJ","TTT","TT",
            "W","VV","VVT","VVJ",
            "ggH_hww125","qqH_hww125","EWKZ"};
        std::vector<std::string> all_mc_bkgs_no_W = {
            "ZL","ZLL","ZJ","ZTT","TTJ","TTT","TT",
            "VV","VVT","VVJ",
            "ggH_hww125","qqH_hww125","EWKZ"};
        std::vector<std::string> all_mc_bkgs_no_TTJ = {
            "ZL","ZLL","ZJ","ZTT","TTT","TT",
            "VV","VVT","VVJ",
            "ggH_hww125","qqH_hww125","EWKZ"};
        std::vector<std::string> embed = {"EmbedZTT"};
        std::vector<std::string> real_tau_mc_bkgs = {"ZTT","TTT","TT","VV","VVT"};
            
        //##############################################################################
        //  lumi
        //##############################################################################
        
        // total lumi uncertainty is 2.5% for 2016, 2.3% for 2017, 2.5% for 2018
        //
        // for correlations using https://twiki.cern.ch/twiki/bin/view/CMS/TWikiLUM#LumiComb

        // uncorrelated parts 2.2%, 2.0%, 1.5%
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).channel({"tt","tt_2016","et","et_2016","mt","mt_2016","em","em_2016","ttbar","ttbar_2016"}).AddSyst(cb,
                                            "lumi_2016_13TeV", "lnN", SystMap<>::init(1.022));
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).channel({"tt_2017","mt_2017","et_2017","em_2017","ttbar_2017"}).AddSyst(cb,
                                            "lumi_2017_13TeV", "lnN", SystMap<>::init(1.020));
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).channel({"tt_2018","mt_2018","et_2018","em_2018","ttbar_2018"}).AddSyst(cb,
                                            "lumi_2018_13TeV", "lnN", SystMap<>::init(1.015));

        // correlated parts, 1.2%, 1.1%, 2.0%
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).channel({"tt","tt_2016","et","et_2016","mt","mt_2016","em","em_2016","ttbar","ttbar_2016"}).AddSyst(cb,
                                            "lumi_13TeV", "lnN", SystMap<>::init(1.012));
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).channel({"tt_2017","mt_2017","et_2017","em_2017","ttbar_2017"}).AddSyst(cb,
                                            "lumi_13TeV", "lnN", SystMap<>::init(1.011));
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).channel({"tt_2018","mt_2018","et_2018","em_2018","ttbar_2018"}).AddSyst(cb,
                                            "lumi_13TeV", "lnN", SystMap<>::init(1.020));

        //##############################################################################
        //  trigger   
        //##############################################################################
        
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed})).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,
                                             "CMS_eff_trigger_mt_13TeV", "lnN", SystMap<>::init(1.02));
        
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed})).channel({"et","et_2016","et_2017","et_2018"}).AddSyst(cb,
                                             "CMS_eff_trigger_et_13TeV", "lnN", SystMap<>::init(1.02)); 
        
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs,embed})).channel({"em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}).AddSyst(cb,
                                             "CMS_eff_trigger_em_13TeV", "lnN", SystMap<>::init(1.02)); 


        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_trg_DM0_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_trg_DM1_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_trg_DM10_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_trg_DM11_13TeV", "shape", SystMap<>::init(1.00));


        // additional uncertainties due to tau SF on cross-triggers - decorrelated for embedded samples in Morphing code
        //  Add back when this is working properly (i.e when you have fixed issue with nan values in weights)
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_mt_DM0_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_mt_DM1_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_mt_DM10_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_mt_DM11_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"et_2017","et_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_et_DM0_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"et_2017","et_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_et_DM1_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"et_2017","et_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_et_DM10_13TeV", "shape", SystMap<>::init(1.00));
//        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs,embed})).channel({"et_2017","et_2018"}).AddSyst(cb,"CMS_eff_Xtrigger_et_DM11_13TeV", "shape", SystMap<>::init(1.00));        

        //##############################################################################
        //  Electron, muon and tau Id  efficiencies
        //##############################################################################
        
        cb.cp().AddSyst(cb, "CMS_eff_m", "lnN", SystMap<channel, process>::init
                        ({"mt","mt_2016","mt_2017","mt_2018","em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}, JoinStr({sig_procs, all_mc_bkgs,embed}),  1.02));
        
        // embedded selection efficiency
        cb.cp().AddSyst(cb, "CMS_eff_m_embedsel", "lnN", SystMap<channel, process>::init
                        ({"em","em_2016","em_2017","em_2018","et","et_2016","et_2017","et_2018","tt","tt_2016","tt_2017","tt_2018","mt","mt_2016","mt_2017","mt_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}, embed,  1.04)); 
        
        cb.cp().AddSyst(cb, "CMS_eff_e", "lnN", SystMap<channel, process>::init
                        ({"et","et_2016","et_2017","et_2018","em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}, JoinStr({sig_procs, all_mc_bkgs,embed}),       1.02));


//CMS_eff_m, CMS_eff_e, CMS_eff_t_mt_13TeV, CMS_eff_t_et_13TeV, CMS_eff_t_tt_13TeV

        // due to different treatments of embedding and MC uncertainties for the tau ID they are included seperatly for now

        cb.cp().process(embed).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,
                                             "CMS_eff_t_13TeV", "lnN", SystMap<>::init(1.05));

        cb.cp().process(embed).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,
                                             "CMS_eff_t_13TeV", "lnN", SystMap<>::init(1.1));

        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_DM0_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_DM1_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_DM10_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,all_mc_bkgs})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,"CMS_eff_t_DM11_13TeV", "shape", SystMap<>::init(1.00));

        cb.cp().process(JoinStr({sig_procs,real_tau_mc_bkgs})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_t_bin1_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,real_tau_mc_bkgs})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_t_bin2_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,real_tau_mc_bkgs})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_t_bin3_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,real_tau_mc_bkgs})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_t_bin4_13TeV", "shape", SystMap<>::init(1.00));
        cb.cp().process(JoinStr({sig_procs,real_tau_mc_bkgs})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,"CMS_eff_t_bin5_13TeV", "shape", SystMap<>::init(1.00));

        // the uncorrelated part by channel is due to anti-electron and anti-muon disctiminant, it is the same for MC and embedding so decorrelated in the Morphing       
 
        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed})).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,
                                             "CMS_eff_t_mt_13TeV", "lnN", SystMap<>::init(1.01));

        cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed})).channel({"et","et_2016","et_2017","et_2018"}).AddSyst(cb,
                                             "CMS_eff_t_et_13TeV", "lnN", SystMap<>::init(1.01));

        // 2 real taus
        cb.cp().process(JoinStr({sig_procs, {"ZTT","VVT","TTT","EWKZ"}, embed})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,
                                             "CMS_eff_t_tt_13TeV", "lnN", SystMap<>::init(1.02));

        // 1 real tau
        cb.cp().process(JoinStr({{"TTJ","ZJ","VVJ","W","Wfakes","TTfakes"}})).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,
                                             "CMS_eff_t_tt_13TeV", "lnN", SystMap<>::init(1.01));


//CMS_eff_t_DM_13TeV
        
        //##############################################################################
        //  b tag and mistag rate  efficiencies 
        //##############################################################################
 
        // update number for 2017 
        // real uncerts for TT and VV only (others are small) 
        cb.cp().AddSyst(cb,
          "CMS_eff_b_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
          ({"et","et_2016"}, {1}, {"TTT"}, 1.020,0.969)
          ({"et","et_2016"}, {2}, {"TTT"}, 1.034,0.968)
          ({"et","et_2016"}, {3}, {"TTT"}, 1.025,0.932)
          ({"et","et_2016"}, {4}, {"TTT"}, 1.008,0.969)
          ({"et","et_2016"}, {5}, {"TTT"}, 1.032,0.963)
          ({"et","et_2016"}, {6}, {"TTT"}, 1.015,0.942)
          ({"et","et_2016"}, {1}, {"VVT"}, 1.001,1.0)
          ({"et","et_2016"}, {2}, {"VVT"}, 1.010,0.989)
          ({"et","et_2016"}, {3}, {"VVT"}, 1.024,0.987)
          ({"et","et_2016"}, {4}, {"VVT"}, 1.000,0.983)
          //({"et","et_2016"}, {5}, {"VVT"}, 1.000,1.000)
          //({"et","et_2016"}, {6}, {"VVT"}, 1.000,1.000)
          ({"mt","mt_2016"}, {1}, {"TTT"}, 1.024,0.975)
          ({"mt","mt_2016"}, {2}, {"TTT"}, 1.030,0.967)
          ({"mt","mt_2016"}, {3}, {"TTT"}, 1.069,0.967)
          ({"mt","mt_2016"}, {4}, {"TTT"}, 1.040,0.964)
          ({"mt","mt_2016"}, {5}, {"TTT"}, 1.028,0.968)
          ({"mt","mt_2016"}, {6}, {"TTT"}, 1.060,0.952)
          ({"mt","mt_2016"}, {1}, {"VVT"}, 1.0001,0.999) 
          ({"mt","mt_2016"}, {2}, {"VVT"}, 1.010,0.994)
          ({"mt","mt_2016"}, {3}, {"VVT"}, 1.015,1.000)
          ({"mt","mt_2016"}, {4}, {"VVT"}, 1.014,0.987)
          ({"mt","mt_2016"}, {5}, {"VVT"}, 1.005,1.000)
          ({"mt","mt_2016"}, {6}, {"VVT"}, 1.024,0.986)
          ({"em","em_2016"}, {1}, {"TT"}, 1.016,0.982)
          ({"em","em_2016"}, {2}, {"TT"}, 1.030,0.968)
          ({"em","em_2016"}, {3}, {"TT"}, 1.033,0.968)
          ({"em","em_2016"}, {4}, {"TT"}, 1.032,0.957)
          ({"em","em_2016"}, {5}, {"TT"}, 1.032,0.975)
          ({"em","em_2016"}, {6}, {"TT"}, 1.032,0.969)
          ({"em","em_2016"}, {1}, {"VV"}, 1.001, 0.999)
          ({"em","em_2016"}, {2}, {"VV"}, 1.008,0.992)
          ({"em","em_2016"}, {3}, {"VV"}, 1.013,0.986)
          ({"em","em_2016"}, {4}, {"VV"}, 1.008,0.988)
          ({"em","em_2016"}, {5}, {"VV"}, 1.010,0.992)
          ({"em","em_2016"}, {6}, {"VV"}, 1.011,0.988)
          ({"em_2017"}, {1}, {"TT"}, 1.032, 0.973)
          ({"em_2017"}, {1}, {"VV"}, 1.002, 0.998)
          ({"em_2017"}, {4}, {"TT"}, 1.042, 0.963)
          ({"em_2017"}, {4}, {"VV"}, 1.018, 0.980)
          ({"em_2017"}, {3}, {"TT"}, 1.036, 0.962)
          ({"em_2017"}, {3}, {"VV"}, 1.014, 0.985)
          ({"em_2017"}, {6}, {"TT"}, 1.041, 0.959)
          ({"em_2017"}, {6}, {"VV"}, 1.017, 0.979)
          ({"em_2017"}, {5}, {"TT"}, 1.050, 0.965)
          ({"em_2017"}, {5}, {"VV"}, 1.007, 0.980)
          ({"em_2017"}, {2}, {"TT"}, 1.036, 0.963)
          ({"em_2017"}, {2}, {"VV"}, 1.011, 0.991)
          ({"et_2017"}, {1}, {"TTT"}, 1.049, 0.981)
          ({"et_2017"}, {1}, {"VVT"}, 1.001, 0.998)
          ({"et_2017"}, {4}, {"TTT"}, 1.032, 0.975)
          ({"et_2017"}, {4}, {"VVT"}, 1.000, 0.974)
          ({"et_2017"}, {3}, {"TTT"}, 1.052, 0.954)
          ({"et_2017"}, {3}, {"VVT"}, 1.037, 0.964)
          ({"et_2017"}, {6}, {"TTT"}, 1.015, 0.925)
          ({"et_2017"}, {6}, {"VVT"}, 1.026, 1.002)
          ({"et_2017"}, {5}, {"TTT"}, 1.020, 0.977)
          //({"et_2017"}, {5}, {"VVT"}, 1.000, 1.000)
          ({"et_2017"}, {2}, {"TTT"}, 1.047, 0.957)
          ({"et_2017"}, {2}, {"VVT"}, 1.010, 0.988)
          ({"mt_2017"}, {1}, {"TTT"}, 1.005, 0.972)
          ({"mt_2017"}, {1}, {"VVT"}, 1.002, 0.998)
          ({"mt_2017"}, {4}, {"TTT"}, 1.047, 0.968)
          ({"mt_2017"}, {4}, {"VVT"}, 1.040, 0.979)
          ({"mt_2017"}, {3}, {"TTT"}, 1.042, 0.944)
          ({"mt_2017"}, {3}, {"VVT"}, 1.008, 0.974)
          ({"mt_2017"}, {6}, {"TTT"}, 1.074, 0.964)
          ({"mt_2017"}, {6}, {"VVT"}, 1.058, 0.973)
          ({"mt_2017"}, {5}, {"TTT"}, 1.057, 0.981)
          ({"mt_2017"}, {5}, {"VVT"}, 1.003, 0.961)
          ({"mt_2017"}, {2}, {"TTT"}, 1.038, 0.956)
          ({"mt_2017"}, {2}, {"VVT"}, 1.009, 0.988)

          ({"em_2018"}, {1}, {"TT"}, 1.032, 0.973)
          ({"em_2018"}, {1}, {"VV"}, 1.002, 0.998)
          ({"em_2018"}, {4}, {"TT"}, 1.042, 0.963)
          ({"em_2018"}, {4}, {"VV"}, 1.018, 0.980)
          ({"em_2018"}, {3}, {"TT"}, 1.036, 0.962)
          ({"em_2018"}, {3}, {"VV"}, 1.014, 0.985)
          ({"em_2018"}, {6}, {"TT"}, 1.041, 0.959)
          ({"em_2018"}, {6}, {"VV"}, 1.017, 0.979)
          ({"em_2018"}, {5}, {"TT"}, 1.050, 0.965)
          ({"em_2018"}, {5}, {"VV"}, 1.007, 0.980)
          ({"em_2018"}, {2}, {"TT"}, 1.036, 0.963)
          ({"em_2018"}, {2}, {"VV"}, 1.011, 0.991)
          ({"et_2018"}, {1}, {"TTT"}, 1.049, 0.981)
          ({"et_2018"}, {1}, {"VVT"}, 1.001, 0.998)
          ({"et_2018"}, {4}, {"TTT"}, 1.032, 0.975)
          ({"et_2018"}, {4}, {"VVT"}, 1.000, 0.974)
          ({"et_2018"}, {3}, {"TTT"}, 1.052, 0.954)
          ({"et_2018"}, {3}, {"VVT"}, 1.037, 0.964)
          ({"et_2018"}, {6}, {"TTT"}, 1.015, 0.925)
          ({"et_2018"}, {6}, {"VVT"}, 1.026, 1.002)
          ({"et_2018"}, {5}, {"TTT"}, 1.020, 0.977)
          //({"et_2018"}, {5}, {"VVT"}, 1.000, 1.000)
          ({"et_2018"}, {2}, {"TTT"}, 1.047, 0.957)
          ({"et_2018"}, {2}, {"VVT"}, 1.010, 0.988)
          ({"mt_2018"}, {1}, {"TTT"}, 1.005, 0.972)
          ({"mt_2018"}, {1}, {"VVT"}, 1.002, 0.998)
          ({"mt_2018"}, {4}, {"TTT"}, 1.047, 0.968)
          ({"mt_2018"}, {4}, {"VVT"}, 1.040, 0.979)
          ({"mt_2018"}, {3}, {"TTT"}, 1.042, 0.944)
          ({"mt_2018"}, {3}, {"VVT"}, 1.008, 0.974)
          ({"mt_2018"}, {6}, {"TTT"}, 1.074, 0.964)
          ({"mt_2018"}, {6}, {"VVT"}, 1.058, 0.973)
          ({"mt_2018"}, {5}, {"TTT"}, 1.057, 0.981)
          ({"mt_2018"}, {5}, {"VVT"}, 1.003, 0.961)
          ({"mt_2018"}, {2}, {"TTT"}, 1.038, 0.956)
          ({"mt_2018"}, {2}, {"VVT"}, 1.009, 0.988)

          // the commented numbers are for deepCSV (above numbers for CSVv2)
          //({"mt_2017"}, {1}, {"TTT"}, 1.026, 0.982)
          //({"mt_2017"}, {1}, {"VVT"}, 1.002, 0.999)
          //({"mt_2017"}, {4}, {"TTT"}, 1.021, 0.965)
          //({"mt_2017"}, {4}, {"VVT"}, 1.039, 0.986)
          //({"mt_2017"}, {3}, {"TTT"}, 1.072, 0.971)
          //({"mt_2017"}, {3}, {"VVT"}, 1.022, 0.982)
          //({"mt_2017"}, {6}, {"TTT"}, 1.072, 0.972)
          //({"mt_2017"}, {6}, {"VVT"}, 1.028, 0.963)
          //({"mt_2017"}, {5}, {"TTT"}, 1.047, 0.989)
          //({"mt_2017"}, {5}, {"VVT"}, 1.023, 0.955)
          //({"mt_2017"}, {2}, {"TTT"}, 1.052, 0.950)
          //({"mt_2017"}, {2}, {"VVT"}, 1.012, 0.986)
          //({"et_2017"}, {1}, {"TTT"}, 1.009, 0.976)
          //({"et_2017"}, {1}, {"VVT"}, 1.001, 0.999)
          //({"et_2017"}, {4}, {"TTT"}, 1.065, 0.968)
          //({"et_2017"}, {4}, {"VVT"}, 1.019, 0.975)
          //({"et_2017"}, {3}, {"TTT"}, 1.062, 0.906)
          //({"et_2017"}, {3}, {"VVT"}, 1.043, 1.000)
          //({"et_2017"}, {6}, {"TTT"}, 1.068, 0.947)
          //({"et_2017"}, {6}, {"VVT"}, 1.024, 1.001)
          //({"et_2017"}, {5}, {"TTT"}, 1.026, 0.988)
          //({"et_2017"}, {5}, {"VVT"}, 1.000, 1.000)
          //({"et_2017"}, {2}, {"TTT"}, 1.046, 0.950)
          //({"et_2017"}, {2}, {"VVT"}, 1.016, 0.987)
          //({"em_2017"}, {1}, {"TT"}, 1.029, 0.980)
          //({"em_2017"}, {1}, {"VV"}, 1.002, 0.999)
          //({"em_2017"}, {4}, {"TT"}, 1.055, 0.948)
          //({"em_2017"}, {4}, {"VV"}, 1.021, 0.976)
          //({"em_2017"}, {3}, {"TT"}, 1.047, 0.948)
          //({"em_2017"}, {3}, {"VV"}, 1.020, 0.987)
          //({"em_2017"}, {6}, {"TT"}, 1.050, 0.946)
          //({"em_2017"}, {6}, {"VV"}, 1.022, 0.982)
          //({"em_2017"}, {5}, {"TT"}, 1.050, 0.951)
          //({"em_2017"}, {5}, {"VV"}, 1.017, 0.979)
          //({"em_2017"}, {2}, {"TT"}, 1.044, 0.957)
          //({"em_2017"}, {2}, {"VV"}, 1.010, 0.989)
          //
          //({"mt_2018"}, {1}, {"TTT"}, 1.026, 0.982)
          //({"mt_2018"}, {1}, {"VVT"}, 1.002, 0.999)
          //({"mt_2018"}, {4}, {"TTT"}, 1.021, 0.965)
          //({"mt_2018"}, {4}, {"VVT"}, 1.039, 0.986)
          //({"mt_2018"}, {3}, {"TTT"}, 1.072, 0.971)
          //({"mt_2018"}, {3}, {"VVT"}, 1.022, 0.982)
          //({"mt_2018"}, {6}, {"TTT"}, 1.072, 0.972)
          //({"mt_2018"}, {6}, {"VVT"}, 1.028, 0.963)
          //({"mt_2018"}, {5}, {"TTT"}, 1.047, 0.989)
          //({"mt_2018"}, {5}, {"VVT"}, 1.023, 0.955)
          //({"mt_2018"}, {2}, {"TTT"}, 1.052, 0.950)
          //({"mt_2018"}, {2}, {"VVT"}, 1.012, 0.986)
          //({"et_2018"}, {1}, {"TTT"}, 1.009, 0.976)
          //({"et_2018"}, {1}, {"VVT"}, 1.001, 0.999)
          //({"et_2018"}, {4}, {"TTT"}, 1.065, 0.968)
          //({"et_2018"}, {4}, {"VVT"}, 1.019, 0.975)
          //({"et_2018"}, {3}, {"TTT"}, 1.062, 0.906)
          //({"et_2018"}, {3}, {"VVT"}, 1.043, 1.000)
          //({"et_2018"}, {6}, {"TTT"}, 1.068, 0.947)
          //({"et_2018"}, {6}, {"VVT"}, 1.024, 1.001)
          //({"et_2018"}, {5}, {"TTT"}, 1.026, 0.988)
          //({"et_2018"}, {5}, {"VVT"}, 1.000, 1.000)
          //({"et_2018"}, {2}, {"TTT"}, 1.046, 0.950)
          //({"et_2018"}, {2}, {"VVT"}, 1.016, 0.987)
          //({"em_2018"}, {1}, {"TT"}, 1.029, 0.980)
          //({"em_2018"}, {1}, {"VV"}, 1.002, 0.999)
          //({"em_2018"}, {4}, {"TT"}, 1.055, 0.948)
          //({"em_2018"}, {4}, {"VV"}, 1.021, 0.976)
          //({"em_2018"}, {3}, {"TT"}, 1.047, 0.948)
          //({"em_2018"}, {3}, {"VV"}, 1.020, 0.987)
          //({"em_2018"}, {6}, {"TT"}, 1.050, 0.946)
          //({"em_2018"}, {6}, {"VV"}, 1.022, 0.982)
          //({"em_2018"}, {5}, {"TT"}, 1.050, 0.951)
          //({"em_2018"}, {5}, {"VV"}, 1.017, 0.979)
          //({"em_2018"}, {2}, {"TT"}, 1.044, 0.957)
          //({"em_2018"}, {2}, {"VV"}, 1.010, 0.989)
          
          ({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}, {100,101,102,103,104,107,108}, {"TTT"}, 1.05, 0.95)
          ({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}, {105,106}, {"TTT"}, 1.06, 0.91)
          ({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}, {100,101,102,103,104,107,108}, {"VVT"}, 1.02, 0.98)
          ({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}, {105,106}, {"VVT"}, 1.04, 0.96)
        );

        cb.cp().process({"TTT","TT","VVT","VV"}).bin_id({31,32,33,34,35,36,37,41,42,43,44,45,46,47}).AddSyst(cb,
                                             "CMS_eff_b_13TeV", "shape", SystMap<>::init(1.00));
        
        //##############################################################################
        //  Electron, muon and tau energy Scale
        //##############################################################################
        
        // Add back later!
        //cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed, {"jetFakes", "QCD"}})).channel({"et","et_2016","et_2017","et_2018","em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}).AddSyst(cb,
        //                                     "CMS_scale_e_13TeV", "shape", SystMap<>::init(1.00));
       
        //cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed, {"jetFakes", "QCD"}})).channel({"em","em_2016","em_2017","ttbar","ttbar_2016","ttbar_2017"}).AddSyst(cb,
        //                                     "CMS_scale_e_13TeV", "shape", SystMap<>::init(1.00));

 
        // Decay Mode based TES Settings
        //cb.cp().process(JoinStr({sig_procs, real_tau_mc_bkgs, embed, {"jetFakes"}})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,
        //                                        "CMS_scale_t_1prong_13TeV", "shape", SystMap<>::init(1.00));
        //cb.cp().process(JoinStr({sig_procs, real_tau_mc_bkgs, embed, {"jetFakes"}})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,
        //                                        "CMS_scale_t_1prong1pizero_13TeV", "shape", SystMap<>::init(1.00));
        //cb.cp().process(JoinStr({sig_procs, real_tau_mc_bkgs, embed, {"jetFakes"}})).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb,
        //                                        "CMS_scale_t_3prong_13TeV", "shape", SystMap<>::init(1.00));

        // Muon 
        // ES Add back after!
        //cb.cp().process(JoinStr({sig_procs, all_mc_bkgs, embed, {"jetFakes", "QCD"}})).channel({"mt","mt_2016","mt_2017","et_2018","em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}).AddSyst(cb,
        //                                     "CMS_scale_mu_13TeV", "shape", SystMap<>::init(1.00));

        //##############################################################################
        //  Embedded uncertainty on ttbar contamination (and VV contamination)
        //##############################################################################        
        cb.cp().process(embed).AddSyst(cb,"CMS_ttbar_embeded_13TeV", "shape", SystMap<>::init(1.00));
 
        //##############################################################################
        //  jet and met energy Scale
        //##############################################################################


        // Add back later! 
        //
        // MET Systematic shapes - recoil uncertainties for recoil corrected met, unclustered energy uncertainty for samples with no recoil correction, jes uncertainties propogated to met for samples with no recoil correction
        //cb.cp().process({"TT","TTJ","TTT","VV","VVJ","VVT"}).AddSyst(cb,
        //                                          "CMS_scale_met_unclustered_13TeV", "shape", SystMap<>::init(1.00));


        //cb.cp().process(JoinStr({sig_procs, {"ZTT","ZLL","ZL","ZJ","EWKZ","W"}})).AddSyst(cb,
        //                                          "CMS_htt_boson_reso_met_13TeV", "shape", SystMap<>::init(1.00)); 
        //cb.cp().process(JoinStr({sig_procs, {"ZTT","ZLL","ZL","ZJ","EWKZ","W"}})).AddSyst(cb,
        //                                          "CMS_htt_boson_scale_met_13TeV", "shape", SystMap<>::init(1.00));      
 

      

        //cb.cp().process(JoinStr({sig_procs, all_mc_bkgs})).AddSyst(cb,"CMS_scale_j_13TeV", "shape", SystMap<>::init(1.00));
 
        
        //##############################################################################
        //  Background normalization uncertainties
        //##############################################################################
        
        //   Diboson  Normalisation - fully correlated
        cb.cp().process({"VV","VVT","VVJ"}).AddSyst(cb,
                                        "CMS_htt_vvXsec_13TeV", "lnN", SystMap<>::init(1.05));

        cb.cp().process({"ZTT","ZJ","ZL","ZLL"}).AddSyst(cb,
                                        "CMS_htt_zjXsec_13TeV", "lnN", SystMap<>::init(1.04));        
 
        cb.cp().process({"EWKZ"}).AddSyst(cb,
                                        "CMS_htt_ewkzXsec_13TeV", "lnN", SystMap<>::init(1.04));

        //if (! ttbar_fit){
        //   ttbar Normalisation - fully correlated
	    cb.cp().process({"TT","TTT","TTJ"}).AddSyst(cb,
					  "CMS_htt_tjXsec_13TeV", "lnN", SystMap<>::init(1.06));
        //}

        // W norm, just for em, tt and the mm region where MC norm is from MC
        
        cb.cp().process({"W"}).channel({"em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}).AddSyst(cb,
                                                       "CMS_htt_jetFakeLep_13TeV", "lnN", SystMap<>::init(1.20));
        
        cb.cp().process({"W"}).channel({"tt","tt_2016","tt_2017","tt_2018","em","em_2016","em_2017","em_2018","ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}).AddSyst(cb,
                                                       "CMS_htt_wjXsec_13TeV", "lnN", SystMap<>::init(1.04));
        
        if(control_region==0){
          cb.cp().process({"W"}).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,
                                                       "CMS_htt_wjXsec_13TeV", "lnN", SystMap<>::init(1.04));    
        }

// prefiring uncertainties, all values < 0.5% are neglected
        cb.cp().AddSyst(cb,
                  "CMS_PreFire_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
                  ({"mt_2016"}, {6}, {"TTT"}, 1.005, 0.995)
                  ({"mt_2016"}, {6}, {"qqH_htt125"}, 1.007, 0.993)
                  ({"mt_2016"}, {6}, {"qqHmm_htt"}, 1.008, 0.992)
                  ({"mt_2016"}, {6}, {"ggHsm_htt125"}, 1.006, 0.994)
                  ({"mt_2016"}, {6}, {"qqHps_htt"}, 1.008, 0.992)
                  ({"mt_2016"}, {6}, {"qqHsm_htt125"}, 1.007, 0.993)
                  ({"mt_2016"}, {5}, {"qqHps_htt"}, 1.006, 0.994)
                  ({"tt_2016"}, {6}, {"TTT"}, 1.010, 0.990)
                  ({"tt_2016"}, {6}, {"qqH_htt125"}, 1.007, 0.993)
                  ({"tt_2016"}, {6}, {"ggHps_htt125"}, 1.006, 0.994)
                  ({"tt_2016"}, {6}, {"qqHmm_htt"}, 1.008, 0.992)
                  ({"tt_2016"}, {6}, {"qqHps_htt"}, 1.008, 0.992)
                  ({"tt_2016"}, {6}, {"qqHsm_htt125"}, 1.007, 0.993)
                  ({"tt_2016"}, {6}, {"WH_htt125"}, 1.007, 0.993)
                  ({"tt_2016"}, {5}, {"TTT"}, 1.010, 0.990)
                  ({"tt_2016"}, {5}, {"VVT"}, 1.006, 0.994)
                  ({"tt_2016"}, {5}, {"ZHsm_htt125"}, 1.006, 0.994)
                  ({"tt_2016"}, {5}, {"qqHps_htt"}, 1.005, 0.995)
                  ({"et_2016"}, {4}, {"WHsm_htt125"}, 1.007, 0.993)
                  ({"et_2016"}, {6}, {"TTT"}, 1.010, 0.990)
                  ({"et_2016"}, {6}, {"EWKZ"}, 1.007, 0.993)
                  ({"et_2016"}, {6}, {"qqH_htt125"}, 1.007, 0.993)
                  ({"et_2016"}, {6}, {"qqHmm_htt"}, 1.008, 0.992)
                  ({"et_2016"}, {6}, {"qqHps_htt"}, 1.008, 0.992)
                  ({"et_2016"}, {6}, {"ggHmm_htt125"}, 1.005, 0.995)
                  ({"et_2016"}, {6}, {"qqHsm_htt125"}, 1.007, 0.993)
                  ({"et_2016"}, {5}, {"EWKZ"}, 1.006, 0.994)
                  ({"et_2016"}, {5}, {"ZHps_htt"}, 1.006, 0.994)       
                  ({"ttbar_2016"}, {1}, {"qqHmm_htt"}, 1.005, 0.995)
                  ({"ttbar_2016"}, {1}, {"qqHps_htt"}, 1.005, 0.995)
                  ({"em_2016"}, {4}, {"WHsm_htt125"}, 1.006, 0.994)
                  ({"em_2016"}, {4}, {"ZH_htt125"}, 1.006, 0.994)
                  ({"em_2016"}, {6}, {"qqH_hww125"}, 1.006, 0.994)
                  ({"em_2016"}, {6}, {"qqH_htt125"}, 1.006, 0.994)
                  ({"em_2016"}, {6}, {"ggHps_htt125"}, 1.005, 0.995)
                  ({"em_2016"}, {6}, {"qqHmm_htt"}, 1.007, 0.993)
                  ({"em_2016"}, {6}, {"qqHps_htt"}, 1.008, 0.992)
                  ({"em_2016"}, {6}, {"ggHmm_htt125"}, 1.005, 0.994)
                  ({"em_2016"}, {6}, {"qqHsm_htt125"}, 1.006, 0.994)
                  ({"em_2016"}, {6}, {"ZH_htt125"}, 1.006, 0.994)
                  ({"em_2016"}, {6}, {"TT"}, 1.006, 0.993)
                  ({"em_2016"}, {5}, {"qqHps_htt"}, 1.006, 0.994)
                  
                  ({"mt_2017"}, {4}, {"ZL"}, 1.009, 0.991)
                  ({"mt_2017"}, {4}, {"qqH_htt125"}, 1.005, 0.994)
                  ({"mt_2017"}, {4}, {"qqHmm_htt"}, 1.006, 0.994)
                  ({"mt_2017"}, {4}, {"ggHsm_htt125"}, 1.007, 0.993)
                  ({"mt_2017"}, {4}, {"qqHps_htt"}, 1.005, 0.995)
                  ({"mt_2017"}, {3}, {"EWKZ"}, 1.073, 0.928)
                  ({"mt_2017"}, {6}, {"ZL"}, 1.006, 0.994)
                  ({"mt_2017"}, {6}, {"TTT"}, 1.016, 0.984)
                  ({"mt_2017"}, {6}, {"VVT"}, 1.015, 0.985)
                  ({"mt_2017"}, {6}, {"qqH_htt125"}, 1.012, 0.988)
                  ({"mt_2017"}, {6}, {"ggHps_htt125"}, 1.009, 0.991)
                  ({"mt_2017"}, {6}, {"qqHmm_htt"}, 1.015, 0.985)
                  ({"mt_2017"}, {6}, {"ggHsm_htt125"}, 1.010, 0.990)
                  ({"mt_2017"}, {6}, {"qqHps_htt"}, 1.015, 0.985)
                  ({"mt_2017"}, {6}, {"WHmm_htt"}, 1.006, 0.994)
                  ({"mt_2017"}, {6}, {"ZHmm_htt"}, 1.008, 0.992)
                  ({"mt_2017"}, {6}, {"ggHmm_htt125"}, 1.009, 0.991)
                  ({"mt_2017"}, {6}, {"qqHsm_htt125"}, 1.012, 0.988)
                  ({"mt_2017"}, {6}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"mt_2017"}, {6}, {"ZH_htt125"}, 1.007, 0.993)
                  ({"mt_2017"}, {6}, {"WH_htt125"}, 1.006, 0.994)
                  ({"mt_2017"}, {5}, {"EWKZ"}, 1.010, 0.990)
                  ({"mt_2017"}, {5}, {"qqHmm_htt"}, 1.005, 0.995)
                  ({"mt_2017"}, {5}, {"WHps_htt"}, 1.008, 0.992)
                  ({"mt_2017"}, {5}, {"qqHps_htt"}, 1.011, 0.989)
                  ({"mt_2017"}, {5}, {"qqHsm_htt125"}, 1.005, 0.995)
                  ({"tt_2017"}, {4}, {"VVT"}, 1.006, 0.994)
                  ({"tt_2017"}, {4}, {"EWKZ"}, 1.154, 0.846)
                  ({"tt_2017"}, {4}, {"qqHsm_htt125"}, 1.005, 0.995)
                  ({"tt_2017"}, {3}, {"ZL"}, 1.005, 0.995)
                  ({"tt_2017"}, {3}, {"qqHmm_htt"}, 1.007, 0.993)
                  ({"tt_2017"}, {3}, {"ZHmm_htt"}, 1.006, 0.994)
                  ({"tt_2017"}, {3}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"tt_2017"}, {6}, {"ZL"}, 1.044, 0.956)
                  ({"tt_2017"}, {6}, {"TTT"}, 1.004, 0.994)
                  ({"tt_2017"}, {6}, {"EWKZ"}, 1.034, 0.966)
                  ({"tt_2017"}, {6}, {"qqH_htt125"}, 1.013, 0.987)
                  ({"tt_2017"}, {6}, {"ggHps_htt125"}, 1.009, 0.991)
                  ({"tt_2017"}, {6}, {"qqHmm_htt"}, 1.014, 0.986)
                  ({"tt_2017"}, {6}, {"ggHsm_htt125"}, 1.010, 0.990)
                  ({"tt_2017"}, {6}, {"qqHps_htt"}, 1.015, 0.985)
                  ({"tt_2017"}, {6}, {"ggHmm_htt125"}, 1.010, 0.990)
                  ({"tt_2017"}, {6}, {"qqHsm_htt125"}, 1.013, 0.987)
                  ({"tt_2017"}, {6}, {"ZH_htt125"}, 1.005, 0.994)
                  ({"tt_2017"}, {6}, {"WH_htt125"}, 1.007, 0.993)
                  ({"tt_2017"}, {5}, {"qqH_htt125"}, 1.006, 0.994)
                  ({"tt_2017"}, {5}, {"qqHmm_htt"}, 1.008, 0.992)
                  ({"tt_2017"}, {5}, {"WHps_htt"}, 1.011, 0.989)
                  ({"tt_2017"}, {5}, {"qqHps_htt"}, 1.009, 0.991)
                  ({"tt_2017"}, {5}, {"qqHsm_htt125"}, 1.006, 0.994)
                  ({"tt_2017"}, {5}, {"ZH_htt125"}, 1.007, 0.993)
                  ({"tt_2017"}, {5}, {"WH_htt125"}, 1.007, 0.993)
                  ({"et_2017"}, {4}, {"TTT"}, 1.007, 0.993)
                  ({"et_2017"}, {4}, {"VVT"}, 1.008, 0.992)
                  ({"et_2017"}, {4}, {"qqH_htt125"}, 1.006, 0.994)
                  ({"et_2017"}, {4}, {"qqHmm_htt"}, 1.005, 0.995)
                  ({"et_2017"}, {4}, {"ggHsm_htt125"}, 1.005, 0.995)
                  ({"et_2017"}, {4}, {"WHps_htt"}, 1.005, 0.995)
                  ({"et_2017"}, {4}, {"ZHmm_htt"}, 1.005, 0.995)
                  ({"et_2017"}, {6}, {"ZL"}, 1.019, 0.981)
                  ({"et_2017"}, {6}, {"VVT"}, 1.007, 0.993)
                  ({"et_2017"}, {6}, {"EWKZ"}, 1.032, 0.968)
                  ({"et_2017"}, {6}, {"qqH_htt125"}, 1.013, 0.987)
                  ({"et_2017"}, {6}, {"ggHps_htt125"}, 1.007, 0.993)
                  ({"et_2017"}, {6}, {"qqHmm_htt"}, 1.013, 0.987)
                  ({"et_2017"}, {6}, {"ggHsm_htt125"}, 1.009, 0.991)
                  ({"et_2017"}, {6}, {"WHsm_htt125"}, 1.005, 0.995)
                  ({"et_2017"}, {6}, {"qqHps_htt"}, 1.014, 0.986)
                  ({"et_2017"}, {6}, {"WHmm_htt"}, 1.007, 0.993)
                  ({"et_2017"}, {6}, {"ggHmm_htt125"}, 1.010, 0.990)
                  ({"et_2017"}, {6}, {"qqHsm_htt125"}, 1.011, 0.989)
                  ({"et_2017"}, {6}, {"ZH_htt125"}, 1.006, 0.994)
                  ({"et_2017"}, {6}, {"WH_htt125"}, 1.005, 0.995)
                  ({"et_2017"}, {5}, {"TTT"}, 1.007, 0.993)
                  ({"et_2017"}, {5}, {"VVT"}, 1.008, 0.992)
                  ({"et_2017"}, {5}, {"EWKZ"}, 1.006, 0.994)
                  ({"et_2017"}, {5}, {"qqHmm_htt"}, 1.006, 0.994)
                  ({"et_2017"}, {5}, {"WHps_htt"}, 1.008, 0.992)
                  ({"et_2017"}, {5}, {"qqHps_htt"}, 1.009, 0.991)
                  ({"et_2017"}, {5}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"et_2017"}, {5}, {"ZH_htt125"}, 1.006, 0.994)
                  ({"em_2017"}, {7}, {"qqHmm_htt"}, 1.009, 0.991)
                  ({"em_2017"}, {7}, {"qqHps_htt"}, 1.009, 0.991)
                  ({"em_2017"}, {4}, {"TTJ"}, 1.005, 0.995)
                  ({"em_2017"}, {4}, {"W"}, 1.013, 0.985)
                  ({"em_2017"}, {4}, {"qqH_htt125"}, 1.005, 0.995)
                  ({"em_2017"}, {4}, {"ggHsm_htt125"}, 1.006, 0.994)
                  ({"em_2017"}, {4}, {"ZHsm_htt125"}, 1.008, 0.992)
                  ({"em_2017"}, {4}, {"ggHmm_htt125"}, 1.005, 0.995)
                  ({"em_2017"}, {4}, {"qqHsm_htt125"}, 1.006, 0.994)
                  ({"em_2017"}, {4}, {"TT"}, 1.005, 0.995)
                  ({"em_2017"}, {3}, {"qqHps_htt"}, 1.005, 0.995)
                  ({"em_2017"}, {3}, {"ZHmm_htt"}, 1.007, 0.993)
                  ({"em_2017"}, {6}, {"ZLL"}, 1.012, 0.987)
                  ({"em_2017"}, {6}, {"EWKZ"}, 1.074, 0.926)
                  ({"em_2017"}, {6}, {"qqH_htt125"}, 1.012, 0.988)
                  ({"em_2017"}, {6}, {"ggHps_htt125"}, 1.010, 0.990)
                  ({"em_2017"}, {6}, {"qqHmm_htt"}, 1.013, 0.987)
                  ({"em_2017"}, {6}, {"ggHsm_htt125"}, 1.010, 0.990)
                  ({"em_2017"}, {6}, {"WHsm_htt125"}, 1.007, 0.993)
                  ({"em_2017"}, {6}, {"qqHps_htt"}, 1.013, 0.987)
                  ({"em_2017"}, {6}, {"ggHmm_htt125"}, 1.010, 0.989)
                  ({"em_2017"}, {6}, {"qqHsm_htt125"}, 1.012, 0.988)
                  ({"em_2017"}, {6}, {"ZH_htt125"}, 1.006, 0.993)
                  ({"em_2017"}, {6}, {"TT"}, 1.010, 0.990)
                  ({"em_2017"}, {6}, {"VV"}, 1.008, 0.992)
                  ({"em_2017"}, {6}, {"WH_htt125"}, 1.006, 0.994)
                  ({"em_2017"}, {5}, {"EWKZ"}, 1.021, 0.979)
                  ({"em_2017"}, {5}, {"qqHmm_htt"}, 1.007, 0.993)
                  ({"em_2017"}, {5}, {"qqHps_htt"}, 1.008, 0.992)
                  ({"em_2017"}, {5}, {"WHmm_htt"}, 1.009, 0.991)
                  ({"em_2017"}, {5}, {"qqHsm_htt125"}, 1.005, 0.995)
                  ({"em_2017"}, {5}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"em_2017"}, {5}, {"TT"}, 1.006, 0.994)
                  ({"em_2017"}, {5}, {"WH_htt125"}, 1.006, 0.993)

                  ({"mt_2018"}, {4}, {"ZL"}, 1.009, 0.991)
                  ({"mt_2018"}, {4}, {"qqH_htt125"}, 1.005, 0.994)
                  ({"mt_2018"}, {4}, {"qqHmm_htt"}, 1.006, 0.994)
                  ({"mt_2018"}, {4}, {"ggHsm_htt125"}, 1.007, 0.993)
                  ({"mt_2018"}, {4}, {"qqHps_htt"}, 1.005, 0.995)
                  ({"mt_2018"}, {3}, {"EWKZ"}, 1.073, 0.928)
                  ({"mt_2018"}, {6}, {"ZL"}, 1.006, 0.994)
                  ({"mt_2018"}, {6}, {"TTT"}, 1.016, 0.984)
                  ({"mt_2018"}, {6}, {"VVT"}, 1.015, 0.985)
                  ({"mt_2018"}, {6}, {"qqH_htt125"}, 1.012, 0.988)
                  ({"mt_2018"}, {6}, {"ggHps_htt125"}, 1.009, 0.991)
                  ({"mt_2018"}, {6}, {"qqHmm_htt"}, 1.015, 0.985)
                  ({"mt_2018"}, {6}, {"ggHsm_htt125"}, 1.010, 0.990)
                  ({"mt_2018"}, {6}, {"qqHps_htt"}, 1.015, 0.985)
                  ({"mt_2018"}, {6}, {"WHmm_htt"}, 1.006, 0.994)
                  ({"mt_2018"}, {6}, {"ZHmm_htt"}, 1.008, 0.992)
                  ({"mt_2018"}, {6}, {"ggHmm_htt125"}, 1.009, 0.991)
                  ({"mt_2018"}, {6}, {"qqHsm_htt125"}, 1.012, 0.988)
                  ({"mt_2018"}, {6}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"mt_2018"}, {6}, {"ZH_htt125"}, 1.007, 0.993)
                  ({"mt_2018"}, {6}, {"WH_htt125"}, 1.006, 0.994)
                  ({"mt_2018"}, {5}, {"EWKZ"}, 1.010, 0.990)
                  ({"mt_2018"}, {5}, {"qqHmm_htt"}, 1.005, 0.995)
                  ({"mt_2018"}, {5}, {"WHps_htt"}, 1.008, 0.992)
                  ({"mt_2018"}, {5}, {"qqHps_htt"}, 1.011, 0.989)
                  ({"mt_2018"}, {5}, {"qqHsm_htt125"}, 1.005, 0.995)
                  ({"tt_2018"}, {4}, {"VVT"}, 1.006, 0.994)
                  ({"tt_2018"}, {4}, {"EWKZ"}, 1.154, 0.846)
                  ({"tt_2018"}, {4}, {"qqHsm_htt125"}, 1.005, 0.995)
                  ({"tt_2018"}, {3}, {"ZL"}, 1.005, 0.995)
                  ({"tt_2018"}, {3}, {"qqHmm_htt"}, 1.007, 0.993)
                  ({"tt_2018"}, {3}, {"ZHmm_htt"}, 1.006, 0.994)
                  ({"tt_2018"}, {3}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"tt_2018"}, {6}, {"ZL"}, 1.044, 0.956)
                  ({"tt_2018"}, {6}, {"TTT"}, 1.004, 0.994)
                  ({"tt_2018"}, {6}, {"EWKZ"}, 1.034, 0.966)
                  ({"tt_2018"}, {6}, {"qqH_htt125"}, 1.013, 0.987)
                  ({"tt_2018"}, {6}, {"ggHps_htt125"}, 1.009, 0.991)
                  ({"tt_2018"}, {6}, {"qqHmm_htt"}, 1.014, 0.986)
                  ({"tt_2018"}, {6}, {"ggHsm_htt125"}, 1.010, 0.990)
                  ({"tt_2018"}, {6}, {"qqHps_htt"}, 1.015, 0.985)
                  ({"tt_2018"}, {6}, {"ggHmm_htt125"}, 1.010, 0.990)
                  ({"tt_2018"}, {6}, {"qqHsm_htt125"}, 1.013, 0.987)
                  ({"tt_2018"}, {6}, {"ZH_htt125"}, 1.005, 0.994)
                  ({"tt_2018"}, {6}, {"WH_htt125"}, 1.007, 0.993)
                  ({"tt_2018"}, {5}, {"qqH_htt125"}, 1.006, 0.994)
                  ({"tt_2018"}, {5}, {"qqHmm_htt"}, 1.008, 0.992)
                  ({"tt_2018"}, {5}, {"WHps_htt"}, 1.011, 0.989)
                  ({"tt_2018"}, {5}, {"qqHps_htt"}, 1.009, 0.991)
                  ({"tt_2018"}, {5}, {"qqHsm_htt125"}, 1.006, 0.994)
                  ({"tt_2018"}, {5}, {"ZH_htt125"}, 1.007, 0.993)
                  ({"tt_2018"}, {5}, {"WH_htt125"}, 1.007, 0.993)
                  ({"et_2018"}, {4}, {"TTT"}, 1.007, 0.993)
                  ({"et_2018"}, {4}, {"VVT"}, 1.008, 0.992)
                  ({"et_2018"}, {4}, {"qqH_htt125"}, 1.006, 0.994)
                  ({"et_2018"}, {4}, {"qqHmm_htt"}, 1.005, 0.995)
                  ({"et_2018"}, {4}, {"ggHsm_htt125"}, 1.005, 0.995)
                  ({"et_2018"}, {4}, {"WHps_htt"}, 1.005, 0.995)
                  ({"et_2018"}, {4}, {"ZHmm_htt"}, 1.005, 0.995)
                  ({"et_2018"}, {6}, {"ZL"}, 1.019, 0.981)
                  ({"et_2018"}, {6}, {"VVT"}, 1.007, 0.993)
                  ({"et_2018"}, {6}, {"EWKZ"}, 1.032, 0.968)
                  ({"et_2018"}, {6}, {"qqH_htt125"}, 1.013, 0.987)
                  ({"et_2018"}, {6}, {"ggHps_htt125"}, 1.007, 0.993)
                  ({"et_2018"}, {6}, {"qqHmm_htt"}, 1.013, 0.987)
                  ({"et_2018"}, {6}, {"ggHsm_htt125"}, 1.009, 0.991)
                  ({"et_2018"}, {6}, {"WHsm_htt125"}, 1.005, 0.995)
                  ({"et_2018"}, {6}, {"qqHps_htt"}, 1.014, 0.986)
                  ({"et_2018"}, {6}, {"WHmm_htt"}, 1.007, 0.993)
                  ({"et_2018"}, {6}, {"ggHmm_htt125"}, 1.010, 0.990)
                  ({"et_2018"}, {6}, {"qqHsm_htt125"}, 1.011, 0.989)
                  ({"et_2018"}, {6}, {"ZH_htt125"}, 1.006, 0.994)
                  ({"et_2018"}, {6}, {"WH_htt125"}, 1.005, 0.995)
                  ({"et_2018"}, {5}, {"TTT"}, 1.007, 0.993)
                  ({"et_2018"}, {5}, {"VVT"}, 1.008, 0.992)
                  ({"et_2018"}, {5}, {"EWKZ"}, 1.006, 0.994)
                  ({"et_2018"}, {5}, {"qqHmm_htt"}, 1.006, 0.994)
                  ({"et_2018"}, {5}, {"WHps_htt"}, 1.008, 0.992)
                  ({"et_2018"}, {5}, {"qqHps_htt"}, 1.009, 0.991)
                  ({"et_2018"}, {5}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"et_2018"}, {5}, {"ZH_htt125"}, 1.006, 0.994)
                  ({"em_2018"}, {7}, {"qqHmm_htt"}, 1.009, 0.991)
                  ({"em_2018"}, {7}, {"qqHps_htt"}, 1.009, 0.991)
                  ({"em_2018"}, {4}, {"TTJ"}, 1.005, 0.995)
                  ({"em_2018"}, {4}, {"W"}, 1.013, 0.985)
                  ({"em_2018"}, {4}, {"qqH_htt125"}, 1.005, 0.995)
                  ({"em_2018"}, {4}, {"ggHsm_htt125"}, 1.006, 0.994)
                  ({"em_2018"}, {4}, {"ZHsm_htt125"}, 1.008, 0.992)
                  ({"em_2018"}, {4}, {"ggHmm_htt125"}, 1.005, 0.995)
                  ({"em_2018"}, {4}, {"qqHsm_htt125"}, 1.006, 0.994)
                  ({"em_2018"}, {4}, {"TT"}, 1.005, 0.995)
                  ({"em_2018"}, {3}, {"qqHps_htt"}, 1.005, 0.995)
                  ({"em_2018"}, {3}, {"ZHmm_htt"}, 1.007, 0.993)
                  ({"em_2018"}, {6}, {"ZLL"}, 1.012, 0.987)
                  ({"em_2018"}, {6}, {"EWKZ"}, 1.074, 0.926)
                  ({"em_2018"}, {6}, {"qqH_htt125"}, 1.012, 0.988)
                  ({"em_2018"}, {6}, {"ggHps_htt125"}, 1.010, 0.990)
                  ({"em_2018"}, {6}, {"qqHmm_htt"}, 1.013, 0.987)
                  ({"em_2018"}, {6}, {"ggHsm_htt125"}, 1.010, 0.990)
                  ({"em_2018"}, {6}, {"WHsm_htt125"}, 1.007, 0.993)
                  ({"em_2018"}, {6}, {"qqHps_htt"}, 1.013, 0.987)
                  ({"em_2018"}, {6}, {"ggHmm_htt125"}, 1.010, 0.989)
                  ({"em_2018"}, {6}, {"qqHsm_htt125"}, 1.012, 0.988)
                  ({"em_2018"}, {6}, {"ZH_htt125"}, 1.006, 0.993)
                  ({"em_2018"}, {6}, {"TT"}, 1.010, 0.990)
                  ({"em_2018"}, {6}, {"VV"}, 1.008, 0.992)
                  ({"em_2018"}, {6}, {"WH_htt125"}, 1.006, 0.994)
                  ({"em_2018"}, {5}, {"EWKZ"}, 1.021, 0.979)
                  ({"em_2018"}, {5}, {"qqHmm_htt"}, 1.007, 0.993)
                  ({"em_2018"}, {5}, {"qqHps_htt"}, 1.008, 0.992)
                  ({"em_2018"}, {5}, {"WHmm_htt"}, 1.009, 0.991)
                  ({"em_2018"}, {5}, {"qqHsm_htt125"}, 1.005, 0.995)
                  ({"em_2018"}, {5}, {"ZHps_htt"}, 1.007, 0.993)
                  ({"em_2018"}, {5}, {"TT"}, 1.006, 0.994)
                  ({"em_2018"}, {5}, {"WH_htt125"}, 1.006, 0.993)
        );

        // QCD uncerts for em
        // add lnN uncertainties for now        


        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).AddSyst(cb,
                                                       "CMS_$CHANNEL_QCD_$BIN_13TeV", "lnN", SystMap<>::init(1.15));

 
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_0JetRate_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"em","em_2016"}, {1}, {"QCD"}, 0.904, 1.096)
//          ({"em_2017"}, {1}, {"QCD"}, 0.923, 1.077)
//          ({"em_2018"}, {1}, {"QCD"}, 0.923, 1.077)
//        ); 
//        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).bin_id({31,32,33,34,35,36,37,100,101,102,103,104,105,106,107,108}).AddSyst(cb,
//                                             "CMS_em_QCD_0JetRate_13TeV", "shape", SystMap<>::init(1.00));
//    
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_1JetRate_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"em","em_2016"}, {4}, {"QCD"}, 0.995, 1.005)
//          ({"em","em_2016"}, {3}, {"QCD"}, 0.995, 1.005)
//          ({"em","em_2016"}, {6}, {"QCD"}, 0.993, 1.007)
//          ({"em","em_2016"}, {5}, {"QCD"}, 0.995, 1.005)
//          ({"em","em_2016"}, {2}, {"QCD"}, 0.995, 1.005)
//          ({"ttbar","ttbar_2016"}, {1}, {"QCD"}, 0.997, 1.003)
//          ({"ttbar_2017"}, {1}, {"QCD"}, 0.958, 1.042)
//          ({"em_2017"}, {4}, {"QCD"}, 0.940, 1.061)
//          ({"em_2017"}, {3}, {"QCD"}, 0.959, 1.041)
//          ({"em_2017"}, {6}, {"QCD"}, 0.949, 1.051)
//          ({"em_2017"}, {5}, {"QCD"}, 0.960, 1.040)
//          ({"em_2017"}, {2}, {"QCD"}, 0.958, 1.042)
//
//          ({"ttbar_2018"}, {1}, {"QCD"}, 0.958, 1.042)
//          ({"em_2018"}, {4}, {"QCD"}, 0.940, 1.061)
//          ({"em_2018"}, {3}, {"QCD"}, 0.959, 1.041)
//          ({"em_2018"}, {6}, {"QCD"}, 0.949, 1.051)
//          ({"em_2018"}, {5}, {"QCD"}, 0.960, 1.040)
//          ({"em_2018"}, {2}, {"QCD"}, 0.958, 1.042)
//
//        ); // neglect small uncertainties
//
//        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).bin_id({31,32,33,34,35,36,37,41,42,43,44,45,46,47,48,49,100,101,102,103,104,105,106,107,108}).AddSyst(cb,
//                                             "CMS_em_QCD_1JetRate_13TeV", "shape", SystMap<>::init(1.00));
//
//        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).bin_id({1,31,32,33,34,35,36,37,100,101,102,103,104,105,106,107,108}).AddSyst(cb,
//                                             "CMS_em_QCD_0JetShape_13TeV", "shape", SystMap<>::init(1.00));
//
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_1JetShape_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"ttbar","ttbar_2016","ttbar_2017","ttbar_2018"}, {1}, {"QCD"}, 0.955, 1.045)
//          ({"em","em_2016"}, {4}, {"QCD"}, 0.966, 1.034)
//          ({"em","em_2016"}, {3}, {"QCD"}, 0.955, 1.045)
//          ({"em","em_2016"}, {6}, {"QCD"}, 0.874, 1.121)
//          ({"em","em_2016"}, {5}, {"QCD"}, 0.940, 1.060)
//          ({"ttbar_2017"}, {1}, {"QCD"}, 0.959, 1.041)
//          ({"em_2017"}, {4}, {"QCD"}, 0.903, 1.099)
//          ({"em_2017"}, {3}, {"QCD"}, 0.960, 1.040)
//          ({"em_2017"}, {6}, {"QCD"}, 0.933, 1.068)
//          ({"em_2017"}, {5}, {"QCD"}, 0.963, 1.037)
//
//          ({"ttbar_2018"}, {1}, {"QCD"}, 0.959, 1.041)
//          ({"em_2018"}, {4}, {"QCD"}, 0.903, 1.099)
//          ({"em_2018"}, {3}, {"QCD"}, 0.960, 1.040)
//          ({"em_2018"}, {6}, {"QCD"}, 0.933, 1.068)
//          ({"em_2018"}, {5}, {"QCD"}, 0.963, 1.037)
//        );
//
//        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).bin_id({2,31,32,33,34,35,36,37,41,42,43,44,45,47,48,49,100,101,102,103,104,105,106,107,108}).AddSyst(cb,
//                                             "CMS_em_QCD_1JetShape_13TeV", "shape", SystMap<>::init(1.00));
//
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_IsoExtrap_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"ttbar","ttbar_2016"}, {1}, {"QCD"}, 0.967, 1.039)
//          ({"em","em_2016"}, {1}, {"QCD"}, 1.050, 0.956)
//          ({"em","em_2016"}, {4}, {"QCD"}, 1.034, 0.965)
//          ({"em","em_2016"}, {3}, {"QCD"}, 1.042, 0.962)
//          ({"em","em_2016"}, {6}, {"QCD"}, 1.040, 0.965) // set to same values as for bin 5 as statistics are too bad to estimate uncertainty
//          ({"em","em_2016"}, {5}, {"QCD"}, 1.040, 0.965)
//          ({"em","em_2016"}, {2}, {"QCD"}, 1.047, 0.960)
//          ({"ttbar_2017"}, {1}, {"QCD"}, 1.076, 0.930)
//          ({"em_2017"}, {1}, {"QCD"}, 1.084, 0.925)
//          ({"em_2017"}, {4}, {"QCD"}, 1.086, 0.923) // set to same values as for bin 3 as statistics are too bad to estimate uncertainty
//          ({"em_2017"}, {3}, {"QCD"}, 1.086, 0.923)
//          ({"em_2017"}, {6}, {"QCD"}, 1.064, 0.939)
//          ({"em_2017"}, {5}, {"QCD"}, 1.091, 0.920)
//          ({"em_2017"}, {2}, {"QCD"}, 1.081, 0.927)
//
//          ({"ttbar_2018"}, {1}, {"QCD"}, 1.076, 0.930)
//          ({"em_2018"}, {1}, {"QCD"}, 1.084, 0.925)
//          ({"em_2018"}, {4}, {"QCD"}, 1.086, 0.923) // set to same values as for bin 3 as statistics are too bad to estimate uncertainty
//          ({"em_2018"}, {3}, {"QCD"}, 1.086, 0.923)
//          ({"em_2018"}, {6}, {"QCD"}, 1.064, 0.939)
//          ({"em_2018"}, {5}, {"QCD"}, 1.091, 0.920)
//          ({"em_2018"}, {2}, {"QCD"}, 1.081, 0.927)
//        );
//
//        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).bin_id({31,32,33,34,35,36,37,41,42,43,44,45,47,48,49,100,101,102,103,104,105,106,107,108}).AddSyst(cb,
//                                             "CMS_em_QCD_IsoExtrap_13TeV", "shape", SystMap<>::init(1.00));

//        cb.cp().process({"QCD"}).channel({"em","em_2016","em_2017","em_2018"}).bin_id({2,3,4,5,6}, false).AddSyst(cb,
//                                             "CMS_em_QCD_BackgroundSubtraction_13TeV", "shape", SystMap<>::init(1.00)); // this uncertanty is only included as a shape uncertainty for he 0jet category no bin label in the name since it applied only to this category (the others will have bin labels in the name so that they are added as seperate uncertainties)
//
//
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_BackgroundSubtraction_ttbar_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"ttbar_2016"}, {1}, {"QCD"}, 1.902, 0.098)
//          ({"ttbar_2017"}, {1}, {"QCD"}, 1.359, 0.641)
//          ({"ttbar_2018"}, {1}, {"QCD"}, 1.359, 0.641)
//        );
//
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_BackgroundSubtraction_boosted_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"em_2016"}, {2}, {"QCD"}, 1.094, 0.906)
//          ({"em_2017"}, {2}, {"QCD"}, 1.055, 0.944)
//          ({"em_2018"}, {2}, {"QCD"}, 1.055, 0.944)
//        );       
//
//        // for dijet categories all uncertainties are treated as correlated (subtracted background fractions are ~ the same for all). For the boosted di-jet categories the stats are too low to get a good estimate of the uncertainty so take the same values as for the low boost categories
//        cb.cp().AddSyst(cb,
//          "CMS_em_QCD_BackgroundSubtraction_dijet_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
//          ({"em_2016"}, {3}, {"QCD"}, 1.203, 0.797)
//          ({"em_2016"}, {4}, {"QCD"}, 1.203, 0.797)
//          ({"em_2016"}, {6}, {"QCD"}, 1.144, 0.856)
//          ({"em_2016"}, {5}, {"QCD"}, 1.144, 0.856)
// 
//          ({"em_2017"}, {3}, {"QCD"}, 1.091, 0.909)
//          ({"em_2017"}, {4}, {"QCD"}, 1.091, 0.909)
//          ({"em_2017"}, {6}, {"QCD"}, 1.076, 0.924)
//          ({"em_2017"}, {5}, {"QCD"}, 1.076, 0.924)
//
//          ({"em_2018"}, {3}, {"QCD"}, 1.091, 0.909)
//          ({"em_2018"}, {4}, {"QCD"}, 1.091, 0.909)
//          ({"em_2018"}, {6}, {"QCD"}, 1.076, 0.924)
//          ({"em_2018"}, {5}, {"QCD"}, 1.076, 0.924)
//        );
        

        //##############################################################################
        //  Fake-Factor Method Uncertainties
        //##############################################################################

        // FF statistical uncertainties are uncorrelated between all years
        //
        // add lnN uncertainties fow now!
        //
        cb.cp().process({"jetFakes"}).AddSyst(cb,
                                                       "CMS_$CHANNEL_FF_$BIN_13TeV", "lnN", SystMap<>::init(1.15));

     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016","et_2017","et_2018"}).bin_id({2,3,4,5,6},false).AddSyst(cb, "ff_qcd_dm0_njet0_et_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016"}).bin_id({1},false).AddSyst(cb, "ff_qcd_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00)); //2.00
     //   cb.cp().process({"jetFakes"}).channel({"et_2017"}).bin_id({1},false).AddSyst(cb, "ff_qcd_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"et_2018"}).bin_id({1},false).AddSyst(cb, "ff_qcd_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016","et_2017","et_2018"}).bin_id({2,3,4,5,6},false).AddSyst(cb, "ff_w_dm0_njet0_et_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016"}).bin_id({1},false).AddSyst(cb, "ff_w_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00)); //2.00
     //   cb.cp().process({"jetFakes"}).channel({"et_2017"}).bin_id({1},false).AddSyst(cb, "ff_w_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"et_2018"}).bin_id({1},false).AddSyst(cb, "ff_w_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016","et_2017","et_2018"}).bin_id({1,2,3,4,5,6}).AddSyst(cb, "ff_tt_dm0_njet0_et_stat", "shape", SystMap<>::init(1.00));
     //   //cb.cp().process({"jetFakes"}).channel({"et","et_2016","et_2017"}).bin_id({1,2,3,4,5,6}).AddSyst(cb, "ff_tt_dm0_njet1_et_stat", "shape", SystMap<>::init(1.00));

     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).bin_id({2,3,4,5,6},false).AddSyst(cb, "ff_qcd_dm0_njet0_mt_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).bin_id({1},false).AddSyst(cb, "ff_qcd_dm0_njet1_mt_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).bin_id({2,3,4,5,6},false).AddSyst(cb, "ff_w_dm0_njet0_mt_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).bin_id({1},false).AddSyst(cb, "ff_w_dm0_njet1_mt_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).bin_id({1,2,3,4,5,6}).AddSyst(cb, "ff_tt_dm0_njet0_mt_stat", "shape", SystMap<>::init(1.00));
     //   //cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017"}).bin_id({1,2,3,4,5,6}).AddSyst(cb, "ff_tt_dm0_njet1_mt_stat", "shape", SystMap<>::init(1.00));

     //   // tt statistical uncertainties

     //   cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017","tt_2018"}).bin_id({2,3,4,5,6},false).AddSyst(cb, "ff_qcd_dm0_njet0_tt_stat", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017","tt_2018"}).bin_id({1},false).AddSyst(cb, "ff_qcd_dm0_njet1_tt_stat", "shape", SystMap<>::init(1.00));

     //   // FF systematic uncertainties 

     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018","et","et_2016","et_2017","et_2018"}).AddSyst(cb, "ff_w_syst", "shape", SystMap<>::init(1.00));
     //   //cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","et","et_2016","et_2017"}).AddSyst(cb, "ff_tt_syst", "shape", SystMap<>::init(1.00)); // dropping for now since FF are the same as the nominal

     //   cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb, "ff_w_tt_syst", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb, "ff_tt_tt_syst", "shape", SystMap<>::init(1.00));

     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016","et_2017","et_2018"}).AddSyst(cb, "ff_qcd_et_syst", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb, "ff_qcd_mt_syst", "shape", SystMap<>::init(1.00));
     //   cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb, "ff_qcd_tt_syst", "shape", SystMap<>::init(1.00));

     //   //cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017"}).AddSyst(cb,"ff_w_frac_tt_syst", "shape", SystMap<>::init(1.00));
     //   //cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017"}).AddSyst(cb,"ff_tt_frac_tt_syst", "shape", SystMap<>::init(1.00));

     //   // et subtraction uncertainties
     //   cb.cp().process({"jetFakes"}).channel({"et","et_2016","et_2017","et_2018"}).AddSyst(cb, "ff_sub_syst_et", "shape", SystMap<>::init(1.00));

     //   // mt subtraction uncertainties
     //   cb.cp().process({"jetFakes"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb, "ff_sub_syst_mt", "shape", SystMap<>::init(1.00));

     //   // tt subtraction uncertainties
     //   cb.cp().process({"jetFakes"}).channel({"tt","tt_2016","tt_2017","tt_2018"}).AddSyst(cb, "ff_sub_syst_tt", "shape", SystMap<>::init(1.00));

        //##############################################################################
        //  DY LO->NLO reweighting, Between no and twice the correction.
        //##############################################################################
        //
        cb.cp().process( {"ZTT","ZJ","ZL","ZLL"}).AddSyst(cb,
                                             "CMS_htt_dyShape_13TeV", "shape", SystMap<>::init(0.1));
        
        
        //##############################################################################
        // Ttbar shape reweighting, Between no and twice the correction
        //##############################################################################
        
        cb.cp().process( {"TTJ","TTT","TT"}).AddSyst(cb,
                                        "CMS_htt_ttbarShape_13TeV", "shape", SystMap<>::init(1.00));
        
        //##############################################################################
        // ZL shape  and electron/muon  to tau fake only in  mt and et channels (updated March 22)
        //##############################################################################

        // Add back later!   
        //cb.cp().process( {"ZL"}).channel({"et","et_2016","et_2017","et_2018"}).AddSyst(cb,
        //                                                 "CMS_ZLShape_et_1prong_13TeV", "shape", SystMap<>::init(1.00));
        //cb.cp().process( {"ZL"}).channel({"et","et_2016","et_2017","et_2018"}).AddSyst(cb,
        //                                                 "CMS_ZLShape_et_1prong1pizero_13TeV", "shape", SystMap<>::init(1.00));

        //cb.cp().process( {"ZL"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,
        //                                                 "CMS_ZLShape_mt_1prong_13TeV", "shape", SystMap<>::init(1.00));
        //cb.cp().process( {"ZL"}).channel({"mt","mt_2016","mt_2017","mt_2018"}).AddSyst(cb,
        //                                                 "CMS_ZLShape_mt_1prong1pizero_13TeV", "shape", SystMap<>::init(1.00));
       
        // weighted avarages of recommended tau POG uncertainties provided in bins of eta
        cb.cp().process({"ZL","EWKZ"}).channel({"mt","mt_2016"}).AddSyst(cb,
                                                        "CMS_htt_mFakeTau_13TeV", "lnN", SystMap<>::init(1.27));
        cb.cp().process({"ZL","EWKZ"}).channel({"mt_2017"}).AddSyst(cb,
                                                        "CMS_htt_mFakeTau_13TeV", "lnN", SystMap<>::init(1.27));
        cb.cp().process({"ZL","EWKZ"}).channel({"mt_2018"}).AddSyst(cb,
                                                        "CMS_htt_mFakeTau_13TeV", "lnN", SystMap<>::init(1.27));
        cb.cp().process({"ZL","EWKZ"}).channel({"et","et_2016"}).AddSyst(cb,
                                                        "CMS_htt_eFakeTau_13TeV", "lnN", SystMap<>::init(1.11));
        cb.cp().process({"ZL","EWKZ"}).channel({"tt","tt_2016"}).AddSyst(cb,
                                                        "CMS_htt_eFakeTau_13TeV", "lnN", SystMap<>::init(1.11));
        cb.cp().process({"ZL","EWKZ"}).channel({"et_2017"}).AddSyst(cb,
                                                        "CMS_htt_eFakeTau_13TeV", "lnN", SystMap<>::init(1.11));
        cb.cp().process({"ZL","EWKZ"}).channel({"et_2018"}).AddSyst(cb,
                                                        "CMS_htt_eFakeTau_13TeV", "lnN", SystMap<>::init(1.11));
        cb.cp().process({"ZL","EWKZ"}).channel({"tt_2017"}).AddSyst(cb,
                                                        "CMS_htt_eFakeTau_13TeV", "lnN", SystMap<>::init(1.23));
        cb.cp().process({"ZL","EWKZ"}).channel({"tt_2018"}).AddSyst(cb,
                                                        "CMS_htt_eFakeTau_13TeV", "lnN", SystMap<>::init(1.23));
        
        //##############################################################################
        // Theoretical Uncertainties on signal (update me)
        //##############################################################################
        // don't use acceptance uncertainties on VBF as there isn't an easy way to get these for the JHU samples (and they are expected to be small for this process)
        // Removed PDF acceptance uncertainties for ggH as these are verysmall compared to PDF uncertainty on XS and scale uncertainty on acceptance/shape
        
        //scale_gg on signal
        cb.cp().process(ggH_sig_procs).process({"ggH_ph_htt"},false).bin_id({2,3,4,5,6,31,32,33,34,35,36,37,41,42,43,44,45,46,47,48,49}).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018","em","em_2016","em_2017","em_2018"}).AddSyst(cb,
                                             "CMS_scale_gg_13TeV", "shape", SystMap<>::init(1.00));
       
        cb.cp().AddSyst(cb,
          "CMS_scale_gg_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
          ({"tt","tt_2016"}, {1}, {"ggHps_htt"}, 0.937, 1.063)
          ({"tt","tt_2016"}, {1}, {"ggHsm_htt"}, 0.928, 1.069)
          ({"tt","tt_2016"}, {1}, {"ggHmm_htt"}, 0.942, 1.059)
          ({"mt","mt_2016"}, {1}, {"ggHps_htt"}, 0.948, 1.054)
          ({"mt","mt_2016"}, {1}, {"ggHsm_htt"}, 0.939, 1.061)
          ({"mt","mt_2016"}, {1}, {"ggHmm_htt"}, 0.946, 1.056)
          ({"et","et_2016"}, {1}, {"ggHps_htt"}, 0.946, 1.056)
          ({"et","et_2016"}, {1}, {"ggHsm_htt"}, 0.966, 1.042)
          ({"et","et_2016"}, {1}, {"ggHmm_htt"}, 0.929, 1.069)
          ({"em","em_2016"}, {1}, {"ggHps_htt"}, 0.947, 1.056)
          ({"em","em_2016"}, {1}, {"ggHsm_htt"}, 0.942, 1.058)
          ({"em","em_2016"}, {1}, {"ggHmm_htt"}, 0.950, 1.053)
          ({"em_2017"}, {1}, {"ggHps_htt"}, 0.975, 1.027)
          ({"em_2017"}, {1}, {"ggHmm_htt"}, 0.963, 1.037)
          ({"em_2017"}, {1}, {"ggHsm_htt"}, 0.954, 1.044)
          ({"et_2017"}, {1}, {"ggHps_htt"}, 0.963, 1.036)
          ({"et_2017"}, {1}, {"ggHmm_htt"}, 0.973, 1.031)
          ({"et_2017"}, {1}, {"ggHsm_htt"}, 0.946, 1.050)
          ({"mt_2017"}, {1}, {"ggHps_htt"}, 0.987, 1.019)
          ({"mt_2017"}, {1}, {"ggHmm_htt"}, 0.966, 1.035)
          ({"mt_2017"}, {1}, {"ggHsm_htt"}, 0.952, 1.047)
          ({"tt_2017"}, {1}, {"ggHps_htt"}, 0.975, 1.029)
          ({"tt_2017"}, {1}, {"ggHmm_htt"}, 0.966, 1.035)
          ({"tt_2017"}, {1}, {"ggHsm_htt"}, 0.956, 1.043)

          ({"em_2018"}, {1}, {"ggHps_htt"}, 0.975, 1.027)
          ({"em_2018"}, {1}, {"ggHmm_htt"}, 0.963, 1.037)
          ({"em_2018"}, {1}, {"ggHsm_htt"}, 0.954, 1.044)
          ({"et_2018"}, {1}, {"ggHps_htt"}, 0.963, 1.036)
          ({"et_2018"}, {1}, {"ggHmm_htt"}, 0.973, 1.031)
          ({"et_2018"}, {1}, {"ggHsm_htt"}, 0.946, 1.050)
          ({"mt_2018"}, {1}, {"ggHps_htt"}, 0.987, 1.019)
          ({"mt_2018"}, {1}, {"ggHmm_htt"}, 0.966, 1.035)
          ({"mt_2018"}, {1}, {"ggHsm_htt"}, 0.952, 1.047)
          ({"tt_2018"}, {1}, {"ggHps_htt"}, 0.975, 1.029)
          ({"tt_2018"}, {1}, {"ggHmm_htt"}, 0.966, 1.035)
          ({"tt_2018"}, {1}, {"ggHsm_htt"}, 0.956, 1.043)
 
        ); 
       
        cb.cp().process(ggH_sig_procs).process({"ggH_ph_htt"},false).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018","em","em_2016","em_2017","em_2018"}).bin_id({2,3,4,5,6}).AddSyst(cb,
                                             "CMS_FiniteQuarkMass_13TeV", "shape", SystMap<>::init(1.00)); // this uncertainty takes the difference between the finite top-mass dependence and the EFT


        cb.cp().AddSyst(cb,
          "CMS_FiniteQuarkMass_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
          ({"mt","mt_2016"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"mt","mt_2016"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"mt","mt_2016"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"et","et_2016"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"et","et_2016"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"et","et_2016"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"tt","tt_2016"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"tt","tt_2016"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"tt","tt_2016"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"em","em_2016"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"em","em_2016"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"em","em_2016"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"mt_2017"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"mt_2017"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"mt_2017"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"et_2017"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"et_2017"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"et_2017"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"tt_2017"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"tt_2017"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"tt_2017"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"em_2017"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"em_2017"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"em_2017"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)         

          ({"mt_2018"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"mt_2018"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"mt_2018"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"et_2018"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"et_2018"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"et_2018"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"tt_2018"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"tt_2018"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"tt_2018"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)
          ({"em_2018"}, {1}, {"ggHps_htt"}, 1.001, 0.988)
          ({"em_2018"}, {1}, {"ggHmm_htt"}, 1.001, 0.988)
          ({"em_2018"}, {1}, {"ggHsm_htt"}, 1.001, 0.988)         
        ); 

        // PS uncertainty affects njets and pT distribution so is included as a shape uncertainty for the boosted category where pT is fitted
        cb.cp().process(ggH_sig_procs).process({"ggH_ph_htt"},false).bin_id({2,31,32,33,34,35,36,37,41,42,43,44,45,46,47,48,49}).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018","em","em_2016","em_2017","em_2018"}).AddSyst(cb,
                                             "CMS_PS_ggH_13TeV", "shape", SystMap<>::init(1.00));

        cb.cp().AddSyst(cb,
          "CMS_PS_ggH_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
          ({"tt","tt_2016"}, {1}, {"ggHps_htt"}, 0.981, 1.016)
          ({"tt","tt_2016"}, {1}, {"ggHsm_htt"}, 0.984, 1.012)
          ({"tt","tt_2016"}, {1}, {"ggHmm_htt"}, 0.977, 1.019)
          //({"tt","tt_2016"}, {2}, {"ggHps_htt"}, 0.984, 1.016)
          //({"tt","tt_2016"}, {2}, {"ggHsm_htt"}, 0.982, 1.016)
          //({"tt","tt_2016"}, {2}, {"ggHmm_htt"}, 0.983, 1.016)
          ({"tt","tt_2016"}, {3}, {"ggHps_htt"}, 1.002, 1.003)
          ({"tt","tt_2016"}, {3}, {"ggHsm_htt"}, 0.993, 1.010)
          ({"tt","tt_2016"}, {3}, {"ggHmm_htt"}, 0.997, 1.007)
          ({"tt","tt_2016"}, {4}, {"ggHps_htt"}, 1.018, 0.991)
          ({"tt","tt_2016"}, {4}, {"ggHsm_htt"}, 1.016, 0.992)
          ({"tt","tt_2016"}, {4}, {"ggHmm_htt"}, 1.017, 0.992)
          ({"tt","tt_2016"}, {5}, {"ggHps_htt"}, 0.993, 1.010)
          ({"tt","tt_2016"}, {5}, {"ggHsm_htt"}, 0.999, 1.004)
          ({"tt","tt_2016"}, {5}, {"ggHmm_htt"}, 0.997, 1.006)
          ({"tt","tt_2016"}, {6}, {"ggHps_htt"}, 1.018, 0.991)
          ({"tt","tt_2016"}, {6}, {"ggHsm_htt"}, 1.020, 0.990)
          ({"tt","tt_2016"}, {6}, {"ggHmm_htt"}, 1.019, 0.991)
          ({"mt","mt_2016"}, {1}, {"ggHps_htt"}, 0.990, 1.007)
          ({"mt","mt_2016"}, {1}, {"ggHsm_htt"}, 0.993, 1.005)
          ({"mt","mt_2016"}, {1}, {"ggHmm_htt"}, 0.989, 1.008)
          //({"mt","mt_2016"}, {2}, {"ggHps_htt"}, 0.986, 1.014)
          //({"mt","mt_2016"}, {2}, {"ggHsm_htt"}, 0.988, 1.012)
          //({"mt","mt_2016"}, {2}, {"ggHmm_htt"}, 0.987, 1.013)
          ({"mt","mt_2016"}, {3}, {"ggHps_htt"}, 0.986, 1.014)
          ({"mt","mt_2016"}, {3}, {"ggHsm_htt"}, 0.983, 1.017)
          ({"mt","mt_2016"}, {3}, {"ggHmm_htt"}, 0.983, 1.017)
          ({"mt","mt_2016"}, {4}, {"ggHps_htt"}, 1.011, 0.996)
          ({"mt","mt_2016"}, {4}, {"ggHsm_htt"}, 1.012, 0.995)
          ({"mt","mt_2016"}, {4}, {"ggHmm_htt"}, 1.012, 0.995)
          ({"mt","mt_2016"}, {5}, {"ggHps_htt"}, 0.984, 1.017)
          ({"mt","mt_2016"}, {5}, {"ggHsm_htt"}, 0.988, 1.012)
          ({"mt","mt_2016"}, {5}, {"ggHmm_htt"}, 0.980, 1.020)
          ({"mt","mt_2016"}, {6}, {"ggHps_htt"}, 1.013, 0.994)
          ({"mt","mt_2016"}, {6}, {"ggHsm_htt"}, 1.011, 0.996)
          ({"mt","mt_2016"}, {6}, {"ggHmm_htt"}, 1.011, 0.996)
          ({"et","et_2016"}, {1}, {"ggHps_htt"}, 0.985, 1.012)
          ({"et","et_2016"}, {1}, {"ggHsm_htt"}, 0.985, 1.012)
          ({"et","et_2016"}, {1}, {"ggHmm_htt"}, 0.984, 1.013)
          //({"et","et_2016"}, {2}, {"ggHps_htt"}, 0.983, 1.016)
          //({"et","et_2016"}, {2}, {"ggHsm_htt"}, 0.982, 1.017)
          //({"et","et_2016"}, {2}, {"ggHmm_htt"}, 0.980, 1.018)
          ({"et","et_2016"}, {3}, {"ggHps_htt"}, 0.989, 1.011)
          ({"et","et_2016"}, {3}, {"ggHsm_htt"}, 0.993, 1.009)
          ({"et","et_2016"}, {3}, {"ggHmm_htt"}, 0.990, 1.011)
          ({"et","et_2016"}, {4}, {"ggHps_htt"}, 1.016, 0.993)
          ({"et","et_2016"}, {4}, {"ggHsm_htt"}, 1.015, 0.993)
          ({"et","et_2016"}, {4}, {"ggHmm_htt"}, 1.010, 0.996)
          ({"et","et_2016"}, {5}, {"ggHps_htt"}, 0.986, 1.014)
          ({"et","et_2016"}, {5}, {"ggHsm_htt"}, 0.984, 1.015)
          ({"et","et_2016"}, {5}, {"ggHmm_htt"}, 0.984, 1.018)
          ({"et","et_2016"}, {6}, {"ggHps_htt"}, 1.016, 0.993)
          ({"et","et_2016"}, {6}, {"ggHsm_htt"}, 1.012, 0.995)
          ({"et","et_2016"}, {6}, {"ggHmm_htt"}, 1.015, 0.993)
          ({"em","em_2016"}, {1}, {"ggHps_htt"}, 1.006, 0.993)
          ({"em","em_2016"}, {1}, {"ggHsm_htt"}, 1.005, 0.993)
          ({"em","em_2016"}, {1}, {"ggHmm_htt"}, 1.003, 0.996)
          //({"em","em_2016"}, {2}, {"ggHps_htt"}, 0.995, 1.007)
          //({"em","em_2016"}, {2}, {"ggHsm_htt"}, 1.000, 1.003)
          //({"em","em_2016"}, {2}, {"ggHmm_htt"}, 0.996, 1.006)
          ({"em","em_2016"}, {3}, {"ggHps_htt"}, 0.984, 1.015)
          ({"em","em_2016"}, {3}, {"ggHsm_htt"}, 0.982, 1.017)
          ({"em","em_2016"}, {3}, {"ggHmm_htt"}, 0.984, 1.015)
          ({"em","em_2016"}, {4}, {"ggHps_htt"}, 1.004, 1.001)
          ({"em","em_2016"}, {4}, {"ggHsm_htt"}, 1.008, 0.999)
          ({"em","em_2016"}, {4}, {"ggHmm_htt"}, 1.006, 1.000)
          ({"em","em_2016"}, {5}, {"ggHps_htt"}, 0.992, 1.009)
          ({"em","em_2016"}, {5}, {"ggHsm_htt"}, 0.995, 1.012)
          ({"em","em_2016"}, {5}, {"ggHmm_htt"}, 0.985, 1.015)
          ({"em","em_2016"}, {6}, {"ggHps_htt"}, 1.008, 0.998)
          ({"em","em_2016"}, {6}, {"ggHsm_htt"}, 1.008, 0.998)
          ({"em","em_2016"}, {6}, {"ggHmm_htt"}, 1.007, 0.999)

          ({"em_2017"}, {1}, {"ggHps_htt"}, 0.989, 0.990)
          ({"em_2017"}, {1}, {"ggHmm_htt"}, 0.990, 0.989)
          ({"em_2017"}, {1}, {"ggHsm_htt"}, 0.991, 0.989)
          ({"em_2017"}, {4}, {"ggHps_htt"}, 1.006, 1.011)
          ({"em_2017"}, {4}, {"ggHmm_htt"}, 1.006, 1.012)
          ({"em_2017"}, {4}, {"ggHsm_htt"}, 1.007, 1.010)
          ({"em_2017"}, {3}, {"ggHps_htt"}, 0.997, 1.025)
          ({"em_2017"}, {3}, {"ggHmm_htt"}, 0.995, 1.025)
          ({"em_2017"}, {3}, {"ggHsm_htt"}, 0.996, 1.023)
          ({"em_2017"}, {6}, {"ggHps_htt"}, 1.007, 1.011)
          ({"em_2017"}, {6}, {"ggHmm_htt"}, 1.007, 1.008)
          ({"em_2017"}, {6}, {"ggHsm_htt"}, 1.007, 1.009)
          ({"em_2017"}, {5}, {"ggHps_htt"}, 0.993, 1.025)
          ({"em_2017"}, {5}, {"ggHmm_htt"}, 0.995, 1.024)
          ({"em_2017"}, {5}, {"ggHsm_htt"}, 0.997, 1.021)
          //({"em_2017"}, {2}, {"ggHps_htt"}, 1.006, 1.019)
          //({"em_2017"}, {2}, {"ggHmm_htt"}, 1.007, 1.018)
          //({"em_2017"}, {2}, {"ggHsm_htt"}, 1.007, 1.017)          
          ({"et_2017"}, {1}, {"ggHps_htt"}, 0.975, 1.000)
          ({"et_2017"}, {1}, {"ggHmm_htt"}, 0.973, 1.002)
          ({"et_2017"}, {1}, {"ggHsm_htt"}, 0.976, 1.001)
          ({"et_2017"}, {4}, {"ggHps_htt"}, 1.009, 0.998)
          ({"et_2017"}, {4}, {"ggHmm_htt"}, 1.010, 0.998)
          ({"et_2017"}, {4}, {"ggHsm_htt"}, 1.009, 1.000)
          ({"et_2017"}, {3}, {"ggHps_htt"}, 0.995, 1.016)
          ({"et_2017"}, {3}, {"ggHmm_htt"}, 0.995, 1.019)
          ({"et_2017"}, {3}, {"ggHsm_htt"}, 0.993, 1.020)
          ({"et_2017"}, {6}, {"ggHps_htt"}, 1.011, 0.994)
          ({"et_2017"}, {6}, {"ggHmm_htt"}, 1.010, 0.997)
          ({"et_2017"}, {6}, {"ggHsm_htt"}, 1.010, 0.998)
          ({"et_2017"}, {5}, {"ggHps_htt"}, 0.997, 1.019)
          ({"et_2017"}, {5}, {"ggHmm_htt"}, 0.992, 1.019)
          ({"et_2017"}, {5}, {"ggHsm_htt"}, 0.992, 1.021)
          ({"et_2017"}, {2}, {"ggHps_htt"}, 0.994, 1.025)
          ({"et_2017"}, {2}, {"ggHmm_htt"}, 0.994, 1.025)
          ({"et_2017"}, {2}, {"ggHsm_htt"}, 0.994, 1.026)
          ({"mt_2017"}, {1}, {"ggHps_htt"}, 0.977, 0.999)
          ({"mt_2017"}, {1}, {"ggHmm_htt"}, 0.980, 0.996)
          ({"mt_2017"}, {1}, {"ggHsm_htt"}, 0.982, 0.996)
          ({"mt_2017"}, {4}, {"ggHps_htt"}, 1.008, 1.003)
          ({"mt_2017"}, {4}, {"ggHmm_htt"}, 1.008, 1.003)
          ({"mt_2017"}, {4}, {"ggHsm_htt"}, 1.009, 1.001)
          ({"mt_2017"}, {3}, {"ggHps_htt"}, 0.998, 1.018)
          ({"mt_2017"}, {3}, {"ggHmm_htt"}, 0.991, 1.023)
          ({"mt_2017"}, {3}, {"ggHsm_htt"}, 0.992, 1.022)
          ({"mt_2017"}, {6}, {"ggHps_htt"}, 1.010, 0.997)
          ({"mt_2017"}, {6}, {"ggHmm_htt"}, 1.009, 1.003)
          ({"mt_2017"}, {6}, {"ggHsm_htt"}, 1.009, 1.002)
          ({"mt_2017"}, {5}, {"ggHps_htt"}, 1.000, 1.018)
          ({"mt_2017"}, {5}, {"ggHmm_htt"}, 0.992, 1.023)
          ({"mt_2017"}, {5}, {"ggHsm_htt"}, 0.996, 1.017)
          //({"mt_2017"}, {2}, {"ggHps_htt"}, 0.997, 1.023)
          //({"mt_2017"}, {2}, {"ggHmm_htt"}, 0.998, 1.023)
          //({"mt_2017"}, {2}, {"ggHsm_htt"}, 0.998, 1.022)
          ({"tt_2017"}, {1}, {"ggHps_htt"}, 0.974, 1.001)
          ({"tt_2017"}, {1}, {"ggHmm_htt"}, 0.972, 1.006)
          ({"tt_2017"}, {1}, {"ggHsm_htt"}, 0.972, 1.004)
          ({"tt_2017"}, {4}, {"ggHps_htt"}, 1.011, 0.992)
          ({"tt_2017"}, {4}, {"ggHmm_htt"}, 1.011, 0.993)
          ({"tt_2017"}, {4}, {"ggHsm_htt"}, 1.011, 0.994)
          ({"tt_2017"}, {3}, {"ggHps_htt"}, 1.002, 1.006)
          ({"tt_2017"}, {3}, {"ggHmm_htt"}, 0.996, 1.012)
          ({"tt_2017"}, {3}, {"ggHsm_htt"}, 0.999, 1.011)
          ({"tt_2017"}, {6}, {"ggHps_htt"}, 1.011, 0.992)
          ({"tt_2017"}, {6}, {"ggHmm_htt"}, 1.010, 0.998)
          ({"tt_2017"}, {6}, {"ggHsm_htt"}, 1.011, 0.994)
          ({"tt_2017"}, {5}, {"ggHps_htt"}, 1.001, 1.010)
          ({"tt_2017"}, {5}, {"ggHmm_htt"}, 1.000, 1.011)
          ({"tt_2017"}, {5}, {"ggHsm_htt"}, 0.999, 1.012)
          //({"tt_2017"}, {2}, {"ggHps_htt"}, 0.996, 1.023)
          //({"tt_2017"}, {2}, {"ggHmm_htt"}, 0.995, 1.025)
          //({"tt_2017"}, {2}, {"ggHsm_htt"}, 0.994, 1.026)
          //
          ({"em_2018"}, {1}, {"ggHps_htt"}, 0.989, 0.990)
          ({"em_2018"}, {1}, {"ggHmm_htt"}, 0.990, 0.989)
          ({"em_2018"}, {1}, {"ggHsm_htt"}, 0.991, 0.989)
          ({"em_2018"}, {4}, {"ggHps_htt"}, 1.006, 1.011)
          ({"em_2018"}, {4}, {"ggHmm_htt"}, 1.006, 1.012)
          ({"em_2018"}, {4}, {"ggHsm_htt"}, 1.007, 1.010)
          ({"em_2018"}, {3}, {"ggHps_htt"}, 0.997, 1.025)
          ({"em_2018"}, {3}, {"ggHmm_htt"}, 0.995, 1.025)
          ({"em_2018"}, {3}, {"ggHsm_htt"}, 0.996, 1.023)
          ({"em_2018"}, {6}, {"ggHps_htt"}, 1.007, 1.011)
          ({"em_2018"}, {6}, {"ggHmm_htt"}, 1.007, 1.008)
          ({"em_2018"}, {6}, {"ggHsm_htt"}, 1.007, 1.009)
          ({"em_2018"}, {5}, {"ggHps_htt"}, 0.993, 1.025)
          ({"em_2018"}, {5}, {"ggHmm_htt"}, 0.995, 1.024)
          ({"em_2018"}, {5}, {"ggHsm_htt"}, 0.997, 1.021)
          //({"em_2018"}, {2}, {"ggHps_htt"}, 1.006, 1.019)
          //({"em_2018"}, {2}, {"ggHmm_htt"}, 1.007, 1.018)
          //({"em_2018"}, {2}, {"ggHsm_htt"}, 1.007, 1.017)          
          ({"et_2018"}, {1}, {"ggHps_htt"}, 0.975, 1.000)
          ({"et_2018"}, {1}, {"ggHmm_htt"}, 0.973, 1.002)
          ({"et_2018"}, {1}, {"ggHsm_htt"}, 0.976, 1.001)
          ({"et_2018"}, {4}, {"ggHps_htt"}, 1.009, 0.998)
          ({"et_2018"}, {4}, {"ggHmm_htt"}, 1.010, 0.998)
          ({"et_2018"}, {4}, {"ggHsm_htt"}, 1.009, 1.000)
          ({"et_2018"}, {3}, {"ggHps_htt"}, 0.995, 1.016)
          ({"et_2018"}, {3}, {"ggHmm_htt"}, 0.995, 1.019)
          ({"et_2018"}, {3}, {"ggHsm_htt"}, 0.993, 1.020)
          ({"et_2018"}, {6}, {"ggHps_htt"}, 1.011, 0.994)
          ({"et_2018"}, {6}, {"ggHmm_htt"}, 1.010, 0.997)
          ({"et_2018"}, {6}, {"ggHsm_htt"}, 1.010, 0.998)
          ({"et_2018"}, {5}, {"ggHps_htt"}, 0.997, 1.019)
          ({"et_2018"}, {5}, {"ggHmm_htt"}, 0.992, 1.019)
          ({"et_2018"}, {5}, {"ggHsm_htt"}, 0.992, 1.021)
          ({"et_2018"}, {2}, {"ggHps_htt"}, 0.994, 1.025)
          ({"et_2018"}, {2}, {"ggHmm_htt"}, 0.994, 1.025)
          ({"et_2018"}, {2}, {"ggHsm_htt"}, 0.994, 1.026)
          ({"mt_2018"}, {1}, {"ggHps_htt"}, 0.977, 0.999)
          ({"mt_2018"}, {1}, {"ggHmm_htt"}, 0.980, 0.996)
          ({"mt_2018"}, {1}, {"ggHsm_htt"}, 0.982, 0.996)
          ({"mt_2018"}, {4}, {"ggHps_htt"}, 1.008, 1.003)
          ({"mt_2018"}, {4}, {"ggHmm_htt"}, 1.008, 1.003)
          ({"mt_2018"}, {4}, {"ggHsm_htt"}, 1.009, 1.001)
          ({"mt_2018"}, {3}, {"ggHps_htt"}, 0.998, 1.018)
          ({"mt_2018"}, {3}, {"ggHmm_htt"}, 0.991, 1.023)
          ({"mt_2018"}, {3}, {"ggHsm_htt"}, 0.992, 1.022)
          ({"mt_2018"}, {6}, {"ggHps_htt"}, 1.010, 0.997)
          ({"mt_2018"}, {6}, {"ggHmm_htt"}, 1.009, 1.003)
          ({"mt_2018"}, {6}, {"ggHsm_htt"}, 1.009, 1.002)
          ({"mt_2018"}, {5}, {"ggHps_htt"}, 1.000, 1.018)
          ({"mt_2018"}, {5}, {"ggHmm_htt"}, 0.992, 1.023)
          ({"mt_2018"}, {5}, {"ggHsm_htt"}, 0.996, 1.017)
          //({"mt_2018"}, {2}, {"ggHps_htt"}, 0.997, 1.023)
          //({"mt_2018"}, {2}, {"ggHmm_htt"}, 0.998, 1.023)
          //({"mt_2018"}, {2}, {"ggHsm_htt"}, 0.998, 1.022)
          ({"tt_2018"}, {1}, {"ggHps_htt"}, 0.974, 1.001)
          ({"tt_2018"}, {1}, {"ggHmm_htt"}, 0.972, 1.006)
          ({"tt_2018"}, {1}, {"ggHsm_htt"}, 0.972, 1.004)
          ({"tt_2018"}, {4}, {"ggHps_htt"}, 1.011, 0.992)
          ({"tt_2018"}, {4}, {"ggHmm_htt"}, 1.011, 0.993)
          ({"tt_2018"}, {4}, {"ggHsm_htt"}, 1.011, 0.994)
          ({"tt_2018"}, {3}, {"ggHps_htt"}, 1.002, 1.006)
          ({"tt_2018"}, {3}, {"ggHmm_htt"}, 0.996, 1.012)
          ({"tt_2018"}, {3}, {"ggHsm_htt"}, 0.999, 1.011)
          ({"tt_2018"}, {6}, {"ggHps_htt"}, 1.011, 0.992)
          ({"tt_2018"}, {6}, {"ggHmm_htt"}, 1.010, 0.998)
          ({"tt_2018"}, {6}, {"ggHsm_htt"}, 1.011, 0.994)
          ({"tt_2018"}, {5}, {"ggHps_htt"}, 1.001, 1.010)
          ({"tt_2018"}, {5}, {"ggHmm_htt"}, 1.000, 1.011)
          ({"tt_2018"}, {5}, {"ggHsm_htt"}, 0.999, 1.012)
          //({"tt_2018"}, {2}, {"ggHps_htt"}, 0.996, 1.023)
          //({"tt_2018"}, {2}, {"ggHmm_htt"}, 0.995, 1.025)
          //({"tt_2018"}, {2}, {"ggHsm_htt"}, 0.994, 1.026)
        );

        cb.cp().process(ggH_sig_procs).bin_id({31,32,33,34,35,36,37,41,42,43,44,45,46,47,48,49}).channel({"et","et_2016","et_2017","et_2018","mt","mt_2016","mt_2017","mt_2018","tt","tt_2016","tt_2017","tt_2018","em","em_2016","em_2017","em_2018"}).AddSyst(cb,
                                             "CMS_UE_ggH_13TeV", "shape", SystMap<>::init(1.00));

        // UE uncertainty affects njets distributions so included as lnN for cut based approach.
        cb.cp().AddSyst(cb,
          "CMS_UE_ggH_13TeV", "lnN", SystMapAsymm<channel,bin_id,process>::init
          ({"tt","tt_2016"}, {1}, {"ggHps_htt"}, 0.997, 1.009)
          ({"tt","tt_2016"}, {1}, {"ggHsm_htt"}, 0.997, 1.010)
          ({"tt","tt_2016"}, {1}, {"ggHmm_htt"}, 0.997, 1.010)
          ({"tt","tt_2016"}, {2}, {"ggHps_htt"}, 0.993, 1.026)
          ({"tt","tt_2016"}, {2}, {"ggHsm_htt"}, 0.993, 1.025)
          ({"tt","tt_2016"}, {2}, {"ggHmm_htt"}, 0.993, 1.025)
          ({"tt","tt_2016"}, {3}, {"ggHps_htt"}, 0.992, 1.036)
          ({"tt","tt_2016"}, {3}, {"ggHsm_htt"}, 0.992, 1.033)
          ({"tt","tt_2016"}, {3}, {"ggHmm_htt"}, 0.992, 1.034)
          ({"tt","tt_2016"}, {4}, {"ggHps_htt"}, 0.990, 1.037)
          ({"tt","tt_2016"}, {4}, {"ggHsm_htt"}, 0.990, 1.037)
          ({"tt","tt_2016"}, {4}, {"ggHmm_htt"}, 0.990, 1.037)
          ({"tt","tt_2016"}, {5}, {"ggHps_htt"}, 0.992, 1.034)
          ({"tt","tt_2016"}, {5}, {"ggHsm_htt"}, 0.992, 1.032)
          ({"tt","tt_2016"}, {5}, {"ggHmm_htt"}, 0.991, 1.034)
          ({"tt","tt_2016"}, {6}, {"ggHps_htt"}, 0.989, 1.037)
          ({"tt","tt_2016"}, {6}, {"ggHsm_htt"}, 0.989, 1.038)
          ({"tt","tt_2016"}, {6}, {"ggHmm_htt"}, 0.989, 1.037)
          ({"mt","mt_2016"}, {1}, {"ggHps_htt"}, 1.000, 0.999)
          ({"mt","mt_2016"}, {1}, {"ggHsm_htt"}, 1.000, 0.998)
          ({"mt","mt_2016"}, {1}, {"ggHmm_htt"}, 1.000, 0.998)
          ({"mt","mt_2016"}, {2}, {"ggHps_htt"}, 0.995, 1.017)
          ({"mt","mt_2016"}, {2}, {"ggHsm_htt"}, 0.995, 1.017)
          ({"mt","mt_2016"}, {2}, {"ggHmm_htt"}, 0.995, 1.017)
          ({"mt","mt_2016"}, {3}, {"ggHps_htt"}, 0.993, 1.028)
          ({"mt","mt_2016"}, {3}, {"ggHsm_htt"}, 0.993, 1.027)
          ({"mt","mt_2016"}, {3}, {"ggHmm_htt"}, 0.993, 1.028)
          ({"mt","mt_2016"}, {4}, {"ggHps_htt"}, 0.990, 1.035)
          ({"mt","mt_2016"}, {4}, {"ggHsm_htt"}, 0.990, 1.036)
          ({"mt","mt_2016"}, {4}, {"ggHmm_htt"}, 0.991, 1.036)
          ({"mt","mt_2016"}, {5}, {"ggHps_htt"}, 0.994, 1.026)
          ({"mt","mt_2016"}, {5}, {"ggHsm_htt"}, 0.993, 1.024)
          ({"mt","mt_2016"}, {5}, {"ggHmm_htt"}, 0.993, 1.026)
          ({"mt","mt_2016"}, {6}, {"ggHps_htt"}, 0.990, 1.036)
          ({"mt","mt_2016"}, {6}, {"ggHsm_htt"}, 0.990, 1.035)
          ({"mt","mt_2016"}, {6}, {"ggHmm_htt"}, 0.990, 1.035)
          ({"et","et_2016"}, {1}, {"ggHps_htt"}, 0.998, 1.005)
          ({"et","et_2016"}, {1}, {"ggHsm_htt"}, 0.998, 1.006)
          ({"et","et_2016"}, {1}, {"ggHmm_htt"}, 0.998, 1.005)
          ({"et","et_2016"}, {2}, {"ggHps_htt"}, 0.994, 1.020)
          ({"et","et_2016"}, {2}, {"ggHsm_htt"}, 0.994, 1.020)
          ({"et","et_2016"}, {2}, {"ggHmm_htt"}, 0.994, 1.021)
          ({"et","et_2016"}, {3}, {"ggHps_htt"}, 0.993, 1.030)
          ({"et","et_2016"}, {3}, {"ggHsm_htt"}, 0.992, 1.032)
          ({"et","et_2016"}, {3}, {"ggHmm_htt"}, 0.993, 1.030)
          ({"et","et_2016"}, {4}, {"ggHps_htt"}, 0.990, 1.037)
          ({"et","et_2016"}, {4}, {"ggHsm_htt"}, 0.990, 1.036)
          ({"et","et_2016"}, {4}, {"ggHmm_htt"}, 0.990, 1.035)
          ({"et","et_2016"}, {5}, {"ggHps_htt"}, 0.993, 1.029)
          ({"et","et_2016"}, {5}, {"ggHsm_htt"}, 0.992, 1.032)
          ({"et","et_2016"}, {5}, {"ggHmm_htt"}, 0.992, 1.029)
          ({"et","et_2016"}, {6}, {"ggHps_htt"}, 0.990, 1.036)
          ({"et","et_2016"}, {6}, {"ggHsm_htt"}, 0.990, 1.036)
          ({"et","et_2016"}, {6}, {"ggHmm_htt"}, 0.990, 1.036)
          ({"em","em_2016"}, {1}, {"ggHps_htt"}, 1.003, 0.989)
          ({"em","em_2016"}, {1}, {"ggHsm_htt"}, 1.003, 0.989)
          ({"em","em_2016"}, {1}, {"ggHmm_htt"}, 1.003, 0.989)
          ({"em","em_2016"}, {2}, {"ggHps_htt"}, 0.996, 1.013)
          ({"em","em_2016"}, {2}, {"ggHsm_htt"}, 0.996, 1.012)
          ({"em","em_2016"}, {2}, {"ggHmm_htt"}, 0.996, 1.013)
          ({"em","em_2016"}, {3}, {"ggHps_htt"}, 0.994, 1.025)
          ({"em","em_2016"}, {3}, {"ggHsm_htt"}, 0.994, 1.024)
          ({"em","em_2016"}, {3}, {"ggHmm_htt"}, 0.993, 1.024)
          ({"em","em_2016"}, {4}, {"ggHps_htt"}, 0.991, 1.032)
          ({"em","em_2016"}, {4}, {"ggHsm_htt"}, 0.991, 1.033)
          ({"em","em_2016"}, {4}, {"ggHmm_htt"}, 0.991, 1.033)
          ({"em","em_2016"}, {5}, {"ggHps_htt"}, 0.993, 1.025)
          ({"em","em_2016"}, {5}, {"ggHsm_htt"}, 0.993, 1.025)
          ({"em","em_2016"}, {5}, {"ggHmm_htt"}, 0.994, 1.022)
          ({"em","em_2016"}, {6}, {"ggHps_htt"}, 0.991, 1.033)
          ({"em","em_2016"}, {6}, {"ggHsm_htt"}, 0.991, 1.034)
          ({"em","em_2016"}, {6}, {"ggHmm_htt"}, 0.991, 1.033)

          ({"tt_2017"}, {1}, {"ggHps_htt"}, 1.001, 1.002)
          ({"tt_2017"}, {1}, {"ggHmm_htt"}, 1.001, 1.002)
          ({"tt_2017"}, {1}, {"ggHsm_htt"}, 1.001, 1.002)
          ({"tt_2017"}, {4}, {"ggHps_htt"}, 0.990, 0.997)
          ({"tt_2017"}, {4}, {"ggHmm_htt"}, 0.990, 0.997)
          ({"tt_2017"}, {4}, {"ggHsm_htt"}, 0.991, 0.998)
          ({"tt_2017"}, {3}, {"ggHps_htt"}, 0.993, 1.000)
          ({"tt_2017"}, {3}, {"ggHmm_htt"}, 0.994, 1.001)
          ({"tt_2017"}, {3}, {"ggHsm_htt"}, 0.994, 1.001)
          ({"tt_2017"}, {6}, {"ggHps_htt"}, 0.990, 0.997)
          ({"tt_2017"}, {6}, {"ggHmm_htt"}, 0.991, 0.998)
          ({"tt_2017"}, {6}, {"ggHsm_htt"}, 0.990, 0.997)
          ({"tt_2017"}, {5}, {"ggHps_htt"}, 0.994, 1.000)
          ({"tt_2017"}, {5}, {"ggHmm_htt"}, 0.994, 1.000)
          ({"tt_2017"}, {5}, {"ggHsm_htt"}, 0.994, 1.000)
          ({"tt_2017"}, {2}, {"ggHps_htt"}, 0.998, 1.003)
          ({"tt_2017"}, {2}, {"ggHmm_htt"}, 0.999, 1.004)
          ({"tt_2017"}, {2}, {"ggHsm_htt"}, 0.999, 1.004)          
          ({"mt_2017"}, {1}, {"ggHps_htt"}, 1.000, 1.000)
          ({"mt_2017"}, {1}, {"ggHmm_htt"}, 1.000, 1.000)
          ({"mt_2017"}, {1}, {"ggHsm_htt"}, 1.000, 1.000)
          ({"mt_2017"}, {4}, {"ggHps_htt"}, 0.993, 0.999)
          ({"mt_2017"}, {4}, {"ggHmm_htt"}, 0.993, 0.999)
          ({"mt_2017"}, {4}, {"ggHsm_htt"}, 0.993, 1.000)
          ({"mt_2017"}, {3}, {"ggHps_htt"}, 0.997, 1.002)
          ({"mt_2017"}, {3}, {"ggHmm_htt"}, 0.998, 1.003)
          ({"mt_2017"}, {3}, {"ggHsm_htt"}, 0.997, 1.003)
          ({"mt_2017"}, {6}, {"ggHps_htt"}, 0.991, 0.998)
          ({"mt_2017"}, {6}, {"ggHmm_htt"}, 0.992, 0.999)
          ({"mt_2017"}, {6}, {"ggHsm_htt"}, 0.993, 0.999)
          ({"mt_2017"}, {5}, {"ggHps_htt"}, 0.997, 1.002)
          ({"mt_2017"}, {5}, {"ggHmm_htt"}, 0.997, 1.002)
          ({"mt_2017"}, {5}, {"ggHsm_htt"}, 0.997, 1.002)
          ({"mt_2017"}, {2}, {"ggHps_htt"}, 1.000, 1.003)
          ({"mt_2017"}, {2}, {"ggHmm_htt"}, 1.000, 1.003)
          ({"mt_2017"}, {2}, {"ggHsm_htt"}, 1.001, 1.003)
          ({"et_2017"}, {1}, {"ggHps_htt"}, 1.000, 1.002)
          ({"et_2017"}, {1}, {"ggHmm_htt"}, 1.000, 1.001)
          ({"et_2017"}, {1}, {"ggHsm_htt"}, 1.000, 1.002)
          ({"et_2017"}, {4}, {"ggHps_htt"}, 0.992, 0.999)
          ({"et_2017"}, {4}, {"ggHmm_htt"}, 0.992, 0.999)
          ({"et_2017"}, {4}, {"ggHsm_htt"}, 0.992, 0.999)
          ({"et_2017"}, {3}, {"ggHps_htt"}, 0.995, 1.002)
          ({"et_2017"}, {3}, {"ggHmm_htt"}, 0.997, 1.002)
          ({"et_2017"}, {3}, {"ggHsm_htt"}, 0.996, 1.002)
          ({"et_2017"}, {6}, {"ggHps_htt"}, 0.991, 0.998)
          ({"et_2017"}, {6}, {"ggHmm_htt"}, 0.991, 0.998)
          ({"et_2017"}, {6}, {"ggHsm_htt"}, 0.991, 0.998)
          ({"et_2017"}, {5}, {"ggHps_htt"}, 0.997, 1.002)
          ({"et_2017"}, {5}, {"ggHmm_htt"}, 0.996, 1.002)
          ({"et_2017"}, {5}, {"ggHsm_htt"}, 0.996, 1.002)
          ({"et_2017"}, {2}, {"ggHps_htt"}, 1.000, 1.004)
          ({"et_2017"}, {2}, {"ggHmm_htt"}, 1.000, 1.004)
          ({"et_2017"}, {2}, {"ggHsm_htt"}, 1.000, 1.004)
          ({"em_2017"}, {1}, {"ggHps_htt"}, 1.000, 0.998)
          ({"em_2017"}, {1}, {"ggHmm_htt"}, 1.000, 0.998)
          ({"em_2017"}, {1}, {"ggHsm_htt"}, 1.000, 0.998)
          ({"em_2017"}, {4}, {"ggHps_htt"}, 0.994, 1.001)
          ({"em_2017"}, {4}, {"ggHmm_htt"}, 0.995, 1.001)
          ({"em_2017"}, {4}, {"ggHsm_htt"}, 0.994, 1.000)
          ({"em_2017"}, {3}, {"ggHps_htt"}, 0.999, 1.003)
          ({"em_2017"}, {3}, {"ggHmm_htt"}, 0.999, 1.003)
          ({"em_2017"}, {3}, {"ggHsm_htt"}, 0.999, 1.003)
          ({"em_2017"}, {6}, {"ggHps_htt"}, 0.995, 1.001)
          ({"em_2017"}, {6}, {"ggHmm_htt"}, 0.994, 1.000)
          ({"em_2017"}, {6}, {"ggHsm_htt"}, 0.994, 1.000)
          ({"em_2017"}, {5}, {"ggHps_htt"}, 0.999, 1.003)
          ({"em_2017"}, {5}, {"ggHmm_htt"}, 0.999, 1.003)
          ({"em_2017"}, {5}, {"ggHsm_htt"}, 0.998, 1.002)
          ({"em_2017"}, {2}, {"ggHps_htt"}, 1.000, 1.003)
          ({"em_2017"}, {2}, {"ggHmm_htt"}, 1.000, 1.003)
          ({"em_2017"}, {2}, {"ggHsm_htt"}, 1.001, 1.003)

          ({"tt_2018"}, {1}, {"ggHps_htt"}, 1.001, 1.002)
          ({"tt_2018"}, {1}, {"ggHmm_htt"}, 1.001, 1.002)
          ({"tt_2018"}, {1}, {"ggHsm_htt"}, 1.001, 1.002)
          ({"tt_2018"}, {4}, {"ggHps_htt"}, 0.990, 0.997)
          ({"tt_2018"}, {4}, {"ggHmm_htt"}, 0.990, 0.997)
          ({"tt_2018"}, {4}, {"ggHsm_htt"}, 0.991, 0.998)
          ({"tt_2018"}, {3}, {"ggHps_htt"}, 0.993, 1.000)
          ({"tt_2018"}, {3}, {"ggHmm_htt"}, 0.994, 1.001)
          ({"tt_2018"}, {3}, {"ggHsm_htt"}, 0.994, 1.001)
          ({"tt_2018"}, {6}, {"ggHps_htt"}, 0.990, 0.997)
          ({"tt_2018"}, {6}, {"ggHmm_htt"}, 0.991, 0.998)
          ({"tt_2018"}, {6}, {"ggHsm_htt"}, 0.990, 0.997)
          ({"tt_2018"}, {5}, {"ggHps_htt"}, 0.994, 1.000)
          ({"tt_2018"}, {5}, {"ggHmm_htt"}, 0.994, 1.000)
          ({"tt_2018"}, {5}, {"ggHsm_htt"}, 0.994, 1.000)
          ({"tt_2018"}, {2}, {"ggHps_htt"}, 0.998, 1.003)
          ({"tt_2018"}, {2}, {"ggHmm_htt"}, 0.999, 1.004)
          ({"tt_2018"}, {2}, {"ggHsm_htt"}, 0.999, 1.004)          
          ({"mt_2018"}, {1}, {"ggHps_htt"}, 1.000, 1.000)
          ({"mt_2018"}, {1}, {"ggHmm_htt"}, 1.000, 1.000)
          ({"mt_2018"}, {1}, {"ggHsm_htt"}, 1.000, 1.000)
          ({"mt_2018"}, {4}, {"ggHps_htt"}, 0.993, 0.999)
          ({"mt_2018"}, {4}, {"ggHmm_htt"}, 0.993, 0.999)
          ({"mt_2018"}, {4}, {"ggHsm_htt"}, 0.993, 1.000)
          ({"mt_2018"}, {3}, {"ggHps_htt"}, 0.997, 1.002)
          ({"mt_2018"}, {3}, {"ggHmm_htt"}, 0.998, 1.003)
          ({"mt_2018"}, {3}, {"ggHsm_htt"}, 0.997, 1.003)
          ({"mt_2018"}, {6}, {"ggHps_htt"}, 0.991, 0.998)
          ({"mt_2018"}, {6}, {"ggHmm_htt"}, 0.992, 0.999)
          ({"mt_2018"}, {6}, {"ggHsm_htt"}, 0.993, 0.999)
          ({"mt_2018"}, {5}, {"ggHps_htt"}, 0.997, 1.002)
          ({"mt_2018"}, {5}, {"ggHmm_htt"}, 0.997, 1.002)
          ({"mt_2018"}, {5}, {"ggHsm_htt"}, 0.997, 1.002)
          ({"mt_2018"}, {2}, {"ggHps_htt"}, 1.000, 1.003)
          ({"mt_2018"}, {2}, {"ggHmm_htt"}, 1.000, 1.003)
          ({"mt_2018"}, {2}, {"ggHsm_htt"}, 1.001, 1.003)
          ({"et_2018"}, {1}, {"ggHps_htt"}, 1.000, 1.002)
          ({"et_2018"}, {1}, {"ggHmm_htt"}, 1.000, 1.001)
          ({"et_2018"}, {1}, {"ggHsm_htt"}, 1.000, 1.002)
          ({"et_2018"}, {4}, {"ggHps_htt"}, 0.992, 0.999)
          ({"et_2018"}, {4}, {"ggHmm_htt"}, 0.992, 0.999)
          ({"et_2018"}, {4}, {"ggHsm_htt"}, 0.992, 0.999)
          ({"et_2018"}, {3}, {"ggHps_htt"}, 0.995, 1.002)
          ({"et_2018"}, {3}, {"ggHmm_htt"}, 0.997, 1.002)
          ({"et_2018"}, {3}, {"ggHsm_htt"}, 0.996, 1.002)
          ({"et_2018"}, {6}, {"ggHps_htt"}, 0.991, 0.998)
          ({"et_2018"}, {6}, {"ggHmm_htt"}, 0.991, 0.998)
          ({"et_2018"}, {6}, {"ggHsm_htt"}, 0.991, 0.998)
          ({"et_2018"}, {5}, {"ggHps_htt"}, 0.997, 1.002)
          ({"et_2018"}, {5}, {"ggHmm_htt"}, 0.996, 1.002)
          ({"et_2018"}, {5}, {"ggHsm_htt"}, 0.996, 1.002)
          ({"et_2018"}, {2}, {"ggHps_htt"}, 1.000, 1.004)
          ({"et_2018"}, {2}, {"ggHmm_htt"}, 1.000, 1.004)
          ({"et_2018"}, {2}, {"ggHsm_htt"}, 1.000, 1.004)
          ({"em_2018"}, {1}, {"ggHps_htt"}, 1.000, 0.998)
          ({"em_2018"}, {1}, {"ggHmm_htt"}, 1.000, 0.998)
          ({"em_2018"}, {1}, {"ggHsm_htt"}, 1.000, 0.998)
          ({"em_2018"}, {4}, {"ggHps_htt"}, 0.994, 1.001)
          ({"em_2018"}, {4}, {"ggHmm_htt"}, 0.995, 1.001)
          ({"em_2018"}, {4}, {"ggHsm_htt"}, 0.994, 1.000)
          ({"em_2018"}, {3}, {"ggHps_htt"}, 0.999, 1.003)
          ({"em_2018"}, {3}, {"ggHmm_htt"}, 0.999, 1.003)
          ({"em_2018"}, {3}, {"ggHsm_htt"}, 0.999, 1.003)
          ({"em_2018"}, {6}, {"ggHps_htt"}, 0.995, 1.001)
          ({"em_2018"}, {6}, {"ggHmm_htt"}, 0.994, 1.000)
          ({"em_2018"}, {6}, {"ggHsm_htt"}, 0.994, 1.000)
          ({"em_2018"}, {5}, {"ggHps_htt"}, 0.999, 1.003)
          ({"em_2018"}, {5}, {"ggHmm_htt"}, 0.999, 1.003)
          ({"em_2018"}, {5}, {"ggHsm_htt"}, 0.998, 1.002)
          ({"em_2018"}, {2}, {"ggHps_htt"}, 1.000, 1.003)
          ({"em_2018"}, {2}, {"ggHmm_htt"}, 1.000, 1.003)
          ({"em_2018"}, {2}, {"ggHsm_htt"}, 1.001, 1.003)
        );
        
        //    Uncertainty on BR for HTT @ 125 GeV
        cb.cp().process(sig_procs).AddSyst(cb,"BR_htt_THU", "lnN", SystMap<>::init(1.017));
        cb.cp().process(sig_procs).AddSyst(cb,"BR_htt_PU_mq", "lnN", SystMap<>::init(1.0099));
        cb.cp().process(sig_procs).AddSyst(cb,"BR_htt_PU_alphas", "lnN", SystMap<>::init(1.0062));
        
        //    Uncertainty on BR of HWW @ 125 GeV
        cb.cp().process({"ggH_hww125","qqH_hww125"}).AddSyst(cb,"BR_hww_THU", "lnN", SystMap<>::init(1.0099));
        cb.cp().process({"ggH_hww125","qqH_hww125"}).AddSyst(cb,"BR_hww_PU_mq", "lnN", SystMap<>::init(1.0099));
        cb.cp().process({"ggH_hww125","qqH_hww125"}).AddSyst(cb,"BR_hww_PU_alphas", "lnN", SystMap<>::init(1.0066));
        
        
        cb.cp().process(JoinStr({ggH_sig_procs, {"ggH_hww125"}})).AddSyst(cb,"QCDScale_ggH", "lnN", SystMap<>::init(1.039));
        cb.cp().process(JoinStr({qqH_sig_procs, {"qqH_hww125"}})).AddSyst(cb,"QCDScale_qqH", "lnN", SystMap<>::init(1.004));
        cb.cp().process({"WH_htt125","WH_htt","WHsm_htt125","WHps_htt","WHmm_htt","WHsm_htt","WHps_htt","WHmm_htt"}).AddSyst(cb,"QCDScale_WH", "lnN", SystMap<>::init(1.007));
        cb.cp().process({"WH_htt125","ZH_htt","ZHsm_htt125","ZHps_htt","ZHmm_htt","ZHsm_htt","ZHps_htt","ZHmm_htt"}).AddSyst(cb,"QCDScale_ZH", "lnN", SystMap<>::init(1.038));
        
        cb.cp().process(JoinStr({ggH_sig_procs, {"ggH_hww125"}})).AddSyst(cb,"pdf_Higgs_gg", "lnN", SystMap<>::init(1.032));
        cb.cp().process(JoinStr({qqH_sig_procs, {"qqH_hww125"}})).AddSyst(cb,"pdf_Higgs_qq", "lnN", SystMap<>::init(1.021));
        cb.cp().process({"WH_htt125","WH_htt","WHsm_htt125","WHps_htt","WHmm_htt","WHsm_htt","WHps_htt","WHmm_htt"}).AddSyst(cb,"pdf_Higgs_WH", "lnN", SystMap<>::init(1.019));
        cb.cp().process({"ZH_htt125","ZH_htt""ZHsm_htt125","ZHps_htt","ZHmm_htt","ZHsm_htt","ZHps_htt","ZHmm_htt"}).AddSyst(cb,"pdf_Higgs_ZH", "lnN", SystMap<>::init(1.016));
        
        // jet bin migration uncertainties from: https://arxiv.org/pdf/1610.07922.pdf#subsection.1.4.2.5 (Table 20)
        // For boosted category this is not exclusivly 1 jet events since events with > 1 jets and mjj<300 enter also. So take weighted average of Njets=1 and Njets>=1 uncertainties i.e sigma(boosted) = sigma(njets=1)*(# Njets=1 && boosted)/(# boosted) + sigma(njets>=1)*(#Njets>1 && boosted)/(# boosted)
        // These need to be set properly for MVA approach (placeholders for now)
        
        cb.cp().AddSyst(cb, "CMS_ggH_mig01", "lnN", SystMap<channel, bin_id, process>::init
                        ({"em","em_2016","em_2017","em_2018"},{1,31,32,33,34,35,36,37},ggH_sig_procs, 0.959)
                        ({"et","et_2016","et_2017","et_2018"},{1,31,32,33,34,35,36,37},ggH_sig_procs, 0.959)
                        ({"mt","mt_2016","mt_2017","mt_2018"},{1,31,32,33,34,35,36,37},ggH_sig_procs, 0.959)
                        ({"tt","tt_2016","tt_2017","tt_2018"},{1,31,32,33,34,35,36,37},ggH_sig_procs, 0.959)
                        
                        ({"em","em_2016","em_2017","em_2018"},{2},ggH_sig_procs, 1.071)
                        ({"et","et_2016","et_2017","et_2018"},{2},ggH_sig_procs, 1.071)
                        ({"mt","mt_2016","mt_2017","mt_2018"},{2},ggH_sig_procs, 1.071)
                        ({"tt","tt_2016","tt_2017","tt_2018"},{2},ggH_sig_procs, 1.071)
                        
                        ({"em","em_2016","em_2017","em_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.036)
                        ({"et","et_2016","et_2017","et_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.036)
                        ({"mt","mt_2016","mt_2017","mt_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.036)
                        ({"tt","tt_2016","tt_2017","tt_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.036)
                        );
        
        
        cb.cp().AddSyst(cb, "CMS_ggH_mig12", "lnN", SystMap<channel, bin_id, process>::init 
                        ({"em","em_2016","em_2017","em_2018"},{2,31,32,33,34,35,36,37},ggH_sig_procs, 0.986)
                        ({"et","et_2016","et_2017","et_2018"},{2,31,32,33,34,35,36,37},ggH_sig_procs, 0.986)
                        ({"mt","mt_2016","mt_2017","mt_2018"},{2,31,32,33,34,35,36,37},ggH_sig_procs, 0.986)
                        ({"tt","tt_2016","tt_2017","tt_2018"},{2,31,32,33,34,35,36,37},ggH_sig_procs, 0.986)
                        
                        ({"em","em_2016","em_2017","em_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.145)
                        ({"et","et_2016","et_2017","et_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.145)
                        ({"mt","mt_2016","mt_2017","mt_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.145)
                        ({"tt","tt_2016","tt_2017","tt_2018"},{3,4,5,6,41,42,43,44,45,46,47,48,49},ggH_sig_procs, 1.145)
                        );

        

        if (control_region > 0) {
            // Create rateParams for control regions:
            //  - [x] 1 rateParam for all W in every region
            //  - [x] 1 rateParam for QCD in low mT
            //  - [x] 1 rateParam for QCD in high mT
            //  - [x] lnNs for the QCD OS/SS ratio
            //         * should account for stat + syst
            //         * systs should account for: extrap. from anti-iso to iso region,
            //  - [x] lnNs for the W+jets OS/SS ratio
            //         * should account for stat only if not being accounted for with bbb,
            //           i.e. because the OS/SS ratio was measured with a relaxed selection
            //         * systs should account for: changes in low/high mT and OS/SS due to experimental effects e.g JES,
            //           OS/SS being wrong in the MC 
            //           low/high mT being wrong in the MC 
            
            // W rate params added for all et/mt signal-regions/control-regions. The same W rate param is used for dijet_lowboost and dijet_boosted since the W for the dijet_boosted category is estimated using dijet_lowboost control-region and extraplated to dijet_boosted using MC
            cb.cp().bin({"mt_0jet","mt_0jet_wjets_cr","mt_0jet_qcd_cr","mt_0jet_wjets_ss_cr"}).process({"W"}).AddSyst(cb, "rate_W_mt_0jet", "rateParam", SystMap<>::init(1.0)); 
            cb.cp().bin({"mt_boosted","mt_boosted_wjets_cr","mt_boosted_qcd_cr","mt_boosted_wjets_ss_cr"}).process({"W"}).AddSyst(cb, "rate_W_mt_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"mt_dijet_lowboost","mt_dijet_lowboost_wjets_cr","mt_dijet_lowboost_qcd_cr","mt_dijet_lowboost_wjets_ss_cr","mt_dijet_boosted","mt_dijet_boosted_qcd_cr"}).process({"W"}).AddSyst(cb, "rate_W_mt_dijet", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_0jet","et_0jet_wjets_cr","et_0jet_qcd_cr","et_0jet_wjets_ss_cr"}).process({"W"}).AddSyst(cb, "rate_W_et_0jet", "rateParam", SystMap<>::init(1.0)); 
            cb.cp().bin({"et_boosted","et_boosted_wjets_cr","et_boosted_qcd_cr","et_boosted_wjets_ss_cr"}).process({"W"}).AddSyst(cb, "rate_W_et_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_dijet_lowboost","et_dijet_lowboost_wjets_cr","et_dijet_lowboost_qcd_cr","et_dijet_lowboost_wjets_ss_cr","et_dijet_boosted","et_dijet_boosted_qcd_cr"}).process({"W"}).AddSyst(cb, "rate_W_et_dijet", "rateParam", SystMap<>::init(1.0));
            
            // QCD rate params added for low-mT region   
            cb.cp().bin({"mt_0jet","mt_0jet_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_mt_0jet", "rateParam", SystMap<>::init(1.0)); 
            cb.cp().bin({"mt_boosted","mt_boosted_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_mt_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"mt_dijet_lowboost","mt_dijet_lowboost_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_mt_dijet_lowboost", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"mt_dijet_boosted","mt_dijet_boosted_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_mt_dijet_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_0jet","et_0jet_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_et_0jet", "rateParam", SystMap<>::init(1.0)); 
            cb.cp().bin({"et_boosted","et_boosted_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_et_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_dijet_lowboost","et_dijet_lowboost_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_et_dijet_lowboost", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_dijet_boosted","et_dijet_boosted_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_lowmT_et_dijet_boosted", "rateParam", SystMap<>::init(1.0));
            
            // QCD rate params added for high-mT regions    
            cb.cp().bin({"mt_0jet_wjets_cr","mt_0jet_wjets_ss_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_highmT_mt_0jet", "rateParam", SystMap<>::init(1.0)); 
            cb.cp().bin({"mt_boosted_wjets_cr","mt_boosted_wjets_ss_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_highmT_mt_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"mt_dijet_lowboost_wjets_cr","mt_dijet_lowboost_wjets_ss_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_highmT_mt_dijet_lowboost", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_0jet_wjets_cr","et_0jet_wjets_ss_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_highmT_et_0jet", "rateParam", SystMap<>::init(1.0)); 
            cb.cp().bin({"et_boosted_wjets_cr","et_boosted_wjets_ss_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_highmT_et_boosted", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"et_dijet_lowboost_wjets_cr","et_dijet_lowboost_wjets_ss_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_highmT_et_dijet_lowboost", "rateParam", SystMap<>::init(1.0));

            // tt QCD rate params
            cb.cp().bin({"tt_0jet","tt_0jet_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_cr_0jet_tt", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"tt_boosted","tt_boosted_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_cr_boosted_tt", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"tt_dijet_lowboost","tt_dijet_lowboost_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_cr_dijet_lowboost_tt", "rateParam", SystMap<>::init(1.0));
            cb.cp().bin({"tt_dijet_boosted","tt_dijet_boosted_qcd_cr"}).process({"QCD"}).AddSyst(cb, "rate_QCD_cr_dijet_boosted_tt", "rateParam", SystMap<>::init(1.0));  

            // Should set a sensible range for our rateParams
            for (auto sys : cb.cp().syst_type({"rateParam"}).syst_name_set()) {
                cb.GetParameter(sys)->set_range(0.0, 5.0);
            }
        }

        
        //if (ttbar_fit) {
        //    cb.cp().channel({"ttbar_2016","em_2016","et_2016","mt_2016","tt_2016"}).process({"TT","TTT","TTJ"}).AddSyst(cb, "rate_ttbar_2016", "rateParam", SystMap<>::init(1.0));
        //    cb.cp().channel({"ttbar_2017","em_2017","et_2017","mt_2017","tt_2017"}).process({"TT","TTT","TTJ"}).AddSyst(cb, "rate_ttbar_2017", "rateParam", SystMap<>::init(1.0));
        //    cb.cp().channel({"ttbar_2018","em_2018","et_2018","mt_2018","tt_2018"}).process({"TT","TTT","TTJ"}).AddSyst(cb, "rate_ttbar_2018", "rateParam", SystMap<>::init(1.0));
        //    for (auto sys : cb.cp().syst_type({"rateParam"}).syst_name_set()) {
        //        if(sys.find("rate_ttbar") != std::string::npos) cb.GetParameter(sys)->set_range(0.8, 1.2); 
        //    }
        //}
        
    }
}
