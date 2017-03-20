#ifndef ASL485AND422_H
#define ASL485AND422_H

#include <QWidget>
#include "ivi.h"
#include "visa.h"

class ASL485AND422 : public QWidget
{
    Q_OBJECT
public:
    enum ASL485AND422_ATTR{

    };
public:
    explicit ASL485AND422(QString strDevice, ViSession viResourceRM, QWidget *parent);
    QString getDevName();
signals:

public slots:
private:
    ViSession m_session;
    QString m_strDev;
};

#endif // ASL485AND422_H
