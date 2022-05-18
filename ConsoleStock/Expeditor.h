#pragma once
#include "User.h"
#include "Goods.h"
#include <list>
#include <memory>
#include <fstream>
#include "Building.h"

class Expeditor :
    public User
{
public:
    void createGoods(std::list<std::shared_ptr<Goods>>& goods, std::list<std::shared_ptr<Building>>& buildings);
    void showGoods(std::list<std::shared_ptr<Goods>>& goods);
    void saveInFile(std::list<std::shared_ptr<Goods>>& goods);
    friend void addGoodsToBuilding(std::shared_ptr<Goods>& goods, std::list<std::shared_ptr<Building>>& buildings);
    int showMenu() override;
    friend std::ostream& operator << (std::ostream& os, std::list<std::shared_ptr<Goods>>& goods);
    void editGoods(std::list<std::shared_ptr<Goods>>& goods);
    void deleteGoods(std::list<std::shared_ptr<Goods>>& goods, std::list<std::shared_ptr<Building>>& buildings);
    void searchGoods(std::list<std::shared_ptr<Goods>>& goods);
    void sortGoods(std::list<std::shared_ptr<Goods>>& goods);
};

 