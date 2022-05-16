#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"
#include "Input.h"
#include "Stock.h"
#include "Storehouse.h"
//#include <synchapi.h>





void Expeditor::createGoods(std::list<std::shared_ptr<Goods>> &goods, std::list<std::shared_ptr<Building>>& buildings)
{
	
	int n;
	std::cout << "Выберите категорию товара для добавления:\n 1.Жидкости\n 2.Розничные\n";
	std::cin >> n;
	switch (n) {
	case 1: {
		
		std::shared_ptr<Goods> ptr(new Liquids());
		(*ptr).setType("Жидкость");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(1); std::cout << std::endl;
		goods.push_back(ptr);
		std::cout << "Идет добавление товара в Stock..." << std::endl;
		//Sleep(3000);
		addGoodsToBuilding(ptr, buildings);
		

		break;
	}
	case 2: {
		std::shared_ptr<Goods> ptr(new Retail());
		(*ptr).setType("Розница");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(2); std::cout << std::endl;
		goods.push_back(ptr);
		std::cout << "Идет добавление товара в Storehouse..." << std::endl;		
		addGoodsToBuilding(ptr, buildings);
	//	Sleep(3000);
		break;
	}
	}

}


void Expeditor::showGoods(std::list<std::shared_ptr<Goods>>& goods)
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

void Expeditor::saveInFile(std::list<std::shared_ptr<Goods>>& goods)
{
	std::fstream inFile;
	inFile.open("goods.dat", std::ios::out | std::ios::trunc);
	if (inFile.is_open()) {
		inFile << goods;
		inFile.close();
		std::cout << "Данные успешно записаны\n";
	}
	else {
		std::cout << "Файл не удалось открыть\n";
	}
}

 void Expeditor::addGoodsToBuilding(std::shared_ptr<Goods> & goods, std::list<std::shared_ptr<Building>>& buildings)
{
	

	for (auto& item : buildings) {
		if (item.get()->getId() == (*goods).getBuildingId()) {
			item.get()->setbGoods(goods);
		}
	}

}



int Expeditor::showMenu()
{
	int choice;
	bool exit = false;

	
		INPUT
		(
			std::cout
			<< "\t\tМеню\n"
			<< "\t*****************************************************\n"
			<< "\t1. Создать товар в базе данных\n"
			<< "\t2. Вывод отчета\n"
			<< "\t3. Просмотр всех складов\n"
			<< "\t4. Редактирование содержимого\n"
			<< "\t5. Сохранить информацию в файл\n"
			<< "\t6. Сортировка публикаций по цене\n"
			<< "\t7. Поиск публикации\n"
			<< "\t0. Выход\n"
			<< "\t*****************************************************\n",
			choice
		);
		return choice;
}



std::ostream& operator<<(std::ostream& os, std::list<std::shared_ptr<Goods>>& goods)
{
	for (const auto& i : goods)
	{
		os <<i.get()->getId() << " " << i.get()->getType() << " " << i.get()->getName() << " "
			<< i.get()->getAdmissionDate() << " " << i.get()->getShelfLife() << " " << i.get()->getBuildingId()<<"\n&"<<std:: endl;
	}
	return os;
}
