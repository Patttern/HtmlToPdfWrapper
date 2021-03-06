# HtmlToPdfWrapper

## Описание

HtmlToPdf wrapper - это библиотека, построенная на основе библиотеки Webkit, предназначенная для прямого вызова конвертации HTML в PDF посредством Java
через Java Native Interface (JNI). Библиотека предназначена для использования в 64-битных Linux-системах (семейства Debian и RedHat, на других не проверялось).
Собранные библиотеки расположены в директории _build/libs_. Для удобства так же автоматически собираются пакеты для систем, которые расположены
в директории _build/packages_.

Если вы желаете самостоятельно собрать библиотеку на собственной системе, смотрите раздел "Разработка".

## Источники

Convert HTML to PDF using Webkit (QtWebKit)<br>
[Official Site](http://wkhtmltopdf.org/)<br>
[Git repository](https://github.com/wkhtmltopdf/wkhtmltopdf)<br>
[Settings](http://wkhtmltopdf.org/libwkhtmltox/pagesettings.html)

## Установка

#### SO библиотека

Для установки достаточно разместить собранный wrapper в переменной окружения системы, где распалагаются все библиотеки. Обычно это диретория _/usr/lib_.
Основным является файл вида _libHtmlToPdfWrapper.so.1.0.1_ (в зависимости от версии сборки), остальные файлы являются симлинками на этот файл.
Поэтому, после копирования wrapper-а, требуется так же создать симлинки со смещением расширения до _.so_:

``` bash
$ sudo cp build/libs/1.0.1/libHtmlToPdfWrapper.so.1.0.1 /usr/lib
$ cd /usr/lib
$ sudo ln -s libHtmlToPdfWrapper.so.1.0.1 libHtmlToPdfWrapper.so.1.0
$ sudo ln -s libHtmlToPdfWrapper.so.1.0.1 libHtmlToPdfWrapper.so.1
$ sudo ln -s libHtmlToPdfWrapper.so.1.0.1 libHtmlToPdfWrapper.so
```

#### Debian пакет

Если у вас установлен linux семейства Debian, вам достатчоно установить готовый Debian-пакет:

``` bash
$ sudo dpkg i build/packages/libhtmltopdfwrapper_1.0.1-20160119_amd64.deb
```

#### RedHat пакет

Если у вас установлен linux семейства RedHat, вам достатчоно установить готовый RPM-пакет:

``` bash
$ sudo dpkg i build/packages/libhtmltopdfwrapper-1.0.1-20160119.x86_64.rpm
```

## Использование

``` java
// Создаем Wrapper
Wrapper wrapper = new Wrapper();

// Определяем наименования файлов истоников и назначения
String currPath = Paths.get(".").toAbsolutePath().normalize().toString();
String sourceLocalHtml = currPath + "/result/sources/QFileInfo_Class.html";
String destLocalResult = currPath + "/result/out/test_local.pdf";
String destLocalWithParamResult = currPath + "/result/out/test_local_with_param.pdf";
String sourceRemoteHtml = "http://patttern.blogspot.ru/2015/07/mariadb-nginx-php-fpm-centos-7-page5.html";
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
```

Работу wrapper-а можно проверить в Java-классе _test.patttern.Main_.

## Разработка

Вы можете добавить собственные функции для дальнейшего использования.

### Добавление функционала

К примеру, требуется добавить, чтобы у wrapper-а появилась дополнительная функция _hello_.

#### Java

Java-проект построен с помощью IDE [JetBrains IntelliJ Idea](https://www.jetbrains.com/idea/).
Для добавления новой функции, ее требуется сначала описать в классе _net.patttern.htmltopdf.Wrapper_.

``` java
  public native static String hello(String param);
```

После того, как все функции вызова из Java описаны, требуется произвести компиляю header-файла для C++. Для этого достаточно вызвать скрипт compile,
расположенный в корне проекта:

``` bash
$ ./compile
```

Результатом работы скрипта будет перегенерированный файл _build/src/net_patttern_htmltopdf_Wrapper.h_.

#### C++

C++-проект построен с помощью IDE [Qt Creator](http://www.qt.io/ru/download-open-source/).
После того, как был перегенерирован файл _build/src/net_patttern_htmltopdf_Wrapper.h_, требуется написать обработку для новых функций в файле
_build/src/net_patttern_htmltopdf_Wrapper.cpp_. В данном примере, в файле _build/src/net_patttern_htmltopdf_Wrapper.h_ появится новая запись:

``` cpp
/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    hello
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_net_patttern_htmltopdf_Wrapper_hello
  (JNIEnv *, jclass, jstring);
```

Напишем обработчик функции, которая будет возвращать строку "Hello, " + входящий параметр.

``` cpp
JNIEXPORT jstring JNICALL Java_net_patttern_htmltopdf_Wrapper_hello (JNIEnv * jni, jclass jclass, jstring jname) {
  // cast-инг из 'jstring' в 'const char *'
  const char * name = jni->GetStringUTFChars(jname, NULL);
  QString message = "Hello, " + QString::fromUtf8(name);

  // уничтожаем jname и name, больше они нам не требуются
  jni->ReleaseStringUTFChars(jname, name);

  // cast-инг из 'const char *' в 'jstring'
  result = jni->NewStringUTF(message);
  return result;
}
```

После того, как все функции описаны, требуется собрать wrapper. Это производится из диретории _build_ с помощью скрипта _install_. Так же, этот скрипт
используется для полной перекомпиляции wrapper-а, если вы желаете его создать на собственной системе, даже если никаких изменений не производилось.
При каждой сборке BUILD-версия wrapper-а инкрементируется на 1. MAJOR и MINOR версии wrapper-а устанавливаются в скрипте _install_ (10-15 строки):

``` bash
#==================================================
# MAJOR и MINOR версии библиотеки
#==================================================

PKGMAJOR=1
PKGMINOR=0
```

Если вы желаете изменить версию, требуется выставить нужную версию в соответсвующих параметрах. После этого требутся запустить компиляю: 

``` bash
$ cd build
$ ./install
```

В результате, в директории _build/libs_ будет создан wrapper и симлинки на него, в директории _build/packages_ будут пересобраны установочные пакеты.

### Feedback

Нашли ошибку? Сообщите ее в [Bug Tracker](https://github.com/Patttern/HtmlToPdfWrapper/issues).
