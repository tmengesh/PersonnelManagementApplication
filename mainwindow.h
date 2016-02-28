/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "monthlypaid.h"
#include "hourlypaid.h"
#include "salesman.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionMonthly_paid_employee_triggered();

    void on_actionHourly_Employee_List_triggered();

    void on_actionHourly_paid_employee_triggered();

    void on_actionHourly_Paid_Employee_List_triggered();

    void on_actionSalesman_triggered();

    void on_actionSalesman_List_triggered();

    void on_actionE_xit_triggered();

private:
    Ui::MainWindow *ui;
    monthlyPaid monthlyPaidForm;
    hourlyPaid hourlyPaidForm;
    salesMan salesManForm;

};


#endif // MAINWINDOW_H
