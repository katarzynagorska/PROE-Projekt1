/**
* \file  testClinic.h
* \brief Provides functions for testing Clinic
*/

/**
* \name testClinic
* \brief Provides functions for testing Clinic
*/

#pragma once
#include "Clinic.h"
#include "utilities.h"
#include "testHealthCareUnit.h"
#include <iostream>

using namespace std;
///Function displaying test menu
void displayClinicMenu();
/**
* \brief Adding / removing patients test
* \param c - Clinic to be tested
*/
void clinicPatientsTest(Clinic &c);
/**
* \brief Informative functions test
* \param c - Clinic to be tested
*/
void clinicInfoTest(Clinic &c);
///Testing function
void testClinic()
{
	cout << "-------------------------------------" << endl;
	cout << "Uruchomiono test obiektu Clinic" << endl;
	cout << "-------------------------------------" << endl;

	Clinic c;
	char ch = 1;

	while (ch != '0') {

		displayClinicMenu();
		ch = getMenuChoice();

		cout << endl;

		switch (ch)
		{
		case 49:
			nameTest(c);
			break;

		case 50:
			equipmentTest(c);
			break;

		case 51:
			clinicPatientsTest(c);
			break;

		case 52:
			clinicInfoTest(c);
			break;

		default:
			break;
		}
	}

	cout << "-------------------------------------" << endl;
	cout << "Zakoñczono testy obiektu Clinic" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl << endl << endl;

}

void displayClinicMenu()
{
	cout << endl;
	cout << "Test Clinic - wybierz co chcesz zrobic" << endl;
	cout << "1 - Ustaw nazwe i adres - funkcje odziedziczone po HCU" << endl;
	cout << "2 - Dodaj/usun wyposazenie kliniki - funkcje odziedziczone po HCU; Listing wyposazenia" << endl;
	cout << "3 - Testy na pacjentach" << endl;
	cout << "4 - Wyswietl wszystkie info o zakladzie" << endl;
	cout << "0 - Zakoncz testy" << endl;
};

///Function for adding random patients to clinic
void addingPatients(Clinic&c);
void clinicPatientsTest(Clinic &c) {
	
	cout << "3 - Testy na pacjentach" << endl;
	addingPatients(c);

};

//Function for adding random examinations to patient
void addingExamination(Patient&p);
//Function for adding random examinations to patient
void addingHistory(Patient &p);
void addingPatients(Clinic&c)
{
	string patientName, patientDate;
	string ch;
	
	cout << "Dodawanie pacjentow" << endl;
	while(1) {

		cout << "Podaj imie pacjenta" << endl;
		while (cin.peek() == 10) getline(cin, patientName);
		getline(cin, patientName);
		cout << endl;

		cout << "Podaj date urodzenia " << patientName << endl;
		while (!(is_number(patientDate)) || patientDate.size() != 4) {
			cout << "Podaj czterocyfrowa wartosc liczbowa" << endl;
			cin >> patientDate;
		}

		Patient p(stoi(patientDate), patientName);

		addingExamination(p);
		addingHistory(p);

		cout << p.getPatientInfo() << endl;

		c + p;

		cout << "Aby zakonczyc dodawanie pacjentow wybierz 0" << endl;
		getline(cin, ch);
		if (ch == "0") break;
	} 

	c.getInfo();
};

void addingExamination(Patient&p) {
	string input;
	string ch;

	int day, month, year;
	double tsh, ft3, ft4;
	bool at;
	
	cout << "Dodawanie badan do pacjenta " << p.getName() << endl;
	while (1) {
		Examination e;

		input = "";
		while ((!(is_number(input)) || stoi(input) > 31)) {
			cout << "Podaj dzien badania" << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		} 
		day = stoi(input);
		input = "";

		while ((!(is_number(input)) || stoi(input) > 12)) {
			cout << "Podaj miesiac badania" << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		} 
		month = stoi(input);
		input = "";

		while ((!(is_number(input)) || input.size() != 4)) {
			cout << "Podaj rok badania" << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		}
		year = stoi(input);
		input = "";
		e.setDate(day, month, year);

		
		cout << "Wprowadzanie wartosci parametrow" << endl;	//double tsh, double ft3, double ft4, bool aT
		

		while (!is_double(input)) {
			cout << "Podaj wartosc TSH: " << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		}
		tsh = stod(input);
		input = "";

		while (!is_double(input)){
			cout << "Podaj wartosc FT3: " << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		}
		ft3 = stod(input);
		input = "";

		while (!is_double(input)) {
			cout << "Podaj wartosc FT4: " << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		}
		ft4 = stod(input);
		input = "";

		while (!is_number(input) || (stoi(input) != 1 && stoi(input) != 0)) {
			cout << "Podaj wartosc antyTSH (0/1): " << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		}
		at = (input=="1");
		input = "";

		e.setResults(tsh, ft3, ft4, at);
		p + e;

		cout << e.getExamination() << endl;

		cout << "Aby zakonczyc dodawanie badan wybierz 0" << endl;
		while (cin.peek() == '\n') getline(cin, ch);
		getline(cin, ch);
		if (ch == "0") break;
	} 
}

void addingHistory(Patient &p)
{
	cout << "Dodawanie historii chorob" << endl;
	string input;
	string ch;

	string desease;
	bool cured;
	int date;

	while (1) {
		cout << "Podaj nazwe choroby" << endl;
		while (cin.peek() == 10) getline(cin, desease);
		getline(cin, desease);
		cout << endl;

		input = "";
		while (!is_number(input) || (stoi(input) != 1 && stoi(input) != 0)) {
			cout << "Wyleczono (0/1): " << endl;
			while (cin.peek() == 10) getline(cin, input);
			getline(cin, input);
		}cured = (input == "1");
		
		input = "";
		while ((!(is_number(input)) || input.size() != 4)) {
			cout << "Podaj rok diagnozy" << endl;
			while (cin.peek() == '\n') getline(cin, input);
			getline(cin, input);
		} date = stoi(input);
		input = "";

		History h(desease, cured, date);
		p + h;

		cout << "Aby zakonczyc dodawanie historii wybierz 0" << endl;
		while (cin.peek() == '\n') getline(cin, ch);
		getline(cin, ch);
		if (ch == "0") break;
	}
}

void clinicInfoTest(Clinic &c) {
	cout << "getInfo()" << endl;
	c.getInfo();
	cout << endl;

	cout << "Operator <<" << endl;
	cout << c << endl;

}


