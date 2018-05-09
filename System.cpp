#include "System.h"

System::System(int warehouseCapacity)
{
	this->warehouseHandler = new WarehouseHandler(warehouseCapacity);
	this->selectedWarehouse = nullptr;
	this->selectedTruck = nullptr;
    this->selectedGoods = nullptr;
}

System::~System()
{
	delete this->warehouseHandler;
}

void System::selectWarehouse(std::string name)
{
	this->selectedWarehouse = this->warehouseHandler->getWarehouse(name);
}

void System::addWarehouse(Warehouse * warehouse)
{
	this->warehouseHandler->addWarehouse(warehouse);
}

void System::removeWarehouse(std::string name)
{
	this->selectedWarehouse = this->warehouseHandler->removeWarehouse(name);
	delete this->selectedWarehouse;
	this->selectedWarehouse = nullptr;
}

Warehouse * System::getSelectedWarehouse() const
{
    return this->selectedWarehouse;
}

Truck * System::getSelectedTruck() const
{
	return this->selectedTruck;
}

Goods * System::getSelectedGoods() const
{
	return this->selectedGoods;
}

bool System::warehouseExists(std::string name) const
{
	return this->warehouseHandler->getWarehouse(name) != nullptr;
}

void System::selectTruck(std::string name)
{
	this->selectedTruck = this->selectedWarehouse->getTruck(name);
}

void System::selectGoods(std::string name, bool isWarehouse)
{
    if (isWarehouse)
	{
        this->selectedGoods = this->selectedWarehouse->getGoods(name);
	}
	else
    {
        this->selectedGoods = this->selectedTruck->getGoods(name);
	}
}

bool System::isWarehouseHandlerFull() const
{
	return this->warehouseHandler->isFull();
}
