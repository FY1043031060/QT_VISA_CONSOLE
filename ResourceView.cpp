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
    m_resourceWidget = new QTreeWidget(this);
    setWindowFlags(Qt::Window);
    QHBoxLayout* hlayout = new QHBoxLayout(this);
    hlayout->addWidget(m_resourceWidget);
    QPushButton* pushButton = new QPushButton(this);
    pushButton->setText(QStringLiteral("DevList"));
    hlayout->addWidget(pushButton);
    QObject::connect(pushButton,&QPushButton::clicked,this,[&](){
        this->m_resourceWidget->clear();
        foreach (QString var, this->m_RM->getResourcesList()) {
            this->addResourceViewItem(var);
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
    QTreeWidgetItem* topItem = new QTreeWidgetItem(m_resourceWidget);
    m_resourceWidget->addTopLevelItem(topItem);
    return status;
}

void ResourceView::addResourceViewItem(QString strItem)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(m_resourceWidget);
    item->setText(0,strItem);
    m_resourceWidget->topLevelItem(0)->addChild(item);
}
