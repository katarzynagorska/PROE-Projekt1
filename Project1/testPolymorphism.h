/**
* \file  testPolymorphism.h
* \brief Provides function for testing polymorphism
*/
/**
* \name  testPolymorphism
* \brief Provides function for testing polymorphism
*/

#pragma once
#include "BeautyStudio.h"
#include "Clinic.h"
#include "Examination.h"
#include "HealthCareUnit.h"
#include "History.h"
#include "NailArtSaloon.h"
#include "Patient.h"

using namespace std;


///Functions for testing polymorphism
void testPoly()
{
	cout << "-------------------------------------" << endl;
	cout << "Uruchomiono test polimorfizmu" << endl;
	cout << "-------------------------------------" << endl;

	vector<HealthCareUnit*> myHCUvector;

	NailArtSaloon salon;

	salon.setAddress("Adres");
	salon.setName("Nazwa");

	for (int i = 1; i < 5; i++)
		salon.addEquipment("Rzecz" + to_string(i));

	for (int i = 1; i < 5; i++)
		salon.addBeautician("Kosmetyczka" + to_string(i));

	for (int i = 1; i < 4; i++)
		salon.addService(("Usluga" + to_string(i)),i*20);

	cout << "Mamy nastepujacy salon paznokci: " << endl;
	salon.getInfo();

	cout << "Dodajemy do wektora vector<HealtCareUnit*>" << endl;
	
	BeautyStudio studio;
	studio.setAddress("AdresStudia");
	studio.setName("NazwaStudia");
	for (int i = 1; i < 5; i++)
		studio.addEquipment("Przedmiot" + to_string(i));

	for (int i = 1; i < 5; i++)
		studio.addBeautician("Pracownik" + to_string(i));

	studio.setPrice(50);

	myHCUvector.push_back(((HealthCareUnit*)&salon));
	myHCUvector.push_back(((HealthCareUnit*)&studio));

	myHCUvector[0]->getInfo();
	myHCUvector[1]->getInfo();

	cout << endl << "Wywolanie opreatora klasy NailArtSaloon" << endl;
	cout << salon << endl;

	cout << endl << "Wywo³anie operatora klasy BeautyStudio" << endl;
	cout << *((BeautyStudio*)&salon) << endl;

	cout << endl << "Wywo³anie operatora klasy HealthCareUnit" << endl;
	cout << *((HealthCareUnit*)&salon) << endl;

	cout << "-------------------------------------" << endl;
	cout << "Zakonczono testy polimorfizmu" << endl;
	cout << "-------------------------------------" << endl;
}