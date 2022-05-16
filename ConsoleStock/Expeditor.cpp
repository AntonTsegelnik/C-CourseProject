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
	std::cout << "�������� ��������� ������ ��� ����������:\n 1.��������\n 2.���������\n";
	std::cin >> n;
	switch (n) {
	case 1: {
		
		std::shared_ptr<Goods> ptr(new Liquids());
		(*ptr).setType("��������");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(1); std::cout << std::endl;
		goods.push_back(ptr);
		std::cout << "���� ���������� ������ � Stock..." << std::endl;
		//Sleep(3000);
		addGoodsToBuilding(ptr, buildings);
		

		break;
	}
	case 2: {
		std::shared_ptr<Goods> ptr(new Retail());
		(*ptr).setType("�������");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(2); std::cout << std::endl;
		goods.push_back(ptr);
		std::cout << "���� ���������� ������ � Storehouse..." << std::endl;		
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
		std::cout << " ����������������� �����: " << (*item).getId() << std::endl;
		std::cout << " ��� ������: " << (*item).getType() << std::endl;
		std::cout << " �������� ������: " << (*item).getName() << std::endl;
		std::cout << " ���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
		std::cout << " ���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
		std::cout << " ����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
		std::cout << "****************************************************";
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
			<< "\t\t����\n"
			<< "\t*****************************************************\n"
			<< "\t1. ������� ����� � ���� ������\n"
			<< "\t2. ����� ������\n"
			<< "\t3. �������� ���� �������\n"
			<< "\t4. �������������� �����������\n"
			<< "\t5. ��������� ���������� � ����\n"
			<< "\t6. ���������� ���������� �� ����\n"
			<< "\t7. ����� ����������\n"
			<< "\t0. �����\n"
			<< "\t*****************************************************\n",
			choice
		);
		return choice;
}
