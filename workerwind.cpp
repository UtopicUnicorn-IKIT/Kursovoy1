#include "workerwind.h"
#include "ui_workerwind.h"


workerWind::workerWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workerWind)
{
    ui->setupUi(this);
    ui->comboBox->addItems({"По дате","По алфавиту"});

}

workerWind::~workerWind()
{
    delete ui;
}

void workerWind::SetModelView()
{
    Model = new QSqlTableModel(this);
    Model->setTable("Workers");
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->show();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void workerWind::on_pushButton_3_clicked()
{
    this->close();
    emit firstWindow();
}


void workerWind::SetTable(QSqlDatabase &Table)
{
   table = Table;
}

void workerWind::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() == "По дате")
    {
        Model->setSort(3,Qt::DescendingOrder);
        Model->select();
    }
    else if (ui->comboBox->currentText() == "По алфавиту")
    {
       Model->setSort(0,Qt::AscendingOrder);
       Model->select();
    }
    return;
}

