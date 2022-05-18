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

void Expeditor::saveInFile(std::list<std::shared_ptr<Goods>>& goods)
{
	std::fstream inFile;
	inFile.open("goods.dat", std::ios::out | std::ios::trunc);
	if (inFile.is_open()) {
		inFile << goods;
		inFile.close();
		std::cout << "������ ������� ��������\n";
	}
	else {
		std::cout << "���� �� ������� �������\n";
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
			<< "\t****************************************\n"
			<< "\t|1. ������� ����� � ���� ������        |\n"
			<< "\t|2. ����� ������ � ���� �������        |\n"
			<< "\t|3. �������� ���� �������              |\n"
			<< "\t|4. �������������� ������ � ������     |\n "
			<< "\t|5. �������� ������ �� ���� ������     |\n "
			<< "\t|6. ����� ����������                   |\n "
			<< "\t|7. ���������� ������� �� ID           |\n "
			<< "\t|0. �����                              |\n "
			<< "\t****************************************\n",
			choice
		);
		return choice;
}

void Expeditor::editGoods(std::list<std::shared_ptr<Goods>>& goods)
{	
	int find = false;
	int exit = false;
	std::string n ="  \n\n|========================================|\
						\n|1. �������� ����������������� �����     |\
						\n|2. �������� ��������                    |\
						\n|3. �������� ���� ����������� �� �����   |\
						\n|4. �������� ���� �������� ����� ��������|\
						\n|0. �����                                |\
					    \n|========================================|\n";
	int id;
	int choice;
	std::cout << "Id ������ ��� ���������: \n";
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
					std::cout << "������ ������� ��������\n";
					system("cls");
					break;
				case 2:
					item.get()->setName();
					std::cout << "������ ������� ��������\n";
					system("cls");
					break;
				case 3:
					item.get()->setAdmissionDate();
					std::cout << "������ ������� ��������\n";
					system("cls");

					break;
				case 4:
					item.get()->setShelfLife();
					std::cout << "������ ������� ��������\n";
					system("cls");
					break;
				case 0:
					exit = true;
					return;
				}
			}
			
		}
		//if (find==0) std::cout << "��� ������ ������\n ";
		throw std::exception("��� ������ ������");
	}

}

void Expeditor::deleteGoods(std::list<std::shared_ptr<Goods>>& goods, std::list<std::shared_ptr<Building>>& buildings)
{	
	int find = false;
	std::list<std::shared_ptr<Goods>>::iterator item = goods.begin();
	int id;
	std::cout << "Id ������ ��� ��������: \n";
	std::cin >> id;
	for (; item != goods.end(); item++) {
		if (item->get()->getId() == id) {
			goods.erase(item);
			std::cout << "������ ������� �������\n";
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
	
	if (find == 0) { "����� �� ������\n"; }
}

void Expeditor::searchGoods(std::list<std::shared_ptr<Goods>>& goods)
{	
	int exit = false;
	std::string name;
	
	std::string n = " \n\n|========================================|\
					    \n|1. ����� �� id						   |\
						\n|2. ����� �� ��������                    |\
						\n|3. ����� �� ���� ����������� �� �����   |\
						\n|4. ����� �� ���� �������� ����� ��������|\
						\n|0. �����                                |\
					    \n|========================================|\n";
	int id;
	int choice;


	while (!exit) {

		INPUT(
			std::cout
			<< n,
			choice
		);
		switch (choice)
		{
		case 1:
			system("cls");
			int id;
			std::cout << "�����: ";
			std::cin >> id;
			for (auto& item : goods) {
				if (item->getId() == id) {
					std::cout << std::endl;
					std::cout << "**************************************" << std::endl;
					std::cout << "|����������������� �����: " << (*item).getId() << std::endl;
					std::cout << "|��� ������: " << (*item).getType() << std::endl;
					std::cout << "|�������� ������: " << (*item).getName() << std::endl;
					std::cout << "|���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
					std::cout << "|���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
					std::cout << "|����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
					std::cout << "****************************************";
				}
			}

			break;
		case 2:
			system("cls");
		
			std::cout << "�����: ";
			getline(std::cin, name);
			getc(stdin);
			for (auto& item : goods) {
				if (item->getName() == name) {
					std::cout << std::endl;
					std::cout << "***************************************" << std::endl;
					std::cout << "|����������������� �����: " << (*item).getId() << std::endl;
					std::cout << "|��� ������: " << (*item).getType() << std::endl;
					std::cout << "|�������� ������: " << (*item).getName() << std::endl;
					std::cout << "|���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
					std::cout << "|���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
					std::cout << "|����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
					std::cout << "****************************************";
				}
			}

			break;
		case 3:

			system("cls");
			std::cout << "�����: ";
			getline(std::cin, name);
			getc(stdin);
			for (auto& item : goods) {
				if (item->getAdmissionDate() == name) {
					std::cout << std::endl;
					std::cout << "***************************************" << std::endl;
					std::cout << "|����������������� �����: " << (*item).getId() << std::endl;
					std::cout << "|��� ������: " << (*item).getType() << std::endl;
					std::cout << "|�������� ������: " << (*item).getName() << std::endl;
					std::cout << "|���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
					std::cout << "|���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
					std::cout << "|����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
					std::cout << "****************************************";
				}
			}
	
			break;
		case 4:

			system("cls");
			std::cout << "�����: ";
			getline(std::cin, name);
			getc(stdin);
			for (auto& item : goods) {
				if (item->getShelfLife() == name) {
					std::cout << std::endl;
					std::cout << "***************************************" << std::endl;
					std::cout << "|����������������� �����: " << (*item).getId() << std::endl;
					std::cout << "|��� ������: " << (*item).getType() << std::endl;
					std::cout << "|�������� ������: " << (*item).getName() << std::endl;
					std::cout << "|���� ����������� �� �����: " << (*item).getAdmissionDate() << std::endl;
					std::cout << "|���� �������� ����� ��������: " << (*item).getShelfLife() << std::endl;
					std::cout << "|����������������� ����� ������: " << (*item).getBuildingId() << std::endl;
					std::cout << "****************************************";
				}
			}

			break;
		case 0:
			exit = true;
			return;
		}
	}
	throw std::exception("��� ������ ������");

}

void Expeditor::sortGoods(std::list<std::shared_ptr<Goods>>& goods)
{	
	int choice;
	INPUT(
		std::cout
		<< "1.�� �����������\n"
		<< "2.�� ��������\n",
		choice;
	);
	switch (choice)
	{
	case 1 : 
		goods.sort([](std::shared_ptr<Goods >& a, std::shared_ptr<Goods>& b) {return a->getId() < b->getId(); });
		break;
	case 2:
		goods.sort([](std::shared_ptr<Goods >& a, std::shared_ptr<Goods>& b) {return a->getId() < b->getId(); });
		goods.reverse();
		break;
	default:
		break;
	}
	
}






