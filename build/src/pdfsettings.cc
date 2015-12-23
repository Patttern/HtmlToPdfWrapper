#ifdef _MSC_VER
#define strcasecmp _stricmp
#endif

#include "pdfsettings.hh"
#include "reflect.hh"
#include <QMap>
#include <stdexcept>

namespace wkhtmltopdf {
  namespace settings {
    template<>
    struct ReflectImpl<UnitReal>: public ReflectSimple {
      UnitReal & ur;
      ReflectImpl(UnitReal & _): ur(_) {}
      QString get() {bool d; return unitRealToStr(ur, &d);}
      void set(const QString & value, bool * ok) {ur = strToUnitReal(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<QPrinter::PageSize>: public ReflectSimple {
      QPrinter::PageSize & ps;
      ReflectImpl(QPrinter::PageSize & _): ps(_) {}
      QString get() {return pageSizeToStr(ps);}
      void set(const QString & value, bool * ok) {ps = strToPageSize(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<QPrinter::Orientation>: public ReflectSimple {
      QPrinter::Orientation & o;
      ReflectImpl(QPrinter::Orientation & _): o(_) {}
      QString get() {return orientationToStr(o);}
      void set(const QString & value, bool * ok) {o = strToOrientation(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<QPrinter::PrinterMode>: public ReflectSimple {
      QPrinter::PrinterMode & m;
      ReflectImpl(QPrinter::PrinterMode & _): m(_) {}
      QString get() {return printerModeToStr(m);}
      void set(const QString & value, bool * ok) {m = strToPrinterMode(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<QPrinter::ColorMode>: public ReflectSimple {
      QPrinter::ColorMode & m;
      ReflectImpl(QPrinter::ColorMode & _): m(_) {}
      QString get() {return colorModeToStr(m);}
      void set(const QString & value, bool * ok) {m = strToColorMode(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<Margin>: public ReflectClass {
      ReflectImpl(Margin & c) {
        WKHTMLTOPDF_REFLECT(top);
        WKHTMLTOPDF_REFLECT(right);
        WKHTMLTOPDF_REFLECT(bottom);
        WKHTMLTOPDF_REFLECT(left);
      }
    };

    template<>
    struct ReflectImpl<Size>: public ReflectClass {
      ReflectImpl(Size & c) {
        WKHTMLTOPDF_REFLECT(pageSize);
        WKHTMLTOPDF_REFLECT(height);
        WKHTMLTOPDF_REFLECT(width);
      }
    };

    template<>
    struct ReflectImpl<TableOfContent>: public ReflectClass {
      ReflectImpl(TableOfContent & c) {
        WKHTMLTOPDF_REFLECT(useDottedLines);
        WKHTMLTOPDF_REFLECT(captionText);
        WKHTMLTOPDF_REFLECT(forwardLinks);
        WKHTMLTOPDF_REFLECT(backLinks);
        WKHTMLTOPDF_REFLECT(indentation);
        WKHTMLTOPDF_REFLECT(fontScale);
      }
    };

    template<>
    struct ReflectImpl<PdfGlobal>: public ReflectClass {
      ReflectImpl(PdfGlobal & c) {
        WKHTMLTOPDF_REFLECT(size);
        WKHTMLTOPDF_REFLECT(quiet);
        WKHTMLTOPDF_REFLECT(useGraphics);
        WKHTMLTOPDF_REFLECT(resolveRelativeLinks);
        WKHTMLTOPDF_REFLECT(orientation);
        WKHTMLTOPDF_REFLECT(colorMode);
        WKHTMLTOPDF_REFLECT(resolution);
        WKHTMLTOPDF_REFLECT(dpi);
        WKHTMLTOPDF_REFLECT(pageOffset);
        WKHTMLTOPDF_REFLECT(copies);
        WKHTMLTOPDF_REFLECT(collate);
        WKHTMLTOPDF_REFLECT(outline);
        WKHTMLTOPDF_REFLECT(dumpOutline);
        WKHTMLTOPDF_REFLECT(out);
        WKHTMLTOPDF_REFLECT(documentTitle);
        WKHTMLTOPDF_REFLECT(useCompression);
        WKHTMLTOPDF_REFLECT(margin);
        WKHTMLTOPDF_REFLECT(imageDPI);
        WKHTMLTOPDF_REFLECT(imageQuality);
        WKHTMLTOPDF_REFLECT(load);
      }
    };

    template<>
    struct ReflectImpl<HeaderFooter>: public ReflectClass {
      ReflectImpl(HeaderFooter & c) {
        WKHTMLTOPDF_REFLECT(fontSize);
        WKHTMLTOPDF_REFLECT(fontName);
        WKHTMLTOPDF_REFLECT(left);
        WKHTMLTOPDF_REFLECT(right);
        WKHTMLTOPDF_REFLECT(center);
        WKHTMLTOPDF_REFLECT(line);
        WKHTMLTOPDF_REFLECT(htmlUrl);
        WKHTMLTOPDF_REFLECT(spacing);
      }
    };

    template<>
    struct ReflectImpl<PdfObject>: public ReflectClass {
      ReflectImpl(PdfObject & c) {
        WKHTMLTOPDF_REFLECT(toc);
        WKHTMLTOPDF_REFLECT(page);
        WKHTMLTOPDF_REFLECT(header);
        WKHTMLTOPDF_REFLECT(footer);
        WKHTMLTOPDF_REFLECT(useExternalLinks);
        WKHTMLTOPDF_REFLECT(useLocalLinks);
        WKHTMLTOPDF_REFLECT(replacements);
        WKHTMLTOPDF_REFLECT(produceForms);
        WKHTMLTOPDF_REFLECT(load);
        WKHTMLTOPDF_REFLECT(web);
        WKHTMLTOPDF_REFLECT(includeInOutline);
        WKHTMLTOPDF_REFLECT(pagesCount);
        WKHTMLTOPDF_REFLECT(isTableOfContent);
        WKHTMLTOPDF_REFLECT(tocXsl);
      }
    };

    QMap<QString, QPrinter::PageSize> pageSizeMap() {
      QMap<QString, QPrinter::PageSize> res;
      res["A0"] = QPrinter::A0;
      res["A1"] = QPrinter::A1;
      res["A2"] = QPrinter::A2;
      res["A3"] = QPrinter::A3;
      res["A4"] = QPrinter::A4;
      res["A5"] = QPrinter::A5;
      res["A6"] = QPrinter::A6;
      res["A7"] = QPrinter::A7;
      res["A8"] = QPrinter::A8;
      res["A9"] = QPrinter::A9;
      res["B0"] = QPrinter::B0;
      res["B1"] = QPrinter::B1;
      res["B10"] = QPrinter::B10;
      res["B2"] = QPrinter::B2;
      res["B3"] = QPrinter::B3;
      res["B4"] = QPrinter::B4;
      res["B5"] = QPrinter::B5;
      res["B6"] = QPrinter::B6;
      res["B7"] = QPrinter::B7;
      res["B8"] = QPrinter::B8;
      res["B9"] = QPrinter::B9;
      res["C5E"] = QPrinter::C5E;
      res["Comm10E"] = QPrinter::Comm10E;
      res["DLE"] = QPrinter::DLE;
      res["Executive"] = QPrinter::Executive;
      res["Folio"] = QPrinter::Folio;
      res["Ledger"] = QPrinter::Ledger;
      res["Legal"] = QPrinter::Legal;
      res["Letter"] = QPrinter::Letter;
      res["Tabloid"] = QPrinter::Tabloid;
      return res;
    }

    /**
     * @brief Convert a string to a paper size, basically all thinkable values are allowed.
     * if a unknown value is given A4 is returned
     * @param s The string to convert
     * @param ok If supplied indicates if the conversion was successful
     * @return
     */
    QPrinter::PageSize strToPageSize(const char * s, bool * ok) {
      QMap<QString,QPrinter::PageSize> map = pageSizeMap();
      for (QMap<QString,QPrinter::PageSize>::const_iterator i=map.begin(); i != map.end(); ++i) {
        if (i.key().compare(s, Qt::CaseInsensitive) != 0) continue;
        if (ok) *ok=true;
        return i.value();
      }
      if (ok) *ok = false;
      return QPrinter::A4;
    }

    QString pageSizeToStr(QPrinter::PageSize ps) {
      QMap<QString,QPrinter::PageSize> map = pageSizeMap();
      for (QMap<QString,QPrinter::PageSize>::const_iterator i=map.begin(); i != map.end(); ++i) {
        if (i.value() == ps) return i.key();
      }
      return "";
    }

    /**
     * @brief Read orientation from a string, possible values are landscape and portrait (case insensitive)
     * @param s The string containing the orientation
     * @param ok If supplied indicates whether the s was valid
     * @return
     */
    QPrinter::Orientation strToOrientation(const char * s, bool * ok) {
      if (ok) *ok = true;
      if (!strcasecmp(s,"Landscape")) return QPrinter::Landscape;
      if (!strcasecmp(s,"Portrait")) return QPrinter::Portrait;
      if (ok) *ok = false;
      return QPrinter::Portrait;
    }

    QString orientationToStr(QPrinter::Orientation o) {
      return (o == QPrinter::Landscape)?"Landscape":"Portrait";
    }

    /**
     * @brief Parse a string describing a distance, into a real number and a unit.
     * @param o Tho string describing the distance
     * @param ok If supplied indicates whether the s was valid
     * @return
     */
    UnitReal strToUnitReal(const char * o, bool * ok) {
      qreal s=1.0; //Since not all units are provided by qt, we use this variable to scale
      //Them into units that are.
      QPrinter::Unit u=QPrinter::Millimeter;
      //Skip the real number part
      int i=0;
      while ('0' <= o[i]  && o[i] <= '9') ++i;
      if (o[i] == '.' || o[i] == '.') ++i;
      while ('0' <= o[i]  && o[i] <= '9') ++i;
      //Try to match the unit used
      if (!strcasecmp(o+i,"") || !strcasecmp(o+i,"mm") || !strcasecmp(o+i,"millimeter")) {
        u=QPrinter::Millimeter;
      } else if (!strcasecmp(o+i,"cm") || !strcasecmp(o+i,"centimeter")) {
        u=QPrinter::Millimeter;
        s=10.0; //1cm=10mm
      } else if (!strcasecmp(o+i,"m") || !strcasecmp(o+i,"meter")) {
        u=QPrinter::Millimeter;
        s=1000.0; //1m=1000m
      } else if (!strcasecmp(o+i,"didot"))
        u=QPrinter::Didot; //Todo is there a short for didot??
      else if (!strcasecmp(o+i,"inch") || !strcasecmp(o+i,"in"))
        u=QPrinter::Inch;
      else if (!strcasecmp(o+i,"pica") || !strcasecmp(o+i,"pc"))
        u=QPrinter::Pica;
      else if (!strcasecmp(o+i,"cicero"))
        u=QPrinter::Cicero;
      else if (!strcasecmp(o+i,"pixel") || !strcasecmp(o+i,"px"))
        u=QPrinter::DevicePixel;
      else if (!strcasecmp(o+i,"point") || !strcasecmp(o+i,"pt"))
        u=QPrinter::Point;
      else {
        if (ok) *ok=false;
        return UnitReal(QString(o).left(i).toDouble()*s, u);
      }
      return UnitReal(QString(o).left(i).toDouble(ok)*s, u);
    }

    QString unitRealToStr(const UnitReal & ur, bool * ok) {
      QString c;
      if (ur.first == -1) {
        if (ok) *ok=false;
        return "";
      }
      if (ok) *ok=true;
      switch (ur.second) {
        case QPrinter::Didot: c = "didot"; break;
        case QPrinter::Inch: c = "in"; break;
        case QPrinter::Pica: c = "pica"; break;
        case QPrinter::DevicePixel: c = "px"; break;
        case QPrinter::Point: c = "pt"; break;
        case QPrinter::Millimeter: c = "mm"; break;
        default:
          if (ok) *ok=false; break;
      }
      return QString("%1%2").arg(ur.first).arg(c);
    }

    QPrinter::PrinterMode strToPrinterMode(const char * s, bool * ok) {
      if (ok) *ok=true;
      if (!strcasecmp(s,"screen")) return QPrinter::ScreenResolution;
      if (!strcasecmp(s,"printer")) return QPrinter::PrinterResolution;
      if (!strcasecmp(s,"high")) return QPrinter::HighResolution;
      *ok=false;
      return QPrinter::HighResolution;
    }

    QString printerModeToStr(QPrinter::PrinterMode o) {
      switch (o) {
        case QPrinter::ScreenResolution: return "screen";
        case QPrinter::PrinterResolution: return "printer";
        case QPrinter::HighResolution: return "high";
      }
      return QString();
    }

    QPrinter::ColorMode strToColorMode(const char * s, bool * ok) {
      if (ok) *ok=true;
      if (!strcasecmp(s,"color"))	return QPrinter::Color;
      if (!strcasecmp(s,"grayscale")) return QPrinter::GrayScale;
      *ok=false;
      return QPrinter::Color;
    }

    QString colorModeToStr(QPrinter::ColorMode o) {
      switch (o) {
        case QPrinter::Color: return "color";
        case QPrinter::GrayScale: return "grayscale";
      }
      return QString();
    }

    Size::Size():
      pageSize(QPrinter::A4),
      height(UnitReal(-1,QPrinter::Millimeter)),
      width(UnitReal(-1,QPrinter::Millimeter)) {}

    HeaderFooter::HeaderFooter():
      fontSize(12),
      fontName("Arial"),
      left(""),
      right(""),
      center(""),
      line(false),
      htmlUrl(""),
      spacing(0.0) {}

    Margin::Margin():
      top(UnitReal(-1,QPrinter::Millimeter)),
      right(UnitReal(10,QPrinter::Millimeter)),
      bottom(UnitReal(-1,QPrinter::Millimeter)),
      left(UnitReal(10,QPrinter::Millimeter)) {}

    PdfGlobal::PdfGlobal():
      quiet(false),
      useGraphics(false),
      resolveRelativeLinks(true),
      orientation(QPrinter::Portrait),
      colorMode(QPrinter::Color),
      resolution(QPrinter::HighResolution),
      dpi(-1),
      pageOffset(0),
      copies(1),
      collate(true),
      outline(true),
      outlineDepth(4),
      dumpOutline(""),
      out(""),
      documentTitle(""),
      useCompression(true),
      viewportSize(""),
      imageDPI(600),
      imageQuality(94){}

    TableOfContent::TableOfContent():
      useDottedLines(true),
      captionText("Table of Contents"),
      forwardLinks(true),
      backLinks(false),
      indentation("1em"),
      fontScale(0.8f) {}

    PdfObject::PdfObject():
      useExternalLinks(true),
      useLocalLinks(true),
      produceForms(false),
      includeInOutline(true),
      pagesCount(true),
      isTableOfContent(false),
      tocXsl("") {}

    QString PdfGlobal::get(const char * name) {
      ReflectImpl<PdfGlobal> impl(*this);
      return impl.get(name);
    }

    bool PdfGlobal::set(const char * name, const QString & value) {
      ReflectImpl<PdfGlobal> impl(*this);
      return impl.set(name, value);
    }

    QString PdfObject::get(const char * name) {
      ReflectImpl<PdfObject> impl(*this);
      return impl.get(name);
    }

    bool PdfObject::set(const char * name, const QString & value) {
      ReflectImpl<PdfObject> impl(*this);
      return impl.set(name, value);
    }
  }
}
