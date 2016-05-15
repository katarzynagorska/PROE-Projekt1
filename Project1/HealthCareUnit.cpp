#include "HealthCareUnit.h"
#include <iostream>
#include <algorithm>
using namespace std;

HealthCareUnit::HealthCareUnit()
{
	address = "";
	name = "";
}


HealthCareUnit::~HealthCareUnit()
{
}

void HealthCareUnit::getInfo()
{
	cout << "----Health Care Unit ----" << endl;
	cout << name << endl;
	cout << address << endl;
}

void HealthCareUnit::listEquipment()
{
	cout << "Wyposazenie obiektu: " << endl;
	for (int i = 0; i <int( equipment.size()); i++)
		cout << "- " << equipment[i] << endl;
}

void HealthCareUnit::addEquipment(string e)
{
	
	vector<string>::iterator it;

	it = find(equipment.begin(), equipment.end(), e);
	if (it != equipment.end())
		return;
	else
		equipment.push_back(e);
}

void HealthCareUnit::removeEquipment(string eq)
{
	int idx = -1;
	for (int i = 0; i < int(equipment.size()); i++)
		if (equipment[i] == eq)
			idx = i;
	if (idx >= 0)
		equipment.erase(equipment.begin() + idx);
}

void HealthCareUnit::setAddress(string s)
{
	address = s;
}

void HealthCareUnit::setName(string s)
{
	name = s;
}

istream & operator >> (istream & ist, HealthCareUnit & hcu)
{
	string s;

//	ist >> hcu.name >>  hcu.address;
	while (ist.peek() == 10) getline(ist, s); //Usuwanie zbednej nowej lini

	while (getline(ist, s))
	{
		hcu.name = s;
		break;
	}

	while (getline(ist, s))
	{
		hcu.address = s;
		break;
	}

	while (getline(ist, s))
	{	
		hcu.equipment.push_back(s); // Poniewaz sa spacje i przecinki wykorzystuje getline

		while (ist.peek() == 10) getline(ist, s); //usuniecie zbednych znakow nowej linii

		if (char(ist.peek()) == '@')
		{
			getline(ist, s);
			break;
		}
	}

	while (ist.peek() == 10) getline(ist, s); //Usuwanie zbednej nowej lini

	return ist;
}

ostream & operator<<(ostream & ost, HealthCareUnit & hcu)
{
	ost << hcu.name << endl << hcu.address << endl;

	for (int i = 0; i < int(hcu.equipment.size()); i++)
		ost << hcu.equipment[i] << endl;

	return ost;
}