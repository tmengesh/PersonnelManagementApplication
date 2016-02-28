#include "mpemployeelist.h"
#include "ui_mpemployeelist.h"
#include"global.h"
#include<QMessageBox>
#include <QMap>
#include<QMapIterator>
#include<QDebug>
#include<QMessageBox>
MPEmployeeList::MPEmployeeList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MPEmployeeList)
{
    ui->setupUi(this);
}

MPEmployeeList::~MPEmployeeList()
{
    delete ui;
}







void MPEmployeeList::on_listWidgetMP_clicked(const QModelIndex &index)
{
     QMessageBox::information( this, "Form on load", "Clicked!", QMessageBox::Ok, 0 );
}

void MPEmployeeList::on_listWidgetMP_activated(const QModelIndex &index)
{
    QMessageBox::information( this, "Form on load", "Activated!", QMessageBox::Ok, 0 );
}

void MPEmployeeList::on_MPEmployeeList_accepted()
{
       QMessageBox::information( this, "Form on load", "Formon load!", QMessageBox::Ok, 0 );
    //    QMapIterator<int, EmployeeMPaid> mi(MPmap);
    //    while ( mi.hasNext() )
    //    {
    //      mi.next();

    //      this->ui->listWidgetMP->addItem(mi.value().name()+ " " + mi.value().socialSecurityNumber() + " " + mi.value().salary());

    //             //( + " " + mi.value().socialSecurityNumber() + " " + mi.value().salary());

    //      //qDebug() << mi.key() << ":" << mi.value().name() << mi.value().socialSecurityNumber() << mi.value().salary();
    //    }
}
