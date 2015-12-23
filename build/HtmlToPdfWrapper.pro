#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T16:01:12
#
#-------------------------------------------------
# qt5-qmake qt5-default libqt5svg5-dev libqt5webkit5-dev libqt5xmlpatterns5-dev

QT       += network svg webkitwidgets xmlpatterns
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = HtmlToPdfWrapper
TEMPLATE = lib

INCLUDEPATH += /usr/lib/jvm/java-8-oracle/include \
  /usr/lib/jvm/java-8-oracle/include/linux

DEFINES += HTMLTOPDFWRAPPER_LIBRARY

SOURCES += $$PWD/src/net_patttern_htmltopdf_Wrapper.cpp \
  $$PWD/src/*.cc

HEADERS += $$PWD/src/*.h \
  $$PWD/src/*.hh

unix {
  target.path = $$PWD/libs
  INSTALLS += target
}
