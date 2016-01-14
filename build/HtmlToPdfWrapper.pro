#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T16:01:12
#
#-------------------------------------------------
# Required packages:
#   oracle-java8-installer
#   oracle-java8-set-default
#   qt5-qmake
#   qt5-default
#   libqt5network5
#   libqt5svg5-dev
#   libqt5webkit5-dev
#   libqt5xmlpatterns5-dev
#   libqt5printsupport5

QT       += network svg webkitwidgets xmlpatterns
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = HtmlToPdfWrapper
TEMPLATE = lib

JAVAHOME = $$(JAVA_HOME)

INCLUDEPATH += $$JAVAHOME/include \
  $$JAVAHOME/include/linux

DEFINES += HTMLTOPDFWRAPPER_LIBRARY

SOURCES += $$PWD/src/net_patttern_htmltopdf_Wrapper.cpp \
  $$PWD/src/*.cc

HEADERS += $$PWD/src/*.h \
  $$PWD/src/*.hh

unix {
  target.path = $$PWD/libs
  INSTALLS += target
}
