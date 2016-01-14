package test.patttern;

import net.patttern.htmltopdf.Wrapper;

import java.nio.file.Paths;

/**
 * Created by ebabenko on 27.08.15.
 */
public class Main {
  public static void main(String[] args) {
    try {
      Wrapper wrapper = new Wrapper();
      String currPath = Paths.get(".").toAbsolutePath().normalize().toString();
      String sourceLocalHtml = currPath + "/result/sources/QFileInfo_Class.html";
      String destLocalResult = currPath + "/result/out/test_local.pdf";
      String sourceRemoteHtml = "http://doc.qt.io/qt-5/qfileinfo.html";
      String destRemoteResult = currPath + "/result/out/test_remote.pdf";
      wrapper.init(false);
      wrapper.setSource(sourceLocalHtml);
      wrapper.setDestination(destLocalResult);
//      wrapper.setSource(sourceRemoteHtml);
//      wrapper.setDestination(destRemoteResult);
//      wrapper.setObjectSettings("page", sourceLocalHtml);
//      wrapper.setGlobalSettings("out", destLocalResult);
      wrapper.convert();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
