#pragma once
#include "User.h"
#include <list>
#include "Building.h"
#include "Stock.h"
#include "Storehouse.h"
class Admin :
    public User
{
public:

    int showMenu();
    void createBuilding(std::list<std::shared_ptr<Building>> &buildings);
  
};

