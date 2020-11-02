void SumObservations(TString workspace = "etau_htt_bkg_et") {

  TFile * mlfit = new TFile("shapes_"+workspace+".root");
  std::vector<TString> cats = 
    {"htt_et_2016_1_13TeV",
     "htt_et_2016_2_13TeV",
     "htt_et_2017_1_13TeV",
     "htt_et_2017_2_13TeV",
     "htt_et_2018_1_13TeV",
     "htt_et_2018_2_13TeV"
    };
  double obs_data = 0.0;
  for (unsigned int i = 0; i < cats.size(); ++i ) {
    TH1D * hist = (TH1D*)mlfit->Get(cats.at(i)+"_postfit/data_obs");
    std::cout << hist << std::endl;
    obs_data += hist->GetSumOfWeights();
  }
  double err = TMath::Sqrt(obs_data);
  std::cout << "data = " << obs_data << " +/- " << err << std::endl;

}
