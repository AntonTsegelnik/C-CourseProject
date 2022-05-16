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
	std::string str;
	str = "               << ���������� ����� � ����������� ������� �� ������  >>               \
		 \n\n|=====================================================================|\
		   \n|1. �����������                                                       |\
           \n|=====================================================================|\
		   \n|2. �����                                                             |\
		   \n|=====================================================================|\n";

	while (!exit) {
		INPUT(
			std::cout
			<< str,
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
				case 2:
					break;
				case 3:
					break;
				case 4:
					admin.createBuilding(buildings);
					break;
				case 5:
					admin.showBuildings(buildings);
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
						usr.showBuildings(buildings);
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


