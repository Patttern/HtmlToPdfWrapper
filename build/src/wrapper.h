#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include "htmltopdfwrapper_global.h"
#include "pdf_c_bindings_p.hh"

wkhtmltopdf_global_settings * gs;
wkhtmltopdf_object_settings * os;
wkhtmltopdf_converter * conv;
bool debugMode = false;

void reinit_settings() {
//  if (gs) {
//    if (debugMode) {
//      qDebug() << "Global settings already initialized: [" << gs << "]";
//    }
//  }
  gs = wkhtmltopdf_create_global_settings();
  if (debugMode) {
    qDebug() << "Global settings reinitialized: [" << gs << "]";
  }

//  if (os) {
//    if (debugMode) {
//      qDebug() << "Object settings already initialized: [" << os << "]";
//    }
//  }
  os = wkhtmltopdf_create_object_settings();
  if (debugMode) {
    qDebug() << "Object settings reinitialized: [" << os << "]";
  }

  if (debugMode) {
    qDebug() << "Set global settings [name][value]: [ 'load.cookieJar' ][ '/tmp/myjar.jar' ]";
  }
  int res = wkhtmltopdf_set_global_setting(gs, "load.cookieJar", "/tmp/myjar.jar");
  if (debugMode) {
    qDebug() << "Set 'load.cookieJar' result: [" << res << "]";
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
