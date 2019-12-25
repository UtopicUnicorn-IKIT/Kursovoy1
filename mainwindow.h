#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <development.h>
#include <registration.h>
#include <development.h>
#include <adminwindow.h>
#include <workerwind.h>
#include <newgroup.h>
#include <QSqlDatabase>
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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Registration *registrationWindow;
    adminwindow *adwin;
    workerWind *worwin;
    dispWindow *dispwin;
    QSqlDatabase Database;
    DepWindow *dp;

};

#endif // MAINWINDOW_H
