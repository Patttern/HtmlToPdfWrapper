package net.patttern.classes;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class HeaderFooter extends Structure {
/*
  HeaderFooter();
  //! Size of the font used to render the text
  int fontSize;
  //! Name of font used to render text
  QString fontName;
  //! Text to render at the left
  QString left;
  //! Text to render at the right
  QString right;
  //! Text to render at the center
  QString center;
  //! Should a line seperate the header/footer and the document
  bool line;
  //! Url of the document the html document that should be used as a header/footer
  QString htmlUrl;
  //! Spacing
  float spacing;
*/
  public Integer fontSize;
  public String fontName;
  public String left;
  public String right;
  public String center;
  public Boolean line;
  public String htmlUrl;
  public Float spacing;

  public HeaderFooter() {
  }
}
