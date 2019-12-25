#ifndef NEWGROUP_H
#define NEWGROUP_H

#include <QDialog>
#include "development.h"
#include "registration.h"
#include <fstream>
#include <vector>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newGroup *ui;
};

#endif // NEWGROUP_H
