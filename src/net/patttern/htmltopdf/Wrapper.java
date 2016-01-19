package net.patttern.htmltopdf;

/**
 * Created by pattern on 22.12.15.
 * Commands:
 * javac -d ~/work/HtmlToPdfWrapper/build/src src/net/patttern/htmltopdf/Wrapper.java
 * cd ~/work/HtmlToPdfWrapper/build/src
 * javah net.patttern.htmltopdf.Wrapper
 * cd ~/work/HtmlToPdfWrapper
 */
public class Wrapper {
  static {
    System.loadLibrary("HtmlToPdfWrapper");
  }

  public native static String getVersion();
  public native static void init(boolean debug);
  public native static void setSource(String value);
  public native static void setDestination(String value);
  public native static void setGlobalSettings(String name, String value);
  public native static void setObjectSettings(String name, String value);
  public native static int convert();
  public native static void release();
}
