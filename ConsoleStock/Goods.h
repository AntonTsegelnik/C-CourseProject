#pragma once
#include <string>
class Goods 
{
private:
	int id;
	std::string type;
	std::string name;
	double amount;
	std::string admissionDate;
	std::string shelfLife;
	int buildingId;


public:
	int getId();
	void setId();
	std::string getType();
	void setType(std::string g);
	std::string getName();
	void setName();
	double getAmount();
	void setAmount();
	std::string getAdmissionDate();
	void setAdmissionDate();
	std::string getShelfLife();
	void setShelfLife();
	int getBuildingId();
	void setBuildingId();

	
};

