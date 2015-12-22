#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T16:01:12
#
#-------------------------------------------------

QT       += network svg webkitwidgets xmlpatterns

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = HtmlToPdfWrapper
TEMPLATE = lib

INCLUDEPATH += /usr/lib/jvm/java-8-oracle/include/\
  /usr/lib/jvm/java-8-oracle/include/linux/

DEFINES += HTMLTOPDFWRAPPER_LIBRARY

SOURCES += *.cpp \
  *.cc

HEADERS += *.h \
  *.hh

unix {
  target.path = ../libs
  INSTALLS += target
}
