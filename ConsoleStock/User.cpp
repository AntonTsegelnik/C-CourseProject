#include "User.h"
#include <iostream>
void User::showBuildings(std::list<std::shared_ptr<Building>>& buildings)
{
	for (auto& item : buildings) {

		std::cout << std::endl;
		std::cout << "*********************************************************************\n";
		std::cout << "Адрес:" << item.get()->getAddress() << std::endl;
		std::cout << "Идентификационный номер склада:" << item.get()->getId() << std::endl;
		std::cout << "\t\tТовары на складе: \n";
		if (!item.get()->getbGoods().empty()) {
			for (auto& i : item.get()->getbGoods()) {

				std::cout << "################################################################\n";

				std::cout << " идентификационный номер: " << i.get()->getId() << std::endl;
				std::cout << " тип товара: " << i.get()->getType() << std::endl;
				std::cout << " название товара: " << i.get()->getName() << std::endl;
				std::cout << " дата поступления на склад: " << i.get()->getAdmissionDate() << std::endl;
				std::cout << " дата окнчания срока годности: " << i.get()->getShelfLife() << std::endl;
				std::cout << " идентификационный номер склада: " << i.get()->getBuildingId() << std::endl;
			}
			std::cout << "*********************************************************************\n";
		}
		else {
			std::cout << "отсутствуют" << std::endl;
		}
	}
}