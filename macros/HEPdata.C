TString strFileName = "jtAnalysisFixedFinalGraphs.root";

const int NE = 2;
const int NXlong = 3;
TGraphErrors *gr_RMSNarrow_stat[NE][NXlong]; // 2: pp5, pPb 3: 3 xlong bins
TGraphErrors *gr_RMSNarrow_syst[NE][NXlong];
TGraphErrors *gr_RMSWide_stat[NE][NXlong]; // 2: pp5, pPb 3: 3 xlong bins
TGraphErrors *gr_RMSWide_syst[NE][NXlong];

TGraphErrors *gr_YieldNarrow_stat[NE][NXlong]; // 2: pp5, pPb 3: 3 xlong bins
TGraphErrors *gr_YieldNarrow_syst[NE][NXlong];
TGraphErrors *gr_YieldWide_stat[NE][NXlong]; // 2: pp5, pPb 3: 3 xlong bins
TGraphErrors *gr_YieldWide_syst[NE][NXlong];
const int Npt = 7;
const double PtBins[Npt+1] = {3, 4, 5, 6, 8, 10, 12, 15};

TString sEnergy[NE] = {"pp_7.0TeV","p-Pb_5.02TeV"};
TString sXlong[NXlong] = {"0.2<xlong<0.4","0.4<xlong<0.6","0.6<xlong<1.0"};
void LoadResults();
void printGrrHepData(TGraphErrors *gr, TGraphErrors *gr_syst, const double *CentBins, ofstream *file=NULL);

void HEPdata() {

	LoadResults();
	// PP
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 4"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables RMS for narrow component in p-p collisions at 7 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P P --> CHARGED X"<<endl;
		cout <<"*obskey: RMSNarrow"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P P --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S) IN GEV : 7000"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: RMS narrow"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_RMSNarrow_stat[0][ix], gr_RMSNarrow_syst[0][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 4"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables RMS for wide component in p-p collisions at 7 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P P --> CHARGED X"<<endl;
		cout <<"*obskey: RMSWide"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P P --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S) IN GEV : 7000"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: RMS wide"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_RMSWide_stat[0][ix], gr_RMSWide_syst[0][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	// pPb
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 4"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables RMS for narrow component in p-Pb collisions at 5.02 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P PB --> CHARGED X"<<endl;
		cout <<"*obskey: RMSNarrow"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P PB --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S)/NUCLEON IN GEV : 5020"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: RMS narrow"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_RMSNarrow_stat[1][ix], gr_RMSNarrow_syst[1][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 4"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables RMS for wide component in p-Pb collisions at 5.02 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P PB --> CHARGED X"<<endl;
		cout <<"*obskey: RMSWide"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P PB --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S)/NUCLEON IN GEV : 5020"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: RMS wide"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_RMSWide_stat[1][ix], gr_RMSWide_syst[1][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	// Yield
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 5"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables per-trigger yield for narrow component in p-p collisions at 7 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P P --> CHARGED X"<<endl;
		cout <<"*obskey: YieldNarrow"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P P --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S) IN GEV : 7000"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: Yield narrow"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_YieldNarrow_stat[0][ix], gr_YieldNarrow_syst[0][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 5"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables per-trigger yield for wide component in p-p collisions at 7 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P P --> CHARGED X"<<endl;
		cout <<"*obskey: YieldWide"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P P --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S) IN GEV : 7000"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: Yield wide"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_YieldWide_stat[0][ix], gr_YieldWide_syst[0][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	// pPb
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 5"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables per-trigger yield for narrow component in p-Pb collisions at 5.02 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P PB --> CHARGED X"<<endl;
		cout <<"*obskey: YieldNarrow"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P PB --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S)/NUCLEON IN GEV : 5020"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: Yield narrow"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_YieldNarrow_stat[1][ix], gr_YieldNarrow_syst[1][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}
	for(int ix=0;ix<NXlong;ix++) {
		cout <<"*dataset:"<<endl;
		cout <<"*location: Figure 5"<<endl;
		cout <<"*dscomment: trigger particle momentum dependence of observables per-trigger yield for wide component in p-Pb collisions at 5.02 TeV with "<< sXlong[ix]<<endl;
		cout <<"*reackey: P PB --> CHARGED X"<<endl;
		cout <<"*obskey: YieldWide"<<endl;
		cout <<"*qual: ETARAP : -0.8 TO 0.8"<<endl;
		cout <<"*qual: RE : P PB --> CHARGED X"<<endl;
		cout <<"*qual: SQRT(S)/NUCLEON IN GEV : 5020"<<endl;
		cout <<"*xheader: PT IN GEV/C"<<endl;
		cout <<"*yheader: Yield wide"<<endl; 	
		cout <<"*data: x : y"<<endl;
		printGrrHepData(gr_YieldWide_stat[1][ix], gr_YieldWide_syst[1][ix],PtBins,NULL);
		cout <<"*dataend:"<<endl;
		cout << endl;
	}


}

void LoadResults(){
	TFile *fin = new TFile( Form("%s", strFileName.Data() ), "read" );
	cout <<"Loading the results..."<<endl;
	for(int ie=0;ie<NE;ie++) {
		for(int ix=0;ix<NXlong;ix++) {
			gr_RMSNarrow_stat[ie][ix] = (TGraphErrors*)fin->Get(Form("RMSNarrow_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
			gr_RMSWide_stat[ie][ix] = (TGraphErrors*)fin->Get(Form("RMSWide_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
			gr_RMSNarrow_syst[ie][ix] = (TGraphErrors*)fin->Get(Form("systematicError_RMSNarrow_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
			gr_RMSWide_syst[ie][ix] = (TGraphErrors*)fin->Get(Form("systematicError_RMSWide_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 

			gr_YieldNarrow_stat[ie][ix] = (TGraphErrors*)fin->Get(Form("YieldNarrow_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
			gr_YieldWide_stat[ie][ix] = (TGraphErrors*)fin->Get(Form("YieldWide_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
			gr_YieldNarrow_syst[ie][ix] = (TGraphErrors*)fin->Get(Form("systematicError_YieldNarrow_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
			gr_YieldWide_syst[ie][ix] = (TGraphErrors*)fin->Get(Form("systematicError_YieldWide_%s_%s",sEnergy[ie].Data(),sXlong[ix].Data())); 
		}
	}
}

void printGrrHepData(TGraphErrors *gr, TGraphErrors *gr_syst, const double *CentBins, ofstream *file=NULL){
	streambuf* sbuf = cout.rdbuf();
	if(file != NULL)  cout.rdbuf(file->rdbuf());

	double x[300], y[300], ex[300], ey[300];
	int NC =  gr->GetN();
	for(int ii=0;ii<NC;ii++){
		gr->GetPoint(ii,x[ii],y[ii]);
		ex[ii] = gr->GetErrorX(ii);
		ey[ii] = gr->GetErrorY(ii);
	}
	double x_syst[300], y_syst[300], ex_syst[300], ey_syst[300];
	int NC_syst =  gr_syst->GetN();
	for(int ii=0;ii<NC;ii++){
		gr_syst->GetPoint(ii,x_syst[ii],y_syst[ii]);
		ex_syst[ii] = gr_syst->GetErrorX(ii);
		ey_syst[ii] = gr_syst->GetErrorY(ii);
	}
	for(int ii=0;ii<NC;ii++) {
		TString strData = Form("%.1f TO %.1f;\t%E +- %E (DSYS=%E);",CentBins[ii],CentBins[ii+1],y[ii],ey[ii],ey_syst[ii]);
		cout << strData << endl;
	}

	if(file != NULL) cout.rdbuf(sbuf);
}


// 
