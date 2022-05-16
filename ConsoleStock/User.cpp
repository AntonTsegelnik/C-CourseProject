#include "User.h"
#include <iostream>
void User::showBuildings(std::list<std::shared_ptr<Building>>& buildings)
{
	for (auto& item : buildings) {

		std::cout << std::endl;
		std::cout << "*********************************************************************\n";
		std::cout << "�����:" << item.get()->getAddress() << std::endl;
		std::cout << "����������������� ����� ������:" << item.get()->getId() << std::endl;
		std::cout << "\t\t������ �� ������: \n";
		if (!item.get()->getbGoods().empty()) {
			for (auto& i : item.get()->getbGoods()) {

				std::cout << "################################################################\n";

				std::cout << " ����������������� �����: " << i.get()->getId() << std::endl;
				std::cout << " ��� ������: " << i.get()->getType() << std::endl;
				std::cout << " �������� ������: " << i.get()->getName() << std::endl;
				std::cout << " ���� ����������� �� �����: " << i.get()->getAdmissionDate() << std::endl;
				std::cout << " ���� �������� ����� ��������: " << i.get()->getShelfLife() << std::endl;
				std::cout << " ����������������� ����� ������: " << i.get()->getBuildingId() << std::endl;
			}
			std::cout << "*********************************************************************\n";
		}
		else {
			std::cout << "�����������" << std::endl;
		}
	}
}