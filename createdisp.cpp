#include "createdisp.h"
#include "ui_createdisp.h"
#include <QMessageBox>
#include <QFile>
#include "development.h"
#include <QDataStream>
CreateDisp::CreateDisp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDisp)
{
    ui->setupUi(this);
}

CreateDisp::~CreateDisp()
{
    delete ui;
}

void CreateDisp::on_pushButton_clicked()
{
    QString username = ui->userName->text();
    QString login=ui->Login->text();
     QString password = ui->Password->text();
   if((ui->userName->text() !=0) || (ui->Login->text()!=0)||(ui->Password->text() !=0)){
       QMessageBox::information(this, "Create", "Пользователь успешно создан");
       Develop use;

           use.Name = username;
           use.UserName = login;
         use.Password = password;
            use.Group = "Dispetcher";
            QFile out("logsys5.bin");
            out.open(QIODevice::Append);
            QDataStream
                    Stream(&out);
            Stream << use;
            out.close();
            ui->userName->clear();
            ui->Login->clear();
            ui->Password->clear();
            this ->close();
            emit AdminWindow();
        }else
        QMessageBox::warning(this, "Create", "Некоторые поля пустые");
}

void CreateDisp::on_pushButton_2_clicked()
{
    ui->userName->clear();
    ui->Login->clear();
    ui->Password->clear();
    emit AdminWindow();
     this->close();
}
