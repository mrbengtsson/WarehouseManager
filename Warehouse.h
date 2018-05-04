#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "TruckHandler.h"
#include "GoodsHandler.h"

class Warehouse
{
private:
	std::string name;
	GoodsHandler* goodsHandler;
	TruckHandler* truckHandler;
public:
	Warehouse(std::string name, int goodsCapacity, int truckCapacity);
	virtual ~Warehouse();

	Warehouse(const Warehouse& other) = delete;
	bool operator=(const Warehouse& other) const = delete;

	std::string getName() const;
	void setName(std::string name);

	//From goodshandler
	void addGoods(Goods* goods) throw(...);
	Goods* getGoods(std::string name);
	Goods* removeGoods(std::string name);
	int getNrOfGoods() const;
	bool isFullWithGoods() const;

	//From truckhandler
	void addTruck(Truck* truck) throw(...);
	Truck* getTruck(std::string name);
	Truck* removeTruck(std::string name);
	int getNrOfTrucks() const;
	bool isFullWithTrucks() const;
};

#endif // !WAREHOUSE_H
