#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "System.h"
#include "failedadddialog.h"

namespace Ui {
class MainWindow;
}

enum Page
{
    SelectWarehouse,
    NewWarehouse,
    CurrentWarehouse,
    CurrentTruck,
    CurrentGoods,
    NewGoods,
    NewTruck,
    MoveGoods
};

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


    void on_pushButtonBackToTruck_clicked();

    void on_pushButtonNewTruck_clicked();

    void on_pushButtonWarehouseNewGoods_clicked();

    void on_pushButtonBackToMain_2_clicked();

    void on_pushButtonWarehouseSelectGoods_clicked();

    void on_pushButtonWarehouseRemoveGoods_clicked();

    void on_pushButtonSelectTruck_clicked();

    void on_pushButtonRemoveTruck_clicked();

    void on_pushButtonBackToWarehouse_clicked();

    void on_pushButtonTruckNewGoods_clicked();

    void on_pushButtonTruckMoveGoods_clicked();

    void on_pushButtonTruckChangeDestination_clicked();

    void on_pushButtonTruckSelectGoods_clicked();

    void on_pushButtonTruckRemoveGoods_clicked();

    void on_pushButtonSaveGoods_clicked();

    void on_pushButtonBackToWarehouse_2_clicked();

    void on_pushButtonMoveToTruck_clicked();

    void on_pushButtonMoveToWarehouse_clicked();

private:
    Ui::MainWindow *ui;
    FailedAddDialog* dialog;
    System* system;
    int lastPage;

    void setCurrentPage(int index);
    void loadWarehouseNames();
};

#endif // MAINWINDOW_H
