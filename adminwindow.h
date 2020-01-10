#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <createdisp.h>
#include <depwindow.h>
#include <newgroup.h>

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
private slots:
    void on_Exit_clicked();

    void on_OpenDisp_clicked();

    void on_ChangeRights_clicked();
    void on_NewDisp_clicked();

private:
    Ui::adminwindow *ui;
    DepWindow *Dep;
    QSqlDatabase table;
    CreateDisp *crt;
    newGroup *upWind;
};

#endif // ADMINWINDOW_H
