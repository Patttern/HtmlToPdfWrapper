#include "websettings.hh"
namespace wkhtmltopdf {
  namespace settings {
    Web::Web() :
      background(true),
      loadImages(true),
      enableJavascript(true),
      enableIntelligentShrinking(true),
      minimumFontSize(-1),
      printMediaType(false),
      defaultEncoding(""),
      userStyleSheet(""),
      enablePlugins(false) {}
  }
}
