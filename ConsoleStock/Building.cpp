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

std::list<std::shared_ptr<Goods>>& Building::getbGoods()
{
	return bGoods;
}

void Building::setbGoods(std::shared_ptr<Goods> a)
{
	bGoods.push_back(a);
}


