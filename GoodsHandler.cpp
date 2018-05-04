#include "GoodsHandler.h"

GoodsHandler::GoodsHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfGoods = 0;
	this->goodsList = new Goods*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		this->goodsList[i] = nullptr;
	}
}

GoodsHandler::~GoodsHandler()
{
	for (int i = 0; i < this->nrOfGoods; i++)
	{
		delete this->goodsList[i];
	}

	delete[] this->goodsList;
}

void GoodsHandler::addGoods(Goods* goods) throw(...)
{
	if (this->nrOfGoods >= this->capacity)
	{
		throw std::exception("Array is full.");
	}

	this->goodsList[this->nrOfGoods] = goods;
	this->nrOfGoods++;
}

Goods* GoodsHandler::getGoods(std::string name)
{
	Goods* result = nullptr;

	for (int i = 0; i < this->nrOfGoods && result == nullptr; i++)
	{
		if (this->goodsList[i]->getName() == name)
		{
			result = this->goodsList[i];
		}
	}

	return result;
}

Goods * GoodsHandler::removeGoods(std::string name)
{
	Goods* result = nullptr;

	for (int i = 0; i < this->nrOfGoods && result == nullptr; i++)
	{
		if (this->goodsList[i]->getName() == name)
		{
			result = this->goodsList[i];

			if (i == this->nrOfGoods - 1)
			{
				this->goodsList[i] = nullptr;
			}
			else
			{
				this->goodsList[i] = this->goodsList[this->nrOfGoods - 1];
				this->goodsList[this->nrOfGoods - 1] = nullptr;
			}

			this->nrOfGoods--;
		}
	}

	return result;
}

int GoodsHandler::getNrOfGoods() const
{
	return this->nrOfGoods;
}

bool GoodsHandler::isFull() const
{
	return this->nrOfGoods >= this->capacity;
}
