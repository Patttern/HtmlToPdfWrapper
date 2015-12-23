#ifndef __MULTIPAGELOADER_HH__
#define __MULTIPAGELOADER_HH__

#include <QFile>
#include <QObject>
#include <QUrl>
#if QT_VERSION >= 0x050000
#include <QtWebKitWidgets>
#else
#include <QWebPage>
#endif
#include "loadsettings.hh"

namespace wkhtmltopdf {
  class MyQWebPage;

  class LoaderObject {
    public:
      QWebPage & page;
      bool skip;
      LoaderObject(QWebPage & page);
  };

  class MultiPageLoaderPrivate;

  class MultiPageLoader: public QObject {
      Q_OBJECT
    public:
      MultiPageLoader(settings::LoadGlobal & s, bool mainLoader = false);
      ~MultiPageLoader();
      LoaderObject * addResource(const QString & url, const settings::LoadPage & settings, const QString * data=NULL);
      LoaderObject * addResource(const QUrl & url, const settings::LoadPage & settings);
      static QUrl guessUrlFromString(const QString &string);
      int httpErrorCode();
      static bool copyFile(QFile & src, QFile & dst);
    public slots:
      void load();
      void clearResources();
      void cancel();
    signals:
      void loadFinished(bool ok);
      void loadProgress(int progress);
      void loadStarted();
      void warning(QString text);
      void error(QString text);
    private:
      MultiPageLoaderPrivate * d;
      friend class MultiPageLoaderPrivate;
      friend class MyQWebPage;
      friend class ResourceObject;
  };
}

#endif //__MULTIPAGELOADER_HH__
