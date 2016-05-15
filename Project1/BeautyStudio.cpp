#include "BeautyStudio.h"

#include <iostream>
#include <algorithm>


BeautyStudio::BeautyStudio() : HealthCareUnit()
{
	name = "";
	address = "";
	price = 0;
}


BeautyStudio::~BeautyStudio()
{
}

void BeautyStudio::getInfo() 
{
	cout << endl<<"----Salon pieknosci----" << endl;
	cout << name << endl;
	cout << address << endl;
	cout << "Cena zabiegu: " << price << endl;

	listEquipment();

	listBeauticians();
	
}


void BeautyStudio::addBeautician(string b)
{
	vector<string>::iterator it;

	it = find(beautician.begin(), beautician.end(), b);
	if (it != beautician.end())
		return;
	else
		beautician.push_back(b);
}

void BeautyStudio::removeBeautician(string b)
{
	vector<string>::iterator it;

	it = find(beautician.begin(), beautician.end(), b);
	if (it != beautician.end())
		beautician.erase(it);
}

void BeautyStudio::listBeauticians()
{
	cout << endl << "Kosmetyczki pracujace w salonie: " << endl;
	for (int i = 0; i < int(beautician.size()); i++)
		cout << beautician[i] << endl;
}

void BeautyStudio::setPrice(int price)
{
	this->price = price;
}

void BeautyStudio::getPrice()
{
	cout << "Srednia cena ze uslugi: " << price << endl;
}

ostream & operator<<(ostream & ost, BeautyStudio & bs)
{
	ost << (HealthCareUnit&)bs << "@" << endl;

	for (int i = 0; i < int(bs.beautician.size()); i++)
		ost << bs.beautician[i] << endl;

	ost << "$" << endl << bs.price << endl;
	return ost; 
}

istream & operator >> (istream & ist, BeautyStudio & bs)
{
	ist >> ((HealthCareUnit&)bs);
	string s;

	while (ist.peek() == 10) getline(ist, s); //Usuwam zbedne newline

	while (getline(ist, s))
	{
		bs.beautician.push_back(s); // Poniewaz sa spacje i przecinki wykorzystuje getline

		while (ist.peek() == 10) getline(ist, s); //usuniecie zbednych znakow nowej linii

		if (char(ist.peek()) == '$')
		{
			getline(ist, s);
			break;
		}
	}
	
	while (ist.peek() == 10) getline(ist, s); //Usuwam zbedne newline

	while ((getline(ist, s)))
	{
		
		if (s.empty()|| (s == "#")) break;
		bs.price = stoi(s);
	}

	return ist;
}
