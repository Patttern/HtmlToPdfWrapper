#include <stdbool.h>
#include <stdio.h>
#include "net_patttern_htmltopdf_Wrapper.h"
#include "wrapper.h"
#include <QString>
#include <QDebug>

JNIEXPORT jstring JNICALL Java_net_patttern_htmltopdf_Wrapper_getVersion (JNIEnv * jni, jclass jclass) {
  QString qversion = QString("%1.%2.%3").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_BUILD);
  const char * version = qversion.toStdString().c_str();

  return jni->NewStringUTF(version);
}

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
  jni->ReleaseStringUTFChars(jvalue, value);
  if (debugMode) {
    qDebug() << "setSource [sourcePath]: [" << sourcePath << "]";
  }

  wkhtmltopdf_set_object_setting(os, "page", sourcePath.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setDestination (JNIEnv * jni, jclass jclass, jstring jvalue) {
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  QString destPath = QString::fromUtf8(value);
  jni->ReleaseStringUTFChars(jvalue, value);
  if (debugMode) {
    qDebug() << "setDestination [destPath]: [" << destPath << "]";
  }

  wkhtmltopdf_set_global_setting(gs, "out", destPath.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setGlobalSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  QString name = QString::fromUtf8(jni->GetStringUTFChars(jname, NULL));
  QString value = QString::fromUtf8(jni->GetStringUTFChars(jvalue, NULL));
  jni->ReleaseStringUTFChars(jname, NULL);
  jni->ReleaseStringUTFChars(jvalue, NULL);
  if (debugMode) {
    qDebug() << "setGlobalSettings [name][value]: [" << name << "][" << value << "]";
  }

  wkhtmltopdf_set_global_setting(gs, name.toStdString().c_str(), value.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setObjectSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  QString name = QString::fromUtf8(jni->GetStringUTFChars(jname, NULL));
  QString value = QString::fromUtf8(jni->GetStringUTFChars(jvalue, NULL));
  jni->ReleaseStringUTFChars(jname, NULL);
  jni->ReleaseStringUTFChars(jvalue, NULL);
  if (debugMode) {
    qDebug() << "setObjectSettings [name][value]: [" << name << "][" << value << "]";
  }

  wkhtmltopdf_set_object_setting(os, name.toStdString().c_str(), value.toStdString().c_str());
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
