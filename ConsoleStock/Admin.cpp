#include "Admin.h"
#include "Input.h"



int Admin::showMenu()
{
		int choice;
		INPUT
		(
			std::cout
			<< "\t\t���� ��������������\n"
			<< "\t*****************************************************\n"
			<< "\t1. ���������� ������������\n"
			<< "\t2. �������� ������������\n"
			<< "\t3. ����� ������ ���� �������������\n"
			<< "\t4. ���������� ������\n"
			<< "\t5. �������� ���� �������\n"
			<< "\t0. �����\n"
			<< "\t*****************************************************\n",
			choice;
		);

		return choice;
}

void Admin::createBuilding(std::list<std::shared_ptr<Building>>& buildings)
{
	int check;
	INPUT(
		std::cout
		<< "1.������� ����\n"
		<< "2.������� ����\n",
		check;
	);
	if (check == 1) {
		std::shared_ptr<Building> ptr(new Stock());
		(*ptr).setAddress(); std::cout << std::endl;
		(*ptr).setId(); std::cout << std::endl;
		//(*ptr).setbGoods(NULL);
		buildings.push_back(ptr);
	}
	if (check == 2) {
		std::shared_ptr<Building> ttr(new Storehouse());
		(*ttr).setAddress(); std::cout << std::endl;
		(*ttr).setId(); std::cout << std::endl;
		//(*ttr).setbGoods();
		buildings.push_back(ttr);
	}
}



