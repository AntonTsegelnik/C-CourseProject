#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"





void Expeditor::createGoods(std::list<Goods>& test)
{	
	int n;
	std::cout << "Выберите категорию товара для добавления:\n 1.Жидкости\n 2.Розничные\n";
	std::cin >> n;
	switch (n) {
	case 1: {
		Liquids product;
		product.setType("Liquids");
		product.setId(); std::cout << std::endl;
		product.setName(); std::cout << std::endl;
		product.setAmount(); std::cout << std::endl;	
		product.setAdmissionDate(); std::cout << std::endl;
		product.setShelfLife(); std::cout << std::endl;
		product.setBuildingId(); std::cout << std::endl;
		test.push_back(product);
		break;
	}
	case 2: {
		Retail product;
		product.setType("Retail");
		product.setId(); std::cout << std::endl;
		product.setName(); std::cout << std::endl;
		product.setAmount(); std::cout << std::endl;
		product.setAdmissionDate(); std::cout << std::endl;
		product.setShelfLife(); std::cout << std::endl;
		product.setBuildingId(); std::cout << std::endl;
		test.push_back(product);
		break;
	}
	}

}

void Expeditor::showGoods(std::list<Goods>& test)
{
	for (auto& item : test) {
		std::cout << " Идентификационный номер: " << item.getId() << std::endl;
		std::cout << " Тип товара: " << item.getType() << std::endl;
		std::cout << " Название товара: " << item.getName() << std::endl;
		std::cout << " Дата поступления на склад: " << item.getAdmissionDate() << std::endl;
		std::cout << " Дата окнчания срока годности: " << item.getShelfLife() << std::endl;
		std::cout << " Идентификационный номер склада: " << item.getBuildingId() << std::endl;
	}
}

void Expeditor::addGoodsToBuilding()
{

}

int Expeditor::getMenyType()
{
	return 1;
}
