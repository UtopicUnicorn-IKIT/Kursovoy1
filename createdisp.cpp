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

void CreateDisp::on_CreateNew_clicked()
{
    QString username = ui->userName->text();
    QString login=ui->Login->text();
     QString password = ui->Password->text();
     if(Check() == true){
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
}

void CreateDisp::on_Cancle_clicked()
{
    ui->userName->clear();
    ui->Login->clear();
    ui->Password->clear();
    emit AdminWindow();
     this->close();
}
bool CreateDisp::Check(){
    QString login=ui->userName->text();
     Develop use;
     int i = 0;
     QFile in("logsys5.bin");
     in.open(QIODevice::ReadOnly);
     QDataStream stream(&in);
     while(!stream.atEnd())
     {
         stream >> use;
         if(use.UserName == login ){
          QMessageBox::warning(this, "Create", "Данный логин уже используется!");
          ui->userName->clear();
          ui->Password->clear();
          i++;
          in.close();
           }
     }
     if(i ==0)
         return true;
     else {
         return false;
     }

}
