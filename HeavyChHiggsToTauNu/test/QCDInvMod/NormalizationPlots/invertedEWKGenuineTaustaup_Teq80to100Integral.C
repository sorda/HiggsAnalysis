{
//=========Macro generated from canvas: invertedEWKGenuineTaustaup_Teq80to100Integral/
//=========  (Wed Aug 13 15:49:57 2014) by ROOT version5.32/00
   TCanvas *invertedEWKGenuineTaustaup_Teq80to100Integral = new TCanvas("invertedEWKGenuineTaustaup_Teq80to100Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetHighLightColor(2);
   invertedEWKGenuineTaustaup_Teq80to100Integral->Range(-101.2658,-1.228293,531.6456,0.5278047);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetFillColor(0);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetBorderMode(0);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetBorderSize(2);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetLogy();
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetTickx(1);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetTicky(1);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetLeftMargin(0.16);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetRightMargin(0.05);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetTopMargin(0.05);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetBottomMargin(0.13);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetFrameFillStyle(0);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetFrameBorderMode(0);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetFrameFillStyle(0);
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__75 = new TH1F("hframe__75","",1000,0,500);
   hframe__75->SetMinimum(0.1);
   hframe__75->SetMaximum(2.754228);
   hframe__75->SetDirectory(0);
   hframe__75->SetStats(0);
   hframe__75->SetLineStyle(0);
   hframe__75->SetMarkerStyle(20);
   hframe__75->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__75->GetXaxis()->SetLabelFont(43);
   hframe__75->GetXaxis()->SetLabelOffset(0.007);
   hframe__75->GetXaxis()->SetLabelSize(27);
   hframe__75->GetXaxis()->SetTitleSize(33);
   hframe__75->GetXaxis()->SetTitleOffset(0.9);
   hframe__75->GetXaxis()->SetTitleFont(43);
   hframe__75->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__75->GetYaxis()->SetLabelFont(43);
   hframe__75->GetYaxis()->SetLabelOffset(0.007);
   hframe__75->GetYaxis()->SetLabelSize(27);
   hframe__75->GetYaxis()->SetTitleSize(33);
   hframe__75->GetYaxis()->SetTitleOffset(1.25);
   hframe__75->GetYaxis()->SetTitleFont(43);
   hframe__75->GetZaxis()->SetLabelFont(43);
   hframe__75->GetZaxis()->SetLabelOffset(0.007);
   hframe__75->GetZaxis()->SetLabelSize(27);
   hframe__75->GetZaxis()->SetTitleSize(33);
   hframe__75->GetZaxis()->SetTitleFont(43);
   hframe__75->Draw(" ");
   TLatex *   tex = new TLatex(0.62,0.96,"CMS Preliminary");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.19,0.96,"#sqrt{s} = 8 TeV");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.43,0.96,"L=4.4 fb^{-1}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.7,"Integral = 9 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4 = new TH1F("Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4","#tau p_{T}=80..100",50,0,500);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(2,0.08365948);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(3,0.3474381);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(4,0.5864949);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(5,0.5926082);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(6,0.1579191);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(7,0.2560534);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(8,0.2491045);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(9,0.5587181);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(10,1.377114);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(11,0.5828742);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(12,0.4683833);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(13,0.5103885);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(14,0.4103253);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(15,0.5526011);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(16,0.5021553);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(17,0.118297);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(18,0.2688882);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(19,0.08618321);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(20,0.1820415);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(21,0.304354);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(22,0.04509122);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(24,0.1558346);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(25,0.01917711);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(27,0.08516451);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(29,0.08778214);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(32,0.1825973);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(35,0.1134803);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(39,0.02804228);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(41,0.1701199);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(2,0.08365948);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(3,0.2033136);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(4,0.5254313);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(5,0.5014526);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(6,0.1029163);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(7,0.1333523);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(8,0.184463);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(9,0.3346885);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(10,0.787633);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(11,0.222244);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(12,0.2347713);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(13,0.2057588);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(14,0.2297448);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(15,0.2342075);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(16,0.2460445);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(17,0.1021831);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(18,0.1549226);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(19,0.0861832);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(20,0.1301267);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(21,0.155062);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(22,0.04508133);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(24,0.1104955);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(25,0.0191771);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(27,0.08516451);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(29,0.08778215);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(32,0.1295061);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(35,0.1134803);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(39,0.02804228);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(41,0.1701199);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetEntries(97);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetFillColor(ci);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetLineWidth(2);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetMarkerStyle(20);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetMarkerSize(1.2);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitle("Events / 10 GeV");
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitleOffset(1.5);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METInvertedTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->Draw("HIST same");
   
   TH1F *hframe__76 = new TH1F("hframe__76","",1000,0,500);
   hframe__76->SetMinimum(0.1);
   hframe__76->SetMaximum(2.754228);
   hframe__76->SetDirectory(0);
   hframe__76->SetStats(0);
   hframe__76->SetLineStyle(0);
   hframe__76->SetMarkerStyle(20);
   hframe__76->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__76->GetXaxis()->SetLabelFont(43);
   hframe__76->GetXaxis()->SetLabelOffset(0.007);
   hframe__76->GetXaxis()->SetLabelSize(27);
   hframe__76->GetXaxis()->SetTitleSize(33);
   hframe__76->GetXaxis()->SetTitleOffset(0.9);
   hframe__76->GetXaxis()->SetTitleFont(43);
   hframe__76->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__76->GetYaxis()->SetLabelFont(43);
   hframe__76->GetYaxis()->SetLabelOffset(0.007);
   hframe__76->GetYaxis()->SetLabelSize(27);
   hframe__76->GetYaxis()->SetTitleSize(33);
   hframe__76->GetYaxis()->SetTitleOffset(1.25);
   hframe__76->GetYaxis()->SetTitleFont(43);
   hframe__76->GetZaxis()->SetLabelFont(43);
   hframe__76->GetZaxis()->SetLabelOffset(0.007);
   hframe__76->GetZaxis()->SetLabelSize(27);
   hframe__76->GetZaxis()->SetTitleSize(33);
   hframe__76->GetZaxis()->SetTitleFont(43);
   hframe__76->Draw("sameaxis");
   invertedEWKGenuineTaustaup_Teq80to100Integral->Modified();
   invertedEWKGenuineTaustaup_Teq80to100Integral->cd();
   invertedEWKGenuineTaustaup_Teq80to100Integral->SetSelected(invertedEWKGenuineTaustaup_Teq80to100Integral);
}
