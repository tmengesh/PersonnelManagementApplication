#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T23:01:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PersonnelManagementApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    monthlypaid.cpp \
    global.cpp \
    hourlypaid.cpp \
    salesman.cpp

HEADERS  += mainwindow.h \
    monthlypaid.h \
    global.h \
    hourlypaid.h \
    salesman.h

FORMS    += mainwindow.ui \
    monthlypaid.ui \
    hourlypaid.ui \
    salesman.ui
