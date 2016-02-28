/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman

  Salesman
  Read values from registration form, validate user input, calculate bonus and add to Salesman map

 */

#include "salesman.h"
#include "ui_salesman.h"
#include"global.h"
#include <QMessageBox>
salesMan::salesMan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::salesMan)
{
    ui->setupUi(this);
}

salesMan::~salesMan()
{
    delete ui;
}

void salesMan::on_btnCloseSalesman_clicked()
{
    this->close();
}



void salesMan::on_radioButtonNo_clicked()
{
     ui->txtSalesmanBonus->setEnabled(false);
}

void salesMan::on_radioButtonYes_clicked()
{
    ui->txtSalesmanBonus->setEnabled(true);
    ui->txtSalesmanBonus->setFocus();
}

void salesMan::on_btnAddSalesman_clicked()
{
    //Read values from registration form

     QString name = this->ui->txtSalesmanName->text();
     QString dob= this->ui->txtSalesmanSocialSecuritynumber->text();
     QString salary = this->ui->txtSalesmanSalary->text();
     QString bonus = this->ui->txtSalesmanBonus->text();

     if(name=="")
     {
         QMessageBox::critical( this, "Error", "Enter sales name!", QMessageBox::Ok, 0 );
         this->ui->txtSalesmanName->setFocus();
     }
     else if(dob=="")
     {
         QMessageBox::critical( this, "Error", "Enter salesman social security number!", QMessageBox::Ok, 0 );
         this->ui->txtSalesmanSocialSecuritynumber->setFocus();
     }
     else if(salary==""||salary.toDouble()==false)
     {   QMessageBox::critical( this, "Error", "Enter numeric value to Monthly Compensation!", QMessageBox::Ok, 0 );
         this->ui->txtSalesmanSalary->setText("");
         this->ui->txtSalesmanSalary->setFocus();

     }
     else if(this->ui->radioButtonYes->isChecked()&&bonus==""||bonus.toDouble()==false)
     {
         {   QMessageBox::critical( this, "Error", "Enter numeric value to salesman Bonus % !", QMessageBox::Ok, 0 );
             this->ui->txtSalesmanBonus->setText("");
             this->ui->txtSalesmanBonus->setFocus();

         }
     }
     else
     {
        //If salesman have Salary then Salary = Monthly salary + Bonus %
        if(this->ui->radioButtonYes->isChecked())
        {
         salary = QString::number(((salary.toDouble()*bonus.toDouble())/100)+salary.toDouble());
        }

         //add to monthly paid employee map
         EmployeeSalesman e1 (name,dob,salary);
         SMmap.insert(SMMapIndex,e1);
         SMMapIndex++;

        //Empty the form to blank to register new employee
         QMessageBox::information( this, "Comfirmation", "Sales man has added successfully!", QMessageBox::Ok, 0 );
          this->ui->txtSalesmanName->setText("");
          this->ui->txtSalesmanName->setFocus();
          this->ui->txtSalesmanSocialSecuritynumber->setText("");
          this->ui->txtSalesmanSalary->setText("");
          this->ui->radioButtonYes->isChecked();
          this->ui->txtSalesmanBonus->setText("");

     }
}
