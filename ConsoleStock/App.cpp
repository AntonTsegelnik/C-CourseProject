#include "App.h"
#include "Admin.h"
#include "Input.h"

int App::authorization()
{

	return _storage.login();


}

void App::run()
{
	int choice;
	bool exit = false;

	if (authorization() == 0) {
		Admin admin;
		while (!exit)
		{
			showMenu(admin.getMenuType(), choice);

			switch (choice)
			{
			case 1:
				_storage.addUser();
				break;

			case 0:
				exit = true;
			}
		}
	}
	else {
		Expeditor usr;
		
		while (!exit)
		{
			showMenu(usr.getMenuType(), choice);
		
			switch (choice)
			{
			case 1:
				usr.createGoods(goods);
				//to do save info in file 
				cin.get();
				system("cls");
				break;
			case 2:
				usr.showGoods(goods);
				cin.get();
				system("cls");
				break;
			case 3:
				break;
			case 0:
				exit = true;
			}
		}


	
	
	}

}

void App::showMenu(int x, int &choice)
{
	if (x == 0) 
	 {
		INPUT
		(
			std::cout
			<< "\t\t���� ��������������\n"
			<< "\t*****************************************************\n"
			<< "\t1. ���������� ������������\n"
			<< "\t2. �������� ������������\n"
			<< "\t3. ����� ������ ���� �������������\n"
			<< "\t0. �����\n"
			<< "\t*****************************************************\n",
			choice
		);

	}
	else {
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
	}
}
