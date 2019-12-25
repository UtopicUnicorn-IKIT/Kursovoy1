#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFile"
#include "QDebug"
#include <QTextCodec>
#include <QFile>
#include <QSqlTableModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    registrationWindow = new Registration();
    connect(registrationWindow,&Registration::firstWindow, this, &MainWindow::show);
    adwin = new adminwindow();
    connect(adwin,&adminwindow::firstWindow, this, &MainWindow::show);
    worwin = new workerWind();
    connect(worwin,&workerWind::firstWindow, this, &MainWindow::show);
  /*  dispwin = new dispWindow();
    connect(dispwin,&dispWindow::firstWindow, this, &MainWindow::show);*/
    dp = new DepWindow();
    connect(dp,&DepWindow::firstwindow,this,&MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    Develop use;

    QString username = ui->lineEdit_Login->text();
    QString password = ui->lineEdit_Password->text();
    int temp =0;
    if((ui->lineEdit_Login->text() !=0) || (ui->lineEdit_Password->text()!=0)){
         QFile in("logsys5.bin");
        in.open(QIODevice::ReadOnly);
        QDataStream stream(&in);
    while(!stream.atEnd())
    {
        stream >> use;
        if((ui->lineEdit_Login->text() == use.UserName) && (ui->lineEdit_Password->text()==use.Password))
        {
            temp++;
            QMessageBox::information(this, "Login", "Успешный вход в систему");
            if(use.Group == "Admin")
            {
                SetDatabase();
                adwin->SetTable(Database);
                adwin ->show();
                ui->lineEdit_Login->clear();
                ui->lineEdit_Password->clear();
                this->hide();
                in.close();
                break;
            }
            if(use.Group == "Dispetcher")
            {
                SetDatabase();
                dp->SetTable(Database);
                dp ->show();
                ui->lineEdit_Login->clear();
                ui->lineEdit_Password->clear();
                in.close();
                this->hide();
                break;
            }
            if(use.Group == "Worker")
            {
                SetDatabase();
                worwin ->SetTable(Database);
                worwin->SetModelView();
                worwin ->show();
                ui->lineEdit_Login->clear();
                ui->lineEdit_Password->clear();
                in.close();
                this->hide();
                break;
            }
        }
    }
    }else{
        QMessageBox::warning(this, "Login", "Некоторые поля пустые");

    }
    if(temp ==0){
        QMessageBox::warning(this, "Warning", "Логин или пароль не совпадают!");
    }
}

void MainWindow::SetDatabase()
{

    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("Depart.db");
    Database.open();
    if(Database.isOpen())
      qDebug() << "True";

}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    registrationWindow -> show();
}

void MainWindow::on_pushButton_3_clicked()
{
    qApp->quit();
}
