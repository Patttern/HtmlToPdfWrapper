package net.patttern.htmltopdf;

/**
 * Created by ebabenko on 18.01.16.
 */
public class GlobalSettings {
  private final static String sizePaperSize = "size.paperSize";
  private final static String sizePaperWidth = "size.width";
  private final static String sizePaperHeight = "size.height";
  private final static String orientation = "orientation";
  private final static String colorMode = "colorMode";
  private final static String resolution = "resolution";
  private final static String dpi = "dpi";
  private final static String pageOffset = "pageOffset";
  private final static String copies = "copies";
  private final static String collate = "collate";
  private final static String outline = "outline";
  private final static String outlineDepth = "outlineDepth";
  private final static String dumpOutline = "dumpOutline";
  private final static String documentTitle = "documentTitle";
  private final static String useCompression = "useCompression";
  private final static String marginTop = "margin.top";
  private final static String marginBottom = "margin.bottom";
  private final static String marginLeft = "margin.left";
  private final static String marginRight = "margin.right";
  private final static String imageDPI = "imageDPI";
  private final static String imageQuality = "imageQuality";
  private final static String loadCookieJar = "load.cookieJar";

  /**
   * The paper size of the output document, e.g. "A4".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setSizePaperSize(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(sizePaperSize, value);
  }

  /**
   * The with of the output document, e.g. "4cm".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setSizePaperWidth(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(sizePaperWidth, value);
  }

  /**
   * The height of the output document, e.g. "12in".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setSizePaperHeight(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(sizePaperHeight, value);
  }

  /**
   * The orientation of the output document, must be either "Landscape" or "Portrait".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setOrientation(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(orientation, value);
  }

  /**
   * Should the output be printed in color or gray scale, must be either "Color" or "Grayscale".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setColorMode(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(colorMode, value);
  }

  /**
   * Most likely has no effect.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setResolution(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(resolution, value);
  }

  /**
   * What dpi should we use when printing, e.g. "80".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setDpi(Wrapper wrapper, Integer value) {
    wrapper.setGlobalSettings(dpi, value.toString());
  }

  /**
   * A number that is added to all page numbers when printing headers,
   * footers and table of content.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setPageOffset(Wrapper wrapper, Integer value) {
    wrapper.setGlobalSettings(pageOffset, value.toString());
  }

  /**
   * How many copies should we print?. e.g. "2".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setCopies(Wrapper wrapper, Integer value) {
    wrapper.setGlobalSettings(copies, value.toString());
  }

  /**
   * Should the copies be collated? Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setCollate(Wrapper wrapper, Boolean value) {
    wrapper.setGlobalSettings(collate, value.toString());
  }

  /**
   * Should a outline (table of content in the sidebar) be generated and put into the PDF?
   * Must be either "true" or false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setOutline(Wrapper wrapper, Boolean value) {
    wrapper.setGlobalSettings(outline, value.toString());
  }

  /**
   * The maximal depth of the outline, e.g. "4".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setOutlineDepth(Wrapper wrapper, Integer value) {
    wrapper.setGlobalSettings(outlineDepth, value.toString());
  }

  /**
   * If not set to the empty string a XML representation of the outline is dumped to this file.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setDumpOutline(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(dumpOutline, value);
  }

  /**
   * The path of the output file, if "-" output is sent to stdout, if empty the output is stored in a buffer.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setDestination(Wrapper wrapper, String value) {
    wrapper.setDestination(value);
  }

  /**
   * The title of the PDF document.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setDocumentTitle(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(documentTitle, value);
  }

  /**
   * Should we use loss less compression when creating the pdf file? Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setUseCompression(Wrapper wrapper, Boolean value) {
    wrapper.setGlobalSettings(useCompression, value.toString());
  }

  /**
   * Size of the top margin, e.g. "2cm".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setMarginTop(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(marginTop, value);
  }

  /**
   * Size of the bottom margin, e.g. "2cm".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setMarginBottom(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(marginBottom, value);
  }

  /**
   * Size of the left margin, e.g. "2cm".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setMarginLeft(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(marginLeft, value);
  }

  /**
   * Size of the right margin, e.g. "2cm".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setMarginRight(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(marginRight, value);
  }

  /**
   * The maximal DPI to use for images in the pdf document.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setImageDPI(Wrapper wrapper, Integer value) {
    wrapper.setGlobalSettings(imageDPI, value.toString());
  }

  /**
   * The jpeg compression factor to use when producing the pdf document, e.g. "92".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setImageQuality(Wrapper wrapper, Integer value) {
    wrapper.setGlobalSettings(imageQuality, value.toString());
  }

  /**
   * Path of file used to load and store cookies.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadCookieJar(Wrapper wrapper, String value) {
    wrapper.setGlobalSettings(loadCookieJar, value);
  }
}
