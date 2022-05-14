#include "App.h"
#include "Admin.h"
#include "Input.h"

int App::authorithation()
{

	return _storage.login();


}

void App::run()
{
	int choice;
	bool exit = false;

	if (authorithation() == 0) {
		Admin admin;
		while (!exit)
		{
			showMenu(admin.getMenyType(), choice);

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
			showMenu(usr.getMenyType(), choice);
		
			switch (choice)
			{
			case 1:
				cout << "HI 1" << endl;
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
			<< "\t1. ���������� ������ � �����\n"
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
