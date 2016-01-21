#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include "htmltopdfwrapper_global.h"
#include "pdfsettings.hh"
#include "pdf_c_bindings_p.hh"
#include <QFile>
#include <cstring>

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
/*
  int l = 255;
  const char * cjname = "load.cookieJar";
  const char * pname = "page";
  const char * oname = "out";
  char *cjval = new char[l];
  char *oval = new char[l];
  char *pval = new char[l];
  int cjres = wkhtmltopdf_get_global_setting(gs, cjname, cjval, l);
  int pres = wkhtmltopdf_get_object_setting(os, pname, pval, l);
  int ores = wkhtmltopdf_get_global_setting(gs, oname, oval, l);
  if (debugMode) {
    qDebug() << cjname << "[" << cjres << "]: [" << cjval << "], " << pname << "[" << pres << "]: [" << pval << "], " << oname << "[" << ores << "]: [" << oval << "]";
  }

  if (debugMode) {
    qDebug() << "Global settings: [" << gs << "]";
    qDebug() << "Object settings: [" << os << "]";
  }
*/
  int paramLen = 255;
  const char * name = "load.cookieJar";
  QString value = QString::fromUtf8("/tmp/pdfCookieJar.jar");
  char *cval = new char[paramLen];
  int cres = wkhtmltopdf_get_global_setting(gs, name, cval, paramLen);
  if (cres == 0 || strlen(cval) == 0) {
    wkhtmltopdf_set_global_setting(gs, name, value.toStdString().c_str());
    if (debugMode) {
      qDebug() << "[" << cres << "][" << strlen(cval) << "]Set global settings [name][value]: [" << name << "][" << value << "]";
    }
  }

  conv = wkhtmltopdf_create_converter(gs);
  if (debugMode) {
    qDebug() << "Сreated converter: [" << conv << "]";
  }

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
  int resConv = wkhtmltopdf_convert(conv);
  if (debugMode) {
    if (!resConv) {
      fprintf(stderr, "Convertion failed!");
    } else {
      qDebug() << "Convertion success.";
    }
    printf("httpErrorCode: %d\n", wkhtmltopdf_http_error_code(conv));
  }

  return 0;
}

#endif // __WRAPPER_H__
