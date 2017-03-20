#ifndef RESOURCEVIEW_H
#define RESOURCEVIEW_H

#include <QWidget>
#include <QTreeWidget>
#include <ResourceManager.h>

namespace Ui {
class ResourceView;
}

class ResourceView : public QWidget
{
    Q_OBJECT

public:
    explicit ResourceView(QWidget *parent = 0);
    ~ResourceView();
    int initComponent();
public slots:
    void addResourceViewItem(QString strItem);
    void addResourceViewByCategy(QString strItem);
private:
    Ui::ResourceView *ui;
    QTreeWidget* m_resourceWidget;
    ResourceManager* m_RM;
};

#endif // RESOURCEVIEW_H
