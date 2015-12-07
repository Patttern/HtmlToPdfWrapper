package net.patttern.interfaces;

import com.sun.jna.Library;
import net.patttern.classes.PdfGlobal;
import net.patttern.classes.PdfObject;

/**
 * Created by ebabenko on 04.12.15.
 */
public interface HtmlToX extends Library {
/*
 * PdfGlobal
Exception in thread "main" java.lang.IllegalArgumentException: Unsupported return type class net.patttern.classes.PdfGlobal in function wkhtmltopdf_create_global_settings
Exception in thread "main" java.lang.IllegalArgumentException: Structure class net.patttern.classes.PdfGlobal has unknown size (ensure all fields are public)
Exception in thread "main" java.lang.IllegalArgumentException: The type "net.patttern.enums.PageSize" is not supported as a structure field: Native size for type "net.patttern.enums.PageSize" is unknown
Exception in thread "main" java.lang.IllegalArgumentException: Can't determine size of nested structure: Can't determine size of nested structure: Structure class net.patttern.classes.UnitReal has unknown size (ensure all fields are public)
Exception in thread "main" java.lang.IllegalArgumentException: Can't determine size of nested structure: Can't determine size of nested structure: Can't determine size of nested structure: Can't instantiate class com.sun.jna.Structure (java.lang.InstantiationException)
*/

/*
 * PdfObject
Exception in thread "main" java.lang.IllegalArgumentException: The type "java.util.List" is not supported as a structure field: Native size for type "java.util.List" is unknown
*/

/*
 * Runtime
# A fatal error has been detected by the Java Runtime Environment:
#
#  SIGSEGV (0xb) at pc=0x00007fef03ef00bb, pid=16599, tid=140666341353216
#
# JRE version: Java(TM) SE Runtime Environment (8.0_66-b17) (build 1.8.0_66-b17)
# Java VM: Java HotSpot(TM) 64-Bit Server VM (25.66-b17 mixed mode linux-amd64 compressed oops)
# Problematic frame:
# C  [jna5874131929470968141.tmp+0x90bb]  newJavaString+0x14c
#
# Failed to write core dump. Core dumps have been disabled. To enable core dumping, try "ulimit -c unlimited" before starting Java again
#
# An error report file with more information is saved as:
# /home/ebabenko/work/javatest/hs_err_pid16599.log
#
# If you would like to submit a bug report, please visit:
#   http://bugreport.java.com/bugreport/crash.jsp
# The crash happened outside the Java Virtual Machine in native code.
# See problematic frame for where to report the bug.
*/
  public int wkhtmltopdf_init(int use_graphics);
  public int wkhtmltopdf_deinit();
  public int wkhtmltopdf_extended_qt();
  public String wkhtmltopdf_version();

  public PdfGlobal wkhtmltopdf_create_global_settings();
  public void wkhtmltopdf_destroy_global_settings(PdfGlobal pdfGlobal);

  public PdfObject wkhtmltopdf_create_object_settings();
  public void wkhtmltopdf_destroy_object_settings(PdfObject pdfObject);
/*
  CAPI(wkhtmltopdf_object_settings *) wkhtmltopdf_create_object_settings();
  CAPI(void) wkhtmltopdf_destroy_object_settings(wkhtmltopdf_object_settings *);

  CAPI(int) wkhtmltopdf_set_global_setting(wkhtmltopdf_global_settings * settings, const char * name, const char * value);
  CAPI(int) wkhtmltopdf_get_global_setting(wkhtmltopdf_global_settings * settings, const char * name, char * value, int vs);
  CAPI(int) wkhtmltopdf_set_object_setting(wkhtmltopdf_object_settings * settings, const char * name, const char * value);
  CAPI(int) wkhtmltopdf_get_object_setting(wkhtmltopdf_object_settings * settings, const char * name, char * value, int vs);


  CAPI(wkhtmltopdf_converter *) wkhtmltopdf_create_converter(wkhtmltopdf_global_settings * settings);
  CAPI(void) wkhtmltopdf_destroy_converter(wkhtmltopdf_converter * converter);

  CAPI(void) wkhtmltopdf_set_warning_callback(wkhtmltopdf_converter * converter, wkhtmltopdf_str_callback cb);
  CAPI(void) wkhtmltopdf_set_error_callback(wkhtmltopdf_converter * converter, wkhtmltopdf_str_callback cb);
  CAPI(void) wkhtmltopdf_set_phase_changed_callback(wkhtmltopdf_converter * converter, wkhtmltopdf_void_callback cb);
  CAPI(void) wkhtmltopdf_set_progress_changed_callback(wkhtmltopdf_converter * converter, wkhtmltopdf_int_callback cb);
  CAPI(void) wkhtmltopdf_set_finished_callback(wkhtmltopdf_converter * converter, wkhtmltopdf_int_callback cb);
  CAPI(int) wkhtmltopdf_convert(wkhtmltopdf_converter * converter);
  CAPI(void) wkhtmltopdf_add_object(wkhtmltopdf_converter * converter, wkhtmltopdf_object_settings * setting, const char * data);

  CAPI(int) wkhtmltopdf_current_phase(wkhtmltopdf_converter * converter);
  CAPI(int) wkhtmltopdf_phase_count(wkhtmltopdf_converter * converter);
  CAPI(const char *) wkhtmltopdf_phase_description(wkhtmltopdf_converter * converter, int phase);
  CAPI(const char *) wkhtmltopdf_progress_string(wkhtmltopdf_converter * converter);
  CAPI(int) wkhtmltopdf_http_error_code(wkhtmltopdf_converter * converter);
  CAPI(long) wkhtmltopdf_get_output(wkhtmltopdf_converter * converter, const unsigned char **);
*/
}
