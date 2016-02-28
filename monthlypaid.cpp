/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman

  Monthly Paid Employees
  Read values from registration form, validate user input and add to monthly paid employess map

 */

#include <QApplication>
#include <QMessageBox>
#include "monthlypaid.h"
#include "mainwindow.h"
#include "monthlypaid.h"
#include "ui_monthlypaid.h"
#include"global.h"

monthlyPaid::monthlyPaid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monthlyPaid)
{
    ui->setupUi(this);
}

monthlyPaid::~monthlyPaid()
{
    delete ui;
}

void monthlyPaid::on_btncancelMonthlPaid_clicked()
{
    this->close();
}



void monthlyPaid::on_btnaddMonthlPaid_clicked()
{
   //Read values from registration form

    QString name = this->ui->txtmonthlyPaidName->text();
    QString dob= this->ui->txtmonthlyPaidSocialSecuritynumber->text();
    QString salary = this->ui->txtmonthlyPaidSalary->text();

    //Validate user input
    if(name=="")
    {
        QMessageBox::critical( this, "Error", "Enter employee name!", QMessageBox::Ok, 0 );
        this->ui->txtmonthlyPaidName->setFocus();
    }
    else if(dob=="")
    {
        QMessageBox::critical( this, "Error", "Enter employee social security number!", QMessageBox::Ok, 0 );
        this->ui->txtmonthlyPaidSocialSecuritynumber->setFocus();
    }
    else if(salary=="")
    {   QMessageBox::critical( this, "Error", "Enter employee Monthly Compensation!", QMessageBox::Ok, 0 );
        this->ui->txtmonthlyPaidSalary->setFocus();

    }
    else
    {
        if(salary.toDouble()==false)
        {
            QMessageBox::critical( this, "Error", "Salary must have numeric value!", QMessageBox::Ok, 0 );
            this->ui->txtmonthlyPaidSalary->setText("");
            this->ui->txtmonthlyPaidSalary->setFocus();
        }
        else
        {
            //add to monthly paid employee map
            EmployeeMPaid e1 (name,dob,salary);
            MPmap.insert(MPMapIndex,e1);
            MPMapIndex++;

           //Empty the form to blank to register new employee
            QMessageBox::information( this, "Comfirmation", "Employee has added successfully!", QMessageBox::Ok, 0 );
             this->ui->txtmonthlyPaidName->setText("");
             this->ui->txtmonthlyPaidSocialSecuritynumber->setText("");
             this->ui->txtmonthlyPaidSalary->setText("");
             this->ui->txtmonthlyPaidName->setFocus();
        }

    }

}
