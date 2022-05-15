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
			<< "\t\tМеню Администратора\n"
			<< "\t*****************************************************\n"
			<< "\t1. Добавление пользователя\n"
			<< "\t2. Удаление пользователя\n"
			<< "\t3. Вывод отчета всех пользователей\n"
			<< "\t0. Выход\n"
			<< "\t*****************************************************\n",
			choice
		);

	}
	else {
		INPUT
		(
			std::cout
			<< "\t\tМеню\n"
			<< "\t*****************************************************\n"
			<< "\t1. Создать товар в базе данных\n"
			<< "\t2. Вывод отчета\n"
			<< "\t3. Удаление данных из отчета\n"
			<< "\t4. Редактирование содержимого\n"
			<< "\t5. Сохранить информацию в файл\n"
			<< "\t6. Сортировка публикаций по цене\n"
			<< "\t7. Поиск публикации\n"
			<< "\t0. Выход\n"
			<< "\t*****************************************************\n",
			choice
		);
	}
}
