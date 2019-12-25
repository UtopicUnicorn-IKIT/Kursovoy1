#include "depwindow.h"
#include "ui_depwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
DepWindow::DepWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(model);
    ui->comboBox->addItems({"По дате","По алфавиту"});
}

DepWindow::~DepWindow()
{
    delete ui;
}

void DepWindow::SetModel()
{
    model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("Workers");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->show();
}


void DepWindow::SetTable(QSqlDatabase &Table)
{
    db = Table;
    SetModel();
}

void DepWindow::on_pushButton_3_clicked()
{
   model->submitAll();
}

void DepWindow::on_pushButton_5_clicked()
{
    model->revertAll();
}

void DepWindow::on_Add_pushButton_clicked()
{
    qDebug() << "inserting row" << model->insertRow(model->rowCount());
}

void DepWindow::on_pushButton_2_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    if (selectedRow>=0){
       qDebug() << "deleting row:" << model->removeRow(selectedRow);
    }
    else{
        qDebug() << "no row selected";
    }
}

void DepWindow::on_pushButton_clicked()
{
    emit firstwindow();
    this->close();
}

void DepWindow::on_SortButton_clicked()
{
    if(ui->comboBox->currentText() == "По дате")
    {
        model->setSort(3,Qt::DescendingOrder);
        model->select();
    }
    else if (ui->comboBox->currentText() == "По алфавиту")
    {
       model->setSort(0,Qt::AscendingOrder);
       model->select();
    }
    return;
}

void DepWindow::on_PrintData_clicked()
{
}
