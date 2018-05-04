#ifndef DATABASE_H
#define DATABASE_H

#include "GoodsHandler.h"

class Database
{
private:
	std::string name;
	GoodsHandler* goodsHandler;
public:
	Database(std::string name, int capacity);
	virtual ~Database();

	Database(const Database& other) = delete;
	bool operator=(const Database& other) const = delete;

	std::string getName() const;
	void setName(std::string name);

	//From goodsHandler
	void addGoods(Goods* goods) throw(...);
	Goods* getGoods(std::string name);
	int getNrOfGoods() const;
	bool isFull() const;

};

#endif // !DATABASE_H
