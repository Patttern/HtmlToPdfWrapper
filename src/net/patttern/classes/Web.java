package net.patttern.classes;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class Web extends Structure {
/*
  Web();
  //! Should we print background images
  bool background;
  //! Should we load images
  bool loadImages;
  //! Should we enable Javascript
  bool enableJavascript;
  //! Should the horrible intelligent shrinking feature be enabled?
  bool enableIntelligentShrinking;
  //! Minimum font size
  int minimumFontSize;
  //! Should we use the print or the screen media type
  bool printMediaType;
  //! Encoding used to enterpit a document with do supplied encoding
  QString defaultEncoding;
  //! Stylesheet supplied by the user
  QString userStyleSheet;
  //! Should plugins be allowed
  bool enablePlugins;
*/
  public Boolean background;
  public Boolean loadImages;
  public Boolean enableJavascript;
  public Boolean enableIntelligentShrinking;
  public Integer minimumFontSize;
  public Boolean printMediaType;
  public String defaultEncoding;
  public String userStyleSheet;
  public Boolean enablePlugins;

  public Web() {
  }
}
