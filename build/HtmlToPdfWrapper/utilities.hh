#ifndef __UTILITIES_HH__
#define __UTILITIES_HH__

#include <QProxyStyle>
#include <QFile>
#include <QFileInfo>
#include <QImageWriter>
#include <QPainter>
#include <QStyleOption>
#include <QSvgRenderer>
#include <QUrl>

/**
 * Custom simplistic style
 */
class MyLooksStyle: public QProxyStyle {
    Q_OBJECT
  public:
    typedef QProxyStyle parent_t;
    MyLooksStyle();
    void drawPrimitive( PrimitiveElement element, const QStyleOption * option, QPainter * painter, const QWidget * widget = 0 ) const;
    bool weAreDrawingForms;
    static QSvgRenderer * checkbox;
    static QSvgRenderer * checkbox_checked;
    static QSvgRenderer * radiobutton;
    static QSvgRenderer * radiobutton_checked;
  public slots:
    void producingForms(bool f);
    void setCheckboxSvg(const QString & path);
    void setCheckboxCheckedSvg(const QString & path);
    void setRadioButtonSvg(const QString & path);
    void setRadioButtonCheckedSvg(const QString & path);
};

int handleError(bool success, int errorCode);

#endif //__UTILITIES_HH__
