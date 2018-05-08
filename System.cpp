#include "System.h"

System::System(int databaseCapacity, int warehouseCapacity)
{
	this->databaseHandler = new DatabaseHandler(databaseCapacity);
	this->warehouseHandler = new WarehouseHandler(warehouseCapacity);
	this->selectedWarehouse = nullptr;
}

System::~System()
{
	delete this->databaseHandler;
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

bool System::isDatabaseHandlerFull() const
{
    return this->databaseHandler->isFull();
}

bool System::isWarehouseHandlerFull() const
{
    return this->warehouseHandler->isFull();
}

bool System::warehouseExists(std::string name) const
{
    return this->warehouseHandler->getWarehouse(name) != nullptr;
}
