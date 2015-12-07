package net.patttern.classes;

import com.sun.jna.Structure;
import net.patttern.enums.ColorMode;
import net.patttern.enums.Orientation;
import net.patttern.enums.PrinterMode;

/**
 * Created by ebabenko on 04.12.15.
 */
public class PdfGlobal extends Structure {
/*
  PdfGlobal();
  //! Size related settings
  Size size;
  //! Be less verbose
  bool quiet;
  //! Should we use the graphics system
  bool useGraphics;
  //! Should relative links be resolved or kept as-is
  bool resolveRelativeLinks;
  //! Should we orientate in landscape or portrate
  QPrinter::Orientation orientation;
  //! Color or grayscale
  QPrinter::ColorMode colorMode;
  //! What overall resolution should we use
  QPrinter::PrinterMode resolution;
  //! What dpi should be used when printing
  int dpi;
  //! When pagenumbers are printed, apply this offset to them all
  int pageOffset;
  //! How many copies do we wan to print
  int copies;
  //! Should be print a whole copy before beginning the next
  bool collate;
  //! Should we generate an outline and put it into the pdf file
  bool outline;
  //! Maximal depth of the generated outline
  int outlineDepth;
  //! dump outline to this filename
  QString dumpOutline;
  //! The file where in to store the output
  QString out;
  QString documentTitle;
  bool useCompression;
  //! Margin related settings
  Margin margin;
  QString viewportSize;
  int imageDPI;
  int imageQuality;
  LoadGlobal load;
  QString get(const char * name);
  bool set(const char * name, const QString & value);
*/
  public Size size;
  public Boolean quiet;
  public Boolean useGraphics;
  public Boolean resolveRelativeLinks;
  public Orientation orientation;
  public ColorMode colorMode;
  public PrinterMode resolution;
  public Integer dpi;
  public Integer pageOffset;
  public Integer copies;
  public Boolean collate;
  public Boolean outline;
  public Integer outlineDepth;
  public String dumpOutline;
  public String out;
  public String documentTitle;
  public Boolean useCompression;
  public Margin margin;
  public String viewportSize;
  public Integer imageDPI;
  public Integer imageQuality;
  public LoadGlobal load;
//  public Structure load;

  public PdfGlobal() {
  }
}
