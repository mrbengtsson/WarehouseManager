#include "TruckHandler.h"

TruckHandler::TruckHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfTrucks = 0;
	this->truckList = new Truck*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		this->truckList[i] = nullptr;
	}
}

TruckHandler::~TruckHandler()
{
	for (int i = 0; i < this->nrOfTrucks; i++)
	{
		delete this->truckList[i];
	}

    delete[] this->truckList;
}

std::string *TruckHandler::getAllTruckNames() const
{
    std::string* array = nullptr;

    if (this->nrOfTrucks > 0)
    {
        array = new std::string[this->nrOfTrucks];

        for (int i = 0; i < this->nrOfTrucks; ++i)
        {
            array[i] = this->truckList[i]->getName();
        }
    }

    return array;
}

void TruckHandler::addTruck(Truck* truck) throw(...)
{
	if (this->nrOfTrucks >= this->capacity)
	{
		throw std::exception("Array is full.");
	}

	this->truckList[this->nrOfTrucks] = truck;
	this->nrOfTrucks++;
}

Truck* TruckHandler::getTruck(std::string name)
{
	Truck* result = nullptr;

	for (int i = 0; i < this->nrOfTrucks && result == nullptr; i++)
	{
		if (this->truckList[i]->getName() == name)
		{
			result = this->truckList[i];
		}
	}

	return result;
}

Truck * TruckHandler::removeTruck(std::string name)
{
	Truck* result = nullptr;

	for (int i = 0; i < this->nrOfTrucks && result == nullptr; i++)
	{
		if (this->truckList[i]->getName() == name)
		{
			result = this->truckList[i];

			if (i == this->nrOfTrucks - 1)
			{
				this->truckList[i] = nullptr;
			}
			else
			{
				this->truckList[i] = this->truckList[this->nrOfTrucks - 1];
				this->truckList[this->nrOfTrucks - 1] = nullptr;
			}

			this->nrOfTrucks--;
		}
	}

	return result;
}

int TruckHandler::getNrOfTrucks() const
{
	return this->nrOfTrucks;
}

bool TruckHandler::isFull() const
{
	return this->nrOfTrucks >= this->capacity;
}
