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

private:
    Ui::MainWindow *ui;
    System* system;

    void loadWarehouseNames();
};

#endif // MAINWINDOW_H
