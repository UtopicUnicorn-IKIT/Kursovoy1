#include "newgroup.h"
#include "ui_newgroup.h"
#include "QMessageBox"
#include "QFile"
#include "QDebug"
#include <QTextCodec>
#include <iterator>
#include <fstream>
#include <QFile>
#include <QString>
newGroup::newGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newGroup)
{
    ui->setupUi(this);
}

newGroup::~newGroup()
{
    delete ui;
}

void newGroup::on_pushButton_clicked()
{
    Develop use;
     QFile in("logsys5.bin");
    in.open(QIODevice::ReadOnly);
    QDataStream stream(&in);
    QFile out("logsys7.bin");
   out.open(QIODevice::WriteOnly);
   QDataStream stream2(&out);
 QString username = ui->UserN->text();
 if(ui->UserN != 0){
     while(!stream.atEnd())
     {
          stream >> use;
         if(ui->UserN->text() == use.UserName)
         {

             if(ui->RB1->isChecked())
             {
                use.Group = "Admin";
                QMessageBox::information(this, "Update", "Приоритет изменен!");
             }
             if(ui->RB2->isChecked())
             {
                 use.Group = "Dispetcher";
                 QMessageBox::information(this, "Update", "Приоритет изменен!");
             }
             if(ui->RB3->isChecked())
             {
                 use.Group = "Worker";
                   QMessageBox::information(this, "Update", "Приоритет изменен!");
             }
         }
      stream2 << use;
     }
     in.close();
     out.close();
     Develop use2;
     QFile in1("logsys7.bin");
     in1.open(QIODevice::ReadOnly);
     QDataStream stream3(&in1);
     QFile out1("logsys5.bin");
    out1.open(QIODevice::WriteOnly);
    QDataStream stream4(&out1);
    while(!stream3.atEnd()){
        stream3 >> use2;
        stream4 << use2;
    }
    in1.close();
    out1.close();
    QFile in2("logsys7.bin");
    in2.open(QIODevice::WriteOnly | QIODevice::Truncate);
    in2.close();
    this->close();
 }   else{
QMessageBox::warning(this, "Login", "Некоторые поля пустые");

}

}

void newGroup::on_pushButton_2_clicked()
{
    this->close();
}
