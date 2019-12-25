#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <development.h>
#include <QMessageBox>
#include "development.h"
#include <QDataStream>
namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
