#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"
#include "Input.h"





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
			<< "\t3. Удаление данных из отчета\n"
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
