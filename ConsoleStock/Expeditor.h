#pragma once
#include "User.h"
#include "Goods.h"
#include <list>

class Expeditor :
    public User
{
public:
    void createGoods(std::list<Goods>&test);
    void showGoods(std::list<Goods>&test);
    void addGoodsToBuilding();
    int getMenyType();
};

