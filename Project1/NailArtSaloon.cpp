#include "NailArtSaloon.h"
#include <iostream>

using namespace std;


NailArtSaloon::NailArtSaloon() : BeautyStudio()
{
	
}


NailArtSaloon::~NailArtSaloon()
{
}

void NailArtSaloon::getInfo()
{
	cout << "----Studio paznokci----" << endl;
	cout << name << endl;
	cout << address << endl;
	cout << "Srednia cena zabiegu: " << price << endl;

	listEquipment();

	listBeauticians();

	listService();

}

void NailArtSaloon::addService(string service, int price)
{
	map<string, int>::iterator it;

	it = this->service.find(service);
	if (it != this->service.end())
		return;
	
	this->service.insert(pair<string, int>(service, price));
	updateMeanPrice();
}

void NailArtSaloon::removeService(string service)
{

	map<string, int>::iterator it;

	it = this->service.find(service);
	if (it != this->service.end())
		this->service.erase(it);

	updateMeanPrice();
}

void NailArtSaloon::updateMeanPrice()
{
	price = 0;
	map<string, int>::iterator it;
	it = service.begin();

	while (it!=service.end())
	{
		price += it->second;
		it++;
	}

	price /= service.size();
}

void NailArtSaloon::listService()
{
	cout << endl << "Cennik uslug: " << endl;
	
	map<string, int>::iterator it;
	it = service.begin();

	while (it != service.end())
	{
		cout << it->first << "\t - \t" << it->second << endl;
		it++;
	}

	cout << endl << "Srednia cena za zabieg wynosi: " << price << endl;
}

ostream & operator<<(ostream & ost, NailArtSaloon & nas)
{

	ost << ((BeautyStudio&)nas) << "#" << endl;

	map<string, int>::iterator it;
	it = nas.service.begin();

	while (it != nas.service.end())
	{
		ost << it->first << '\t' << it->second << endl;
		it++;
	}

	return ost;
}

istream & operator >> (istream & is, NailArtSaloon & nas)
{

	is >> ((BeautyStudio&)nas);

	string s;


	while (is.peek() == 10) getline(is, s); //Usuwam zbedne newline


	//Rozdzielenie pierwszej i drugiej pozycji cennika
	while (getline(is, s))
	{
		
		string delimiter = "\t";
		string first,last;

		size_t pos = 0;
		
		while ((pos = s.find(delimiter)) != string::npos) {
			first = s.substr(0, pos);
			
			s.erase(0, pos + delimiter.length());
			last = s;

			nas.addService(first, stoi(last));
		}
		
	
	}

	return is;
}
