#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <development.h>
#include <newgroup.h>
#include <registration.h>
#include <dispwindow.h>
#include <workerwind.h>
#include <depwindow.h>
#include <createdisp.h>

namespace Ui {
class adminwindow;
}

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = nullptr);
    ~adminwindow();
 void SetDatabase();
 void SetTable(QSqlDatabase &);
signals:
    void firstWindow();
    void adminWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();



private:
    Ui::adminwindow *ui;
    newGroup *upWind;
    Registration *registrationWindow;
    DepWindow *Dep;
    QSqlDatabase table;
    CreateDisp *crt;
};

#endif // ADMINWINDOW_H
