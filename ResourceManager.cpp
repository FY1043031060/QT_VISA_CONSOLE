#include "ResourceManager.h"

ResourceManager::ResourceManager(QObject *parent)
    : QObject(parent)
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

    status = viFindRsrc(m_DefaultRM,
                        m_hostName.trimmed().toLatin1().data(),
                        &session,
                        &m_numResources,
                        strDesc);

    m_listRM.push_back(new VisaDev(strDesc, m_DefaultRM, this));
    for(int index = 0; index < m_numResources - 1; index++)
    {
        status = viFindNext(session, strDesc);
        m_listRM.push_back(new VisaDev(strDesc, m_DefaultRM, this));
    }

    return status;
}

QStringList ResourceManager::getResourcesList()
{
    QStringList temp;
    for(int i = 0; i < m_listRM.size(); ++i)
    {
        temp.push_back(m_listRM.at(i)->getVisaDevName());
    }
    return temp;
}

QStringList ResourceManager::getResourcesByType(unsigned int uiType)
{
    QStringList temp;
    ViUInt16 uiDeviceType = 0;
    ViUInt16 uiDeviceInfNum = 0;
    for each(QString var in m_listResources)
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
