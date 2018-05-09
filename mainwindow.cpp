#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "failedadddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), dialog(new FailedAddDialog(this)), system(new System())
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
   this->setCurrentPage(Page::SelectWarehouse);
}

void MainWindow::on_buttonNewWarehouse_clicked()
{
    this->setCurrentPage(Page::NewWarehouse);
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
            this->setCurrentPage(Page::SelectWarehouse);
        }
        else
        {
            dialog->setWindowTitle("Warehouse Already Exists");
            dialog->setDescription("A warehouse with that name already exists in the system.");
            QApplication::beep();
            dialog->exec();
        }
    }
    else
    {
        dialog->setWindowTitle("System Is Full");
        dialog->setDescription("The system has reached its limit on how many warehouses you can have.");
        QApplication::beep();
        dialog->exec();
    }
}

void MainWindow::on_buttonSelectWarehouse_clicked()
{
    if (ui->comboBoxWarehouse->currentIndex() >= 0)
    {
        this->system->selectWarehouse(ui->comboBoxWarehouse->currentText().toStdString());
        Warehouse* warehouse = this->system->getSelectedWarehouse();

        ui->listWidgetWarehouseTrucks->clear();
        ui->listWidgetWarehouseGoods->clear();

        std::string* truckNames = warehouse->getAllTruckNames();
        for (int i = 0; i < warehouse->getNrOfTrucks(); ++i) {
            ui->listWidgetWarehouseTrucks->addItem(truckNames[i].c_str());
        }
        delete[] truckNames;

        std::string* goodsNames = warehouse->getAllGoodsNames();
        for (int i = 0; i < warehouse->getNrOfGoods(); ++i) {
            ui->listWidgetWarehouseGoods->addItem(goodsNames[i].c_str());
        }
        delete[] goodsNames;

        ui->labelWarehouseName->setText((std::string("Warehouse: ") + warehouse->getName()).c_str());
        this->setCurrentPage(Page::CurrentWarehouse);
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
    this->setCurrentPage(Page::CurrentWarehouse);
}

void MainWindow::on_pushButtonAddTruck_clicked()
{
    if(!this->system->getSelectedWarehouse()->isFullWithTrucks())
      {
         QString name = ui->lineEditNewTruckName->text();

        if (this->system->getSelectedWarehouse()->getTruck(name.toStdString()) == nullptr)
        {
            QString destination = ui->lineEditNewTruckDestination->text();
            int goodsCapacity = ui->spinBoxTruckGoodsCap->value();

            Truck* truck = new Truck(name.toStdString(), goodsCapacity);
            truck->setDestination(destination.toStdString());

            this->system->getSelectedWarehouse()->addTruck(truck);
            ui->listWidgetWarehouseTrucks->addItem(name);

            this->setCurrentPage(Page::CurrentWarehouse);
        }
        else
        {
            dialog->setWindowTitle("Truck Already Exists");
            dialog->setDescription("A truck with that name already exists in the warehouse.");
            QApplication::beep();
            dialog->exec();
        }
    }
    else
    {
        dialog->setWindowTitle("Warehouse Is Full");
        dialog->setDescription("The selected warehouse can't store any more trucks.");
        QApplication::beep();
        dialog->exec();
    }
}

void MainWindow::on_pushButtonAddGoodsToWarehouseOrTruck_clicked()
{
    if (this->lastPage == Page::CurrentWarehouse)
    {
        if(!this->system->getSelectedWarehouse()->isFullWithGoods())
        {
            QString name = ui->lineEditNewGoodsName->text();

            if(this->system->getSelectedWarehouse()->getGoods(name.toStdString()) ==nullptr)
            {
                QString destination = ui->lineEditNewGoodsDestination->text();
                QString date = ui->dateEditNewGoodsDate->date().toString("yyyy.MM.dd");
                double weight = ui->doubleSpinBoxNewGoodsWeight->value();

                Goods* goods = new Goods(name.toStdString());
                goods->setDestination(destination.toStdString());
                goods->setExpirationDate(date.toStdString());
                goods->setWeight(weight);

                this->system->getSelectedWarehouse()->addGoods(goods);
                ui->listWidgetWarehouseGoods->addItem(name);

                this->setCurrentPage(Page::CurrentWarehouse);
            }
            else
            {
                dialog->setWindowTitle("Goods Already Exists");
                dialog->setDescription("A goods with that name already exists in the warehouse.");
                QApplication::beep();
                dialog->exec();
            }
        }
        else
        {
            dialog->setWindowTitle("Warehouse Is Full");
            dialog->setDescription("The selected warehouse can't store any more goods.");
            QApplication::beep();
            dialog->exec();
        }
    }
    else if (this->lastPage == Page::CurrentTruck)
    {
        if(!this->system->getSelectedTruck()->isFull())
        {
            QString name = ui->lineEditNewGoodsName->text();

            if(this->system->getSelectedTruck()->getGoods(name.toStdString()) ==nullptr)
            {
                QString destination = ui->lineEditNewGoodsDestination->text();
                QString date = ui->dateEditNewGoodsDate->date().toString("yyyy.MM.dd");
                double weight = ui->doubleSpinBoxNewGoodsWeight->value();

                Goods* goods = new Goods(name.toStdString());
                goods->setDestination(destination.toStdString());
                goods->setExpirationDate(date.toStdString());
                goods->setWeight(weight);

                this->system->getSelectedTruck()->addGoods(goods);
                ui->listWidgetTruckGoods->addItem(name);

                this->setCurrentPage(Page::CurrentTruck);
            }
            else
            {
                dialog->setWindowTitle("Goods Already Exists");
                dialog->setDescription("A goods with that name already exists in the truck.");
                QApplication::beep();
                dialog->exec();
            }
        }
        else
        {
            dialog->setWindowTitle("Truck Is Full");
            dialog->setDescription("The selected truck can't store any more goods.");
            QApplication::beep();
            dialog->exec();
        }
    }
    else
    {
        dialog->setWindowTitle("Error");
        dialog->setDescription("The last page you visited before this does not belong to a warehouse or truck. Sending you back to the main menu.");
        QApplication::beep();
        dialog->exec();

        this->setCurrentPage(Page::SelectWarehouse);
    }
}

void MainWindow::on_pushButtonBackToWarehouse_3_clicked()
{
    if (lastPage != Page::CurrentWarehouse && lastPage != Page::CurrentTruck) {
        dialog->setWindowTitle("Error");
        dialog->setDescription("The last page you visited before this does not belong to a warehouse or truck. Sending you back to the main menu.");
        QApplication::beep();
        dialog->exec();

        this->setCurrentPage(Page::SelectWarehouse);
    }
    else
    {
        this->setCurrentPage(lastPage);
    }
}

void MainWindow::setCurrentPage(int index)
{
    lastPage = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::on_pushButtonBackToTruck_clicked()
{
    ui->listWidgetTruckGoods->clear();
    ui->listWidgetWarehouseGoods->clear();

    Truck* truck = this->system->getSelectedTruck();
    Warehouse* warehouse = this->system->getSelectedWarehouse();

    std::string* truckGoods = truck->getAllGoodsNames();
    for (int i = 0; i < truck->getNrOfGoods(); ++i) {
        ui->listWidgetTruckGoods->addItem(truckGoods[i].c_str());
    }
    delete[] truckGoods;

    std::string* warehouseGoods = warehouse->getAllGoodsNames();
    for (int i = 0; i < warehouse->getNrOfGoods(); ++i) {
        ui->listWidgetWarehouseGoods->addItem(warehouseGoods[i].c_str());
    }
    delete[] warehouseGoods;


    this->setCurrentPage(Page::CurrentTruck);
}

void MainWindow::on_pushButtonNewTruck_clicked()
{
    this->setCurrentPage(Page::NewTruck);
}

void MainWindow::on_pushButtonWarehouseNewGoods_clicked()
{
    this->setCurrentPage(Page::NewGoods);
}

void MainWindow::on_pushButtonBackToMain_2_clicked()
{
    this->setCurrentPage(Page::SelectWarehouse);
}

void MainWindow::on_pushButtonWarehouseSelectGoods_clicked()
{
    if (ui->listWidgetWarehouseGoods->currentRow() >= 0)
    {
        QString name = ui->listWidgetWarehouseGoods->currentItem()->text();

        this->system->selectGoods(name.toStdString(), true);
        Goods* goods = this->system->getSelectedGoods();

        ui->lineEditGoodsDestination->setText(goods->getDestination().c_str());
        ui->dateEditGoodsDate->setDate(QDate::fromString(goods->getExpirationDate().c_str(), "yyyy.MM.dd"));
        ui->doubleSpinBoxGoodsWeight->setValue(goods->getWeight());

        ui->labelGoodsName->setText((std::string("Goods: ") + goods->getName()).c_str());
        this->setCurrentPage(Page::CurrentGoods);
    }
}

void MainWindow::on_pushButtonWarehouseRemoveGoods_clicked()
{
    if (ui->listWidgetWarehouseGoods->currentRow() >= 0)
    {
        delete this->system->getSelectedWarehouse()->removeGoods(ui->listWidgetWarehouseGoods->currentItem()->text().toStdString());
        delete ui->listWidgetWarehouseGoods->takeItem(ui->listWidgetWarehouseGoods->currentRow());
    }
}

void MainWindow::on_pushButtonSelectTruck_clicked()
{
    if (ui->listWidgetWarehouseTrucks->currentRow() >= 0)
    {
        QString name = ui->listWidgetWarehouseTrucks->currentItem()->text();

        this->system->selectTruck(name.toStdString());
        Truck* truck = this->system->getSelectedTruck();

        ui->lineEditTruckDestination->setText(truck->getDestination().c_str());

        ui->listWidgetTruckGoods->clear();

        std::string* goodsNames = truck->getAllGoodsNames();
        for (int i = 0; i < truck->getNrOfGoods(); ++i) {
            ui->listWidgetTruckGoods->addItem(goodsNames[i].c_str());
        }
        delete[] goodsNames;

        ui->labelTruckName->setText((std::string("Truck: ") + truck->getName()).c_str());
        this->setCurrentPage(Page::CurrentTruck);
    }
}

void MainWindow::on_pushButtonRemoveTruck_clicked()
{
    if (ui->listWidgetWarehouseTrucks->currentRow() >= 0)
    {
        delete this->system->getSelectedWarehouse()->removeTruck(ui->listWidgetWarehouseTrucks->currentItem()->text().toStdString());
        delete ui->listWidgetWarehouseTrucks->takeItem(ui->listWidgetWarehouseTrucks->currentRow());
    }
}

void MainWindow::on_pushButtonBackToWarehouse_clicked()
{
    this->setCurrentPage(Page::CurrentWarehouse);
}

void MainWindow::on_pushButtonTruckNewGoods_clicked()
{
    this->setCurrentPage(Page::NewGoods);
}

void MainWindow::on_pushButtonTruckMoveGoods_clicked()
{
    ui->listWidgetMoveTruckGoods->clear();
    ui->listWidgetMoveWarehouseGoods->clear();

    Truck* truck = this->system->getSelectedTruck();
    Warehouse* warehouse = this->system->getSelectedWarehouse();

    std::string* truckGoods = truck->getAllGoodsNames();
    for (int i = 0; i < truck->getNrOfGoods(); ++i) {
        ui->listWidgetMoveTruckGoods->addItem(truckGoods[i].c_str());
    }
    delete[] truckGoods;

    std::string* warehouseGoods = warehouse->getAllGoodsNames();
    for (int i = 0; i < warehouse->getNrOfGoods(); ++i) {
        ui->listWidgetMoveWarehouseGoods->addItem(warehouseGoods[i].c_str());
    }
    delete[] warehouseGoods;

    this->setCurrentPage(Page::MoveGoods);
}

void MainWindow::on_pushButtonTruckChangeDestination_clicked()
{
    this->system->getSelectedTruck()->setDestination(ui->lineEditTruckDestination->text().toStdString());
}

void MainWindow::on_pushButtonTruckSelectGoods_clicked()
{
    if (ui->listWidgetTruckGoods->currentRow() >= 0)
    {
        QString name = ui->listWidgetTruckGoods->currentItem()->text();

        this->system->selectGoods(name.toStdString(), false);
        Goods* goods = this->system->getSelectedGoods();

        ui->lineEditGoodsDestination->setText(goods->getDestination().c_str());
        ui->dateEditGoodsDate->setDate(QDate::fromString(goods->getExpirationDate().c_str(), "yyyy.MM.dd"));
        ui->doubleSpinBoxGoodsWeight->setValue(goods->getWeight());

        ui->labelGoodsName->setText((std::string("Goods: ") + goods->getName()).c_str());
        this->setCurrentPage(Page::CurrentGoods);
    }
}

void MainWindow::on_pushButtonTruckRemoveGoods_clicked()
{
    if (ui->listWidgetTruckGoods->currentRow() >= 0)
    {
        delete this->system->getSelectedTruck()->removeGoods(ui->listWidgetTruckGoods->currentItem()->text().toStdString());
        delete ui->listWidgetTruckGoods->takeItem(ui->listWidgetTruckGoods->currentRow());
    }
}

void MainWindow::on_pushButtonSaveGoods_clicked()
{
    if (lastPage != Page::CurrentWarehouse && lastPage != Page::CurrentTruck) {
        dialog->setWindowTitle("Error");
        dialog->setDescription("The last page you visited before this does not belong to a warehouse or truck. Sending you back to the main menu.");
        QApplication::beep();
        dialog->exec();

        this->setCurrentPage(Page::SelectWarehouse);
    }
    else
    {
        QString destination = ui->lineEditGoodsDestination->text();
        QString expDate = ui->dateEditGoodsDate->date().toString("yyyy.MM.dd");
        double weight = ui->doubleSpinBoxGoodsWeight->value();

        this->system->getSelectedGoods()->setDestination(destination.toStdString());
        this->system->getSelectedGoods()->setExpirationDate(expDate.toStdString());
        this->system->getSelectedGoods()->setWeight(weight);

        this->setCurrentPage(lastPage);
    }
}

void MainWindow::on_pushButtonBackToWarehouse_2_clicked()
{
    if (lastPage != Page::CurrentWarehouse && lastPage != Page::CurrentTruck) {
        dialog->setWindowTitle("Error");
        dialog->setDescription("The last page you visited before this does not belong to a warehouse or truck. Sending you back to the main menu.");
        QApplication::beep();
        dialog->exec();

        this->setCurrentPage(Page::SelectWarehouse);
    }
    else
    {
        this->setCurrentPage(lastPage);
    }
}

void MainWindow::on_pushButtonMoveToTruck_clicked()
{
    QList<QListWidgetItem*> list = ui->listWidgetMoveWarehouseGoods->selectedItems();

    for (int i = list.size() - 1; i >= 0; i--)
    {
        if (this->system->getSelectedTruck()->isFull()) {
            dialog->setWindowTitle("Truck Is Full");
            dialog->setDescription("The selected truck can't store any more goods.");
            QApplication::beep();
            dialog->exec();

            break;
        }

        Goods* goods = this->system->getSelectedWarehouse()->removeGoods(list[i]->text().toStdString());
        this->system->getSelectedTruck()->addGoods(goods);

        ui->listWidgetMoveTruckGoods->addItem(new QListWidgetItem(*list[i]));
        delete list[i];
    }
}

void MainWindow::on_pushButtonMoveToWarehouse_clicked()
{
    QList<QListWidgetItem*> list = ui->listWidgetMoveTruckGoods->selectedItems();

    for(int i = list.size() - 1; i >= 0; i--)
    {
        if (this->system->getSelectedWarehouse()->isFullWithGoods()) {
            dialog->setWindowTitle("Warehouse Is Full");
            dialog->setDescription("The selected warehouse can't store any more goods.");
            QApplication::beep();
            dialog->exec();

            break;
        }

        Goods* goods= this->system->getSelectedTruck()->removeGoods(list[i]->text().toStdString());
        this->system->getSelectedWarehouse()->addGoods(goods);

        ui->listWidgetMoveWarehouseGoods->addItem(new QListWidgetItem(*list[i]));
        delete list[i];
    }
}
