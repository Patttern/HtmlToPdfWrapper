#include "tempfile.hh"
#include <QDir>
#include <QFile>
#include <QUuid>

/**
 * @class TempFile
 * @brief Class responsible for creating and deleting temporary files
 */
TempFile::TempFile() {
}

TempFile::~TempFile() {
  removeAll();
}

/**
 * @brief Create a new temporary file
 * @param ext The extention of the temporary file
 * @return Path of the new temporary file
 */
QString TempFile::create(const QString & ext) {
  QString path = QDir::tempPath()+"/wktemp-"+QUuid::createUuid().toString().mid(1,36)+ext;
  paths.append(path);
  return path;
}

/**
 * @brief Remove all the temporary files held by this object
 */
void TempFile::removeAll() {
  foreach (const QString &path, paths)
    QFile::remove(path);
  paths.clear();
}
