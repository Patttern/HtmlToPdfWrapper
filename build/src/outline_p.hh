#ifndef __OUTLINE_P_HH__
#define __OUTLINE_P_HH__

#include "outline.hh"

namespace wkhtmltopdf {
  class OutlineItem {
    public:
      QList<OutlineItem *> children;
      OutlineItem * parent;
      uint page;
      uint document;
      QString value;
      QWebElement element;
      QString anchor;
      QString tocAnchor;
      bool display;
      bool forwardLinks;
      bool backLinks;
      void fillAnchors(const OutlineItem * other,
                       int & anchorCounter,
                       QVector<QPair<QWebElement, QString> > & local,
                       QHash<QString, QWebElement> & anchors);
      bool differentFrom(const OutlineItem * other) const;
      OutlineItem();
      ~OutlineItem();
  };

  class OutlinePrivate {
    public:
      const settings::PdfGlobal & settings;
      QList<OutlineItem *> documentOutlines;
      QList<int> documentPages;
      QList<int> prefixSum;
      int pageCount;
      int anchorCounter;
      QList< QList< OutlineItem *> > hfCache;
      OutlinePrivate(const settings::PdfGlobal & settings);
      ~OutlinePrivate();
      void buildPrefixSum();
      void fillChildAnchors(OutlineItem * item, QHash<QString, QWebElement> & anchors);
      void outlineChildren(OutlineItem * item, QPrinter * printer, int level);
      void buildHFCache(OutlineItem * i, int level);
      void dumpChildren(QTextStream & stream, const QList<OutlineItem *> & items, int level) const;
  };
}
#endif //__OUTLINE_P_HH__
