/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#ifndef GLOBAL_H
#define GLOBAL_H
#include<QMap>
#include"monthlypaid.h"
#include"hourlypaid.h"
#include"salesman.h"
class global
{
public:
    global();
};
extern int MPMapIndex;
extern int HPMapIndex;
extern int SMMapIndex;
extern QMap<int, EmployeeMPaid> MPmap;
extern QMap<int, EmployeeHPaid> HPmap;
extern QMap<int, EmployeeSalesman> SMmap;
#endif // GLOBAL_H
