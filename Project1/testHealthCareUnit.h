/**
* \file  testHealthCareUnit.h
* \brief Provides functions for testing all HealthCareUnits
*/
/**
* \name  testHealthCareUnit
* \brief Provides functions for testing all HealthCareUnits
*/

#pragma once
#include "HealthCareUnit.h"
#include <iostream>

using namespace std;

/**
* \brief function for testing setting up name and addres
* \param hcu - HealthCareUnit to be tested
*/
void nameTest(HealthCareUnit &hcu) {
	string input;

	cout << endl << "1 - Ustaw nazwe i adres - funkcje odziedziczone po HCU" << endl << endl;

	cout << endl << "Podaj adres obiektu" << endl;
	while (cin.peek() == 10)	getline(cin, input); //Usuniecie nowych linii

	getline(cin, input);
	hcu.setAddress(input);

	cout << endl << "Podaj nazwe obiektu" << endl;
	getline(cin, input);
	hcu.setName(input);

	cout << endl;

	hcu.getInfo();

	cout << endl;
	return;
}
/**
* \brief function for adding / removing equipment
* \param hcu - HealthCareUnit to be tested
*/
void equipmentTest(HealthCareUnit& hcu)
{
	string input;
	string ch;
	cout << endl << "2 - Dodaj/usun wyposazenie - funkcje odziedziczone po HCU;" << endl << "Listing wyposazenia" << endl << endl;
	cout << "Dodawanie elementow." << endl << endl;

	while (1)
	{
		cout << endl << "Podaj nazwe urzadzenia" << endl;
		while (cin.peek() == 10)	getline(cin, input); //Usuniecie nowych linii

		getline(cin, input);
		hcu.addEquipment(input);
		hcu.listEquipment();
		cout << endl;

		cout << "Aby zakonczyc dodawanie podaj 0" << endl;
		while (cin.peek() == 10)	getline(cin, ch); //Usuniecie nowych linii
		getline(cin, ch);
		if (ch == "0") break;
	}

	cout << "Usuwanie elementow." << endl << endl;
	
	while (1)
	{
		cout << endl << "Podaj nazwe urzadzenia" << endl;
		while (cin.peek() == 10)	getline(cin, input); //Usuniecie nowych linii

		getline(cin, input);
		hcu.removeEquipment(input);
		hcu.listEquipment();
		cout << endl;

		cout << "Aby zakonczyc dodawanie podaj 0" << endl;
		while (cin.peek() == 10)	getline(cin, ch); //Usuniecie nowych linii
		getline(cin, ch);
		if (ch == "0") break;
	}

	cout << endl << "Wyswietlenie listy urzadzen: " << endl;
	hcu.listEquipment();
	cout << endl;
	return;
}