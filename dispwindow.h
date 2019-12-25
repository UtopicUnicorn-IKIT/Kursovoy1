#ifndef DISPWINDOW_H
#define DISPWINDOW_H

#include <QDialog>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <depwindow.h>
namespace Ui {
class dispWindow;
}

class dispWindow : public QDialog
{
    Q_OBJECT

public:
    explicit dispWindow(QWidget *parent = nullptr);
    ~dispWindow();
signals:
    void firstWindow();
private slots:
    void on_pushButton_5_clicked();

private:
    Ui::dispWindow *ui;
};

#endif // DISPWINDOW_H
