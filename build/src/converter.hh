#ifndef __CONVERTER_HH__
#define __CONVERTER_HH__

#include <QObject>
#include "loadsettings.hh"

namespace wkhtmltopdf {

  class ConverterPrivate;

  class Converter: public QObject {
      Q_OBJECT
    public:
      virtual ~Converter() {}
      int currentPhase();
      int phaseCount();
      QString phaseDescription(int phase=-1);
      QString progressString();
      int httpErrorCode();
    signals:
      void warning(const QString & message);
      void error(const QString & message);
      void phaseChanged();
      void progressChanged(int progress);
      void finished(bool ok);
      void checkboxSvgChanged(const QString & path);
      void checkboxCheckedSvgChanged(const QString & path);
      void radiobuttonSvgChanged(const QString & path);
      void radiobuttonCheckedSvgChanged(const QString & path);
    public slots:
      void beginConvertion();
      bool convert();
      void cancel();
    protected:
      void emitCheckboxSvgs(const settings::LoadPage & ls);
      virtual ConverterPrivate & priv() = 0;
      friend class ConverterPrivate;
  };
}

#endif //__CONVERTER_HH__
