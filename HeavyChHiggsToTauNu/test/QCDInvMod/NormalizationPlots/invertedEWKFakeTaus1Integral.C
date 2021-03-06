{
//=========Macro generated from canvas: invertedEWKFakeTaus1Integral/
//=========  (Sun Jul 20 15:00:26 2014) by ROOT version5.32/00
   TCanvas *invertedEWKFakeTaus1Integral = new TCanvas("invertedEWKFakeTaus1Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   invertedEWKFakeTaus1Integral->SetHighLightColor(2);
   invertedEWKFakeTaus1Integral->Range(-101.2658,-1.470336,531.6456,2.147636);
   invertedEWKFakeTaus1Integral->SetFillColor(0);
   invertedEWKFakeTaus1Integral->SetBorderMode(0);
   invertedEWKFakeTaus1Integral->SetBorderSize(2);
   invertedEWKFakeTaus1Integral->SetLogy();
   invertedEWKFakeTaus1Integral->SetTickx(1);
   invertedEWKFakeTaus1Integral->SetTicky(1);
   invertedEWKFakeTaus1Integral->SetLeftMargin(0.16);
   invertedEWKFakeTaus1Integral->SetRightMargin(0.05);
   invertedEWKFakeTaus1Integral->SetTopMargin(0.05);
   invertedEWKFakeTaus1Integral->SetBottomMargin(0.13);
   invertedEWKFakeTaus1Integral->SetFrameFillStyle(0);
   invertedEWKFakeTaus1Integral->SetFrameBorderMode(0);
   invertedEWKFakeTaus1Integral->SetFrameFillStyle(0);
   invertedEWKFakeTaus1Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__23 = new TH1F("hframe__23","",1000,0,500);
   hframe__23->SetMinimum(0.1);
   hframe__23->SetMaximum(92.62694);
   hframe__23->SetDirectory(0);
   hframe__23->SetStats(0);
   hframe__23->SetLineStyle(0);
   hframe__23->SetMarkerStyle(20);
   hframe__23->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__23->GetXaxis()->SetLabelFont(43);
   hframe__23->GetXaxis()->SetLabelOffset(0.007);
   hframe__23->GetXaxis()->SetLabelSize(27);
   hframe__23->GetXaxis()->SetTitleSize(33);
   hframe__23->GetXaxis()->SetTitleOffset(0.9);
   hframe__23->GetXaxis()->SetTitleFont(43);
   hframe__23->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__23->GetYaxis()->SetLabelFont(43);
   hframe__23->GetYaxis()->SetLabelOffset(0.007);
   hframe__23->GetYaxis()->SetLabelSize(27);
   hframe__23->GetYaxis()->SetTitleSize(33);
   hframe__23->GetYaxis()->SetTitleOffset(1.25);
   hframe__23->GetYaxis()->SetTitleFont(43);
   hframe__23->GetZaxis()->SetLabelFont(43);
   hframe__23->GetZaxis()->SetLabelOffset(0.007);
   hframe__23->GetZaxis()->SetLabelSize(27);
   hframe__23->GetZaxis()->SetTitleSize(33);
   hframe__23->GetZaxis()->SetTitleFont(43);
   hframe__23->Draw(" ");
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
      tex = new TLatex(0.43,0.96,"L=20 fb^{-1}");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.4,0.7,"Integral = 522 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1 = new TH1F("Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1","#tau p_{T}=50..60",50,0,500);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(1,4.530335);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(2,13.401);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(3,18.63026);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(4,30.83799);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(5,27.78314);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(6,35.3679);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(7,42.61094);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(8,41.87209);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(9,33.71645);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(10,46.31347);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(11,33.89443);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(12,26.00298);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(13,26.89195);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(14,22.20687);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(15,22.55898);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(16,23.10229);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(17,11.16706);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(18,15.61913);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(19,10.87711);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(20,8.151656);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(21,4.432085);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(22,4.066975);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(23,2.323408);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(24,3.136548);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(25,2.262278);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(26,1.861457);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(27,0.3667916);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(28,0.3328759);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(29,1.652606);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(30,1.83202);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(31,0.373017);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(32,0.7993199);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(33,0.3812025);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(34,0.6509599);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(35,0.3723527);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(36,0.6395566);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(37,0.004414531);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(41,0.2380071);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinContent(43,0.7325767);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(1,1.467651);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(2,3.096901);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(3,3.738802);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(4,9.934371);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(5,3.873844);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(6,4.674452);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(7,6.499324);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(8,4.963067);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(9,4.447865);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(10,5.085497);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(11,4.512975);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(12,3.798866);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(13,3.913503);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(14,3.503376);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(15,3.723533);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(16,4.136448);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(17,2.996672);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(18,2.809029);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(19,2.431237);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(20,2.155227);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(21,1.494767);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(22,1.368286);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(23,1.046277);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(24,1.647252);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(25,1.015329);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(26,0.953309);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(27,0.3232271);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(28,0.3328759);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(29,1.223492);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(30,0.9398437);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(31,0.3730171);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(32,0.5655986);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(33,0.3812025);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(34,0.6509599);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(35,0.3723528);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(36,0.6395566);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(37,0.004414531);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(41,0.2380071);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetBinError(43,0.7325766);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetEntries(1258);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetFillColor(ci);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetLineWidth(2);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetMarkerStyle(20);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->SetMarkerSize(1.2);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetXaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetXaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetXaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetXaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetYaxis()->SetTitle("Events / 10 GeV");
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetYaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetYaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetYaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetYaxis()->SetTitleOffset(1.5);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetYaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetZaxis()->SetLabelFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetZaxis()->SetLabelSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetZaxis()->SetTitleSize(0.035);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->GetZaxis()->SetTitleFont(42);
   Inverted/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus/METInvertedTauIdAfterCollinearCutsOnlyEWKFakeTaus1->Draw("HIST same");
   
   TH1F *hframe__24 = new TH1F("hframe__24","",1000,0,500);
   hframe__24->SetMinimum(0.1);
   hframe__24->SetMaximum(92.62694);
   hframe__24->SetDirectory(0);
   hframe__24->SetStats(0);
   hframe__24->SetLineStyle(0);
   hframe__24->SetMarkerStyle(20);
   hframe__24->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__24->GetXaxis()->SetLabelFont(43);
   hframe__24->GetXaxis()->SetLabelOffset(0.007);
   hframe__24->GetXaxis()->SetLabelSize(27);
   hframe__24->GetXaxis()->SetTitleSize(33);
   hframe__24->GetXaxis()->SetTitleOffset(0.9);
   hframe__24->GetXaxis()->SetTitleFont(43);
   hframe__24->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__24->GetYaxis()->SetLabelFont(43);
   hframe__24->GetYaxis()->SetLabelOffset(0.007);
   hframe__24->GetYaxis()->SetLabelSize(27);
   hframe__24->GetYaxis()->SetTitleSize(33);
   hframe__24->GetYaxis()->SetTitleOffset(1.25);
   hframe__24->GetYaxis()->SetTitleFont(43);
   hframe__24->GetZaxis()->SetLabelFont(43);
   hframe__24->GetZaxis()->SetLabelOffset(0.007);
   hframe__24->GetZaxis()->SetLabelSize(27);
   hframe__24->GetZaxis()->SetTitleSize(33);
   hframe__24->GetZaxis()->SetTitleFont(43);
   hframe__24->Draw("sameaxis");
   invertedEWKFakeTaus1Integral->Modified();
   invertedEWKFakeTaus1Integral->cd();
   invertedEWKFakeTaus1Integral->SetSelected(invertedEWKFakeTaus1Integral);
}
