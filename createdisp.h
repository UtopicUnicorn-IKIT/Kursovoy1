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
    bool Check();
    friend  QDataStream &operator <<(QDataStream &out, const Develop &any);
    friend  QDataStream &operator >>(QDataStream &out, Develop &any);
signals:
    void AdminWindow();
private slots:
    void on_CreateNew_clicked();

    void on_Cancle_clicked();

private:
    Ui::CreateDisp *ui;
};

#endif // CREATEDISP_H
