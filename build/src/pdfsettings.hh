#ifndef __PDFSETTINGS_HH__
#define __PDFSETTINGS_HH__

#include <QNetworkProxy>
#include <QPrinter>
#include <QString>
#include "loadsettings.hh"
#include "websettings.hh"

namespace wkhtmltopdf {
  namespace settings {
    typedef QPair<qreal, QPrinter::Unit> UnitReal;

    /**
     * @brief Settings considering margins
     */
    struct Margin {
      Margin();
      /**
       * @brief Margin applied to the top of the page
       */
      UnitReal top;
      /**
       * @brief Margin applied to the right of the page
       */
      UnitReal right;
      /**
       * @brief Margin applied to the bottom of the page
       */
      UnitReal bottom;
      /**
       * @brief Margin applied to the leftp of the page
       */
      UnitReal left;
    };

    /**
     * @brief Settings considering page size
     */
    struct Size {
      Size();
      /**
       * @brief What size paper should we use
       */
      QPrinter::PageSize pageSize;
      /**
       * @brief Height of the page
       */
      UnitReal height;
      /**
       * @brief Width of the page
       */
      UnitReal width;
    };

    /**
     * @brief Settings considering the table of content
     */
    struct TableOfContent {
      TableOfContent();
      /**
       * @brief Should we print dots between the name and the page number?
       */
      bool useDottedLines;
      /**
       * @brief Name af the TOC
       */
      QString captionText;
      /**
       * @brief Link from TOC to section headers
       */
      bool forwardLinks;
      /**
       * @brief Link from section headers to TOC
       */
      bool backLinks;
      /**
       * @brief How fare should we indent on every level
       */
      QString indentation;
      /**
       * @brief Factor we should scale the font with on every level
       */
      float fontScale;
    };

    /**
     * @brief Class holding all user setting.
     * This class holds all the user settings, settings can be filled in by hand,
     * or with other methods.
     * @sa CommandLineParser::parse()
     */
    struct PdfGlobal {
      PdfGlobal();

      /**
       * @brief Size related settings
       */
      Size size;

      /**
       * @brief Be less verbose
       */
      bool quiet;

      /**
       * @brief Should we use the graphics system
       */
      bool useGraphics;

      /**
       * @brief Should relative links be resolved or kept as-is
       */
      bool resolveRelativeLinks;

      /**
       * @brief Should we orientate in landscape or portrate
       */
      QPrinter::Orientation orientation;

      /**
       * @brief Color or grayscale
       */
      QPrinter::ColorMode colorMode;

      /**
       * @brief What overall resolution should we use
       */
      QPrinter::PrinterMode resolution;

      /**
       * @brief What dpi should be used when printing
       */
      int dpi;

      /**
       * @brief When pagenumbers are printed, apply this offset to them all
       */
      int pageOffset;

      /**
       * @brief How many copies do we wan to print
       */
      int copies;

      /**
       * @brief Should be print a whole copy before beginning the next
       */
      bool collate;

      /**
       * @brief Should we generate an outline and put it into the pdf file
       */
      bool outline;

      /**
       * @brief Maximal depth of the generated outline
       */
      int outlineDepth;

      /**
       * @brief dump outline to this filename
       */
      QString dumpOutline;

      /**
       * @brief The file where in to store the output
       */
      QString out;

      QString documentTitle;

      bool useCompression;

      /**
       * @brief Margin related settings
       */
      Margin margin;

      QString viewportSize;

      int imageDPI;
      int imageQuality;

      LoadGlobal load;

      QString get(const char * name);
      bool set(const char * name, const QString & value);
    };

    /**
     * @brief Settings considering headers and footers
     */
    struct HeaderFooter {
      HeaderFooter();
      /**
       * @brief Size of the font used to render the text
       */
      int fontSize;
      /**
       * @brief Name of font used to render text
       */
      QString fontName;
      /**
       * @brief Text to render at the left
       */
      QString left;
      /**
       * @brief Text to render at the right
       */
      QString right;
      /**
       * @brief Text to render at the center
       */
      QString center;
      /**
       * @brief Should a line seperate the header/footer and the document
       */
      bool line;
      /**
       * @brief Url of the document the html document that should be used as a header/footer
       */
      QString htmlUrl;
      /**
       * @brief Spacing
       */
      float spacing;
    };

    struct PdfObject {
      PdfObject();
      /**
       * @brief Settings regarding the TOC
       */
      TableOfContent toc;

      QString page;

      /**
       * @brief Header related settings
       */
      HeaderFooter header;

      /**
       * @brief Header related settings
       */
      HeaderFooter footer;

      /**
       * @brief Should external links be links in the PDF
       */
      bool useExternalLinks;

      /**
       * @brief Should internal links be links in the PDF
       */
      bool useLocalLinks;

      /**
       * @brief Replacements
       */
      QList< QPair<QString, QString> > replacements;

      /**
       * @brief Convert forms on the pages into PDF forms
       */
      bool produceForms;

      LoadPage load;

      Web web;

      bool includeInOutline;

      bool pagesCount;

      bool isTableOfContent;

      QString tocXsl;

      QString get(const char * name);
      bool set(const char * name, const QString & value);
    };

    QPrinter::PageSize strToPageSize(const char * s, bool * ok=0);
    QString pageSizeToStr(QPrinter::PageSize ps);

    UnitReal strToUnitReal(const char * s, bool * ok=0);
    QString unitRealToStr(const UnitReal & ur, bool * ok);

    QPrinter::Orientation strToOrientation(const char * s, bool * ok=0);
    QString orientationToStr(QPrinter::Orientation o);

    QPrinter::PrinterMode strToPrinterMode(const char * s, bool * ok=0);
    QString printerModeToStr(QPrinter::PrinterMode o);

    QPrinter::ColorMode strToColorMode(const char * s, bool * ok=0);
    QString colorModeToStr(QPrinter::ColorMode o);
  }

  void dumpDefaultTOCStyleSheet(QTextStream & stream, settings::TableOfContent & s);
}

#endif //__PDFSETTINGS_HH__
