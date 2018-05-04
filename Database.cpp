#include "Database.h"

Database::Database(std::string name, int capacity)
{
	this->name = name;
	this->goodsHandler = new GoodsHandler(capacity);
}

Database::~Database()
{
	delete this->goodsHandler;
}

std::string Database::getName() const
{
	return this->name;
}

void Database::setName(std::string name)
{
	this->name = name;
}

void Database::addGoods(Goods * goods) throw(...)
{
	this->goodsHandler->addGoods(goods);
}

Goods * Database::getGoods(std::string name)
{
	return this->goodsHandler->getGoods(name);
}

int Database::getNrOfGoods() const
{
	return this->goodsHandler->getNrOfGoods();
}

bool Database::isFull() const
{
	return this->goodsHandler->isFull();
}
