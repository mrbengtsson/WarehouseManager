#ifndef WAREHOUSE_HANDLER_H
#define WAREHOUSE_HANDLER_H

#include "Warehouse.h"

class WarehouseHandler
{
private:
	int capacity;
	int nrOfWarehouses;
	Warehouse** warehouseList;
public:
	WarehouseHandler(int capacity);
	virtual ~WarehouseHandler();

	WarehouseHandler(const WarehouseHandler& other) = delete;
	bool operator=(const WarehouseHandler& other) const = delete;

    std::string* getAllWarehouseNames() const;

	void addWarehouse(Warehouse* warehouse) throw(...);
	Warehouse* getWarehouse(std::string name);
	Warehouse* removeWarehouse(std::string name);
	int getNrOfWarehouses() const;
	bool isFull() const;
};

#endif // !WAREHOUSE_HANDLER_H
