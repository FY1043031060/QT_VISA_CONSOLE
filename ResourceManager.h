#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QObject>
#include "visa.h"
#include "ivi.h"
#include <QMap>
#include <QStringList>
#include <QList>
#include "VisaDev.h"
#pragma comment(lib,"visa32.lib")
#pragma comment(lib,"ivi.lib")

class ResourceManager : public QObject
{
    Q_OBJECT

public:
    explicit ResourceManager(QObject *parent = Q_NULLPTR);
    ~ResourceManager();
    int scanForResources();
    QStringList getResourcesList();
    QStringList getResourcesByType(unsigned int uiType);

private:
    QStringList m_listResources;
    QList<VisaDev* > m_listRM;
    ViSession   m_DefaultRM;
    unsigned long m_numResources;
    const QString m_hostName = "visa://NT-G6000/?*";
};

#endif // RESOURCEMANAGER_H
