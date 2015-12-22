#include "reflect.hh"

namespace wkhtmltopdf {
  namespace settings {
    bool ReflectSimple::set(const char * name, const QString & value) {
      bool ok=false;
      if (name[0]=='\0') set(value, &ok);
      return ok;
    }

    QString ReflectClass::get(const char * name) {
      int i=0;
      while (name[i] !=0 && name[i] != '.' && name[i] != '[') ++i;
      if (!elms.contains(QString::fromLocal8Bit(name, i))) return QString();
      return elms[QString::fromLocal8Bit(name,i)]->get(name + (name[i] == '.'?i+1:i));
    }

    bool ReflectClass::set(const char * name, const QString & value) {
      int i=0;
      while (name[i] !=0 && name[i] != '.' && name[i] != '[') ++i;
      if (!elms.contains(QString::fromLocal8Bit(name, i))) return false;
      return elms[QString::fromLocal8Bit(name,i)]->set(name + (name[i] == '.'?i+1:i), value);
    }

    ReflectClass::~ReflectClass() {
      for (QMap<QString, Reflect *>::iterator i=elms.begin(); i != elms.end(); ++i)
        delete i.value();
    }

    ReflectImpl<LoadGlobal>::ReflectImpl(LoadGlobal & c) {
      WKHTMLTOPDF_REFLECT(cookieJar);
    }

    ReflectImpl<LoadPage>::ReflectImpl(LoadPage & c) {
      WKHTMLTOPDF_REFLECT(username);
      WKHTMLTOPDF_REFLECT(password);
      WKHTMLTOPDF_REFLECT(jsdelay);
      WKHTMLTOPDF_REFLECT(windowStatus);
      WKHTMLTOPDF_REFLECT(zoomFactor);
      WKHTMLTOPDF_REFLECT(customHeaders);
      WKHTMLTOPDF_REFLECT(repeatCustomHeaders);
      WKHTMLTOPDF_REFLECT(cookies);
      WKHTMLTOPDF_REFLECT(post);
      WKHTMLTOPDF_REFLECT(blockLocalFileAccess);
      WKHTMLTOPDF_REFLECT(allowed);
      WKHTMLTOPDF_REFLECT(stopSlowScripts);
      WKHTMLTOPDF_REFLECT(debugJavascript);
      WKHTMLTOPDF_REFLECT(loadErrorHandling);
      WKHTMLTOPDF_REFLECT(proxy);
      WKHTMLTOPDF_REFLECT(runScript);
      WKHTMLTOPDF_REFLECT(checkboxSvg);
      WKHTMLTOPDF_REFLECT(checkboxCheckedSvg);
      WKHTMLTOPDF_REFLECT(radiobuttonSvg);
      WKHTMLTOPDF_REFLECT(radiobuttonCheckedSvg);
      WKHTMLTOPDF_REFLECT(cacheDir);
      WKHTMLTOPDF_REFLECT(bypassProxyForHosts);
    }

    ReflectImpl<Web>::ReflectImpl(Web & c) {
      WKHTMLTOPDF_REFLECT(background);
      WKHTMLTOPDF_REFLECT(loadImages);
      WKHTMLTOPDF_REFLECT(enableJavascript);
      WKHTMLTOPDF_REFLECT(enableIntelligentShrinking);
      WKHTMLTOPDF_REFLECT(minimumFontSize);
      WKHTMLTOPDF_REFLECT(printMediaType);
      WKHTMLTOPDF_REFLECT(defaultEncoding);
      WKHTMLTOPDF_REFLECT(userStyleSheet);
      WKHTMLTOPDF_REFLECT(enablePlugins);
    }
  }
}
