#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"





void Expeditor::createGoods(std::list<std::unique_ptr<Goods>> &goods)
{	
	int n;
	std::cout << "Выберите категорию товара для добавления:\n 1.Жидкости\n 2.Розничные\n";
	std::cin >> n;
	switch (n) {
	case 1: {
		
		std::unique_ptr<Goods> ptr(new Liquids());
		(*ptr).setType("Жидкость");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(); std::cout << std::endl;
		goods.push_back(move(ptr));
		break;
	}
	case 2: {
		std::unique_ptr<Goods> ptr(new Retail());
		(*ptr).setType("Розница");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(); std::cout << std::endl;
		goods.push_back(move(ptr));
		break;
	}
	}

}


void Expeditor::showGoods(std::list<std::unique_ptr<Goods>>& goods)
{
	for (auto& item : goods) {
		std::cout<< std::endl;
		std::cout << "****************************************************" << std::endl;
		std::cout << " идентификационный номер: " << (*item).getId() << std::endl;
		std::cout << " тип товара: " << (*item).getType() << std::endl;
		std::cout << " название товара: " << (*item).getName() << std::endl;
		std::cout << " дата поступления на склад: " << (*item).getAdmissionDate() << std::endl;
		std::cout << " дата окнчания срока годности: " << (*item).getShelfLife() << std::endl;
		std::cout << " идентификационный номер склада: " << (*item).getBuildingId() << std::endl;
		std::cout << "****************************************************";
	}
}

void Expeditor::addGoodsToBuilding()
{

}

int Expeditor::getMenuType()
{
	return 1;
}
