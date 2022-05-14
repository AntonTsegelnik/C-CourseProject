#pragma once
#include"Goods.h"
#include"Building.h"
#include"Liquids.h"
#include <list>
#include "User.h"
#include "Expeditor.h"

class App
{	

	std::list<Goods> goods;
	std::list<Building> buildings;
	
	void authorithation();
};




