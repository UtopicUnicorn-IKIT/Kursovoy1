#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <development.h>
#include <registration.h>
#include <QSqlDatabase>
#include <adminwindow.h>
#include <workerwind.h>
#include <depwindow.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend  QDataStream &operator <<(QDataStream &out, const Develop &any);
    friend  QDataStream &operator >>(QDataStream &out, Develop &any);
 void SetDatabase();
private slots:
    void on_Enter_clicked();

    void on_Registr_clicked();

    void on_closeWind_clicked();

private:
    Ui::MainWindow *ui;
    registration *registrationWindow;
    adminwindow *adwin;
    QSqlDatabase Database;
    workerWind *worwin;
    DepWindow *dp;
};

#endif // MAINWINDOW_H
