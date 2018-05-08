#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "failedadddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), system(new System(1, 2))
{
    ui->setupUi(this);

    this->loadWarehouseNames();
    lastPage = ui->stackedWidget->currentIndex();
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
   this->setCurrentPage(0);
}

void MainWindow::on_buttonNewWarehouse_clicked()
{
    this->setCurrentPage(1);
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
            this->setCurrentPage(0);
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
        this->setCurrentPage(2);
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

void MainWindow::on_pushButtonBackToWarehouse_4_clicked()
{
     this->setCurrentPage(2);
}

void MainWindow::on_pushButtonAddTruck_clicked()
{
    //destination name goodscapacity
    if(!this->system->getSelectedWarehouse()->isFullWithTrucks())
      {
         QString name = ui->lineEditNewTruckName->text();

        if (this->system->getSelectedWarehouse()->getTruck(name.toStdString()) ==nullptr)
        {
        QString name = ui->lineEditNewTruckName->text();
        QString destination = ui->lineEditNewTruckDestination->text();
        int Cap = ui->spinBoxTruckGoodsCap->value();
        Truck* truck = new Truck(name.toStdString(),Cap);
        truck->setDestination(destination.toStdString());
       this->system->getSelectedWarehouse()->addTruck(truck);
         ui->listWidgetWarehouseTrucks->addItem(name);
        }
    }
}

void MainWindow::on_pushButtonAddGoodsToWarehouseOrTruck_clicked()
{
     if(!this->system->getSelectedWarehouse()->isFullWithGoods())
       {
            QString name = ui->lineEditNewGoodsName->text();

            if(lastPage ==2)
            {
                if(this->system->getSelectedWarehouse()->getGoods(name.toStdString()) ==nullptr)
                {
                    QString destination = ui->lineEditNewGoodsDestination->text();
                    QString date = ui->dateEditNewGoodsDate->text();
                    double weight = ui->doubleSpinBoxNewGoodsWeight->text().toDouble();

                    Goods* goods = new Goods(name.toStdString());
                    this->system->getSelectedWarehouse()->addGoods(goods);
                    goods->setDestination(destination.toStdString());
                    goods->setExpirationDate(date.toStdString());
                    goods->setWeight(weight);
                    ui->listWidgetWarehouseGoods->addItem(name);

                }
            }
            else
            {
                if(this->system->getSelectedWarehouse()->getGoods(name.toStdString()) ==nullptr)
                {
                    QString destination = ui->lineEditNewGoodsDestination->text();
                    QString date = ui->dateEditNewGoodsDate->text();
                    double weight = ui->doubleSpinBoxNewGoodsWeight->text().toDouble();

                    Goods* goods = new Goods(name.toStdString());
                    this->system->getSelectedTruck()->addGoods(goods);
                    goods->setDestination(destination.toStdString());
                    goods->setExpirationDate(date.toStdString());
                    goods->setWeight(weight);
                    ui->listWidgetTruckGoods->addItem(name);
                }

            }

        }

}

void MainWindow::on_pushButtonBackToWarehouse_3_clicked()
{
    this->setCurrentPage(lastPage);
}

void MainWindow::setCurrentPage(int index)
{
    lastPage = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(index);
}
