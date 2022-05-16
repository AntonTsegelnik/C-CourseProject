#include "Building.h"
#include "Input.h"

int Building::getId()
{
	return id;
}

void Building::setId()
{
	INPUT_CONDITION
	(
		std::cout << "Идентификационный номер:",
		id,
		id >= 0,
		);
}

std::string Building::getAddress()
{
	return address;
}

void Building::setAddress()
{
	std::cout << "Адрес:",
	getline(std::cin, address);
}

std::list<std::unique_ptr<Goods>> Building::getbGoods()
{
	return move(bGoods);
}

void Building::setbGoods(std::unique_ptr<Goods> a)
{
	bGoods.push_back(move(a));
}
