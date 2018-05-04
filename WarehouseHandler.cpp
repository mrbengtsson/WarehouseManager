#include "WarehouseHandler.h"

WarehouseHandler::WarehouseHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfWarehouses = 0;
	this->warehouseList = new Warehouse*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		this->warehouseList[i] = nullptr;
	}
}

WarehouseHandler::~WarehouseHandler()
{
	for (int i = 0; i < this->nrOfWarehouses; i++)
	{
		delete this->warehouseList[i];
	}

	delete[] this->warehouseList;
}

void WarehouseHandler::addWarehouse(Warehouse* warehouse) throw(...)
{
	if (this->nrOfWarehouses >= this->capacity)
	{
		throw std::exception("Array is full.");
	}

	this->warehouseList[this->nrOfWarehouses] = warehouse;
	this->nrOfWarehouses++;
}

Warehouse* WarehouseHandler::getWarehouse(std::string name)
{
	Warehouse* result = nullptr;

	for (int i = 0; i < this->nrOfWarehouses && result == nullptr; i++)
	{
		if (this->warehouseList[i]->getName() == name)
		{
			result = this->warehouseList[i];
		}
	}

	return result;
}

Warehouse * WarehouseHandler::removeWarehouse(std::string name)
{
	Warehouse* result = nullptr;

	for (int i = 0; i < this->nrOfWarehouses && result == nullptr; i++)
	{
		if (this->warehouseList[i]->getName() == name)
		{
			result = this->warehouseList[i];

			if (i == this->nrOfWarehouses - 1)
			{
				this->warehouseList[i] = nullptr;
			}
			else
			{
				this->warehouseList[i] = this->warehouseList[this->nrOfWarehouses - 1];
				this->warehouseList[this->nrOfWarehouses - 1] = nullptr;
			}

			this->nrOfWarehouses--;
		}
	}

	return result;
}

int WarehouseHandler::getNrOfWarehouses() const
{
	return this->nrOfWarehouses;
}

bool WarehouseHandler::isFull() const
{
	return this->nrOfWarehouses >= this->capacity;
}
