/**
* \file  testNailSaloon.h
* \brief Provides functions for testing NailArtSaloon 
*/

/**
* \name  testNailSaloon
* \brief Provides functions for testing NailArtSaloon
*/

#pragma once
#include "NailArtSaloon.h"
#include"testHealthCareUnit.h"
#include "testBeautyStudios.h"
#include "utilities.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

///Function for displaying tests menu
void displayNailsMenu();
/**
* \brief Adding / removing services test
* \param nas - NailAtrSaloon to be tested
*/
void nailsServiceTest(NailArtSaloon &nas);
/**
* \brief informative functions tests
* \param nas - NailAtrSaloon to be tested
*/
void nailsInfoTest(NailArtSaloon &nas);


void testNails()
{
	cout << "-------------------------------------" << endl;
	cout << "Uruchomiono test obiektu NailArtSaloon" << endl;
	cout << "-------------------------------------" << endl;

	char ch = 1;
	NailArtSaloon nas;



	while (ch != '0') {

		displayNailsMenu();
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case 49:
			nameTest(nas);
			break;

		case 50:
			equipmentTest(nas);
			break;

		case 51:
			beautyWorkersTest(nas);
			break;

		case 52:
			nailsServiceTest(nas);
			break;

		case 53:
			nailsInfoTest(nas);
			break;

		default:
			break;
		}
	}

	cout << "-------------------------------------" << endl;
	cout << "Zakoñczono testy obiektu NailArtSaloon" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl << endl << endl;

}

void displayNailsMenu() {

	cout << endl;
	cout << "Test NailArtSaloon - wybierz co chcesz zrobic" << endl;
	cout << "1 - Ustaw nazwe i adres - funkcje odziedziczone po HCU" << endl;
	cout << "2 - Dodaj/usun wyposazenie salonu - funkcje odziedziczone po HCU; Listing wyposazenia" << endl;
	cout << "3 - Dodaj/usun kosmetyczke - funkcje odziedziczone po BS" << endl;
	cout << "4 - Dodaj/usun uslugi do cennika, wyswietl srednia cene" << endl;
	cout << "5 - Wyswietl wszystkie informacje o zakladzie" << endl;
	cout << "0 - Zakoncz testy" << endl;
}

void nailsServiceTest(NailArtSaloon& nas)
{
	string serviceName, servicePrice;
	string ch;

	cout << endl << "4 - Dodaj/usun uslugi do cennika, wyswietl srednia cene" << endl;
	cout << "Dodawanie pozycji do cennika" << endl;


	while (1) {
		cout << endl << "Podaj nazwe uslugi" << endl;
		while (cin.peek() == 10)	getline(cin, serviceName); //Usuniecie nowych linii

		getline(cin, serviceName);

		cout << endl << "Podaj cene uslugi" << endl;
		while (cin.peek() == 10)	getline(cin, servicePrice); //Usuniecie nowych linii

		getline(cin, servicePrice);

		while (!(is_number(servicePrice)))
		{
			cout << "Podaj wartosc liczbowa" << endl;
			cin >> servicePrice;
		}

		nas.addService(serviceName, std::stoi(servicePrice));

		nas.listService();

		cout << "Aby zakonczyc dodawanie podaj 0" << endl;
		getline(cin, ch);
		if (ch == "0") break;

	}

	while (1) {
		cout << endl << "Podaj nazwe uslugi, ktora chcesz usunac" << endl;
		while (cin.peek() == 10)	getline(cin, serviceName); //Usuniecie nowych linii

		getline(cin, serviceName);

		nas.removeService(serviceName);
		nas.listService();

		cout << "Aby zakonczyc usuwanie podaj 0" << endl;
		getline(cin, ch);
		if (ch == "0") break;
	}
}

void nailsInfoTest(NailArtSaloon &nas)
{
	cout << endl << "getInfo()" << endl;
	nas.getInfo();
	cout << endl;

	cout << "Operator << " << endl;
	cout << nas;
}

