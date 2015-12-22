package test.patttern;

import net.patttern.htmltopdf.Wrapper;

/**
 * Created by ebabenko on 27.08.15.
 */
public class Main {
  public static void main(String[] args) {
    try {
      Wrapper wrapper = new Wrapper();
      wrapper.convertLocal("/home/pattern/work/HtmlToPdfWrapper/result/sources/QFileInfo_Class.html", "/home/pattern/work/HtmlToPdfWrapper/result/out/test.pdf");
//    wrapper.convertRemote("http://doc.qt.io/qt-5/qfileinfo.html", "/home/pattern/work/HtmlToPdfWrapper/result/out/test.pdf");
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
