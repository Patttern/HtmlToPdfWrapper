#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include "htmltopdfwrapper_global.h"
#include "pdfsettings.hh"
#include "pdf_c_bindings_p.hh"
#include <QFile>

wkhtmltopdf_global_settings * gs;
wkhtmltopdf_object_settings * os;
wkhtmltopdf_converter * conv;
bool debugMode = false;

void reinit_settings() {
  gs = wkhtmltopdf_create_global_settings();
  if (debugMode) {
    qDebug() << "Global settings reinitialized: [" << gs << "]";
  }

  os = wkhtmltopdf_create_object_settings();
  if (debugMode) {
    qDebug() << "Object settings reinitialized: [" << os << "]";
  }

  const char * name = "load.cookieJar";
//  QString name = QString::fromUtf8("/tmp/myjar.jar");
//  QString value = "/tmp/pdfCookieJar.jar";
  QFile file;
  file.setFileName("/tmp/pdfCookieJar.jar");
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  file.close();
//  wkhtmltopdf_set_global_setting(gs, "load.cookieJar", file.fileName().toStdString().c_str());
  wkhtmltopdf_set_global_setting(gs, name, file.fileName().toStdString().c_str());
  if (debugMode) {
    qDebug() << "Path to 'load.cookieJar': [" << file.fileName() << "][" << file.exists() << "]";
  }
}

void progress_changed(wkhtmltopdf_converter * c, int p) {
  if (debugMode) {
    printf("%3d%%\n",p);
    fflush(stdout);
  }
}

void phase_changed(wkhtmltopdf_converter * c) {
  if (debugMode) {
    int phase = wkhtmltopdf_current_phase(c);
    printf("%s\n", wkhtmltopdf_phase_description(c, phase));
  }
}

void error(wkhtmltopdf_converter * c, const char * msg) {
  if (debugMode) {
    fprintf(stderr, "Error: %s\n", msg);
  }
}

void warning(wkhtmltopdf_converter * c, const char * msg) {
  if (debugMode) {
    fprintf(stderr, "Warning: %s\n", msg);
  }
}

int run_convert () {
  if (debugMode) {
    qDebug() << "Сreate converter.";
  }
  conv = wkhtmltopdf_create_converter(gs);

  if (debugMode) {
    qDebug() << "Set progress changed callback.";
  }
  wkhtmltopdf_set_progress_changed_callback(conv, progress_changed);

  if (debugMode) {
    qDebug() << "Set phase changed callback.";
  }
  wkhtmltopdf_set_phase_changed_callback(conv, phase_changed);

  if (debugMode) {
    qDebug() << "Set error callback.";
  }
  wkhtmltopdf_set_error_callback(conv, error);

  if (debugMode) {
    qDebug() << "Set warning callback.";
  }
  wkhtmltopdf_set_warning_callback(conv, warning);

  if (debugMode) {
    qDebug() << "Add object to converter.";
  }
  wkhtmltopdf_add_object(conv, os, NULL);

  if (debugMode) {
    qDebug() << "Run convert.";
  }
  if (!wkhtmltopdf_convert(conv)) {
    if (debugMode) {
      fprintf(stderr, "Convertion failed!");
    }
  }

  if (debugMode) {
    printf("httpErrorCode: %d\n", wkhtmltopdf_http_error_code(conv));
  }

  if (debugMode) {
    qDebug() << "Destroy converter.";
  }
  wkhtmltopdf_destroy_converter(conv);

  return 0;
}

#endif // __WRAPPER_H__
