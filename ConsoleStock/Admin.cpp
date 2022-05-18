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
			<< "\t6. �������� ������\n"
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
void Admin::deleteBuilding(std::list<std::shared_ptr<Building>>& buildings, std::list<std::shared_ptr<Goods>>& goods)
{
	int find = false;
	std::list<std::shared_ptr<Building>>::iterator item = buildings.begin();
	int id;
	std::cout << "Id ������ ��� ��������: \n";
	std::cin >> id;
	for (; item != buildings.end(); item++) {
		if (item->get()->getId() == id) {
			buildings.erase(item);
			std::cout << "������ ������� �������\n";
			find = true;
			break;
		}
	}


		auto it = find_if(goods.begin(), goods.end(), [id](const std::shared_ptr<Goods>& w) {return w->getBuildingId() == id; });
		if (it != goods.end()) {
			goods.erase(it);
		}

	if (find == 0) { std::cout<<"����� �� ������\n"; }
}



