#pragma once
#include "Goods.h"
class Retail :
    public Goods
{
    
    void toThink() {
        setAmount();
    };
};

Retail a;
