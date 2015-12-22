#ifndef __TEMPFILE_HH__
#define __TEMPFILE_HH__

#include <QStringList>

class TempFile {
  private:
    QStringList paths;
  public:
    TempFile();
    ~TempFile();
    QString create(const QString & ext);
    void removeAll();
};

#endif //__TEMPFILE_HH__
