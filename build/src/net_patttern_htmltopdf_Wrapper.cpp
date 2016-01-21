#include <stdbool.h>
#include <stdio.h>
#include "net_patttern_htmltopdf_Wrapper.h"
#include "wrapper.h"
#include <QString>
#include <QDebug>

JNIEXPORT jstring JNICALL Java_net_patttern_htmltopdf_Wrapper_getVersion (JNIEnv * jni, jclass jclass) {
  QString version = QString("%1.%2.%3").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_BUILD);

  return jni->NewStringUTF(version.toStdString().c_str());
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

  gs = wkhtmltopdf_create_global_settings();
  if (debugMode) {
    qDebug() << "Global settings reinitialized: [" << gs << "]";
  }

  os = wkhtmltopdf_create_object_settings();
  if (debugMode) {
    qDebug() << "Object settings reinitialized: [" << os << "]";
  }
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setSource (JNIEnv * jni, jclass jclass, jstring jsrc) {
  QString source = QString::fromUtf8(jni->GetStringUTFChars(jsrc, NULL));
  jni->ReleaseStringUTFChars(jsrc, NULL);
  if (debugMode) {
    qDebug() << "Set source: [" << source << "]";
  }

  int res = wkhtmltopdf_set_object_setting(os, "page", source.toStdString().c_str());
  if (debugMode) {
    qDebug() << "Result set source: [" << res << "]";
  }
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setDestination (JNIEnv * jni, jclass jclass, jstring jdest) {
  QString dest = QString::fromUtf8(jni->GetStringUTFChars(jdest, NULL));
  jni->ReleaseStringUTFChars(jdest, NULL);
  if (debugMode) {
    qDebug() << "Set destination: [" << dest << "]";
  }

  int res = wkhtmltopdf_set_global_setting(gs, "out", dest.toStdString().c_str());
  if (debugMode) {
    qDebug() << "Result set destination: [" << res << "]";
  }
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setGlobalSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  QString name = QString::fromUtf8(jni->GetStringUTFChars(jname, NULL));
  QString value = QString::fromUtf8(jni->GetStringUTFChars(jvalue, NULL));
  jni->ReleaseStringUTFChars(jname, NULL);
  jni->ReleaseStringUTFChars(jvalue, NULL);
  if (debugMode) {
    qDebug() << "Set global settings [name][value]: [" << name << "][" << value << "]";
  }

  int res = wkhtmltopdf_set_global_setting(gs, name.toStdString().c_str(), value.toStdString().c_str());
  if (debugMode) {
    qDebug() << "Result global settings: [" << res << "]";
  }
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setObjectSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  QString name = QString::fromUtf8(jni->GetStringUTFChars(jname, NULL));
  QString value = QString::fromUtf8(jni->GetStringUTFChars(jvalue, NULL));
  jni->ReleaseStringUTFChars(jname, NULL);
  jni->ReleaseStringUTFChars(jvalue, NULL);
  if (debugMode) {
    qDebug() << "Set object settings [name][value]: [" << name << "][" << value << "]";
  }

  int res = wkhtmltopdf_set_object_setting(os, name.toStdString().c_str(), value.toStdString().c_str());
  if (debugMode) {
    qDebug() << "Result object settings: [" << res << "]";
  }
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_resetSettings (JNIEnv * jni, jclass jclass) {
  reinit_settings();
}

JNIEXPORT jint JNICALL Java_net_patttern_htmltopdf_Wrapper_convert (JNIEnv * jni, jclass jclass) {
  if (debugMode) {
    qDebug() << "Call run_convert().";
  }
  return run_convert();
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_release (JNIEnv * jni, jclass jclass) {
  if (debugMode) {
    qDebug() << "Destroy converter.";
  }
  wkhtmltopdf_destroy_converter(conv);

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
