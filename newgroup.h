#ifndef NEWGROUP_H
#define NEWGROUP_H


#include <QDialog>
#include "development.h"
#include <fstream>
namespace Ui {
class newGroup;
}

class newGroup : public QDialog
{
    Q_OBJECT

public:
    explicit newGroup(QWidget *parent = nullptr);
    ~newGroup();
    friend  QDataStream &operator <<(QDataStream &out, const Develop &any);
    friend  QDataStream &operator >>(QDataStream &out, Develop &any);
signals:
    void AdminWindow();
private slots:
    void on_Accept_clicked();

    void on_Cancle_clicked();

private:
    Ui::newGroup *ui;
};

#endif // NEWGROUP_H
