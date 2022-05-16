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
	std::list<std::unique_ptr<Goods>> goods;
	std::list<std::unique_ptr<Building>> buildings;
	Storage _storage;
public:
	int authorization();
	void run();
	void showMenu(int x, int&choice);
};




