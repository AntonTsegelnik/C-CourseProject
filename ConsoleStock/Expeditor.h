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
    void createGoods(std::list<std::unique_ptr<Goods>>& goods);
    void showGoods(std::list<std::unique_ptr<Goods>>& goods);
    void addGoodsToBuilding();
    int showMenu();
};

