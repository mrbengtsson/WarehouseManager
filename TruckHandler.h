#ifndef TRUCK_HANDLER_H
#define TRUCK_HANDLER_H

#include "Truck.h"

class TruckHandler
{
private:
	int capacity;
	int nrOfTrucks;
	Truck** truckList;
public:
	TruckHandler(int capacity);
	virtual ~TruckHandler();

	TruckHandler(const TruckHandler& other) = delete;
	bool operator=(const TruckHandler& other) const = delete;

	void addTruck(Truck* truck) throw(...);
	Truck* getTruck(std::string name);
	Truck* removeTruck(std::string name);
	int getNrOfTrucks() const;
	bool isFull() const;
};

#endif // !TRUCK_HANDLER_H
