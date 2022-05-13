#pragma once
#include "Goods.h"
#include <iostream>
class Liquids :
    public Goods
{
    void toThink() {
        id = 1;
        std::cout << "hello" << std::endl;
    }
};

