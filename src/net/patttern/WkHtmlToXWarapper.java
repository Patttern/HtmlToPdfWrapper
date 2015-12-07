package net.patttern;

import com.sun.jna.Native;
import com.sun.jna.Structure;
import net.patttern.classes.PdfGlobal;
import net.patttern.classes.PdfObject;
import net.patttern.interfaces.HtmlToX;

import java.util.Map;

/**
 * Created by ebabenko on 04.12.15.
 */
public class WkHtmlToXWarapper {
  private static final HtmlToX wkhtmltox = (HtmlToX) Native.loadLibrary("wkhtmltox", HtmlToX.class);

  public WkHtmlToXWarapper() {
  }

  public int init(int use_graphics) {
    return wkhtmltox.wkhtmltopdf_init(use_graphics);
  }

  public int deinit() {
    return wkhtmltox.wkhtmltopdf_deinit();
  }

  public int extended() {
    return wkhtmltox.wkhtmltopdf_extended_qt();
  }

  public String version() {
    return wkhtmltox.wkhtmltopdf_version();
  }

  public PdfGlobal createGlobalSettings () {
    return wkhtmltox.wkhtmltopdf_create_global_settings();
  }

  public  void destroyGlobalSettings (PdfGlobal pdfGlobal) {
    wkhtmltox.wkhtmltopdf_destroy_global_settings(pdfGlobal);
  }

  public PdfObject createObjectSettings () {
    return wkhtmltox.wkhtmltopdf_create_object_settings();
  }

  public  void destroyObjectSettings (PdfObject pdfObject) {
    wkhtmltox.wkhtmltopdf_destroy_object_settings(pdfObject);
  }
}
