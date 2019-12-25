#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QFile>
#include "development.h"
#include <QDataStream>
Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
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
void Registration::on_pushButton_clicked()
{
    QString username = ui->Name->text();
    QString login=ui->username->text();
     QString password = ui->password->text();
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


void Registration::on_pushButton_2_clicked()
{
    ui->Name->clear();
    ui->username->clear();
    ui->password->clear();
    this->close();
}
