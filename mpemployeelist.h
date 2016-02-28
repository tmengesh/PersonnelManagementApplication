#ifndef MPEMPLOYEELIST_H
#define MPEMPLOYEELIST_H

#include <QDialog>

namespace Ui {
class MPEmployeeList;
}

class MPEmployeeList : public QDialog
{
    Q_OBJECT

public:
    explicit MPEmployeeList(QWidget *parent = 0);
    ~MPEmployeeList();

private slots:




    void on_listWidgetMP_clicked(const QModelIndex &index);

    void on_listWidgetMP_activated(const QModelIndex &index);

    void on_MPEmployeeList_accepted();

private:
    Ui::MPEmployeeList *ui;
};

#endif // MPEMPLOYEELIST_H
