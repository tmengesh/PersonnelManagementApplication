/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman

  Hourly Paid Employees
  Read values from registration form, validate user input,
  calculate salary(donehours*hourlyCompensation)and add to Hourly Paid map
*/

#include "hourlypaid.h"
#include "ui_hourlypaid.h"
#include"global.h"
#include <QMessageBox>
hourlyPaid::hourlyPaid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hourlyPaid)
{
    ui->setupUi(this);
}

hourlyPaid::~hourlyPaid()
{
    delete ui;
}

void hourlyPaid::on_btnaddhourlyPaid_clicked()
{
    //Read values from registration form
    QString name = this->ui->txthourlyPaidName->text();
    QString dob= this->ui->txthourlyPaidSocialSecuritynumber->text();
    QString hourlyCompensation = this->ui->txthourlyPaidhcompensation->text();
    QString doneHours = this->ui->txthourlyPaidDoneHours->text();

    // Validate user input

    if(name=="")
    {
        QMessageBox::critical( this, "Error", "Enter employee name!", QMessageBox::Ok, 0 );
        this->ui->txthourlyPaidName->setFocus();
    }
    else if(dob=="")
    {
        QMessageBox::critical( this, "Error", "Enter employee Social Security Number!", QMessageBox::Ok, 0 );
        this->ui->txthourlyPaidSocialSecuritynumber->setFocus();
    }
    else if(hourlyCompensation==""||hourlyCompensation.toDouble()==false)
    {
        QMessageBox::critical( this, "Error", "Enter numeric value for Hourly Compensation!", QMessageBox::Ok, 0 );
        this->ui->txthourlyPaidhcompensation->setText("");
        this->ui->txthourlyPaidhcompensation->setFocus();

    }
    else if(doneHours==""||doneHours.toDouble()==false)
    {
        QMessageBox::critical( this, "Error", "Enter numeric value for Done Hours!", QMessageBox::Ok, 0 );
        this->ui->txthourlyPaidDoneHours->setText("");
        this->ui->txthourlyPaidDoneHours->setFocus();
    }
    else
    {
        QString salary = QString::number(hourlyCompensation.toDouble()*doneHours.toDouble());

        //add to Hourly paid employee map
        EmployeeHPaid e1 (name,dob,hourlyCompensation,doneHours,salary);
        HPmap.insert(HPMapIndex,e1);
        HPMapIndex++;

        //Empty the form to blank to register new hourly paid employee
          QMessageBox::information( this, "Comfirmation", "Employee has added successfully!", QMessageBox::Ok, 0 );
          this->ui->txthourlyPaidName->setText("");
          this->ui->txthourlyPaidSocialSecuritynumber->setText("");
          this->ui->txthourlyPaidhcompensation->setText("");
          this->ui->txthourlyPaidDoneHours->setText("");
          this->ui->txthourlyPaidName->setFocus();
    }


}

void hourlyPaid::on_btncancelhourlyPaid_clicked()
{
    this->close();
}
