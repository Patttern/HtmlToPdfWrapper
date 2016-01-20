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
      // Метод можно вызвать в любой момент
      String version = wrapper.getVersion();
      System.out.println("Текущая версия wrapper-а: " + version);

      // Init wrapper
      // Параметр функции указывает включать или не включать отладочный режим:
      // true - отладочный режим включен
      // false - отладочный режим выключен
      wrapper.init(true);

      /*
       * Конвертация локального файла
       */
      // Сброс настроек
      // После вызова wrapper.init(), сброс настроек вызывать не требуется, но ошибкой не будет.
      wrapper.resetSettings();
      // Назначаем файлы источника и назначения
      wrapper.setSource(sourceLocalHtml);
      wrapper.setDestination(destLocalResult);
      // Вызов процесса конвертации
      wrapper.convert();

      /*
       * Конвертация файла с параметрами
       */
      // Сброс настроек
      wrapper.resetSettings();
      // Назначаем файлы источника и назначения
      wrapper.setSource(sourceLocalHtml);
      wrapper.setDestination(destLocalWithParamResult);
      // Назначаем глобальные параметры
      GlobalSettings gs = new GlobalSettings();
      gs.setColorMode(wrapper, "Grayscale");
      // Назначаем параметры для PDF файла
      ObjectSettings os = new ObjectSettings();
      os.setPagesCount(wrapper, true);
      // Вызов процесса конвертации
      wrapper.convert();

      /*
       * Конвертация файла через указание URL
       */
      // Сброс настроек
      wrapper.resetSettings();
      // Назначаем файлы источника и назначения
      wrapper.setSource(sourceRemoteHtml);
      wrapper.setDestination(destRemoteResult);
      // Вызов процесса конвертации
      wrapper.convert();

      // Завершение работы с wrapper-ом
      // Уничтожаем все созданные объекты
      wrapper.release();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
