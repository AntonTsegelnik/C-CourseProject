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
		std:: cout << "����������������� �����:",
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
	std::cout << "������������:",
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
		std::cout << "����������:",
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
	std::cout << "���� ����������� �� �����:";
	getline(std::cin, admissionDate);
}

std::string Goods::getShelfLife()
{
	return shelfLife;
}

void Goods::setShelfLife()
{
	std::cout << "��������� ����� ��������:";
	getline(std::cin, shelfLife);
}

int Goods::getBuildingId()
{
	return buildingId;
}

void Goods::setBuildingId()
{
	INPUT_CONDITION
	(
		std::cout << "����������������� ����� ������:",
		buildingId,
		buildingId >= 0,
		);
}
