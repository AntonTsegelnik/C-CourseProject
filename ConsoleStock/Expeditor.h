#pragma once
#include "User.h"
#include "Goods.h"
#include <list>
class Expeditor :
    public User
{
    void createGoods(std::list<Goods>&test);
    void addGoodsToBuilding();
    int getMenyType();
};

