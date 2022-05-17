#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"
#include "Input.h"
#include "Stock.h"
#include "Storehouse.h"
#include <algorithm>


std::ostream& operator<<(std::ostream& os, std::list<std::shared_ptr<Goods>>& goods)
{
	for (const auto& i : goods)
	{
		os << i.get()->getId() << " " << i.get()->getType() << " " << i.get()->getName() << " "
			<< i.get()->getAdmissionDate() << " " << i.get()->getShelfLife() << " " << i.get()->getBuildingId() << "\n&" << std::endl;
	}
	return os;
}
void addGoodsToBuilding(std::shared_ptr<Goods>& goods, std::list<std::shared_ptr<Building>>& buildings)
{
	for (auto& item : buildings) {
		if (item.get()->getId() == (*goods).getBuildingId()) {
			item.get()->setbGoods(goods);
		}
	}
}

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




int Expeditor::showMenu()
{
	int choice;
	bool exit = false;

	
		INPUT
		(
			std::cout
			<< "\t\tМеню\n"
			<< "\t*****************************************\n"
			<< "\t|1. Создать товар в базе данных        |\n"
			<< "\t|2. Вывод отчета о всех товарах        |\n"
			<< "\t|3. Просмотр всех складов              |\n"
			<< "\t|4. Редактирование данных о товаре     |\n "
			<< "\t|5. Удаление товара из базы данных     |\n "
			<< "\t|6. Сортировка публикаций по цене      |\n "
			<< "\t|7. Поиск публикации					 |\n "
			<< "\t|0. Выход                              |\n "
			<< "\t*****************************************\n",
			choice
		);
		return choice;
}

void Expeditor::editGoods(std::list<std::shared_ptr<Goods>>& goods)
{	
	int find = false;
	int exit = false;
	std::string n ="  \n\n|========================================|\
						\n|1. Изменить идентификационный номер     |\
						\n|2. Изменить название                    |\
						\n|3. Изменить дату поступления на склад   |\
						\n|4. Изменить дату окнчания срока годности|\
						\n|0. Выйти                                |\
					    \n|========================================|\n";
	int id;
	int choice;
	std::cout << "Id товара для изменения: \n";
	std::cin >> id;
	for (auto& item : goods) {
		if (item.get()->getId() == id) {
			find = true;
			while (!exit) {
				INPUT(
					std::cout
					<< n,
					choice
				);
				switch (choice)
				{
				case 1:
					item.get()->setId();
					std::cout << "Данные успешно изменены\n";
					system("cls");
					break;
				case 2:
					item.get()->setName();
					std::cout << "Данные успешно изменены\n";
					system("cls");
					break;
				case 3:
					item.get()->setAdmissionDate();
					std::cout << "Данные успешно изменены\n";
					system("cls");

					break;
				case 4:
					item.get()->setShelfLife();
					std::cout << "Данные успешно изменены\n";
					system("cls");
					break;
				case 0:
					exit = true;
					return;
				}
			}
			
		}
		//if (find==0) std::cout << "Нет такого товара\n ";
		throw std::exception("Нет такого товара");
	}

}

void Expeditor::deleteGoods(std::list<std::shared_ptr<Goods>>& goods, std::list<std::shared_ptr<Building>>& buildings)
{	
	int find = false;
	std::list<std::shared_ptr<Goods>>::iterator item = goods.begin();
	int id;
	std::cout << "Id товара для удаления: \n";
	std::cin >> id;
	for (; item != goods.end(); item++) {
		if (item->get()->getId() == id) {
			goods.erase(item);
			std::cout << "Данные успешно удалены\n";
			find = true;
			break;
		}
	}

	for (auto& item : buildings) {
		auto it = find_if(item->getbGoods().begin(), item->getbGoods().end(), [id](const std::shared_ptr<Goods>& w) {return w->getId() == id; });
		if (it != item->getbGoods().end()) {
			item->getbGoods().erase(it);
		}
	}
	
	if (find == 0) { "Товар не найден\n"; }
}

void Expeditor::searchGoods(std::list<std::shared_ptr<Goods>>& goods)
{
	for (auto& item : goods) {

	}
}






