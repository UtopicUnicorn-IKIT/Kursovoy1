#ifndef WORKERWIND_H
#define WORKERWIND_H

#include <QDialog>
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
private slots:
    void on_Exit_clicked();

    void on_Sort_clicked();

private:
    Ui::workerWind *ui;
    QSqlDatabase table;
    QSqlTableModel *Model;
};

#endif // WORKERWIND_H
