#include "Goods.h"
#include <iostream>

int Goods::getId()
{
	return id;
}

void Goods::setId()
{
	std::cin >> id;
}

std::string Goods::getName()
{
	return name;
}

void Goods::setName()
{
	getline(std::cin, name);
}

double Goods::getAmount()
{
	return amount;
}

void Goods::setAmount()
{
	std::cin >> amount;
}

std::string Goods::getAdmissionDate()
{
	return admissionDate;
}

void Goods::setAdmissionDate()
{
	getline(std::cin, admissionDate);
}

std::string Goods::getShelfLife()
{
	return shelfLife;
}

void Goods::setShelfLife()
{
	getline(std::cin, shelfLife);
}

int Goods::getBuildingId()
{
	return buildingId;
}

void Goods::setBuildingId()
{
	std::cin >> buildingId;
}
