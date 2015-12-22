#ifndef __PDFCONVERTER_HH__
#define __PDFCONVERTER_HH__

#include "converter.hh"
#include "pdfsettings.hh"

namespace wkhtmltopdf {
  class PdfConverterPrivate;

  class PdfConverter: public Converter {
      Q_OBJECT
    public:
      PdfConverter(settings::PdfGlobal & globalSettings);
      ~PdfConverter();
      int pageCount();
      void addResource(const settings::PdfObject & pageSettings, const QString * data=0);
      const settings::PdfGlobal & globalSettings() const;
      const QByteArray & output();
      static const qreal millimeterToPointMultiplier;
    private:
      PdfConverterPrivate * d;
      virtual ConverterPrivate & priv();
      friend class PdfConverterPrivate;
    signals:
      void producingForms(bool);
  };
}

#endif //__PDFCONVERTER_HH__
