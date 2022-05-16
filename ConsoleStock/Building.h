#pragma once
#include<string>
#include<list>
#include<memory>
#include "Goods.h"
class Building
{
	int id;
	std::string address;
	std::list<std::unique_ptr<Goods>> bGoods;
public:
	Building() :id(0), address(""), bGoods(0) {};
	//Building(int i, std::string a, std::list<std::unique_ptr<Goods>> b) :id(i), address(a), bGoods(b) {};
	virtual void  toDo() = 0;
	int getId();
	void setId();
	std::string getAddress();
	void setAddress();
	std::list<std::unique_ptr<Goods>> getbGoods();
	void setbGoods(std::unique_ptr<Goods> a);

};

