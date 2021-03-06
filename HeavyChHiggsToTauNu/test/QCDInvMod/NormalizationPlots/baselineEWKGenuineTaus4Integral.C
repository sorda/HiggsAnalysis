{
//=========Macro generated from canvas: baselineEWKGenuineTaus4Integral/
//=========  (Sun Jul 20 15:00:34 2014) by ROOT version5.32/00
   TCanvas *baselineEWKGenuineTaus4Integral = new TCanvas("baselineEWKGenuineTaus4Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   baselineEWKGenuineTaus4Integral->SetHighLightColor(2);
   baselineEWKGenuineTaus4Integral->Range(-101.2658,-1.443,531.6456,1.964694);
   baselineEWKGenuineTaus4Integral->SetFillColor(0);
   baselineEWKGenuineTaus4Integral->SetBorderMode(0);
   baselineEWKGenuineTaus4Integral->SetBorderSize(2);
   baselineEWKGenuineTaus4Integral->SetLogy();
   baselineEWKGenuineTaus4Integral->SetTickx(1);
   baselineEWKGenuineTaus4Integral->SetTicky(1);
   baselineEWKGenuineTaus4Integral->SetLeftMargin(0.16);
   baselineEWKGenuineTaus4Integral->SetRightMargin(0.05);
   baselineEWKGenuineTaus4Integral->SetTopMargin(0.05);
   baselineEWKGenuineTaus4Integral->SetBottomMargin(0.13);
   baselineEWKGenuineTaus4Integral->SetFrameFillStyle(0);
   baselineEWKGenuineTaus4Integral->SetFrameBorderMode(0);
   baselineEWKGenuineTaus4Integral->SetFrameFillStyle(0);
   baselineEWKGenuineTaus4Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__81 = new TH1F("hframe__81","",1000,0,500);
   hframe__81->SetMinimum(0.1);
   hframe__81->SetMaximum(62.2743);
   hframe__81->SetDirectory(0);
   hframe__81->SetStats(0);
   hframe__81->SetLineStyle(0);
   hframe__81->SetMarkerStyle(20);
   hframe__81->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__81->GetXaxis()->SetLabelFont(43);
   hframe__81->GetXaxis()->SetLabelOffset(0.007);
   hframe__81->GetXaxis()->SetLabelSize(27);
   hframe__81->GetXaxis()->SetTitleSize(33);
   hframe__81->GetXaxis()->SetTitleOffset(0.9);
   hframe__81->GetXaxis()->SetTitleFont(43);
   hframe__81->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__81->GetYaxis()->SetLabelFont(43);
   hframe__81->GetYaxis()->SetLabelOffset(0.007);
   hframe__81->GetYaxis()->SetLabelSize(27);
   hframe__81->GetYaxis()->SetTitleSize(33);
   hframe__81->GetYaxis()->SetTitleOffset(1.25);
   hframe__81->GetYaxis()->SetTitleFont(43);
   hframe__81->GetZaxis()->SetLabelFont(43);
   hframe__81->GetZaxis()->SetLabelOffset(0.007);
   hframe__81->GetZaxis()->SetLabelSize(27);
   hframe__81->GetZaxis()->SetTitleSize(33);
   hframe__81->GetZaxis()->SetTitleFont(43);
   hframe__81->Draw(" ");
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
      tex = new TLatex(0.4,0.7,"Integral = 392 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4 = new TH1F("baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4","#tau p_{T}=80..100",50,0,500);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(1,0.0182317);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(2,1.083185);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(3,5.78496);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(4,7.480262);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(5,8.725943);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(6,6.547968);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(7,6.155234);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(8,14.54689);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(9,13.1002);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(10,23.50372);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(11,27.37656);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(12,15.87922);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(13,31.13715);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(14,26.06076);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(15,21.72545);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(16,20.6029);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(17,30.96841);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(18,16.7732);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(19,10.54507);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(20,17.62604);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(21,7.939657);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(22,10.04982);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(23,8.154355);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(24,11.59768);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(25,6.301722);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(26,5.796148);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(27,4.069607);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(28,7.378724);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(29,4.149147);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(30,1.214411);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(31,4.104929);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(32,3.362848);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(33,1.254144);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(34,1.424401);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(35,1.902393);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(36,0.8404561);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(37,1.6838);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(38,0.4561551);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(39,0.7837662);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(40,0.8783761);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(41,0.5563043);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(42,0.3997096);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(43,0.1153979);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(44,0.3834707);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(45,0.3894083);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(46,0.4913392);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(47,1.146723);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinContent(51,1.715223);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(1,0.0182317);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(2,0.7596507);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(3,2.48729);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(4,2.929245);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(5,4.898271);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(6,1.835341);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(7,2.052214);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(8,3.549513);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(9,3.858137);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(10,4.9364);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(11,6.453517);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(12,3.554204);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(13,5.768913);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(14,4.274425);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(15,3.635012);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(16,4.186061);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(17,6.580132);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(18,2.965501);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(19,2.19476);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(20,3.18802);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(21,1.935389);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(22,2.015573);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(23,1.897189);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(24,5.423193);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(25,1.93739);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(26,1.94624);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(27,1.504294);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(28,3.002533);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(29,1.297407);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(30,0.7407327);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(31,1.367831);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(32,1.40829);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(33,0.6771487);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(34,1.424401);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(35,0.8508371);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(36,0.5958911);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(37,0.8340104);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(38,0.4551355);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(39,0.5542082);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(40,0.6266406);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(41,0.4296518);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(42,0.3997096);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(43,0.1153979);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(44,0.3834707);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(45,0.3894084);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(46,0.3925123);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(47,0.8777884);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetBinError(51,0.780433);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetEntries(871);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetFillColor(ci);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetLineWidth(2);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetMarkerStyle(20);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->SetMarkerSize(1.2);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetXaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitle("Events / 10 GeV");
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitleOffset(1.5);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetYaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->GetZaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus4->Draw("HIST same");
   
   TH1F *hframe__82 = new TH1F("hframe__82","",1000,0,500);
   hframe__82->SetMinimum(0.1);
   hframe__82->SetMaximum(62.2743);
   hframe__82->SetDirectory(0);
   hframe__82->SetStats(0);
   hframe__82->SetLineStyle(0);
   hframe__82->SetMarkerStyle(20);
   hframe__82->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__82->GetXaxis()->SetLabelFont(43);
   hframe__82->GetXaxis()->SetLabelOffset(0.007);
   hframe__82->GetXaxis()->SetLabelSize(27);
   hframe__82->GetXaxis()->SetTitleSize(33);
   hframe__82->GetXaxis()->SetTitleOffset(0.9);
   hframe__82->GetXaxis()->SetTitleFont(43);
   hframe__82->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__82->GetYaxis()->SetLabelFont(43);
   hframe__82->GetYaxis()->SetLabelOffset(0.007);
   hframe__82->GetYaxis()->SetLabelSize(27);
   hframe__82->GetYaxis()->SetTitleSize(33);
   hframe__82->GetYaxis()->SetTitleOffset(1.25);
   hframe__82->GetYaxis()->SetTitleFont(43);
   hframe__82->GetZaxis()->SetLabelFont(43);
   hframe__82->GetZaxis()->SetLabelOffset(0.007);
   hframe__82->GetZaxis()->SetLabelSize(27);
   hframe__82->GetZaxis()->SetTitleSize(33);
   hframe__82->GetZaxis()->SetTitleFont(43);
   hframe__82->Draw("sameaxis");
   baselineEWKGenuineTaus4Integral->Modified();
   baselineEWKGenuineTaus4Integral->cd();
   baselineEWKGenuineTaus4Integral->SetSelected(baselineEWKGenuineTaus4Integral);
}
