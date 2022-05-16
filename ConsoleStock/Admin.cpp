#include "Admin.h"
#include "Input.h"



int Admin::showMenu()
{
		int choice;
		INPUT
		(
			std::cout
			<< "\t\tМеню Администратора\n"
			<< "\t*****************************************************\n"
			<< "\t1. Добавление пользователя\n"
			<< "\t2. Удаление пользователя\n"
			<< "\t3. Вывод отчета всех пользователей\n"
			<< "\t4. Добавление склада\n"
			<< "\t5. Просмотр всех складов\n"
			<< "\t0. Выход\n"
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
		<< "1.Создать сток\n"
		<< "2.Создать стор\n",
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



