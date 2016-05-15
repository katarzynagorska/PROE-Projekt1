/**
* \file  testBeautyStudio.h
* \brief Provides functions for testing BeautyStudio
*/
/**
* \name  testBeautyStudio
* \brief Provides functions for testing BeautyStudio
*/
#pragma once
#include "BeautyStudio.h"
#include "testHealthCareUnit.h"
#include "utilities.h"
#include <iostream>
#include <string>

using namespace std;
///Function for displaing test menu
void displayBeautyMenu();
/**
* \brief Adding / removing services beauticians
* \param bs - BeautyStudio to be tested
*/
void beautyWorkersTest(BeautyStudio&bs);
/**
* \brief Setting up price and viewing price tests
* \param bs - BeautyStudio to be tested
*/
void beautyPriceTest(BeautyStudio&bs);
/**
* \brief Informative functions test
* \param bs - BeautyStudio to be tested
*/
void beautyInfoTest(BeautyStudio& bs);

/**
* \brief Testing function
*/
void testBeauty();

void displayBeautyMenu() {

	cout << "Test BeautyStudio" << endl;
	cout << "1 - Ustaw nazwe i adres - funkcje odziedziczone po HCU" << endl;
	cout << "2 - Dodaj/usun wyposazenie salonu - funkcje odziedziczone po HCU; Listing wyposazenia" << endl;
	cout << "3 - Dodaj/usun kosmetyczke - funkcje obiektu BS" << endl;
	cout << "4 - Ustal/wyswietl cene zabiegu" << endl;
	cout << "5 - Wyswietl wszystkie informacje o zakladzie" << endl;
	cout << "0 - Zakoncz testy" << endl;

}

void testBeauty()
{
	cout << endl << "-------------------------------------" << endl;
	cout << "Uruchomiono test obiektu BeautyStudio" << endl;
	cout << "-------------------------------------" << endl << endl;

	char ch = 1;
	BeautyStudio bs;


	while (ch != '0') {

		displayBeautyMenu();
		ch = getMenuChoice();

		cout << endl;

		switch (ch)
		{
		case 49:
			nameTest(bs);
			break;

		case 50:
			equipmentTest(bs);
			break;

		case 51:
			beautyWorkersTest(bs);
			break;

		case 52:
			beautyPriceTest(bs);
			break;

		case 53:
			beautyInfoTest(bs);
			break;

		default:
			break;
		}
	}

	cout << "-------------------------------------" << endl;
	cout << "Zakoñczono testy obiektu BeautyStudio" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl << endl << endl;
}

void beautyWorkersTest(BeautyStudio &bs) {
	string input;
	string ch;

	cout << endl << "3 - Dodaj/usun kosmetyczke - funkcje obiektu BS" << endl;
	cout << "Dodawanie kosmetyczek" << endl;


	while (1)
	{
		cout << endl << "Podaj imie kosmetyczki" << endl;
		while (cin.peek() == 10)	getline(cin, input); //Usuniecie nowych linii

		getline(cin, input);
		bs.addBeautician(input);
		bs.listBeauticians();
		cout << endl;

		cout << "Aby zakonczyc dodawanie podaj 0" << endl;
		getline(cin, ch);
		if (ch == "0") break;
	}

	cout << endl << "Usuwanie kosmetyczek" << endl;

	while (1)
	{
		cout << endl << "Podaj imie kosmetyczki" << endl;
		while (cin.peek() == 10)	getline(cin, input); //Usuniecie nowych linii

		getline(cin, input);
		bs.removeBeautician(input);
		bs.listBeauticians();
		cout << endl;

		cout << "Aby zakonczyc usuwanie podaj 0" << endl;
		getline(cin, ch);
		if (ch == "0") break;
	}

	bs.listBeauticians();
	cout << endl;
}



void beautyPriceTest(BeautyStudio&bs) {
	string cena;
	cout << endl << "4 - Ustal/wyswietl cene zabiegu" << endl;
	cout << endl << "Wprowadz cene" << endl;
	cin >> cena;
	while (!is_number(cena)) {
		cout << endl << "Wprowadz cene" << endl;
		cin >> cena;
	}
	bs.setPrice(stoi(cena));
	bs.getPrice();
	cout << endl;
}

void beautyInfoTest(BeautyStudio& bs) {
	cout << endl << "getInfo()" << endl;
	bs.getInfo();
	cout << endl;

	cout << "Operator << " << endl;
	cout << bs;
	cout << endl << endl;
}