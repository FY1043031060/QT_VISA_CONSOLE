#ifndef VISADEV_H
#define VISADEV_H
#include <QWidget>
#include "ivi.h"
#include "visa.h"

class VisaDev : public QWidget
{
    Q_OBJECT

public:  enum VISA_DEVICE_TYPE
    {
        VISA_GPIB_DEVICE = 1,
        VISA_VXI_DEVICE,
        VISA_GPIB_VXI_DEVICE,
        VISA_ASRL_DEVICE,
        VISA_PXI_DEVICE,
        VISA_TCPIP_DEVICE,
        VISA_USB_DEVICE,
        VISA_DEVICE_MAX
    };

public:
    explicit VisaDev(QString strDevice, ViSession viResourceRM, QWidget *parent);
    ~VisaDev();
    QString getVisaDevName() const;
protected:
    int setDeviceMode(int iType);
private:
    VISA_DEVICE_TYPE m_typeFlag;
    ViSession m_session;
    QString m_strDev;
};

#endif // VISADEV_H
