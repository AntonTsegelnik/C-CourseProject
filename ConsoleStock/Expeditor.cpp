#include "Expeditor.h"
#include "Liquids.h"
#include "Retail.h"

void Expeditor::createGoods(std::list<Goods>& test)
{	
	int n;
	std::cout << "�������� ��������� ������ ��� ����������:\n 1.��������\n 2.���������\n";
	std::cin >> n;
	switch (n) {
	case 1: {




		Liquids product;
		std::cout << "����������������� �����:";
		product.setId(); std::cout << std::endl;
		std::cout << "������������:";
		product.setName(); std::cout << std::endl;
		std::cout << "����������:";
		product.setAmount(); std::cout << std::endl;
		std::cout << "���� ����������� �� �����:";
		product.setAdmissionDate(); std::cout << std::endl;
		std::cout << "��������� ����� ��������:";
		product.setShelfLife(); std::cout << std::endl;
		std::cout << "����������������� ����� ������:";
		product.setBuildingId(); std::cout << std::endl;
		test.push_back(product);
		break;
	}
	case 2: {
		Retail thing;
		std::cout << "����������������� �����:";
		thing.setId(); std::cout << std::endl;
		std::cout << "������������:";
		thing.setName(); std::cout << std::endl;
		std::cout << "����������:";
		thing.setAmount(); std::cout << std::endl;
		std::cout << "���� ����������� �� �����:";
		thing.setAdmissionDate(); std::cout << std::endl;
		std::cout << "��������� ����� ��������:";
		thing.setShelfLife(); std::cout << std::endl;
		std::cout << "����������������� ����� ������:";
		thing.setBuildingId(); std::cout << std::endl;
		test.push_back(thing);
		break;
	}
	}

}

void Expeditor::addGoodsToBuilding()
{

}
