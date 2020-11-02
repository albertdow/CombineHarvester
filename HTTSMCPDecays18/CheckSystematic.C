//            CMS_scale_t_1prong_2018(13TeV)
//            CMS_scale_met_unclustered_2018(13TeV)
//            CMS_htt_boson_reso_met_2018(13TeV)
//            CMS_scale_j_FlavorQCD(13TeV)
//            CMS_scale_j_Absolute(13TeV)
//            CMS_scale_embedded_t_1prong_2016(13TeV)
//            CMS_res_j_2018(13TeV)
//            CMS_scale_j_HF(13TeV)
void CheckSystematic(TString era = "2018",
		     TString process = "EMB",
		     TString varName = "pt_1",
		     TString sysName = "CMS_scale_e_13TeV") {

  TString fileName = "/nfs/dust/cms/user/rasp/storage/cardinia/"+era+"/OutputDNNet/Sep1-PUB/predictions_"+era+"/et-NOMINAL_ntuple_"+process+".root";

  TFile * file = new TFile(fileName);
  TTree * tree = (TTree*)file->Get("TauCheck");
  TTree * treeUp = (TTree*)file->Get("TauCheck_"+sysName+"Up");
  TTree * treeDown = (TTree*)file->Get("TauCheck_"+sysName+"Down");

  std::vector<Long64_t> eventNumbers;
  std::map<Long64_t,Double_t> predicted;
  std::map<Long64_t,Double_t> predictedUp;
  std::map<Long64_t,Double_t> predictedDown;
  std::map<Long64_t,Double_t> predictedClass;
  std::map<Long64_t,Double_t> predictedClassUp;
  std::map<Long64_t,Double_t> predictedClassDown;
  std::map<Long64_t,Float_t> varCentral;
  std::map<Long64_t,Float_t> varUp;
  std::map<Long64_t,Float_t> varDown;
    
  Long64_t evt;
  Double_t prob;
  Double_t type;
  Float_t var;

  tree->SetBranchAddress("evt",&evt);
  tree->SetBranchAddress("predicted_prob",&prob);
  tree->SetBranchAddress("predicted_class",&type);
  tree->SetBranchAddress(varName,&var);

  treeUp->SetBranchAddress("evt",&evt);
  treeUp->SetBranchAddress("predicted_prob",&prob);
  treeUp->SetBranchAddress("predicted_class",&type);
  treeUp->SetBranchAddress(varName,&var);

  treeDown->SetBranchAddress("evt",&evt);
  treeDown->SetBranchAddress("predicted_prob",&prob);
  treeDown->SetBranchAddress("predicted_class",&type);
  treeDown->SetBranchAddress(varName,&var);

  for (int iEvt=0; iEvt<150; ++iEvt) {
    tree->GetEntry(iEvt);
    eventNumbers.push_back(evt);
    predicted[evt] = prob;
    predictedClass[evt] = type;
    varCentral[evt] = var;
  }

  for (int iEvt=0; iEvt<120; ++iEvt) {
    treeUp->GetEntry(iEvt);
    for (unsigned int j=0; j<eventNumbers.size();++j) {
      if (eventNumbers[j]==evt) {
	predictedUp[evt] = prob;
	predictedClassUp[evt] = type;
	varUp[evt] = var;
	break;
      }
    }
  }

  for (int iEvt=0; iEvt<120; ++iEvt) {
    treeDown->GetEntry(iEvt);
    for (unsigned int j=0; j<eventNumbers.size();++j) {
      if (eventNumbers[j]==evt) {
	predictedDown[evt] = prob;
	predictedClassDown[evt] = type;
	varDown[evt] = var;
	break;
      }
    }

  }
    

  for (unsigned int i=0; i<100; ++i) {
    Long64_t ievt = eventNumbers[i];
    double xCentral = predicted[ievt];
    double xUp = predictedUp[ievt];
    double xDown = predictedDown[ievt];
    double vCentral = varCentral[ievt];
    double vUp = varUp[ievt];
    double vDown = varDown[ievt];
    double xPlus = xUp - xCentral;
    double xMinus = xDown - xCentral;
    int category = int(predictedClass[ievt]);
    int categoryUp = int(predictedClassUp[ievt]);
    int categoryDown = int(predictedClassDown[ievt]);
    printf("event number %10i -> %5.3f : %5.3f : %5.3f  ---  var = %7.2f : %7.2f : %7.2f\n",ievt,xCentral,xUp,xDown,vCentral,vUp,vDown,category,categoryUp);
  }

}
