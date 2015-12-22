#ifndef __PDF_C_BINDINGS_P_HH__
#define __PDF_C_BINDINGS_P_HH__

#include "pdf.h"
#include "pdfconverter.hh"
#include <QObject>
#include <QHash>
#include <vector>

class MyPdfConverter: public QObject {
    Q_OBJECT
  public:
    wkhtmltopdf_str_callback warning_cb;
    wkhtmltopdf_str_callback error_cb;
    wkhtmltopdf_void_callback phase_changed;
    wkhtmltopdf_int_callback progress_changed;
    wkhtmltopdf_int_callback finished_cb;
    wkhtmltopdf::PdfConverter converter;
    wkhtmltopdf::settings::PdfGlobal * globalSettings;
    std::vector<wkhtmltopdf::settings::PdfObject *> objectSettings;
    QHash<QString, QByteArray> utf8StringCache;
    MyPdfConverter(wkhtmltopdf::settings::PdfGlobal * gs);
    ~MyPdfConverter();
  public slots:
    void warning(const QString & message);
    void error(const QString & message);
    void phaseChanged();
    void progressChanged(int progress);
    void finished(bool ok);
  private:
    MyPdfConverter(const MyPdfConverter&);
};

#endif //__PDF_C_BINDINGS_P_HH__
