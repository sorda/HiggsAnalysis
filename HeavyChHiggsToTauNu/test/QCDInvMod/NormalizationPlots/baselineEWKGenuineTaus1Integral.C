{
//=========Macro generated from canvas: baselineEWKGenuineTaus1Integral/
//=========  (Sun Jul 20 15:00:26 2014) by ROOT version5.32/00
   TCanvas *baselineEWKGenuineTaus1Integral = new TCanvas("baselineEWKGenuineTaus1Integral", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   baselineEWKGenuineTaus1Integral->SetHighLightColor(2);
   baselineEWKGenuineTaus1Integral->Range(-101.2658,-1.490784,531.6456,2.284478);
   baselineEWKGenuineTaus1Integral->SetFillColor(0);
   baselineEWKGenuineTaus1Integral->SetBorderMode(0);
   baselineEWKGenuineTaus1Integral->SetBorderSize(2);
   baselineEWKGenuineTaus1Integral->SetLogy();
   baselineEWKGenuineTaus1Integral->SetTickx(1);
   baselineEWKGenuineTaus1Integral->SetTicky(1);
   baselineEWKGenuineTaus1Integral->SetLeftMargin(0.16);
   baselineEWKGenuineTaus1Integral->SetRightMargin(0.05);
   baselineEWKGenuineTaus1Integral->SetTopMargin(0.05);
   baselineEWKGenuineTaus1Integral->SetBottomMargin(0.13);
   baselineEWKGenuineTaus1Integral->SetFrameFillStyle(0);
   baselineEWKGenuineTaus1Integral->SetFrameBorderMode(0);
   baselineEWKGenuineTaus1Integral->SetFrameFillStyle(0);
   baselineEWKGenuineTaus1Integral->SetFrameBorderMode(0);
   
   TH1F *hframe__27 = new TH1F("hframe__27","",1000,0,500);
   hframe__27->SetMinimum(0.1);
   hframe__27->SetMaximum(124.6564);
   hframe__27->SetDirectory(0);
   hframe__27->SetStats(0);
   hframe__27->SetLineStyle(0);
   hframe__27->SetMarkerStyle(20);
   hframe__27->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__27->GetXaxis()->SetLabelFont(43);
   hframe__27->GetXaxis()->SetLabelOffset(0.007);
   hframe__27->GetXaxis()->SetLabelSize(27);
   hframe__27->GetXaxis()->SetTitleSize(33);
   hframe__27->GetXaxis()->SetTitleOffset(0.9);
   hframe__27->GetXaxis()->SetTitleFont(43);
   hframe__27->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__27->GetYaxis()->SetLabelFont(43);
   hframe__27->GetYaxis()->SetLabelOffset(0.007);
   hframe__27->GetYaxis()->SetLabelSize(27);
   hframe__27->GetYaxis()->SetTitleSize(33);
   hframe__27->GetYaxis()->SetTitleOffset(1.25);
   hframe__27->GetYaxis()->SetTitleFont(43);
   hframe__27->GetZaxis()->SetLabelFont(43);
   hframe__27->GetZaxis()->SetLabelOffset(0.007);
   hframe__27->GetZaxis()->SetLabelSize(27);
   hframe__27->GetZaxis()->SetTitleSize(33);
   hframe__27->GetZaxis()->SetTitleFont(43);
   hframe__27->Draw(" ");
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
      tex = new TLatex(0.4,0.7,"Integral = 750 ev");
tex->SetNDC();
   tex->SetTextFont(63);
   tex->SetTextSize(27);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1 = new TH1F("baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1","#tau p_{T}=50..60",50,0,500);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(1,0.3781189);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(2,2.499571);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(3,5.272861);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(4,3.862676);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(5,13.43892);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(6,13.7311);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(7,28.54309);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(8,20.74214);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(9,46.7659);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(10,46.18021);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(11,45.57317);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(12,62.32821);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(13,52.12078);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(14,53.69407);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(15,57.99477);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(16,43.93962);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(17,39.13471);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(18,34.79189);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(19,33.76943);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(20,23.22622);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(21,19.02762);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(22,22.13787);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(23,13.95213);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(24,3.320216);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(25,13.44154);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(26,9.77644);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(27,7.369876);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(28,8.923046);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(29,3.983619);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(30,2.439274);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(31,2.007389);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(32,1.309678);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(33,2.593799);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(34,2.220706);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(35,0.3519025);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(36,0.7754278);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(37,0.5807068);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(38,2.15195);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(39,0.3831142);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(40,1.072944);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(41,0.8805238);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(43,1.517993);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(44,0.8212116);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(46,0.376683);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(47,0.3014398);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(48,0.7381899);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinContent(51,1.765155);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(1,0.378014);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(2,1.209697);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(3,2.804793);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(4,1.555813);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(5,3.913291);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(6,4.047401);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(7,4.69929);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(8,3.697335);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(9,7.322672);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(10,6.784128);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(11,5.969739);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(12,6.984018);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(13,5.357867);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(14,6.172505);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(15,6.708046);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(16,6.101885);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(17,4.939892);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(18,5.592489);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(19,4.279696);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(20,3.639113);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(21,3.230027);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(22,5.55447);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(23,2.565201);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(24,1.005591);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(25,2.647668);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(26,3.445446);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(27,1.884596);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(28,2.943482);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(29,1.441933);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(30,1.084529);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(31,0.9626572);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(32,0.7348736);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(33,1.016191);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(34,0.9227212);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(35,0.2604513);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(36,0.5483131);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(37,0.4302678);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(38,0.8840266);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(39,0.3831142);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(40,0.7871003);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(41,0.6310561);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(43,0.9225019);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(44,0.7174064);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(46,0.376683);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(47,0.3014398);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(48,0.5219793);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetBinError(51,0.9665782);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetEntries(1742);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#ffff00");
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetFillColor(ci);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetLineWidth(2);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetMarkerStyle(20);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->SetMarkerSize(1.2);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetXaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetXaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetXaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetXaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetYaxis()->SetTitle("Events / 10 GeV");
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetYaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetYaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetYaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetYaxis()->SetTitleOffset(1.5);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetYaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetZaxis()->SetLabelFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetZaxis()->SetLabelSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetZaxis()->SetTitleSize(0.035);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->GetZaxis()->SetTitleFont(42);
   baseline/METBaseLineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus/METBaselineTauIdAfterCollinearCutsPlusFilteredEWKFakeTaus1->Draw("HIST same");
   
   TH1F *hframe__28 = new TH1F("hframe__28","",1000,0,500);
   hframe__28->SetMinimum(0.1);
   hframe__28->SetMaximum(124.6564);
   hframe__28->SetDirectory(0);
   hframe__28->SetStats(0);
   hframe__28->SetLineStyle(0);
   hframe__28->SetMarkerStyle(20);
   hframe__28->GetXaxis()->SetTitle("Type1 PFMET (GeV)");
   hframe__28->GetXaxis()->SetLabelFont(43);
   hframe__28->GetXaxis()->SetLabelOffset(0.007);
   hframe__28->GetXaxis()->SetLabelSize(27);
   hframe__28->GetXaxis()->SetTitleSize(33);
   hframe__28->GetXaxis()->SetTitleOffset(0.9);
   hframe__28->GetXaxis()->SetTitleFont(43);
   hframe__28->GetYaxis()->SetTitle("Events / 10 GeV");
   hframe__28->GetYaxis()->SetLabelFont(43);
   hframe__28->GetYaxis()->SetLabelOffset(0.007);
   hframe__28->GetYaxis()->SetLabelSize(27);
   hframe__28->GetYaxis()->SetTitleSize(33);
   hframe__28->GetYaxis()->SetTitleOffset(1.25);
   hframe__28->GetYaxis()->SetTitleFont(43);
   hframe__28->GetZaxis()->SetLabelFont(43);
   hframe__28->GetZaxis()->SetLabelOffset(0.007);
   hframe__28->GetZaxis()->SetLabelSize(27);
   hframe__28->GetZaxis()->SetTitleSize(33);
   hframe__28->GetZaxis()->SetTitleFont(43);
   hframe__28->Draw("sameaxis");
   baselineEWKGenuineTaus1Integral->Modified();
   baselineEWKGenuineTaus1Integral->cd();
   baselineEWKGenuineTaus1Integral->SetSelected(baselineEWKGenuineTaus1Integral);
}
