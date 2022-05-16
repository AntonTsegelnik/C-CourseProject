#pragma once
#include "User.h"
#include "Goods.h"
#include <list>
#include <memory>
#include "Building.h"

class Expeditor :
    public User
{
public:
    void createGoods(std::list<std::shared_ptr<Goods>>& goods, std::list<std::shared_ptr<Building>>& buildings);
    void showGoods(std::list<std::shared_ptr<Goods>>& goods);
    static void addGoodsToBuilding(std::shared_ptr<Goods>& goods, std::list<std::shared_ptr<Building>>& buildings);
    int showMenu();
};

