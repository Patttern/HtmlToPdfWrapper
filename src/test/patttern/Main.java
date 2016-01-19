package test.patttern;

import net.patttern.htmltopdf.GlobalSettings;
import net.patttern.htmltopdf.ObjectSettings;
import net.patttern.htmltopdf.Wrapper;

import java.nio.file.Paths;

/**
 * Created by ebabenko on 27.08.15.
 */
public class Main {
  public static void main(String[] args) {
    try {
      // Создаем Wrapper
      Wrapper wrapper = new Wrapper();

      // Определяем наименования файлов истоников и назначения
      String currPath = Paths.get(".").toAbsolutePath().normalize().toString();
      String sourceLocalHtml = currPath + "/result/sources/QFileInfo_Class.html";
      String destLocalResult = currPath + "/result/out/test_local.pdf";
      String destLocalWithParamResult = currPath + "/result/out/test_local_with_param.pdf";
      String sourceRemoteHtml = "http://doc.qt.io/qt-5/qfileinfo.html";
      String destRemoteResult = currPath + "/result/out/test_remote.pdf";

      // Выводим текущую версию wrapper-а
      String version = wrapper.getVersion();
      System.out.println("Текущая версия wrapper-а: " + version);

      // Init wrapper
      // Параметр функции указывает включать или не включать отладочный режим:
      // true - отладочный режим включен
      // false - отладочный режим выключен
      wrapper.init(false);

      // Конвертация локально сохраненного файла
      wrapper.setSource(sourceLocalHtml);
      wrapper.setDestination(destLocalResult);
      wrapper.convert();

      // Конвертация файла через указание URL
      wrapper.setSource(sourceRemoteHtml);
      wrapper.setDestination(destRemoteResult);
      wrapper.convert();

      // Установка дополнительных параметров.
      // ВАЖНО! Установленные параметры будут действовать для всех последующих конвертаций.
      // Поэтому если требуется сбросить уже назначенные вами парамтеры,
      // требуется пересоздать или создать новый объект на Wrapper.
      wrapper.setSource(sourceLocalHtml);
      wrapper.setDestination(destLocalWithParamResult);

      ObjectSettings os = new ObjectSettings();
      os.setPagesCount(wrapper, true);

      GlobalSettings gs = new GlobalSettings();
      gs.setColorMode(wrapper, "Grayscale");

      wrapper.convert();

      // Уничтожаем все созданные объекты
      wrapper.release();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
