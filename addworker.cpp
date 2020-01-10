#include "addworker.h"
#include "ui_addworker.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
addWorker::addWorker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addWorker)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

addWorker::~addWorker()
{
    delete ui;
}

void addWorker::on_Accept_clicked()
{
    QString username = ui->FIO->text();
    QString Rang=ui->Rank->text();
    QString Profession=ui->Prof->text();
    QString Depart=ui->Otd->text();
    QString Education=ui->Edu->text();
    QDate BirthDate=ui->BDate->date();
    QString Birth = BirthDate.toString("yyyy-MM-dd");
    QString id = ui->WorkID->text();
    QSqlQuery query;
    query.exec(QString(tr("insert into Workers(FIO, Rank, [Group], Birthday,WorkerID,Education,Profession) VALUES('%1','%2','%3','%4','%5','%6','%7')")
                       .arg(username).arg(Rang).arg(Depart).arg(Birth).arg(id).arg(Education).arg(Profession)));
    qDebug() << query.lastError().text();
    emit UpdateTableSignal();
    close();
}

void addWorker::on_Cancle_clicked()
{
    emit UpdateTableSignal();
    close();
}
