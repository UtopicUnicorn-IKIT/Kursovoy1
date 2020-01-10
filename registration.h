#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <development.h>
#include <QDataStream>
namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();
    bool Check();
signals:
    void firstWindow();
private slots:
    void on_OK_clicked();

    void on_Cancle_clicked();

private:
    Ui::registration *ui;
};

#endif // REGISTRATION_H
