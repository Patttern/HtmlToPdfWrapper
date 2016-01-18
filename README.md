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
Основным является файл вида _libHtmlToPdfWrapper.so.1.0.0_ (в зависимости от версии сборки), остальные файлы являются симлинками на этот файл.
Поэтому, после копирования wrapper-а, требуется так же создать симлинки со смещением расширения до _.so_:

```bash
$ sudo cp build/libs/libHtmlToPdfWrapper.so.1.0.0 /usr/lib
$ cd /usr/lib
$ sudo ln -s libHtmlToPdfWrapper.so.1.0.0 libHtmlToPdfWrapper.so.1.0
$ sudo ln -s libHtmlToPdfWrapper.so.1.0.0 libHtmlToPdfWrapper.so.1
$ sudo ln -s libHtmlToPdfWrapper.so.1.0.0 libHtmlToPdfWrapper.so
```

#### Debian пакет

Если у вас установлен linux семейства Debian, вам достатчоно установить готовый Debian-пакет:

```bash
$ sudo dpkg i build/packages/libhtmltopdfwrapper_1.0.0-20160118_amd64.deb
```

#### RedHat пакет

Если у вас установлен linux семейства RedHat, вам достатчоно установить готовый RPM-пакет:

```bash
$ sudo dpkg i build/packages/libhtmltopdfwrapper-1.0.0-20160118.x86_64.rpm
```

## Использование

Подробное использование wrapper-а описано в Java-классе _test.patttern.Main_.

## Разработка

Вы можете добавить собственные функции для дальнейшего использования.

### Добавление функционала

К примеру, требуется добавить, чтобы у wrapper-а появилась дополнительная функция _hello_.

#### Java

Java-проект построен с помощью IDE [JetBrains IntelliJ Idea](https://www.jetbrains.com/idea/).
Для добавления новой функции, ее требуется сначала описать в классе _net.patttern.htmltopdf.Wrapper_.

```java
  public native static void hello(String param);
```

После того, как все функции вызова из Java описаны, требуется произвести компиляю header-файла для C++. Для этого достаточно вызвать скрипт compile,
расположенный в корне проекта:

```bash
$ ./compile
```

Результатом работы скрипта будет перегенерированный файл _build/src/net_patttern_htmltopdf_Wrapper.h_.

#### C++

C++-проект построен с помощью IDE [Qt Creator](http://www.qt.io/ru/download-open-source/).
После того, как был перегенерирован файл _build/src/net_patttern_htmltopdf_Wrapper.h_, требуется написать обработку для новых функций в файле
_build/src/net_patttern_htmltopdf_Wrapper.cpp_. В данном примере, в файле _build/src/net_patttern_htmltopdf_Wrapper.h_ появится новая запись:

```C++
/*
 * Class:     net_patttern_htmltopdf_Wrapper
 * Method:    hello
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_hello
  (JNIEnv *, jclass, jstring);
```

Напишем обработчик функции, которая будет просто выводить входящий параметр.

```C++
JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_hello (JNIEnv * jni, jclass jclass, jstring jname) {
  // cast-инг из 'jstring' в 'const char *' 
  const char * name = jni->GetStringUTFChars(jname, 0);
  qDebug() << name;
}
```

После того, как все функции описаны, требуется собрать wrapper. Это производится из диретории _build_ с помощью скрипта _install_. Так же, этот скрипт
используется для полной перекомпиляции wrapper-а, если вы желаете его создать на собственной системе, даже если никаких изменений не производилось:

```bash
$ cd build
$ ./install
```

В результате, в директории _build/libs_ будет создан wrapper и симлинки на него, в директории _build/packages_ будут пересобраны установочные пакеты.

### Feedback

Нашли ошибку? Сообщите ее в [Bug Tracker](https://github.com/Patttern/HtmlToPdfWrapper/issues).
