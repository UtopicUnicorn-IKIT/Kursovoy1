#ifndef DEPWINDOW_H
#define DEPWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlDatabase>
namespace Ui {
class DepWindow;
}

class DepWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DepWindow(QWidget *parent = nullptr);
    ~DepWindow();
     void SetDatabase();

     void SetModel();

     void SetTable(QSqlDatabase &);

signals:
    void AdminWindow();
    void WorkerWindow();
    void firstwindow();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_Add_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_SortButton_clicked();

    void on_PrintData_clicked();

private:
    Ui::DepWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // DEPWINDOW_H
