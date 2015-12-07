package net.patttern.enums;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class PageSize extends Structure {
  // Existing Qt sizes
  public int A4;
  public int B5;
  public int Letter;
  public int Legal;
  public int Executive;
  public int A0;
  public int A1;
  public int A2;
  public int A3;
  public int A5;
  public int A6;
  public int A7;
  public int A8;
  public int A9;
  public int B0;
  public int B1;
  public int B10;
  public int B2;
  public int B3;
  public int B4;
  public int B6;
  public int B7;
  public int B8;
  public int B9;
  public int C5E;
  public int Comm10E;
  public int DLE;
  public int Folio;
  public int Ledger;
  public int Tabloid;
  public int Custom;

  // New values derived from PPD standard
  public int A10;
  public int A3Extra;
  public int A4Extra;
  public int A4Plus;
  public int A4Small;
  public int A5Extra;
  public int B5Extra;

  public int JisB0;
  public int JisB1;
  public int JisB2;
  public int JisB3;
  public int JisB4;
  public int JisB5;
  public int JisB6;
  public int JisB7;
  public int JisB8;
  public int JisB9;
  public int JisB10;

  // AnsiA = Letter;
  // AnsiB = Ledger;
  public int AnsiC;
  public int AnsiD;
  public int AnsiE;
  public int LegalExtra;
  public int LetterExtra;
  public int LetterPlus;
  public int LetterSmall;
  public int TabloidExtra;

  public int ArchA;
  public int ArchB;
  public int ArchC;
  public int ArchD;
  public int ArchE;

  public int Imperial7x9;
  public int Imperial8x10;
  public int Imperial9x11;
  public int Imperial9x12;
  public int Imperial10x11;
  public int Imperial10x13;
  public int Imperial10x14;
  public int Imperial12x11;
  public int Imperial15x11;

  public int ExecutiveStandard;
  public int Note;
  public int Quarto;
  public int Statement;
  public int SuperA;
  public int SuperB;
  public int Postcard;
  public int DoublePostcard;
  public int Prc16K;
  public int Prc32K;
  public int Prc32KBig;

  public int FanFoldUS;
  public int FanFoldGerman;
  public int FanFoldGermanLegal;

  public int EnvelopeB4;
  public int EnvelopeB5;
  public int EnvelopeB6;
  public int EnvelopeC0;
  public int EnvelopeC1;
  public int EnvelopeC2;
  public int EnvelopeC3;
  public int EnvelopeC4;
  // EnvelopeC5 = C5E;
  public int EnvelopeC6;
  public int EnvelopeC65;
  public int EnvelopeC7;
  // EnvelopeDL = DLE;

  public int Envelope9;
  // Envelope10 = Comm10E;
  public int Envelope11;
  public int Envelope12;
  public int Envelope14;
  public int EnvelopeMonarch;
  public int EnvelopePersonal;

  public int EnvelopeChou3;
  public int EnvelopeChou4;
  public int EnvelopeInvite;
  public int EnvelopeItalian;
  public int EnvelopeKaku2;
  public int EnvelopeKaku3;
  public int EnvelopePrc1;
  public int EnvelopePrc2;
  public int EnvelopePrc3;
  public int EnvelopePrc4;
  public int EnvelopePrc5;
  public int EnvelopePrc6;
  public int EnvelopePrc7;
  public int EnvelopePrc8;
  public int EnvelopePrc9;
  public int EnvelopePrc10;
  public int EnvelopeYou4;

  // Last item; with commonly used synynoms from QPagedPrintEngine / QPrinter
  public int LastPageSize;
  public int NPageSize;
  public int NPaperSize;

  // Convenience overloads for naming consistency
  public int AnsiA;
  public int AnsiB;
  public int EnvelopeC5;
  public int EnvelopeDL;
  public int Envelope10;
}
