#ifndef WORKERWIND_H
#define WORKERWIND_H

#include <QDialog>
#include <depwindow.h>
#include <QSqlTableModel>

namespace Ui {
class workerWind;
}

class workerWind : public QDialog
{
    Q_OBJECT

public:
    explicit workerWind(QWidget *parent = nullptr);
    ~workerWind();
    void SetDatabase();
    void SetTable(QSqlDatabase &);

    void SetModelView();
signals:
    void firstWindow();
    void workerWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::workerWind *ui;
    DepWindow *Dep;
    QSqlDatabase table;
    QSqlTableModel *Model;
};

#endif // WORKERWIND_H
