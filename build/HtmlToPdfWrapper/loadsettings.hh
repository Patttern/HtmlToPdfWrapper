#ifndef __LOADSETTINGS_HH__
#define __LOADSETTINGS_HH__

#include <QNetworkProxy>
#include <QString>

namespace wkhtmltopdf {
  namespace settings {
    /**
     * @brief Settings considering proxy
     */
    struct Proxy {
      Proxy();
      /**
       * @brief Type of proxy to use
       */
      QNetworkProxy::ProxyType type;
      /**
       * @brief The port of the proxy to use
       */
      int port;
      /**
       * @brief The host name of the proxy to use or NULL
       */
      QString host;
      /**
       * @brief Username for the said proxy or NULL
       */
      QString user;
      /**
       * @brief Password for the said proxy or NULL
       */
      QString password;
    };

    struct PostItem {
      QString name;
      QString value;
      bool file;
    };

    struct LoadGlobal {
      LoadGlobal();
      /**
       * @brief Path of the cookie jar file
       */
      QString cookieJar;
    };

    struct LoadPage {
      LoadPage();

      enum LoadErrorHandling {
        abort,
        skip,
        ignore
      };

      /**
       * @brief Username used for http auth login
       */
      QString username;

      /**
       * @brief Password used for http auth login
       */
      QString password;

      /**
       * @brief How many milliseconds should we wait for a Javascript redirect
       */
      int jsdelay;

      /**
       * @brief What window.status value should we wait for
       */
      QString windowStatus;

      /**
       * @brief What zoom factor should we apply when printing
       */
      float zoomFactor;

      /**
       * @brief Map of custom header variables
       */
      QList< QPair<QString, QString> > customHeaders;

      /**
       * @brief Set if the custom header should be repeated for each resource request
       */
      bool repeatCustomHeaders;

      /**
       * @brief Map of cookies
       */
      QList< QPair<QString, QString> > cookies;

      QList<PostItem> post;

      /**
       * @brief Block access to local files for the given page
       */
      bool blockLocalFileAccess;

      /**
       * @brief If access to local files is not allowed in general, allow it for these files
       */
      QList<QString> allowed;

      /**
       * @brief Stop Javascript from running too long
       */
      bool stopSlowScripts;

      /**
       * @brief Output Javascript debug messages
       */
      bool debugJavascript;

      /**
       * @brief What should we do about load errors
       */
      LoadErrorHandling loadErrorHandling;
      LoadErrorHandling mediaLoadErrorHandling;

      /**
       * @brief Proxy related settings
       */
      Proxy proxy;

      /**
       * @brief Additional javascript to run on a page once it has loaded
       */
      QList<QString> runScript;

      QString checkboxSvg;
      QString checkboxCheckedSvg;
      QString radiobuttonSvg;
      QString radiobuttonCheckedSvg;

      QString cacheDir;
      static QList<QString> mediaFilesExtensions;

      /**
       * @brief Hosts to bypass
       */
      QList< QString > bypassProxyForHosts;
    };

    LoadPage::LoadErrorHandling strToLoadErrorHandling(const char * s, bool * ok=0);
    QString loadErrorHandlingToStr(LoadPage::LoadErrorHandling leh);

    Proxy strToProxy(const char * s, bool * ok=0);
    QString proxyToStr(const Proxy & proxy);
  }
}

#endif //__LOADSETTINGS_HH__
