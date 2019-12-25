#include "adminwindow.h"
#include "ui_adminwindow.h"

adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    upWind = new newGroup();
    connect(upWind,&newGroup::AdminWindow, this, &adminwindow::show);
    Dep = new  DepWindow();
    connect(Dep, &DepWindow::AdminWindow, this, &adminwindow::show);
    crt = new CreateDisp();
    connect(crt, &CreateDisp::AdminWindow, this, &adminwindow::show);

}

adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_pushButton_5_clicked()
{
    this->close();
    emit firstWindow();
}

void adminwindow::on_pushButton_9_clicked()
{
    upWind -> show();
}

void adminwindow::on_pushButton_8_clicked()
{
    this->hide();
    crt->show();

}

void adminwindow::on_pushButton_clicked()
{
    Dep->SetTable(table);
    Dep -> show();
}

void adminwindow::SetTable(QSqlDatabase &Table)
{
    table = Table;
}

