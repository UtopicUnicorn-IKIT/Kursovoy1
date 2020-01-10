#include "adminwindow.h"
#include "ui_adminwindow.h"

adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    Dep = new  DepWindow();
    connect(Dep, &DepWindow::AdminWindow, this, &adminwindow::show);
    crt = new CreateDisp();
    connect(crt, &CreateDisp::AdminWindow, this, &adminwindow::show);
    upWind = new newGroup();
    connect(upWind,&newGroup::AdminWindow, this, &adminwindow::show);
}

adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_Exit_clicked()
{
    this->close();
    emit firstWindow();
}

void adminwindow::on_OpenDisp_clicked()
{
    Dep->SetTable(table);
    Dep -> show();
}
void adminwindow::SetTable(QSqlDatabase &Table)
{
    table = Table;
}

void adminwindow::on_ChangeRights_clicked()
{
    upWind -> show();
}

void adminwindow::on_NewDisp_clicked()
{
    this->hide();
    crt->show();
}
