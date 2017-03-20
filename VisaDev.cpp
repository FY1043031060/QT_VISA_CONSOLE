#include "VisaDev.h"

VisaDev::VisaDev(QString strDevice, ViSession viResourceRM, QWidget *parent)
    : QWidget(parent),
      m_strDev(strDevice.trimmed())
{
    ViUInt16 uiType = 0, uifNum = 0;
    viParseRsrc(viResourceRM,
                strDevice.trimmed().toLatin1().data(),
                &uiType,
                &uifNum);
    viOpen(viResourceRM,
           strDevice.trimmed().toLatin1().data(),
           VI_NULL,
           VI_NULL,
           &m_session);
}

VisaDev::~VisaDev()
{

}

QString VisaDev::getVisaDevName() const
{
    return m_strDev;
}

int VisaDev::setDeviceMode(int iType)
{
    int status = 0;
    switch(iType)
    {
        case 1:
            m_typeFlag = VISA_GPIB_DEVICE;
            break;
        case 2:
            m_typeFlag = VISA_VXI_DEVICE;
            break;
        case 3:
            m_typeFlag = VISA_GPIB_VXI_DEVICE;
            break;
        case 4:
            m_typeFlag = VISA_ASRL_DEVICE;
            break;
        case 5:
            m_typeFlag = VISA_PXI_DEVICE;
            break;
        case 6:
            m_typeFlag = VISA_TCPIP_DEVICE;
            break;
        case 7:
            m_typeFlag = VISA_USB_DEVICE;
            break;
        default:
            status = -1;
            break;
    }
    return status;
}
