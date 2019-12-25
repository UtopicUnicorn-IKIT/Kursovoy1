#include "dispwindow.h"
#include "ui_dispwindow.h"

dispWindow::dispWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dispWindow)
{
    ui->setupUi(this);
}

dispWindow::~dispWindow()
{
    delete ui;
}

void dispWindow::on_pushButton_5_clicked()
{
    this->close();
    emit firstWindow();
}
