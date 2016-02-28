/*
Author: Tewodros Mengesha
email: teddy1496@yahoo.com
PERSONNELL MANAGEMENT APPLICATION for
 - Monthly Paid
 - Hourly Paid and
 - Salesman
*/

#include "global.h"
#include<QMap>

global::global()
{

}
//initializing map index
int MPMapIndex = -1;
int HPMapIndex = -1;
int SMMapIndex= -1;

QMap<int, EmployeeMPaid> MPmap; //Monthly paid employee Map
QMap<int, EmployeeHPaid> HPmap; //Hourly paid employee Map
QMap<int, EmployeeSalesman> SMmap; //Salesman Map
