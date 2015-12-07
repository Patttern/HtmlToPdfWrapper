package net.patttern.classes;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class TableOfContent extends Structure {
/*
  TableOfContent();
  //! Should we print dots between the name and the page number?
  bool useDottedLines;
  //! Name af the TOC
  QString captionText;
  //! Link from TOC to section headers
  bool forwardLinks;
  //! Link from section headers to TOC
  bool backLinks;
  //! How fare should we indent on every level
  QString indentation;
  //! Factor we should scale the font with on every level
  float fontScale;
*/
  public Boolean useDottedLines;
  public String captionText;
  public Boolean forwardLinks;
  public Boolean backLinks;
  public String indentation;
  public Float fontScale;

  public TableOfContent() {
  }
}
