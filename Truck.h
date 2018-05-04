#ifndef TRUCK_H
#define TRUCK_H

#include "GoodsHandler.h"

class Truck
{
private:
	std::string name;
	std::string destination;
	GoodsHandler* goodsHandler;
public:
	Truck(std::string name, int capacity);
	virtual ~Truck();

	Truck(const Truck& other) = delete;
	bool operator=(const Truck& other) const = delete;

	std::string getName() const;
	std::string getDestination() const;
	void setName(std::string name);
	void setDestination(std::string destination);

	//From goodsHandler
	void addGoods(Goods* goods) throw(...);
	Goods* getGoods(std::string name);
	int getNrOfGoods() const;
	bool isFull() const;
};

#endif // !TRUCK_H
