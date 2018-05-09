#include "Warehouse.h"

Warehouse::Warehouse(std::string name, int goodsCapacity, int truckCapacity)
{
	this->name = name;
	this->goodsHandler = new GoodsHandler(goodsCapacity);
	this->truckHandler = new TruckHandler(truckCapacity);
}

Warehouse::~Warehouse()
{
	delete this->goodsHandler;
	delete this->truckHandler;
}

std::string Warehouse::getName() const
{
	return this->name;
}

void Warehouse::setName(std::string name)
{
    this->name = name;
}

std::string *Warehouse::getAllGoodsNames() const
{
    return this->goodsHandler->getAllGoodsNames();
}

void Warehouse::addGoods(Goods * goods) throw(...)
{
	this->goodsHandler->addGoods(goods);
}

Goods * Warehouse::getGoods(std::string name)
{
	return this->goodsHandler->getGoods(name);
}

Goods * Warehouse::removeGoods(std::string name)
{
	return this->goodsHandler->removeGoods(name);
}

int Warehouse::getNrOfGoods() const
{
	return this->goodsHandler->getNrOfGoods();
}

bool Warehouse::isFullWithGoods() const
{
    return this->goodsHandler->isFull();
}

std::string *Warehouse::getAllTruckNames() const
{
    return this->truckHandler->getAllTruckNames();
}

void Warehouse::addTruck(Truck * truck) throw(...)
{
	this->truckHandler->addTruck(truck);
}

Truck * Warehouse::getTruck(std::string name)
{
	return this->truckHandler->getTruck(name);
}

Truck * Warehouse::removeTruck(std::string name)
{
	return this->truckHandler->removeTruck(name);
}

int Warehouse::getNrOfTrucks() const
{
	return this->truckHandler->getNrOfTrucks();
}

bool Warehouse::isFullWithTrucks() const
{
	return this->truckHandler->isFull();
}
