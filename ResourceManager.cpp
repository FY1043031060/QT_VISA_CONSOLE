#include "ResourceManager.h"
#include <QDebug>
#include "ASL485AND422.h"
ResourceManager::ResourceManager(QWidget *parent)
    : QWidget(parent)
{
    if(VI_SUCCESS < viOpenDefaultRM(&m_DefaultRM))
    {
        return;
    }
    if(VI_SUCCESS < scanForResources())
    {
        return;
    }

}

ResourceManager::~ResourceManager()
{
    viClose(m_DefaultRM);
}

int ResourceManager::scanForResources()
{
    int status = VI_SUCCESS;
    ViSession session;
    ViChar strDesc[FILENAME_MAX];
    ViUInt16 intfType;
    ViUInt16 intfNum;
    ViChar rsrcClass[FILENAME_MAX];
    ViChar expandedUnaliasedName[FILENAME_MAX];
    ViChar aliasIfExists[FILENAME_MAX]; //USER DEFINE NAME
    for(int index = 0;index < RESOURCE_MAX;index++){
        numWidget[index] = 0;
    }
    //根据默认资源管理器获取资源描述符
    status = viFindRsrc(m_DefaultRM,
                        m_hostName.trimmed().toLatin1().data(),
                        &session,
                        &m_numResources,
                        strDesc);
    if(status != VI_SUCCESS)
        return status;
    //根据默认资源管理器以及资源描述符获取设备其他信息
    status = viParseRsrcEx(m_DefaultRM,
                           strDesc,
                           &intfType,
                           &intfNum,
                           rsrcClass,
                           expandedUnaliasedName,
                           aliasIfExists);
    if(status != VI_SUCCESS)
        return status;
    m_listRM.push_back(new VisaDev(strDesc, m_DefaultRM, this));
    //解析资源别名判断资源类型
    RESOURCE_TYPE enType = parResourceName(aliasIfExists);
    //资源聚合
    m_mapRM.insert(showResourceDev(enType),createWidget(enType,strDesc));

    for(int index = 0; index < m_numResources - 1; index++)
    {
        status = viFindNext(session, strDesc);
        m_listRM.push_back(new VisaDev(strDesc, m_DefaultRM, this));

        viParseRsrcEx(m_DefaultRM,
                      strDesc,
                      &intfType,
                      &intfNum,
                      rsrcClass,
                      expandedUnaliasedName,
                      aliasIfExists);
        RESOURCE_TYPE enType = parResourceName(aliasIfExists);
        m_mapRM.insert(showResourceDev(enType),createWidget(enType,strDesc));
    }

    return status;
}

QStringList ResourceManager::getResourcesList()
{
    QStringList temp;
    for(int i = 0; i < m_listRM.size(); ++i)
    {
        temp.push_back(dynamic_cast<VisaDev*>(m_listRM.at(i))->getVisaDevName());
    }
    return temp;
}

QStringList ResourceManager ::getResourcesByType(unsigned int uiType)
{
    QStringList temp;
    ViUInt16 uiDeviceType = 0;
    ViUInt16 uiDeviceInfNum = 0;
    foreach(QString var ,m_listResources)
    {
        viParseRsrc(m_DefaultRM,
                    var.trimmed().toLatin1().data(),
                    &uiDeviceType,
                    &uiDeviceInfNum);
        if(uiDeviceType == uiType)
        {
            temp.push_back(var);
        }
    }
    return temp;
}

QMap<QString, QWidget *>& ResourceManager::getResourceDev()
{
    return m_mapRM;
}

QWidget *ResourceManager::createWidget(RESOURCE_TYPE enDev,QString strDesc)
{
    switch(enDev)
    {
    case ASL485_422_TYPE:
        return new ASL485AND422(strDesc,m_DefaultRM,this);
    default:
        return NULL;
    }
}

ResourceManager::RESOURCE_TYPE ResourceManager::parResourceName(QString strResource)
{
    //"visa://NT-G6000/GOOD"
    QStringList strList = strResource.split("/");
    qDebug()<<strList.last();
    QString tmpType = strList.last();
    //TODO::条件判断指定字符串指示的设备预设类型是否一致
    if(tmpType.contains("COM"))
    {
        return ASL485_422_TYPE;
    }
    else
        return OTHER_TYPE;
}

QString ResourceManager::showResourceDev(ResourceManager::RESOURCE_TYPE enType)
{
    QString tmp= "";
    switch(enType)
    {
    case ASL485_422_TYPE:
        tmp = QStringLiteral(ASL485_422_DEV_NAME);
        break;
    default:
        tmp = QStringLiteral(OTHER_DEV_NAME);
    }
    qDebug()<<__FUNCTION__<<"1st"<<tmp;
    if(enType< RESOURCE_MAX&& enType >=ASL485_422_TYPE)
        tmp+=QString(".%1").arg(++numWidget[enType]);
    qDebug()<<__FUNCTION__<<"2nd"<<tmp;
    return tmp;
}
