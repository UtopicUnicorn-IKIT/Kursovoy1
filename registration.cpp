#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QFile>
#include "development.h"
#include <QDataStream>
registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}
QDataStream &operator <<(QDataStream &out, const Develop &any)
{
    out << any.Name;
   out << any.UserName;
    out << any.Password;
    out << any.Group;
    return out;
}

QDataStream &operator >>(QDataStream &out, Develop &any)
{
    out >> any.Name;
   out >> any.UserName;
    out >> any.Password;
    out >> any.Group;
    return out;
}
void registration::on_OK_clicked()
{
    QString username = ui->Name->text();
    QString login=ui->username->text();
     QString password = ui->password->text();
     if(Check() == true){
   if((ui->Name->text() !=0) || (ui->username->text()!=0)||(ui->password->text() !=0)){
       QMessageBox::information(this, "Create", "Пользователь успешно создан");
       Develop use;

           use.Name = username;
           use.UserName = login;
         use.Password = password;
            use.Group = "Worker";
            QFile out("logsys5.bin");
            out.open(QIODevice::Append);
            QDataStream
            Stream(&out);
            Stream << use;
            out.close();
            ui->Name->clear();
            ui->username->clear();
            ui->password->clear();
            this ->close();
            emit firstWindow();
        }else
        QMessageBox::warning(this, "Create", "Некоторые поля пустые");
     }
}
bool registration::Check(){
    QString login=ui->username->text();
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
          ui->username->clear();
          ui->password->clear();
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

void registration::on_Cancle_clicked()
{
    ui->Name->clear();
    ui->username->clear();
    ui->password->clear();
    this->close();
}
