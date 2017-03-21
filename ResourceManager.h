#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QWidget>
#include "visa.h"
#include "ivi.h"
#include <QMap>
#include <QStringList>
#include <QList>
#include "VisaDev.h"
#pragma comment(lib,"visa32.lib")
#pragma comment(lib,"ivi.lib")

class ResourceManager : public QWidget
{
    Q_OBJECT
public: enum RESOURCE_TYPE{
        ASL485_422_TYPE = 0,
        ETHERNET_TYPE,
        AIR1553_TYPE,
        CAN_TYPE,
        RESOURCE_MAX,
        RESOURCE_INVALID
    };
public:
    explicit ResourceManager(QWidget *parent = Q_NULLPTR);
    ~ResourceManager();
    int scanForResources();
    QStringList getResourcesList();
    QStringList getResourcesByType(unsigned int uiType);
    QMap<QString,QWidget*> getResourceDev();
    QWidget* createWidget(RESOURCE_TYPE enDev,QString strDesc);
    RESOURCE_TYPE parResourceName(QString strResource);
    QString showResourceDev(RESOURCE_TYPE enType);
private:
    QStringList m_listResources;
    QList<QWidget* > m_listRM;
    QMap<QString,QWidget*> m_mapRM;
    ViSession   m_DefaultRM;
    int numWidget[RESOURCE_MAX];
    unsigned long m_numResources;
    const QString m_hostName = "visa://NT-G6000/?*";
};

#endif // RESOURCEMANAGER_H
