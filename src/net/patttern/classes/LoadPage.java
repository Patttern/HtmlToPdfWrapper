package net.patttern.classes;

import com.sun.jna.StringArray;
import com.sun.jna.Structure;
import net.patttern.enums.ListOfMapStrings;
import net.patttern.enums.ListOfPostItems;
import net.patttern.enums.ListOfStrings;
import net.patttern.enums.LoadErrorHandling;

import java.util.*;
import java.util.List;

/**
 * Created by ebabenko on 07.12.15.
 */
public class LoadPage extends Structure {
/*
  LoadPage();
  enum LoadErrorHandling {
    abort,
    skip,
    ignore
  };
  //! Username used for http auth login
  QString username;
  //! Password used for http auth login
  QString password;
  //! How many milliseconds should we wait for a Javascript redirect
  int jsdelay;
  //! What window.status value should we wait for
  QString windowStatus;
  //! What zoom factor should we apply when printing
  // TODO MOVE
  float zoomFactor;
  //! Map of custom header variables
  QList< QPair<QString, QString> > customHeaders;
  //! Set if the custom header should be repeated for each resource request
  bool repeatCustomHeaders;
  //! Map of cookies
  QList< QPair<QString, QString> > cookies;
  QList< PostItem > post;
  //! Block access to local files for the given page
  bool blockLocalFileAccess;
  //! If access to local files is not allowed in general, allow it for these files
  QList< QString > allowed;
  //! Stop Javascript from running too long
  bool stopSlowScripts;
  //! Output Javascript debug messages
  bool debugJavascript;
  //! What should we do about load errors
  LoadErrorHandling loadErrorHandling;
  LoadErrorHandling mediaLoadErrorHandling;
  //! Proxy related settings
  Proxy proxy;
  //! Additional javascript to run on a page once it has loaded
  QList< QString > runScript;
  QString checkboxSvg;
  QString checkboxCheckedSvg;
  QString radiobuttonSvg;
  QString radiobuttonCheckedSvg;
  QString cacheDir;
  static QList<QString> mediaFilesExtensions;
  // Hosts to bypass
  QList< QString > bypassProxyForHosts;
*/
  public String username;
  public String password;
  public Integer jsdelay;
  public String windowStatus;
  public Float zoomFactor;
//  public List<Map<String, String>> customHeaders;
  public ListOfMapStrings customHeaders;
  public Boolean repeatCustomHeaders;
//  public List<Map<String, String>> cookies;
  public ListOfMapStrings cookies;
//  public List<PostItem> post;
  public ListOfPostItems post;
  public Boolean blockLocalFileAccess;
//  public List<String> allowed;
  public ListOfStrings allowed;
  public Boolean stopSlowScripts;
  public Boolean debugJavascript;
  public LoadErrorHandling loadErrorHandling;
  public LoadErrorHandling mediaLoadErrorHandling;
  public Proxy proxy;
//  public List<String> runScript;
  public ListOfStrings runScript;
  public String checkboxSvg;
  public String checkboxCheckedSvg;
  public String radiobuttonSvg;
  public String radiobuttonCheckedSvg;
  public String cacheDir;
//  public List<String> mediaFilesExtensions;/*static???*/
  public ListOfStrings mediaFilesExtensions;/*static???*/
//  public List<String> bypassProxyForHosts;
  public ListOfStrings bypassProxyForHosts;

  public LoadPage() {
  }
}
