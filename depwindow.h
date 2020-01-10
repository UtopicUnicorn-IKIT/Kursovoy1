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
    void Update();
    void SetTable(QSqlDatabase &);
signals:
    void AdminWindow();
    void firstwindow();
private slots:

    void on_Accept_clicked();

    void on_Cancle_clicked();

    void on_Fire_clicked();

    void on_Sort_clicked();

    void on_Exit_clicked();

    void on_createNew_clicked();

 public slots:
    void UpdateTable();

private:
    Ui::DepWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // DEPWINDOW_H
