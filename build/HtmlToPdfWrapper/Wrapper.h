#ifndef __WRAPPER_H__
#define __WRAPPER_H__

#include "htmltopdfwrapper_global.h"
#include "pdf_c_bindings_p.hh"

wkhtmltopdf_global_settings * gs;
wkhtmltopdf_object_settings * os;

void prepare();
int run_convert();

#endif // __WRAPPER_H__
