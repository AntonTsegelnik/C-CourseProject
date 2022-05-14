#pragma once
#include "Goods.h"
#include <iostream>
class Liquids :
    public Goods
{
    void toThink() {

        std::cout << "hello" << std::endl;
    }
};

