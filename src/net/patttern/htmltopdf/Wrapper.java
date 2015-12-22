package net.patttern.htmltopdf;

/**
 * Created by pattern on 22.12.15.
 * Commands:
 * javac -d ~/work/HtmlToPdfWrapper/build/HtmlToPdfWrapper src/net/patttern/htmltopdf/Wrapper.java
 * cd ~/work/HtmlToPdfWrapper/build/HtmlToPdfWrapper
 * javah net.patttern.htmltopdf.Wrapper
 * cd ~/work/HtmlToPdfWrapper
 */
public class Wrapper {
  static {
    System.loadLibrary("HtmlToPdfWrapper");
  }

  public native static int convertLocal(String src, String dst);
  public native static int convertRemote(String src, String dst);
}
