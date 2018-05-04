#ifndef GOODS_H
#define GOODS_H

#include <string>

class Goods
{
private:
	std::string name;
	float weight;
	std::string expirationDate;
	std::string destination;
public:
	Goods(std::string name, float weight = 0);
	virtual ~Goods();

	std::string getName() const;
	float getWeight() const;
	std::string getExpirationDate() const;
	std::string getDestination() const;
	void setName(std::string name);
	void setWeight(float weight);
	void setExpirationDate(std::string expirationDate);
	void setDestination(std::string destination);
};

#endif // !GOODS_H
