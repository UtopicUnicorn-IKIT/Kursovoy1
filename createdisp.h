#ifndef CREATEDISP_H
#define CREATEDISP_H

#include <QDialog>
#include <development.h>
namespace Ui {
class CreateDisp;
}

class CreateDisp : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDisp(QWidget *parent = nullptr);
    ~CreateDisp();
    friend  QDataStream &operator <<(QDataStream &out, const Develop &any);
    friend  QDataStream &operator >>(QDataStream &out, Develop &any);
signals:
    void AdminWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateDisp *ui;
};

#endif // CREATEDISP_H
