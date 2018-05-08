#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "failedadddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), system(new System(1, 2))
{
    ui->setupUi(this);

    this->loadWarehouseNames();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadWarehouseNames()
{
    //TODO
}

void MainWindow::on_pushButtonBackToMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_buttonNewWarehouse_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonAddWarehouse_clicked()
{
    if (!this->system->isWarehouseHandlerFull())
    {
        QString name = ui->textWarehouseName->text();

        if (!this->system->warehouseExists(name.toStdString()))
        {
            int truckCap = ui->spinBoxWarehouseTruckCap->value();
            int goodsCap = ui->spinBoxWarehouseGoodsCap->value();

            Warehouse* warehouse = new Warehouse(name.toStdString(), goodsCap, truckCap);
            this->system->addWarehouse(warehouse);
            ui->comboBoxWarehouse->addItem(name);

            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            FailedAddDialog dialog;
            dialog.setWindowTitle("Warehouse Already Exists");
            dialog.setDescription("A warehouse with that name already exists in the system.");
            dialog.exec();
        }
    }
    else
    {
        FailedAddDialog dialog;
        dialog.setWindowTitle("System Is Full");
        dialog.setDescription("The system has reached its limit on how many warehouses you can have.");
        dialog.exec();
    }
}

void MainWindow::on_buttonSelectWarehouse_clicked()
{
    if (ui->comboBoxWarehouse->currentIndex() >= 0)
    {
        this->system->selectWarehouse(ui->comboBoxWarehouse->currentText().toStdString());
        QString name = this->system->getSelectedWarehouse()->getName().c_str();

        ui->labelWarehouseName->setText("Warehouse: " + name);
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_buttonRemoveWarehouse_clicked()
{
    if (ui->comboBoxWarehouse->currentIndex() >= 0)
    {
        this->system->removeWarehouse(ui->comboBoxWarehouse->currentText().toStdString());
        ui->comboBoxWarehouse->removeItem(ui->comboBoxWarehouse->currentIndex());
    }
}
