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
		std::cout << "Идентификационный номер:";
		product.setId(); std::cout << std::endl;
		std::cout << "Наименование:";
		product.setName(); std::cout << std::endl;
		std::cout << "Количество:";
		product.setAmount(); std::cout << std::endl;
		std::cout << "Дата поступления на склад:";
		product.setAdmissionDate(); std::cout << std::endl;
		std::cout << "Истечение срока годности:";
		product.setShelfLife(); std::cout << std::endl;
		std::cout << "Идентификационный номер склада:";
		product.setBuildingId(); std::cout << std::endl;
		test.push_back(product);
		break;
	}
	case 2: {
		Retail thing;
		std::cout << "Идентификационный номер:";
		thing.setId(); std::cout << std::endl;
		std::cout << "Наименование:";
		thing.setName(); std::cout << std::endl;
		std::cout << "Количество:";
		thing.setAmount(); std::cout << std::endl;
		std::cout << "Дата поступления на склад:";
		thing.setAdmissionDate(); std::cout << std::endl;
		std::cout << "Истечение срока годности:";
		thing.setShelfLife(); std::cout << std::endl;
		std::cout << "Идентификационный номер склада:";
		thing.setBuildingId(); std::cout << std::endl;
		test.push_back(thing);
		break;
	}
	}

}

void Expeditor::addGoodsToBuilding()
{

}
