#include "ASL485AND422.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

ASL485AND422::ASL485AND422(QString strDevice, ViSession viResourceRM, QWidget *parent)
    : QWidget(parent),
      m_strDev(strDevice.trimmed())
{
    viOpen(viResourceRM,
           strDevice.trimmed().toLatin1().data(),
           VI_NULL,
           VI_NULL,
           &m_session);
    setObjectName(strDevice.trimmed());
    initComponent();
}

QString ASL485AND422::getDevName()
{
    return m_strDev;
}

//设置相关的属性配置界面
void ASL485AND422::initComponent()
{
    setWindowFlags(Qt::Window);
    QLabel* labelBaudrate = new QLabel(QStringLiteral("波特率"),this);
    QLineEdit *editBaudrate  = new QLineEdit(this);
    QPushButton *buttonCommit = new QPushButton(QStringLiteral("提交"));
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hLayout1 = new QHBoxLayout();
    QHBoxLayout* hLayout2 = new QHBoxLayout();
    QSpacerItem* hSpacer = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    hLayout1->addWidget(labelBaudrate);
    hLayout1->addWidget(editBaudrate);
    hLayout2->addItem(hSpacer);
    hLayout2->addWidget(buttonCommit);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    this->resize(400,300);
    this->hide();
}

//属性变更
void ASL485AND422::initConnection()
{

}
