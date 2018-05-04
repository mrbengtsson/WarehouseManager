#include "Truck.h"

Truck::Truck(std::string name, int capacity)
{
	this->name = name;
	this->destination = "None";
	this->goodsHandler = new GoodsHandler(capacity);
}

Truck::~Truck()
{
	delete this->goodsHandler;
}

std::string Truck::getName() const
{
	return this->name;
}

std::string Truck::getDestination() const
{
	return this->destination;
}

void Truck::setName(std::string name)
{
	this->name = name;
}

void Truck::setDestination(std::string destination)
{
	this->destination = destination;
}

void Truck::addGoods(Goods * goods) throw(...)
{
	this->goodsHandler->addGoods(goods);
}

Goods * Truck::getGoods(std::string name)
{
	return this->goodsHandler->getGoods(name);
}

int Truck::getNrOfGoods() const
{
	return this->goodsHandler->getNrOfGoods();
}

bool Truck::isFull() const
{
	return this->goodsHandler->isFull();
}
