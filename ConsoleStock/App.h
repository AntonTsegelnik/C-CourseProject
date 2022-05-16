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
	std::list<std::shared_ptr<Goods>> goods;
	std::list<std::shared_ptr<Building>> buildings;
	Storage _storage;
public:
	int authorization();
	void run();
};




