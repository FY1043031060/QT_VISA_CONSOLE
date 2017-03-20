#include "ResourceView.h"
#include "ui_ResourceView.h"
#include <QHBoxLayout>
#include <QPushButton>
ResourceView::ResourceView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourceView),
    m_RM(new ResourceManager(this))
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);

    //init the layout for this treewidget and set the connection of slots
    QHBoxLayout* hlayout = new QHBoxLayout(this);
    m_resourceWidget = new QTreeWidget(this);
    m_resourceWidget->setObjectName(QString("resourceWidget"));
    initComponent();

    hlayout->addWidget(m_resourceWidget);
    QPushButton* pushButton = new QPushButton(this);
    pushButton->setText(QStringLiteral("DevList"));
    hlayout->addWidget(pushButton);
    QPushButton* buttonByType = new QPushButton(this);
    buttonByType->setText(QStringLiteral("TypeList"));
    hlayout->addWidget(buttonByType);

    QObject::connect(pushButton,&QPushButton::clicked,this,[&](){
        this->m_resourceWidget->clear();
        foreach (QString var, this->m_RM->getResourcesList()) {
            this->addResourceViewItem(var);
        }
    });

    QObject::connect(buttonByType,&QPushButton::clicked,this,[&](){
        this->m_resourceWidget->clear();
        QMap<QString,ResourceManager::RESOURCE_TYPE>::iterator iter =
                QMap<QString,ResourceManager::RESOURCE_TYPE>::begin();
        for(iter;iter!=QMap<QString,ResourceManager::RESOURCE_TYPE>::end();iter++)
        {
            //TODO::树形节点
            //*iter.key()
        }

    });
}

ResourceView::~ResourceView()
{
    delete ui;
}

int ResourceView::initComponent()
{
    int status = 0;
    m_resourceWidget->setColumnCount(1);
    m_resourceWidget->setHeaderLabel(QStringLiteral("在线设备"));
    return status;
}

void ResourceView::addResourceViewItem(QString strItem)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(m_resourceWidget);
    item->setText(0,strItem);
    item->setCheckState(0,Qt::Checked);
    //m_resourceWidget->topLevelItem(0)->addChild(item);
}

void ResourceView::addDevByCategory(QString strItem)
{

}
