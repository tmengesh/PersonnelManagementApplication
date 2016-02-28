/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h";
#include <QApplication>
#include <QMap>
#include<QMapIterator>
#include<QMessageBox>
#include<QWidget>
#include <QListWidget>
#include<monthlypaid.h>

#include<QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionMonthly_paid_employee_triggered()
{
    monthlyPaidForm.show();
}

void MainWindow::on_actionHourly_Employee_List_triggered()
{
    // View Monthly Paid registration form. If the list is empty display a dialog box saying there is no employee record
    if(MPMapIndex==-1)
    {
         QMessageBox::critical( this, "Error", "Monthly paid employee record is empty", QMessageBox::Ok, 0 );
    }

    //else display monthly paid employee's list from map
    else{

        QDialog MPEmployeListWindow;

        MPEmployeListWindow.setFixedSize(365, 240);
        QListWidget *listMP = new QListWidget(&MPEmployeListWindow);
        listMP->setFixedWidth(360);
        listMP->addItem("FullName   SocialSecurityNumber  MonthlyCompensation");
        QMapIterator<int, EmployeeMPaid> mi(MPmap);
        while ( mi.hasNext() )
        {
          mi.next();
          listMP->addItem( mi.value().name()+ "      " + mi.value().socialSecurityNumber() + "     " + mi.value().salary());
        }

       MPEmployeListWindow.exec();
       }

}

void MainWindow::on_actionHourly_paid_employee_triggered()
{
    hourlyPaidForm.show();
}

void MainWindow::on_actionHourly_Paid_Employee_List_triggered()
{
    // View Hourly Paid registration form. If the list is empty display a dialog box saying there is no employee record
    if(HPMapIndex==-1)
    {
         QMessageBox::critical( this, "Error", "Hourly paid employee record is empty", QMessageBox::Ok, 0 );
    }
    else{

        QDialog HPEmployeListWindow;

        HPEmployeListWindow.setFixedSize(365, 240);
        QListWidget *listHP = new QListWidget(&HPEmployeListWindow);
        listHP->setFixedWidth(360);
        listHP->addItem("FullName   Social Security Number   HourlyCompensation   DoneHours   Salary");

        QMapIterator<int, EmployeeHPaid> mi(HPmap);
        while ( mi.hasNext() )
        {
          mi.next();
          listHP->addItem( mi.value().name()+ "    " + mi.value().socialSecurityNumber()
               + "           " + mi.value().hourlyCompensation() + "          " + mi.value().doneHours()+
               "          " + mi.value().salary());
        }
       listHP->addItem(" \n \n \n N.B Salary is calculated as  HourlyCompensation * DoneHours");
       HPEmployeListWindow.exec();
       }
}

void MainWindow::on_actionSalesman_triggered()
{
    salesManForm.show();
}

void MainWindow::on_actionSalesman_List_triggered()
{
    // View Monthly Paid registration form. If the list is empty display a dialog box saying there is no employee record
    if(SMMapIndex==-1)
    {
         QMessageBox::critical( this, "Error", "Salesman record is empty", QMessageBox::Ok, 0 );
    }

    //else display monthly paid employee's list from map
    else{

        QDialog SMEmployeListWindow;

        SMEmployeListWindow.setFixedSize(365, 240);
        QListWidget *listSM = new QListWidget(&SMEmployeListWindow);
        listSM->setFixedWidth(360);
        listSM->addItem("Full Name           SocialSecurityNumber      MonthlyCompensation");
        QMapIterator<int, EmployeeSalesman> mi(SMmap);
        while ( mi.hasNext() )
        {
          mi.next();
          listSM->addItem( mi.value().name()+ "      " + mi.value().socialSecurityNumber() + "              " + mi.value().salary());
        }
      listSM->addItem(" \n \n \n N.B Monthly compensation raised by the bonus % if the outcome claim comes true");
      SMEmployeListWindow.exec();
       }

}

void MainWindow::on_actionE_xit_triggered()
{
    this->close();
}
