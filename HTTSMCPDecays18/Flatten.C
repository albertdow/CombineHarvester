void Flatten(TString year = "2016") {

  int nDNN = 6;
  int nPhi = 8;

  TString fileName = "shapes/DESY/"+year+"/htt_et.inputs-sm-13TeV-mergeXbins.root";
  TFile * file = new TFile(fileName,"update");
  //  TFile * file = new TFile(fileName);
  file->cd("et_mupi_sig_"+year);
  TH1D * cen = (TH1D*)file->Get("et_mupi_sig_"+year+"/ZL");
  TH1D * sysUp = (TH1D*)file->Get("et_mupi_sig_"+year+"/ZL_CMS_htt_ZLShape_et_1prong_13TeVUp");
  TH1D * sysDown = (TH1D*)file->Get("et_mupi_sig_"+year+"/ZL_CMS_htt_ZLShape_et_1prong_13TeVDown");
  for (int iDNN=0; iDNN<nDNN; ++iDNN) {
    double totUp = 0;
    double totDown = 0;
    double totCen = 0;
    for (int iPhi=1; iPhi<=nPhi; ++iPhi) {
      int iBin = 8*iDNN + iPhi;
      double central = cen->GetBinContent(iBin);
      double up = sysUp->GetBinContent(iBin);
      double down = sysDown->GetBinContent(iBin);
      totUp += up;
      totDown += down;
      totCen += central;
    }
    //    double kUp = 1; totUp/totCen;
    //    double kDown = 1; totDown/totCen;
    std::cout << "iDNN = " << iDNN
	      << "   Central = " << totCen
	      << "   Down = " << totDown
	      << "   Up = " << totUp << std::endl;

    bool nonZero = totCen > 0.0;
    if (nonZero) {
      double kUp = totUp/totCen;
      double kDown = totDown/totCen;
      double totUp = 0;
      double totDown = 0;
      double totCen = 0;
      
      for (int iPhi=1; iPhi<=nPhi; ++iPhi) {
	int iBin = 8*iDNN + iPhi;
	double central = cen->GetBinContent(iBin);
	sysUp->SetBinContent(iBin,central*kUp);
	sysDown->SetBinContent(iBin,central*kDown);
	double up = sysUp->GetBinContent(iBin);
	double down = sysDown->GetBinContent(iBin);
	totUp += up;
	totDown += down;
	totCen += central;
      }
      std::cout << "after " << iDNN
		<< "   Central = " << totCen
		<< "   Down = " << totDown
		<< "   Up = " << totUp << std::endl;
    }
  }
  sysUp->Write("ZL_CMS_htt_ZLShape_et_1prong_13TeVUp");
  sysDown->Write("ZL_CMS_htt_ZLShape_et_1prong_13TeVDown");
  file->Close();
  delete file;
  

}
