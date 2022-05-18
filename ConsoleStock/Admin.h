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

    int showMenu() override;
    void createBuilding(std::list<std::shared_ptr<Building>> &buildings);
    void deleteBuilding(std::list<std::shared_ptr<Building>> &buildings, std::list<std::shared_ptr<Goods>>& goods);
  
};

