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
	Goods():id(0),type(""),name(""),amount(0),admissionDate(""),shelfLife(""),buildingId(0) {};
	Goods(int i, std::string t, std::string n, double a, std::string ad, std::string s, int b):id(i),type(t),name(n),amount(a),admissionDate(ad),shelfLife(s),buildingId(b) {};
	//~Goods() {};
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
	void setBuildingId(int a);
	virtual void toThink() = 0;

	
};

