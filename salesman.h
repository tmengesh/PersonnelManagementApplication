/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#ifndef SALESMAN_H
#define SALESMAN_H

#include <QDialog>

//Salesman Class map
class EmployeeSalesman {
  public:
    EmployeeSalesman(const QString &name, const QString &socialSecurityNumber, const QString &salary)
    {
      sm_name = name;
      sm_socialSecurityNumber = socialSecurityNumber;
      sm_salary = salary;
    }

    QString name() const { return sm_name; }
    QString socialSecurityNumber() const { return sm_socialSecurityNumber; }
    QString salary() const { return sm_salary; }


  private:
    QString sm_name;
    QString sm_socialSecurityNumber;
    QString sm_salary;
};

namespace Ui {
class salesMan;
}

class salesMan : public QDialog
{
    Q_OBJECT

public:
    explicit salesMan(QWidget *parent = 0);
    ~salesMan();

private slots:
    void on_btnCloseSalesman_clicked();

    void on_radioButtonNo_clicked();

    void on_radioButtonYes_clicked();

    void on_btnAddSalesman_clicked();

private:
    Ui::salesMan *ui;
};

#endif // SALESMAN_H
