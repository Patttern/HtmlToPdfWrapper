package net.patttern.classes;

import com.sun.jna.Structure;
import net.patttern.enums.ListOfMapStrings;

/**
 * Created by ebabenko on 04.12.15.
 */
public class PdfObject extends Structure {
/*
  PdfObject();
  //! Settings regarding the TOC
  TableOfContent toc;
  QString page;
  //! Header related settings
  HeaderFooter header;
  //! Header related settings
  HeaderFooter footer;
  //! Should external links be links in the PDF
  bool useExternalLinks;
  //! Should internal links be links in the PDF
  bool useLocalLinks;
  //! Replacements
  QList< QPair<QString, QString> > replacements;
  //! Convert forms on the pages into PDF forms
  bool produceForms;
  LoadPage load;
  Web web;
  bool includeInOutline;
  bool pagesCount;
  bool isTableOfContent;
  QString tocXsl;
  QString get(const char * name);
  bool set(const char * name, const QString & value);
*/
  public TableOfContent toc;
  public String page;
  public HeaderFooter header;
  public HeaderFooter footer;
  public Boolean useExternalLinks;
  public Boolean useLocalLinks;
//  public com.sun.jna.Native List<Map<String, String>> replacements;
  public ListOfMapStrings replacements;
  public Boolean produceForms;
  public LoadPage load;
  public Web web;
  public Boolean includeInOutline;
  public Boolean pagesCount;
  public Boolean isTableOfContent;
  public String tocXsl;

  public PdfObject() {
  }
}
