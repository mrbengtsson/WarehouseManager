#ifndef SYSTEM_H
#define SYSTEM_H

#include "WarehouseHandler.h"

class System
{
private:
	WarehouseHandler* warehouseHandler;

	Warehouse* selectedWarehouse;
	Truck* selectedTruck;
	Goods* selectedGoods;
public:
    System(int warehouseCapacity = 10);
	virtual ~System();

	void selectWarehouse(std::string name);
	void addWarehouse(Warehouse* warehouse);
	void removeWarehouse(std::string name);
	bool warehouseExists(std::string name) const;

	void selectTruck(std::string name);
    void selectGoods(std::string name, bool isWarehouse);

	Warehouse* getSelectedWarehouse() const;
	Truck* getSelectedTruck() const;
	Goods* getSelectedGoods() const;

    bool isDatabaseHandlerFull() const;
    bool isWarehouseHandlerFull() const;
};

#endif // !SYSTEM_H
