package net.patttern.htmltopdf;

import net.patttern.htmltopdf.enums.HeaderFooter;
import net.patttern.htmltopdf.enums.Load;
import net.patttern.htmltopdf.enums.TOC;
import net.patttern.htmltopdf.enums.Web;

/**
 * Created by ebabenko on 18.01.16.
 */
public class ObjectSettings {
  private final static String tocUseDottedLines = "toc." + TOC.useDottedLines.toString();
  private final static String tocCaptionText = "toc." + TOC.captionText.toString();
  private final static String tocForwardLinks = "toc." + TOC.forwardLinks.toString();
  private final static String tocBackLinks = "toc." + TOC.backLinks.toString();
  private final static String tocIndentation = "toc." + TOC.indentation.toString();
  private final static String tocFontScale = "toc." + TOC.fontScale.toString();
  private final static String headerFontSize = "header." + HeaderFooter.fontSize.toString();
  private final static String headerFontName = "header." + HeaderFooter.fontName.toString();;
  private final static String headerLeft = "header." + HeaderFooter.left.toString();;
  private final static String headerCenter = "header." + HeaderFooter.center.toString();;
  private final static String headerRight = "header." + HeaderFooter.right.toString();;
  private final static String headerLine = "header." + HeaderFooter.line.toString();;
  private final static String headerSpacing = "header." + HeaderFooter.spacing.toString();;
  private final static String headerHtmlUrl = "header." + HeaderFooter.htmlUrl.toString();;
  private final static String footerFontSize = "footer." + HeaderFooter.fontSize.toString();
  private final static String footerFontName = "footer." + HeaderFooter.fontName.toString();;
  private final static String footerLeft = "footer." + HeaderFooter.left.toString();;
  private final static String footerCenter = "footer." + HeaderFooter.center.toString();;
  private final static String footerRight = "footer." + HeaderFooter.right.toString();;
  private final static String footerLine = "footer." + HeaderFooter.line.toString();;
  private final static String footerSpacing = "footer." + HeaderFooter.spacing.toString();;
  private final static String footerHtmlUrl = "footer." + HeaderFooter.htmlUrl.toString();;
  private final static String useExternalLinks = "useExternalLinks";
  private final static String useLocalLinks = "useLocalLinks";
  private final static String replacements = "replacements";
  private final static String produceForms = "produceForms";
  private final static String loadUsername = "load." + Load.username.toString();
  private final static String loadPassword = "load." + Load.password.toString();
  private final static String loadJsdelay = "load." + Load.jsdelay.toString();
  private final static String loadZoomFactor = "load." + Load.zoomFactor.toString();
  private final static String loadCustomHeaders = "load." + Load.customHeaders.toString();
  private final static String loadRepertCustomHeaders = "load." + Load.repertCustomHeaders.toString();
  private final static String loadCookies = "load." + Load.cookies.toString();
  private final static String loadPost = "load." + Load.post.toString();
  private final static String loadBlockLocalFileAccess = "load." + Load.blockLocalFileAccess.toString();
  private final static String loadStopSlowScript = "load." + Load.stopSlowScript.toString();
  private final static String loadDebugJavascript = "load." + Load.debugJavascript.toString();
  private final static String loadLoadErrorHandling = "load." + Load.loadErrorHandling.toString();
  private final static String loadProxy = "load." + Load.proxy.toString();
  private final static String loadRunScript = "load." + Load.runScript.toString();
  private final static String webBackground = "web." + Web.background.toString();
  private final static String webLoadImages = "web." + Web.loadImages.toString();
  private final static String webEnableJavascript = "web." + Web.enableJavascript.toString();
  private final static String webEnableIntelligentShrinking = "web." + Web.enableIntelligentShrinking.toString();
  private final static String webMinimumFontSize = "web." + Web.minimumFontSize.toString();
  private final static String webPrintMediaType = "web." + Web.printMediaType.toString();
  private final static String webDefaultEncoding = "web." + Web.defaultEncoding.toString();
  private final static String webUserStyleSheet = "web." + Web.userStyleSheet.toString();
  private final static String webEnablePlugins = "web." + Web.enablePlugins.toString();
  private final static String includeInOutline = "includeInOutline";
  private final static String pagesCount = "pagesCount";
  private final static String tocXsl = "tocXsl";

  /**
   * Should we use a dotted line when creating a table of content? Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocUseDottedLines(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(tocUseDottedLines, value.toString());
  }

  /**
   * The caption to use when creating a table of content.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocCaptionText(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(tocCaptionText, value);
  }

  /**
   * Should we create links from the table of content into the actual content? Must be either "true or "false.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocForwardLinks(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(tocForwardLinks, value.toString());
  }

  /**
   * Should we link back from the content to this table of content.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocBackLinks(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(tocBackLinks, value);
  }

  /**
   * The indentation used for every table of content level, e.g. "2em".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocIndentation(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(tocIndentation, value);
  }

  /**
   * How much should we scale down the font for every toc level? E.g. "0.8".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocFontScale(Wrapper wrapper, Float value) {
    wrapper.setObjectSettings(tocFontScale, value.toString());
  }

  /**
   * The URL or path of the web page to convert, if "-" input is read from stdin.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setSource(Wrapper wrapper, String value) {
    wrapper.setSource(value);
  }

  /**
   * The font size to use for the header, e.g. "13".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderFontSize(Wrapper wrapper, Integer value) {
    wrapper.setObjectSettings(headerFontSize, value.toString());
  }

  /**
   * The name of the font to use for the header. e.g. "times".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderFontName(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(headerFontName, value);
  }

  /**
   * The string to print in the left part of the header, note that some sequences
   * are replaced in this string, see the wkhtmltopdf manual.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderLeft(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(headerLeft, value);
  }

  /**
   * The text to print in the center part of the header.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderCenter(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(headerCenter, value);
  }

  /**
   * The text to print in the right part of the header.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderRight(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(headerRight, value);
  }

  /**
   * Whether a line should be printed under the header (either "true" or "false").
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderLine(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(headerLine, value.toString());
  }

  /**
   * The amount of space to put between the header and the content, e.g. "1.8".
   * Be aware that if this is too large the header will be printed outside the pdf document.
   * This can be corrected with the margin.top setting.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderSpacing(Wrapper wrapper, Float value) {
    wrapper.setObjectSettings(headerSpacing, value.toString());
  }

  /**
   * Url for a HTML document to use for the header.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setHeaderHtmlUrl(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(headerHtmlUrl, value);
  }

  /**
   * The font size to use for the footer, e.g. "13".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterFontSize(Wrapper wrapper, Integer value) {
    wrapper.setObjectSettings(footerFontSize, value.toString());
  }

  /**
   * The name of the font to use for the footer, e.g. "times".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterFontName(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(footerFontName, value);
  }

  /**
   * The string to print in the left part of the footer, note that some sequences
   * are replaced in this string, see the wkhtmltopdf manual.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterLeft(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(footerLeft, value);
  }

  /**
   * The text to print in the center part of the footer.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterCenter(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(footerCenter, value);
  }

  /**
   * The text to print in the right part of the footer.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterRight(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(footerRight, value);
  }

  /**
   * Whether a line should be printed under the footer (either "true" or "false").
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterLine(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(footerLine, value.toString());
  }

  /**
   * The amount of space to put between the footer and the content, e.g. "1.8".
   * Be aware that if this is too large the footer will be printed outside the pdf document.
   * This can be corrected with the margin.top setting.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterSpacing(Wrapper wrapper, Float value) {
    wrapper.setObjectSettings(footerSpacing, value.toString());
  }

  /**
   * Url for a HTML document to use for the footer.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setFooterHtmlUrl(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(footerHtmlUrl, value);
  }

  /**
   * Should external links in the HTML document be converted into external pdf links?
   * Must be either "true" or "false.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setUseExternalLinks(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(useExternalLinks, value.toString());
  }

  /**
   * Should internal links in the HTML document be converted into pdf references?
   * Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setUseLocalLinks(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(useLocalLinks, value.toString());
  }

  /**
   * TODO not released yet.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setReplacements(Wrapper wrapper, String value) {
//    wrapper.setObjectSettings(replacements, "");
  }

  /**
   * Should we turn HTML forms into PDF forms? Must be either "true" or file".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setProduceForms(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(produceForms, value.toString());
  }

  /**
   * The user name to use when loging into a website, E.g. "bart".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadUsername(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(loadUsername, value);
  }

  /**
   * The password to used when logging into a website, E.g. "elbarto".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadPassword(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(loadPassword, value);
  }

  /**
   * The mount of time in milliseconds to wait after a page has done loading until it is actually printed.
   * E.g. "1200". We will wait this amount of time or until, javascript calls window.print().
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadJsdelay(Wrapper wrapper, Integer value) {
    wrapper.setObjectSettings(loadJsdelay, value.toString());
  }

  /**
   * How much should we zoom in on the content? E.g. "2.2".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadZoomFactor(Wrapper wrapper, Float value) {
    wrapper.setObjectSettings(loadZoomFactor, value.toString());
  }

  /**
   * TODO not released yet.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadCustomHeaders(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(loadCustomHeaders, value);
  }

  /**
   * Should the custom headers be sent all elements loaded instead of only the main page?
   * Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadRepertCustomHeaders(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(loadRepertCustomHeaders, value.toString());
  }

  /**
   * TODO not released yet.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadCookies(Wrapper wrapper, String value) {
//    wrapper.setObjectSettings(loadCookies, value);
  }

  /**
   * TODO not released yet.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadPost(Wrapper wrapper, String value) {
//    wrapper.setObjectSettings(loadPost, value);
  }

  /**
   * Disallow local and piped files to access other local files. Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadBlockLocalFileAccess(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(loadBlockLocalFileAccess, value.toString());
  }

  /**
   * Stop slow running javascript. Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadStopSlowScript(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(loadStopSlowScript, value.toString());
  }

  /**
   * Forward javascript warnings and errors to the warning callback. Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadDebugJavascript(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(loadDebugJavascript, value.toString());
  }

  /**
   * How should we handle obejcts that fail to load. Must be one of:
   * - "abort" Abort the convertion process;
   * - "skip" Do not add the object to the final output;
   * - "ignore" Try to add the object to the final output.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadLoadErrorHandling(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(loadLoadErrorHandling, value);
  }

  /**
   * String describing what proxy to use when loading the object.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadProxy(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(loadProxy, value);
  }

  /**
   * TODO not released yet.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setLoadRunScript(Wrapper wrapper, String value) {
//    wrapper.setObjectSettings(loadRunScript, value);
  }

  /**
   * Should we print the background? Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebBackground(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(webBackground, value.toString());
  }

  /**
   * Should we load images? Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebLoadImages(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(webLoadImages, value.toString());
  }

  /**
   * Should we enable javascript? Must be either "true" or "false".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebEnableJavascript(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(webEnableJavascript, value.toString());
  }

  /**
   * Should we enable intelligent shrinkng to fit more content on one page?
   * Must be either "true" or "false". Has no effect for wkhtmltoimage.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebEnableIntelligentShrinking(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(webEnableIntelligentShrinking, value.toString());
  }

  /**
   * The minimum font size allowed. E.g. "9".
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebMinimumFontSize(Wrapper wrapper, Integer value) {
    wrapper.setObjectSettings(webMinimumFontSize, value.toString());
  }

  /**
   * Should the content be printed using the print media type instead of the screen media type.
   * Must be either "true" or "false". Has no effect for wkhtmltoimage.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebPrintMediaType(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(webPrintMediaType, value.toString());
  }

  /**
   * What encoding should we guess content is using if they do not specify it properly? E.g. "utf-8"
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebDefaultEncoding(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(webDefaultEncoding, value);
  }

  /**
   * Url er path to a user specified style sheet.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebUserStyleSheet(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(webUserStyleSheet, value);
  }

  /**
   * Should we enable NS plugins, must be either "true" or "false". Enabling this will have limited success.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setWebEnablePlugins(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(webEnablePlugins, value.toString());
  }

  /**
   * Should the sections from this document be included in the outline and table of content?
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setIncludeInOutline(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(includeInOutline, value.toString());
  }

  /**
   * Should we count the pages of this document, in the counter used for TOC, headers and footers?
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setPagesCount(Wrapper wrapper, Boolean value) {
    wrapper.setObjectSettings(pagesCount, value.toString());
  }

  /**
   * If not empty this object is a table of content object, "page" is ignored
   * and this xsl style sheet is used to convert the outline XML into a table of content.
   * @param wrapper HtmlToPdfWrapper.
   * @param value
   */
  public void setTocXsl(Wrapper wrapper, String value) {
    wrapper.setObjectSettings(tocXsl, value);
  }
}
