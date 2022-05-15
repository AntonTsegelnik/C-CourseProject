#pragma once
#include"Goods.h"
#include"Building.h"
#include"Liquids.h"
#include <list>
#include "User.h"
#include "Expeditor.h"
#include "Storage.h"


class App
{	
	std::list<Goods> goods;
//	std::list<Building> buildings;
	Storage _storage;
public:
	int authorithation();
	void run();
	void showMenu(int x, int&choice);
};




