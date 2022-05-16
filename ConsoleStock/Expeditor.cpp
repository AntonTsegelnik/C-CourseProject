#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"
#include "Input.h"
#include "Stock.h"





void Expeditor::createGoods(std::list<std::unique_ptr<Goods>> &goods, std::list<std::unique_ptr<Building>>& buildings)
{
	std::unique_ptr<Building> tr(new Stock());
	(*tr).setAddress(); std::cout << std::endl;
	(*tr).setId(); std::cout << std::endl;
	(*tr).setbGoods(0);
	buildings.push_back(move(tr));
	int n;
	std::cout << "�������� ��������� ������ ��� ����������:\n 1.��������\n 2.���������\n";
	std::cin >> n;
	switch (n) {
	case 1: {
		
		std::unique_ptr<Goods> ptr(new Liquids());
		(*ptr).setType("��������");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(1); std::cout << std::endl;
		goods.push_back(move(ptr));
		for (auto& item : buildings) {
			if (item.get()->getId() == (*ptr).getBuildingId()) {
				item.get()->setbGoods(move(ptr));
			}
		}

		break;
	}
	case 2: {
		std::unique_ptr<Goods> ptr(new Retail());
		(*ptr).setType("�������");
		(*ptr).setId(); std::cout << std::endl;
		(*ptr).setName(); std::cout << std::endl;
		(*ptr).setAmount(); std::cout << std::endl;
		(*ptr).setAdmissionDate(); std::cout << std::endl;
		(*ptr).setShelfLife(); std::cout << std::endl;
		(*ptr).setBuildingId(2); std::cout << std::endl;
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
		std::cout << " ����������������� �����: " << (*item).getId() << std::endl;
		std::cout << " ��� ������: " << (*item).getType() << std::endl;
		std::cout << " �������� ������: " << (*item).getName() << std::endl;
		std::cout << " ���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
		std::cout << " ���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
		std::cout << " ����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
		std::cout << "****************************************************";
	}
}

//void Expeditor::addGoodsToBuilding(std::list<std::unique_ptr<Goods>>& goods, std::list<std::unique_ptr<Building>>& buildings)
//{
//	/*for (auto& item : goods) {
//		if(item.get()->getBuildingId() == )
//	}*/
//
//}



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
			<< "\t3. �������� ������ �� ������\n"
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
