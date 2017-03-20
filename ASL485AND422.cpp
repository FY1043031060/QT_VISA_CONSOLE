#include "ASL485AND422.h"

ASL485AND422::ASL485AND422(QString strDevice, ViSession viResourceRM, QWidget *parent)
    : QWidget(parent),
      m_strDev(strDevice.trimmed())
{
    viOpen(viResourceRM,
           strDevice.trimmed().toLatin1().data(),
           VI_NULL,
           VI_NULL,
           &m_session);
}

QString ASL485AND422::getDevName()
{
    return m_strDev;
}
