#include "converter_p.hh"
#include "multipageloader.hh"
#include <QWebFrame>
#include <qapplication.h>

#ifdef QT4_STATICPLUGIN_TEXTCODECS
#include <QtPlugin>
Q_IMPORT_PLUGIN(qcncodecs)
Q_IMPORT_PLUGIN(qjpcodecs)
Q_IMPORT_PLUGIN(qkrcodecs)
Q_IMPORT_PLUGIN(qtwcodecs)
#endif

namespace wkhtmltopdf {
  void ConverterPrivate::updateWebSettings(QWebSettings * ws, const settings::Web & s) const {
#ifdef  __EXTENSIVE_WKHTMLTOPDF_QT_HACK__
    if (!s.defaultEncoding.isEmpty())
      ws->setDefaultTextEncoding(s.defaultEncoding);
    if (!s.enableIntelligentShrinking) {
      ws->setPrintingMaximumShrinkFactor(1.0);
      ws->setPrintingMinimumShrinkFactor(1.0);
    }
    ws->setPrintingMediaType(s.printMediaType?"print":"screen");
#endif
    ws->setAttribute(QWebSettings::JavaEnabled, s.enablePlugins);
    ws->setAttribute(QWebSettings::JavascriptEnabled, s.enableJavascript);
    ws->setAttribute(QWebSettings::JavascriptCanOpenWindows, false);
    ws->setAttribute(QWebSettings::JavascriptCanAccessClipboard, false);
    ws->setFontSize(QWebSettings::MinimumFontSize, s.minimumFontSize);
    //Newer versions of QT have even more settings to change
    ws->setAttribute(QWebSettings::PrintElementBackgrounds, s.background);
    ws->setAttribute(QWebSettings::AutoLoadImages, s.loadImages);
    ws->setAttribute(QWebSettings::PluginsEnabled, s.enablePlugins);
    if (!s.userStyleSheet.isEmpty())
      ws->setUserStyleSheetUrl(MultiPageLoader::guessUrlFromString(s.userStyleSheet));
  }

  void ConverterPrivate::fail() {
    error = true;
    convertionDone = true;
    clearResources();
    emit outer().finished(false);
    qApp->exit(0); // quit qt's event handling
  }

  /**
   * @brief Called when the page is loading, display some progress to the using
   * @param progress the loading progress in percent
   */
  void ConverterPrivate::loadProgress(int progress) {
    progressString = QString::number(progress) + "%";
    emit outer().progressChanged(progress);
  }

  void ConverterPrivate::forwardError(QString error) {
    emit outer().error(error);
  }

  void ConverterPrivate::forwardWarning(QString warning) {
    emit outer().warning(warning);
  }

  void ConverterPrivate::cancel() {
    error=true;
  }

  bool ConverterPrivate::convert() {
    convertionDone=false;
    beginConvert();
    while (!convertionDone)
      qApp->processEvents(QEventLoop::WaitForMoreEvents | QEventLoop::AllEvents);
    return !error;
  }

  /**
   * @brief Count the number of phases that the conversion process goes though
   * @return
   */
  int Converter::phaseCount() {
    return priv().phaseDescriptions.size();
  }

  /**
   * @brief return the current phase of conversion
   * @return
   */
  int Converter::currentPhase() {
    return priv().currentPhase;
  }

  /**
   * @brief return a textual description of some phase
   * @param phase the phase to get a description of, -1 for current phase
   * @return
   */
  QString Converter::phaseDescription(int phase) {
    if (phase < 0 || priv().phaseDescriptions.size() <= phase) phase=priv().currentPhase;
    if (phase < 0 || priv().phaseDescriptions.size() <= phase) return "Invalid";
    return priv().phaseDescriptions[phase];
  }

  /**
   * @brief return a textual description of progress in the current phase
   * @return
   */
  QString Converter::progressString() {
    return priv().progressString;
  }

  /**
   * @brief return the HTTP return code, of the converted page
   * @return
   */
  int Converter::httpErrorCode() {
    return priv().errorCode;
  }

  /**
   * @brief Start a asynchronous conversion of html pages to a pdf document.
   * Once conversion is done an finished signal will be emitted
   */
  void Converter::beginConvertion() {
    priv().beginConvert();
  }

  /**
   * @brief Synchronous convert html pages to a pdf document.
   * @return
   */
  bool Converter::convert() {
    return priv().convert();
  }

  /**
   * @brief Cancel a running conversion
   */
  void Converter::cancel() {
    priv().cancel();
  }

  void Converter::emitCheckboxSvgs(const settings::LoadPage & ls) {
    emit checkboxSvgChanged(ls.checkboxSvg);
    emit checkboxCheckedSvgChanged(ls.checkboxCheckedSvg);
    emit radiobuttonSvgChanged(ls.radiobuttonSvg);
    emit radiobuttonCheckedSvgChanged(ls.radiobuttonCheckedSvg);
  }
}
