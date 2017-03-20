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
    enum RESOURCE_TYPE{
        ASL485_422_TYPE,
        ETHERNET_TYPE,
        AIR1553_TYPE,
        CAN_TYPE
    };
public:
    explicit ResourceManager(QWidget *parent = Q_NULLPTR);
    ~ResourceManager();
    int scanForResources();
    QStringList getResourcesList();
    QStringList getResourcesByType(unsigned int uiType);
    QWidget* createWidget(QString strDev,QString strAlias);
    RESOURCE_TYPE parResourceName(QString strResource);
private:
    QStringList m_listResources;
    QList<QWidget* > m_listRM;
    ViSession   m_DefaultRM;
    unsigned long m_numResources;
    const QString m_hostName = "visa://NT-G6000/?*";
};

#endif // RESOURCEMANAGER_H
