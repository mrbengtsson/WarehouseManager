#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H

#include "Goods.h"

class GoodsHandler
{
private:
	int capacity;
	int nrOfGoods;
	Goods** goodsList;
public:
	GoodsHandler(int capacity);
	virtual ~GoodsHandler();

	GoodsHandler(const GoodsHandler& other) = delete;
	bool operator=(const GoodsHandler& other) const = delete;

	void addGoods(Goods* goods) throw(...);
	Goods* getGoods(std::string name);
	Goods* removeGoods(std::string name);
	int getNrOfGoods() const;
	bool isFull() const;
};

#endif // !GOODS_HANDLER_H
