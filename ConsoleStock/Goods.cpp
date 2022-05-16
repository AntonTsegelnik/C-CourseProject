#include "Goods.h"
#include <iostream>
#include "Input.h"

int Goods::getId()
{
	return id;
}

void Goods::setId()
{
	INPUT_CONDITION
	(
		std:: cout << "Идентификационный номер:",
		id,
		id >= 0,
	);
}

std::string Goods::getType()
{
	return type;
}

void Goods::setType(std::string g)
{
	type = g;
}

std::string Goods::getName()
{
	return name;
}

void Goods::setName()
{	
	std::cout << "Наименование:",
	getline(std::cin, name);
}

double Goods::getAmount()
{
	return amount;
}

void Goods::setAmount()
{
	INPUT_CONDITION
	(
		std::cout << "Количество:",
		amount,
		amount >= 0,
		);
}

std::string Goods::getAdmissionDate()
{
	return admissionDate;
}

void Goods::setAdmissionDate()
{
	std::cout << "Дата поступления на склад:";
	getline(std::cin, admissionDate);
}

std::string Goods::getShelfLife()
{
	return shelfLife;
}

void Goods::setShelfLife()
{
	std::cout << "Истечение срока годности:";
	getline(std::cin, shelfLife);
}

int Goods::getBuildingId()
{
	return buildingId;
}

void Goods::setBuildingId(int a)
{
	buildingId = a;
}
std::istream& operator>>(std::istream& is, std::shared_ptr<Goods>& goods)
{
	while (is.good())
	{
		std::shared_ptr<Goods> ptr;

		is >> ptr.get()->setId() >> goods._amount >> goods._price;
		p.AddGoodsToStorage(goods);
		is.get();
		is.peek();
	}

	return is;
}