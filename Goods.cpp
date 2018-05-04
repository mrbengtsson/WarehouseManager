#include "Goods.h"

Goods::Goods(std::string name, float weight)
{
	this->name = name;
	this->weight = weight;
	this->expirationDate = "None";
	this->destination = "None";
}

Goods::~Goods()
{
}

std::string Goods::getName() const
{
	return this->name;
}

float Goods::getWeight() const
{
	return this->weight;
}

std::string Goods::getExpirationDate() const
{
	return this->expirationDate;
}

std::string Goods::getDestination() const
{
	return this->destination;
}

void Goods::setName(std::string name)
{
	this->name = name;
}

void Goods::setWeight(float weight)
{
	this->weight = weight;
}

void Goods::setExpirationDate(std::string expirationDate)
{
	this->expirationDate = expirationDate;
}

void Goods::setDestination(std::string destination)
{
	this->destination = destination;
}
