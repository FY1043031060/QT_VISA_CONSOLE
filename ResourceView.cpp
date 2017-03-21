#include "ResourceView.h"
#include "ui_ResourceView.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QtDebug>
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
    //设备资源按照类型排列
    QObject::connect(buttonByType,&QPushButton::clicked,this,[&](){
        this->m_resourceWidget->clear();
        QMap<QString,QWidget*>::iterator iter =
                this->m_RM->getResourceDev().begin();
        for(iter;iter!= this->m_RM->getResourceDev().end();iter++)
        {
            //TODO::树形节点
            qDebug()<<__FUNCTION__<<iter.key();
            this->addDevByCategory(iter.key());
        }

    });
    QObject::connect(m_resourceWidget,&QTreeWidget::activated,this,[&](){
        qDebug()<<"slots is response.";
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

//TODO::树形链表有问题
void ResourceView::addDevByCategory(QString strItem)
{
    int numTopItems = m_resourceWidget->topLevelItemCount();
    qDebug() <<"TOP_LEVEL_ITEMS"<<numTopItems  ;

    for(int index = 0; index <numTopItems;index++)
    {
        QTreeWidgetItem* pTreeItem = m_resourceWidget->topLevelItem(index);
        if(strItem.contains(pTreeItem->text(0)))
        {
            QTreeWidgetItem* pChildItem =  new QTreeWidgetItem(pTreeItem);
            pChildItem->setText(0,strItem);
            pChildItem->setCheckState(0,Qt::Unchecked);
            pTreeItem->addChild(pChildItem);
            return;
        }
    }
    QTreeWidgetItem* pNewTreeItem =  new QTreeWidgetItem(m_resourceWidget);
    pNewTreeItem->setText(0,strItem.split(".").first());
    qDebug()<<"strItem."<<(strItem.split(".").first());
    QTreeWidgetItem* pChildItem =  new QTreeWidgetItem(pNewTreeItem);
    pChildItem->setText(0,strItem);
    pChildItem->setCheckState(0,Qt::Unchecked);
    pNewTreeItem->addChild(pChildItem);
    m_resourceWidget->addTopLevelItem(pNewTreeItem);
}
