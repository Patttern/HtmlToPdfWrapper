#include <stdbool.h>
#include <stdio.h>
#include "net_patttern_htmltopdf_Wrapper.h"
#include "wrapper.h"
#include <QString>
#include <QDebug>

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_init (JNIEnv * jni, jclass jclass, jboolean jb) {
  debugMode = jb;
  if (debugMode) {
    qDebug() << "Debug Mode enabled.";
  }

  if (debugMode) {
    qDebug() << "Init wkhtmltopdf.";
  }
  wkhtmltopdf_init(false);

  if (!gs) {
    if (debugMode) {
      qDebug() << "Init Global settings.";
    }
    gs = wkhtmltopdf_create_global_settings();
  } else {
    if (debugMode) {
      qDebug() << "Global settings already initialized [" << gs << "].";
    }
  }

  if (!os) {
    if (debugMode) {
      qDebug() << "Init Object settings.";
    }
    os = wkhtmltopdf_create_object_settings();
  } else {
    if (debugMode) {
      qDebug() << "Object settings already initialized [" << os << "].";
    }
  }

  QString jarPath = QString::fromUtf8("/tmp/myjar.jar");
  if (debugMode) {
    qDebug() << "Path to 'load.cookieJar':" << jarPath;
  }
  wkhtmltopdf_set_global_setting(gs, "load.cookieJar", jarPath.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setSource (JNIEnv * jni, jclass jclass, jstring jvalue) {
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  QString sourcePath = QString::fromUtf8(value);
  if (debugMode) {
    qDebug() << "setSource [value][sourcePath]: [" << value << "][" << sourcePath << "]";
  }

  wkhtmltopdf_set_object_setting(os, "page", sourcePath.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setDestination (JNIEnv * jni, jclass jclass, jstring jvalue) {
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  QString destPath = QString::fromUtf8(value);
  if (debugMode) {
    qDebug() << "setDestination [value][destPath]: [" << value << "][" << destPath << "]";
  }

  wkhtmltopdf_set_global_setting(gs, "out", destPath.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setGlobalSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  const char * name = jni->GetStringUTFChars(jname, 0);
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  if (debugMode) {
    qDebug() << "setGlobalSettings [jname][jvalue]: [" << jname << "][" << jvalue << "]";
    qDebug() << "setGlobalSettings [name][value]: [" << name << "][" << value << "]";
  }

  wkhtmltopdf_set_global_setting(gs, name, value);
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setObjectSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  const char * name = jni->GetStringUTFChars(jname, 0);
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  if (debugMode) {
    qDebug() << "setObjectSettings [jname][jvalue]: [" << jname << "][" << jvalue << "]";
    qDebug() << "setObjectSettings [name][value]: [" << name << "][" << value << "]";
  }

  wkhtmltopdf_set_object_setting(os, name, value);
}

JNIEXPORT jint JNICALL Java_net_patttern_htmltopdf_Wrapper_convert (JNIEnv * jni, jclass jclass) {
  if (debugMode) {
    qDebug() << "Call run_convert().";
  }
  return run_convert();
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_release (JNIEnv * jni, jclass jclass) {
  if (debugMode) {
    qDebug() << "Destroy global settings.";
  }
  wkhtmltopdf_destroy_global_settings(gs);

  if (debugMode) {
    qDebug() << "Deinit object settings.";
  }
  wkhtmltopdf_destroy_object_settings(os);

  if (debugMode) {
    qDebug() << "Deinit wkhtmltopdf.";
  }
  wkhtmltopdf_deinit();
}
