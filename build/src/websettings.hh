#ifndef __WEBSETTINGS_HH__
#define __WEBSETTINGS_HH__

#include <QNetworkProxy>
#include <QString>

namespace wkhtmltopdf {
  namespace settings {
    struct Web {
      Web();

      /**
       * @brief Should we print background images
       */
      bool background;

      /**
       * @brief Should we load images
       */
      bool loadImages;

      /**
       * @brief Should we enable Javascript
       */
      bool enableJavascript;

      /**
       * @brief Should the horrible intelligent shrinking feature be enabled?
       */
      bool enableIntelligentShrinking;

      /**
       * @brief Minimum font size
       */
      int minimumFontSize;

      /**
       * @brief Should we use the print or the screen media type
       */
      bool printMediaType;

      /**
       * @brief Encoding used to enterpit a document with do supplied encoding
       */
      QString defaultEncoding;

      /**
       * @brief Stylesheet supplied by the user
       */
      QString userStyleSheet;

      /**
       * @brief Should plugins be allowed
       */
      bool enablePlugins;
    };
  }
}

#endif //__WEBSETTINGS_HH__
