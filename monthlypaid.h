/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#ifndef MONTHLYPAID_H
#define MONTHLYPAID_H

#include <QDialog>

//Monthly Paid employee Class map
class EmployeeMPaid {
  public:
    EmployeeMPaid(const QString &name, const QString &socialSecurityNumber, const QString &salary)
    {
      mp_name = name;
      mp_socialSecurityNumber = socialSecurityNumber;
      mp_salary = salary;
    }

    QString name() const { return mp_name; }
    QString socialSecurityNumber() const { return mp_socialSecurityNumber; }
    QString salary() const { return mp_salary; }


  private:
    QString mp_name;
    QString mp_socialSecurityNumber;
    QString mp_salary;
};
namespace Ui {
class monthlyPaid;
}

class monthlyPaid : public QDialog
{
    Q_OBJECT

public:
    explicit monthlyPaid(QWidget *parent = 0);
    ~monthlyPaid();

private slots:
    void on_btncancelMonthlPaid_clicked();

    void on_btnaddMonthlPaid_clicked();


private:
    Ui::monthlyPaid *ui;

};

#endif // MONTHLYPAID_H
