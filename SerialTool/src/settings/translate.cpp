#include "translate.h"
#include <QFile>

Translate::Translate(const QString &fileName)
{
    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        while (!file.atEnd()) {
            QStringList list = QString(file.readLine()).split('\t');
            if (list.count() == 2) {
                m_map.insert(list[0].trimmed(), list[1].trimmed());
            }
        }
        file.close();
    }
}

QString Translate::translate(const QString &str) const
{
    return m_map.value(str, str);
}
