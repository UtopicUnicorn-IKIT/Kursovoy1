#ifndef ADDWORKER_H
#define ADDWORKER_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlDatabase>
namespace Ui {
class addWorker;
}

class addWorker : public QDialog
{
    Q_OBJECT

public:
    explicit addWorker(QWidget *parent = nullptr);
    ~addWorker();

private slots:
    void on_Accept_clicked();

    void on_Cancle_clicked();

signals:
    void UpdateTableSignal();

private:
    Ui::addWorker *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // ADDWORKER_H
