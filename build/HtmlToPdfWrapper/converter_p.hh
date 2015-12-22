#ifndef __CONVERTER_P_HH__
#define __CONVERTER_P_HH__

#include "converter.hh"
#include "websettings.hh"
#include <QFile>
#include <QWebSettings>

namespace wkhtmltopdf {
  class ConverterPrivate: public QObject {
      Q_OBJECT
    public:
      void copyFile(QFile & src, QFile & dst);
      QList<QString> phaseDescriptions;
      int currentPhase;
      QString progressString;
    protected:
      bool error;
      virtual void clearResources() = 0;
      virtual Converter & outer() = 0;
      int errorCode;
      bool convertionDone;
      void updateWebSettings(QWebSettings * ws, const settings::Web & s) const;
    public slots:
      void fail();
      void loadProgress(int progress);
      virtual void beginConvert() = 0;
      void cancel();
      bool convert();
      void forwardError(QString error);
      void forwardWarning(QString warning);
    private:
      friend class Converter;
  };
}

#endif //__CONVERTER_P_HH__
