#include <stdbool.h>
#include <stdio.h>
#include "net_patttern_htmltopdf_Wrapper.h"
#include "Wrapper.h"
#include <QString>
#include <QDebug>

JNIEXPORT jint JNICALL Java_net_patttern_htmltopdf_Wrapper_convertLocal (JNIEnv * env, jclass jc, jstring src, jstring dst) {
  const char * source = env->GetStringUTFChars(src, 0);
  const char * dest = env->GetStringUTFChars(dst, 0);
  qDebug() << "convertLocal: [" << source << "][" << dest << "]";

  QString destPath = QString::fromUtf8(dest);
  qDebug() << destPath;

  prepare();
  wkhtmltopdf_set_global_setting(gs, "out", destPath.toStdString().c_str());
  wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "myjar.jar");
  wkhtmltopdf_set_object_setting(os, "page", source);

  env->ReleaseStringUTFChars(src, source);
  env->ReleaseStringUTFChars(dst, dest);

  return run_convert();
}

JNIEXPORT jint JNICALL Java_net_patttern_htmltopdf_Wrapper_convertRemote (JNIEnv * env, jclass jc, jstring src, jstring dst) {
  const char * source = env->GetStringUTFChars(src, 0);
  const char * dest = env->GetStringUTFChars(dst, 0);
  qDebug() << "convertRemote: [" << source << "][" << dest << "]";

  QString destPath = QString::fromUtf8(dest);
  qDebug() << destPath;

  prepare();
  wkhtmltopdf_set_global_setting(gs, "out", destPath.toStdString().c_str());
  wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "myjar.jar");
  wkhtmltopdf_set_object_setting(os, "page", source);

  env->ReleaseStringUTFChars(src, source);
  env->ReleaseStringUTFChars(dst, dest);

  return run_convert();
}

void prepare () {
  wkhtmltopdf_init(false);

  gs = wkhtmltopdf_create_global_settings();
  os = wkhtmltopdf_create_object_settings();

//  wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "myjar.jar");
}

/**
 * Print out loading progress information
 */
void progress_changed(wkhtmltopdf_converter * c, int p) {
  printf("%3d%%\n",p);
  fflush(stdout);
}

/**
 * Print loading phase information
 */
void phase_changed(wkhtmltopdf_converter * c) {
  int phase = wkhtmltopdf_current_phase(c);
  printf("%s\n", wkhtmltopdf_phase_description(c, phase));
}

/**
 * Print a message to stderr when an error occures
 */
void error(wkhtmltopdf_converter * c, const char * msg) {
  fprintf(stderr, "Error: %s\n", msg);
}

/**
 * Print a message to stderr when a warning is issued
 */
void warning(wkhtmltopdf_converter * c, const char * msg) {
  fprintf(stderr, "Warning: %s\n", msg);
}

int run_convert () {
  /* Create the actual converter object used to convert the pages */
  conv = wkhtmltopdf_create_converter(gs);

  /* Call the progress_changed function when progress changes */
  wkhtmltopdf_set_progress_changed_callback(conv, progress_changed);

  /* Call the phase _changed function when the phase changes */
  wkhtmltopdf_set_phase_changed_callback(conv, phase_changed);

  /* Call the error function when an error occures */
  wkhtmltopdf_set_error_callback(conv, error);

  /* Call the warning function when a warning is issued */
  wkhtmltopdf_set_warning_callback(conv, warning);

  /*
   * Add the the settings object describing the qstring documentation page
   * to the list of pages to convert. Objects are converted in the order in which
   * they are added
   */
  wkhtmltopdf_add_object(conv, os, NULL);

  /* Perform the actual convertion */
  if (!wkhtmltopdf_convert(conv)) {
    fprintf(stderr, "Convertion failed!");
  }

  /* Output possible http error code encountered */
  printf("httpErrorCode: %d\n", wkhtmltopdf_http_error_code(conv));

  /* Destroy the converter object since we are done with it */
  wkhtmltopdf_destroy_converter(conv);

  /* We will no longer be needing wkhtmltopdf funcionality */
  wkhtmltopdf_deinit();

  return 0;
}
