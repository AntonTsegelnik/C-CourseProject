#pragma once
#include <list>
#include <memory>
#include "Building.h"
class User
{
public:
	virtual int showMenu() = 0;
	void showBuildings(std::list<std::shared_ptr<Building>>& buildings);
};

