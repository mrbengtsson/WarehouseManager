#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "System.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonBackToMain_clicked();

    void on_buttonNewWarehouse_clicked();

    void on_pushButtonAddWarehouse_clicked();

    void on_buttonSelectWarehouse_clicked();

    void on_buttonRemoveWarehouse_clicked();

    void on_pushButtonBackToWarehouse_4_clicked();

    void on_pushButtonAddTruck_clicked();

    void on_pushButtonAddGoodsToWarehouseOrTruck_clicked();

    void on_pushButtonBackToWarehouse_3_clicked();


private:
    Ui::MainWindow *ui;
    System* system;
    int lastPage;

    void setCurrentPage(int index);
    void loadWarehouseNames();
};

#endif // MAINWINDOW_H
