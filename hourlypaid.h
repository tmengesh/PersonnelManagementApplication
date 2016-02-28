/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#ifndef HOURLYPAID_H
#define HOURLYPAID_H

#include <QDialog>
//Hourly Paid employee Class map
class EmployeeHPaid {
  public:
    EmployeeHPaid(const QString &name, const QString &socialSecurityNumber, const QString &hourlyCompensation, const QString &doneHours, const QString &salary)
    {
      hp_name = name;
      hp_socialSecurityNumber = socialSecurityNumber;
      hp_hourlyCompensation = hourlyCompensation;
      hp_doneHours = doneHours;
      hp_salary = salary;
    }

    QString name() const { return hp_name; }
    QString socialSecurityNumber() const { return hp_socialSecurityNumber; }
    QString hourlyCompensation() const { return hp_hourlyCompensation; }
    QString doneHours() const { return hp_doneHours; }
    QString salary() const { return hp_salary; }



  private:
    QString hp_name;
    QString hp_socialSecurityNumber;
    QString hp_hourlyCompensation;
    QString hp_doneHours;
    QString hp_salary;
};
namespace Ui {
class hourlyPaid;
}

class hourlyPaid : public QDialog
{
    Q_OBJECT

public:
    explicit hourlyPaid(QWidget *parent = 0);
    ~hourlyPaid();

private slots:
    void on_btnaddhourlyPaid_clicked();

    void on_btncancelhourlyPaid_clicked();

private:
    Ui::hourlyPaid *ui;
};

#endif // HOURLYPAID_H
