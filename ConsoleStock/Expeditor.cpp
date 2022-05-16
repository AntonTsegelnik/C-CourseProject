#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"
#include "Input.h"





void Expeditor::createGoods(std::list<std::unique_ptr<Goods>> &goods)
{	
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
		(*ptr).setBuildingId(); std::cout << std::endl;
		goods.push_back(move(ptr));
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
		std::cout << " ����������������� �����: " << (*item).getId() << std::endl;
		std::cout << " ��� ������: " << (*item).getType() << std::endl;
		std::cout << " �������� ������: " << (*item).getName() << std::endl;
		std::cout << " ���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
		std::cout << " ���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
		std::cout << " ����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
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
