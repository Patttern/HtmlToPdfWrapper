#ifndef __REFLECT_HH__
#define __REFLECT_HH__

#if defined(_MSC_VER) && _MSC_VER>=1600
#define typeof decltype
#endif

#include "loadsettings.hh"
#include "websettings.hh"
#include <QStringList>
#include <cstring>

namespace wkhtmltopdf {
  namespace settings {
    #define WKHTMLTOPDF_REFLECT(name) ReflectClass::add(#name, new ReflectImpl<typeof(c.name)> (c.name));

    class Reflect {
      public:
        virtual QString get(const char * name) = 0;
        virtual bool set(const char * name, const QString & value) = 0;
        virtual ~Reflect() {}
    };

    class ReflectSimple: public Reflect {
      public:
        virtual QString get() = 0;
        virtual void set(const QString & value, bool * ok) = 0;
        virtual QString get(const char * name) {return name[0]=='\0'?get():QString();}
        virtual bool set(const char * name, const QString & value);
    };

    class ReflectClass: public Reflect {
      public:
        QMap<QString, Reflect *> elms;
        void add(const char * name, Reflect * r) {elms[name] = r;}
        QString get(const char * name);
        bool set(const char * name, const QString & value);
        ~ReflectClass();
    };

    template <typename X>
    class ReflectImpl {
      private:
        ReflectImpl();
    };

    template<>
    struct ReflectImpl<bool>: public ReflectSimple {
      bool & b;
      ReflectImpl(bool & _): b(_) {}
      QString get() {return b?"true":"false";}
      void set(const QString & value, bool * ok) {
        if (value == "true") b=true;
        else if (value == "false") b=false;
        else *ok=false;
        *ok=true;
      }
    };

    template<>
    struct ReflectImpl<QString>: public ReflectSimple {
      QString & s;
      ReflectImpl(QString & _): s(_) {}
      QString get() {return s;}
      void set(const QString & value, bool * ok) {s=value; *ok=true;}
    };

    template<>
    struct ReflectImpl<int>: public ReflectSimple {
      int & i;
      ReflectImpl(int & _): i(_) {}
      QString get() {return QString::number(i);}
      void set(const QString & value, bool * ok) {i = value.toInt(ok);}
    };

    template<>
    struct ReflectImpl<float>: public ReflectSimple {
      float & f;
      ReflectImpl(float & _): f(_) {}
      QString get() {return QString::number(f);}
      void set(const QString & value, bool * ok) {f = value.toDouble(ok);}
    };

    template<>
    struct ReflectImpl< QPair<QString, QString> >: public ReflectSimple {
      QPair<QString, QString> & p;
      ReflectImpl(QPair<QString, QString> & _): p(_) {}

      QString get() {
        return p.first + "\n" + p.second;
      }

      void set(const QString & value, bool * ok) {
        QStringList l = value.split("\n");
        if (l.size() != 2) {*ok=false; return;}
        *ok      = true;
        p.first  = l[0];
        p.second = l[1];
      }
    };

    template<typename X>
    struct ReflectImpl< QList< X> >: public Reflect {
      QList<X> & l;

      ReflectImpl(QList<X> & _): l(_) {}

      bool parse(const char * name, int & parmsize, int & next, int & elm) {
        elm=-1;
        parmsize = -1;
        if (name[0] == '[') {
          next = 0;
          while (name[next] != '\0' && name[next] != ']') ++next;
          bool ok=true;
          elm = QString::fromLocal8Bit(name+1,next-1).toInt(&ok);
          while (name[next] == ']' || name[next] == '.') ++next;
          return ok;
        }
        parmsize = 0;
        while (name[parmsize] != '\0' && name[parmsize] != '.' && name[parmsize] != '[') ++parmsize;
        next = parmsize;
        if (name[next] == '.') ++next;
        return true;
      }

      virtual QString get(const char * name) {
        int ps, next, elm;
        if (!strcmp(name,"size") || !strcmp(name,"length") || !strcmp(name,"count")) return QString::number(l.size());
        if (!parse(name, ps, next, elm)) return QString();
        if (ps > 0 && !l.isEmpty() && !strncmp(name, "first", ps)) elm = 0;
        if (ps > 0 && !l.isEmpty() && !strncmp(name, "last",  ps)) elm = l.size() - 1;
        if (elm < 0 || elm >= l.size()) return QString();
        ReflectImpl<X> impl(l[elm]);
        return static_cast<Reflect*>(&impl)->get(name+next);
      }

      virtual bool set(const char * name, const QString & value) {
        int ps, next, elm;
        if (!strcmp(name,"clear"))
          l.clear();
        else if (!strcmp(name,"append"))
          l.append(X());
        else if (!strcmp(name,"prepend"))
          l.prepend(X());
        else if (!strcmp(name,"delete")) {
          bool ok = true;
          int idx = value.toInt(&ok);
          if (ok && idx >= 0 && idx < l.size()) {
            l.removeAt(idx);
            return true;
          }
          return false;
        } else {
          if (!parse(name, ps, next, elm)) return false;
          if (ps > 0 && !l.isEmpty() && !strncmp(name, "first", ps)) elm = 0;
          if (ps > 0 && !l.isEmpty() && !strncmp(name, "last",  ps)) elm = l.size() - 1;
          ReflectImpl<X> impl(l[elm]);
          return static_cast<Reflect *>(&impl)->set(name+next, value);
        }
        return true;
      }
    };

    template<>
    struct ReflectImpl<LoadPage::LoadErrorHandling>: public ReflectSimple {
      LoadPage::LoadErrorHandling & l;
      ReflectImpl(LoadPage::LoadErrorHandling & _): l(_) {}
      QString get() {return loadErrorHandlingToStr(l);}
      void set(const QString & value, bool * ok) {l = strToLoadErrorHandling(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<Proxy>: public ReflectSimple {
      Proxy & p;
      ReflectImpl(Proxy & _): p(_) {}
      QString get() {return proxyToStr(p);}
      void set(const QString & value, bool * ok) {p = strToProxy(value.toUtf8().constData(), ok);}
    };

    template<>
    struct ReflectImpl<PostItem>: public ReflectClass {
      ReflectImpl(PostItem & c) {
        WKHTMLTOPDF_REFLECT(name);
        WKHTMLTOPDF_REFLECT(value);
        WKHTMLTOPDF_REFLECT(file);
      }
    };

    template <>
    struct ReflectImpl<LoadGlobal>: public ReflectClass {
      ReflectImpl(LoadGlobal & c);
    };

    template <>
    struct ReflectImpl<LoadPage>: public ReflectClass {
      ReflectImpl(LoadPage & c);
    };

    template <>
    struct ReflectImpl<Web>: public ReflectClass {
      ReflectImpl(Web & c);
    };
  }
}

#endif //__REFLECT_HH__
