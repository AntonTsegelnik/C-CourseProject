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
	bool exit2;

	while (!exit) {
		INPUT(
			std::cout
			<< "\t      ����\n"
			<<"\t*******************\n"
			<< "\t1.�����������\n" 
			<< "\t2.�����\n"
			<< "\t*******************\n",
			choice,
		);
		exit2 = false;
		switch (choice)
		{
		case 1:
			system("cls");
			if (authorization() == 0) {
				Admin admin;
				while(!exit2){
				int chc = admin.showMenu();
				switch (chc)
				{
				case 1:
					_storage.addUser();
					break;

				case 0:
					exit2 = true;
				}
			}

			}
			else {
				Expeditor usr;
				while (!exit2)
				{	
					system("cls");
					int chc = usr.showMenu();
					switch (chc)
					{
					case 1:
						system("cls");
						usr.createGoods(goods, buildings);
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
						system("cls");
						exit2 = true;
					}
				}
			}
			break;
		case 2:
			exit = true;
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
