#include <stdbool.h>
#include <stdio.h>
#include "net_patttern_htmltopdf_Wrapper.h"
#include "Wrapper.h"
#include <QString>
#include <QDebug>

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_init (JNIEnv * jni, jclass jclass, jboolean jb) {
  debugMode = jb;
  if (debugMode) {
    qDebug() << "Debug Mode enabled.";
  }

  wkhtmltopdf_init(false);

  if (!gs) {
    if (debugMode) {
      qDebug() << "Init Global settings.";
    }
    gs = wkhtmltopdf_create_global_settings();
  }

  if (!os) {
    if (debugMode) {
      qDebug() << "Init Object settings.";
    }
    os = wkhtmltopdf_create_object_settings();
  }

  QString jarPath = QString::fromUtf8("/tmp/myjar.jar");
  if (debugMode) {
    qDebug() << "jarPath: " << jarPath;
  }
  wkhtmltopdf_set_global_setting(gs, "load.cookieJar", jarPath.toStdString().c_str());
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setSource (JNIEnv * jni, jclass jclass, jstring jvalue) {
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  QString sourcePath = QString::fromUtf8(value);
  if (debugMode) {
    qDebug() << "setDestination [value][sourcePath]: [" << value << "][" << sourcePath << "]";
  }

  if (debugMode) {
    qDebug() << "Object settings: [" << os << "]";
  }
  wkhtmltopdf_set_object_setting(os, "page", sourcePath.toStdString().c_str());

//  jni->ReleaseStringUTFChars(jvalue, value);
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setDestination (JNIEnv * jni, jclass jclass, jstring jvalue) {
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  QString destPath = QString::fromUtf8(value);
  if (debugMode) {
    qDebug() << "setDestination [value][destPath]: [" << value << "][" << destPath << "]";
  }

  if (debugMode) {
    qDebug() << "Global settings: [" << gs << "]";
  }
  wkhtmltopdf_set_global_setting(gs, "out", destPath.toStdString().c_str());

//  jni->ReleaseStringUTFChars(jvalue, value);
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setGlobalSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  const char * name = jni->GetStringUTFChars(jname, 0);
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  if (debugMode) {
    qDebug() << "setGlobalSettings [jname][jvalue]: [" << jname << "][" << jvalue << "]";
    qDebug() << "setGlobalSettings [name][value]: [" << name << "][" << value << "]";
  }

  wkhtmltopdf_set_global_setting(gs, name, value);

//  jni->ReleaseStringUTFChars(jname, name);
//  jni->ReleaseStringUTFChars(jvalue, value);
}

JNIEXPORT void JNICALL Java_net_patttern_htmltopdf_Wrapper_setObjectSettings (JNIEnv * jni, jclass jclass, jstring jname, jstring jvalue) {
  const char * name = jni->GetStringUTFChars(jname, 0);
  const char * value = jni->GetStringUTFChars(jvalue, 0);
  if (debugMode) {
    qDebug() << "setObjectSettings [jname][jvalue]: [" << jname << "][" << jvalue << "]";
    qDebug() << "setObjectSettings [name][value]: [" << name << "][" << value << "]";
  }

  wkhtmltopdf_set_object_setting(os, name, value);

//  jni->ReleaseStringUTFChars(jname, name);
//  jni->ReleaseStringUTFChars(jvalue, value);
}

JNIEXPORT jint JNICALL Java_net_patttern_htmltopdf_Wrapper_convert (JNIEnv * jni, jclass jclass) {
  if (debugMode) {
    qDebug() << "Run convert";
  }
  return run_convert();
}

/**
 * Print out loading progress information
 */
void progress_changed(wkhtmltopdf_converter * c, int p) {
  if (debugMode) {
    printf("%3d%%\n",p);
    fflush(stdout);
  }
}

/**
 * Print loading phase information
 */
void phase_changed(wkhtmltopdf_converter * c) {
  if (debugMode) {
    int phase = wkhtmltopdf_current_phase(c);
    printf("%s\n", wkhtmltopdf_phase_description(c, phase));
  }
}

/**
 * Print a message to stderr when an error occures
 */
void error(wkhtmltopdf_converter * c, const char * msg) {
  if (debugMode) {
    fprintf(stderr, "Error: %s\n", msg);
  }
}

/**
 * Print a message to stderr when a warning is issued
 */
void warning(wkhtmltopdf_converter * c, const char * msg) {
  if (debugMode) {
    fprintf(stderr, "Warning: %s\n", msg);
  }
}

int run_convert () {
  /* Create the actual converter object used to convert the pages */
  if (debugMode) {
    qDebug() << "create_converter";
  }
  conv = wkhtmltopdf_create_converter(gs);

  /* Call the progress_changed function when progress changes */
  if (debugMode) {
    qDebug() << "set_progress_changed_callback";
  }
  wkhtmltopdf_set_progress_changed_callback(conv, progress_changed);

  /* Call the phase _changed function when the phase changes */
  if (debugMode) {
    qDebug() << "set_phase_changed_callback";
  }
  wkhtmltopdf_set_phase_changed_callback(conv, phase_changed);

  /* Call the error function when an error occures */
  if (debugMode) {
    qDebug() << "set_error_callback";
  }
  wkhtmltopdf_set_error_callback(conv, error);

  /* Call the warning function when a warning is issued */
  if (debugMode) {
    qDebug() << "set_warning_callback";
  }
  wkhtmltopdf_set_warning_callback(conv, warning);

  /*
   * Add the the settings object describing the qstring documentation page
   * to the list of pages to convert. Objects are converted in the order in which
   * they are added
   */
  if (debugMode) {
    qDebug() << "add_object";
  }
  wkhtmltopdf_add_object(conv, os, NULL);

  /* Perform the actual convertion */
  if (debugMode) {
    qDebug() << "convert";
  }
  if (!wkhtmltopdf_convert(conv)) {
    if (debugMode) {
      fprintf(stderr, "Convertion failed!");
    }
  }

  /* Output possible http error code encountered */
  if (debugMode) {
    printf("httpErrorCode: %d\n", wkhtmltopdf_http_error_code(conv));
  }

  /* Destroy the converter object since we are done with it */
  if (debugMode) {
    qDebug() << "destroy_converter";
  }
  wkhtmltopdf_destroy_converter(conv);

  /* We will no longer be needing wkhtmltopdf funcionality */
  if (debugMode) {
    qDebug() << "deinit";
  }
  wkhtmltopdf_deinit();

  return 0;
}
