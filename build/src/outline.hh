#ifndef __OUTLINE_HH__
#define __OUTLINE_HH__

#include "pdfsettings.hh"
#include <QWebElement>
#include <QWebFrame>

namespace wkhtmltopdf {
  class OutlinePrivate;

  class Outline {
    public:
      Outline(const settings::PdfGlobal & settings);
      ~Outline();
      void addEmptyWebPage();
      bool replaceWebPage(int d,
                          const QString & name,
                          QPrinter & wp,/*QWebPrinter & wp,*/
                          QWebFrame * f,
                          const settings::PdfObject & ps,
                          QVector< QPair<QWebElement, QString> > & local,
                          QHash<QString, QWebElement> & anchors);
      void addWebPage(const QString & name,
                      QPrinter & wp,/*QWebPrinter & wp,*/
                      QWebFrame * frame,
                      const settings::PdfObject & ps,
                      QVector< QPair<QWebElement, QString> > & local,
                      QHash<QString, QWebElement> & external);
      void fillHeaderFooterParms(int page,
                                 QHash<QString, QString> & parms,
                                 const settings::PdfObject & ps);
      void fillAnchors(int d, QHash<QString, QWebElement> & anchors);
      int pageCount();
      void printOutline(QPrinter * printer);
      void dump(QTextStream & stream) const;
    private:
      OutlinePrivate * d;
      friend class TocPrinter;
      friend class TocPrinterPrivate;
  };
}
#endif //__OUTLINE_HH__
