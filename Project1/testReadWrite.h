/**
* \file  testReadWrite.h
* \brief Provides functions for testing stream operators and file reading/writing operations
*/
/**
* \name  testReadWrite
* \brief Provides functions for testing stream operators and file reading/writing operations
*/


#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>   
#include <time.h> 
#include<string>


using namespace std;

///Test for BeutyStudio Class ostream << operator and writing class to file
void writingBeautyTest();
///Test for BeutyStudio Class istream >> operator and reading class from file
void readingBeautyTest();
///Test for NailArtSaloon Class ostream << operator and writing class to file
void writingNailsTest();
///Test for NailArtSaloon Class istream >> operator and reading class from file
void readingNailsTest();
///Test for Clinic Class istream >> operator and reading class from file
void readingtestClinic();
///Test for Clinic Class ostream << operator and writing class to file
void writingtestClinic();

///Function for testing every class stream operators and file reading/writing operations
void testRW()
{
	char stop;
	
	cout << "-------------------------------------" << endl;
	cout << "Uruchomiono test zapisu/odczytu" << endl;
	cout << "-------------------------------------" << endl;
	
	cout << endl << endl;
	cout << "***********************" << endl << endl;
	cout << "Testy dla Beauty Studio" << endl << endl << endl;
	writingBeautyTest();
	readingBeautyTest();

	
	cout << endl << endl;
	cout << "***********************" << endl << endl;
	cout << "Testy dla NailArtSaloon" << endl << endl << endl;
	writingNailsTest();
	readingNailsTest();

	cout << endl << endl;
	cout << "****************" << endl << endl;
	cout << "Testy dla Clinic" << endl;
	writingtestClinic();
	readingtestClinic();
	

	cout << "-------------------------------------" << endl;
	cout << "Zakoñczono testy zapisu/odczytu" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl << endl << endl;
};


void writingBeautyTest()
{
	cout << "#####################" << endl << endl;
	cout << "Beauty Studio Writing" << endl << endl;

	fstream myfile;
	BeautyStudio b;

	myfile.open("beauty.txt", std::fstream::out | std::fstream::trunc);

	b.setAddress("AdresSalonuPieknosci_1");
	b.setName("NazwaSalonuPieknosci_1");
	b.setPrice(500);

	srand(time(NULL));
	int iRand = rand() % 10 + 4;

	for (int i = 1; i < iRand; i++)
		b.addBeautician(to_string(i) + ". kosmetyczka studia pieknosci");

	iRand = rand() % 10 + 4;
	for (int i = 1; i < iRand; i++)
		b.addEquipment(to_string(i) + ". rzecz studia pieknosci");

	

	if (myfile.is_open())
	{
		myfile.clear();
		myfile << b;
		myfile.close();
		cout << "Zakonczono zapis do pliku" << endl;
	}
	else cout << "Unable to open file";

	cout << endl << endl;
}



void writingNailsTest() {
	
	cout << "#######################" << endl << endl;
	cout << "Nail Art Saloon Writing" << endl << endl;
	
	fstream myfile;
	myfile.open("nails.txt", std::fstream::out | std::fstream::trunc);

	NailArtSaloon n;
	n.setAddress("AdresSalonuPieknosci_1");
	n.setName("NazwaSalonuPieknosci_1");

	srand(time(NULL));
	int iRand = rand() % 10 + 4;

	for (int i = 1; i < iRand; i++)
		n.addEquipment(to_string(i) + "Przedmiot_" + to_string(i) + " salonu paznokci");

	iRand = rand() % 10 + 4;
	for (int i = 1; i < iRand; i++)
		n.addBeautician(to_string(i) + "Pracownik_" + to_string(i) + " salonu paznokci");

	iRand = rand() % 10 + 4;
	for (int i = 1; i < iRand; i++)
		n.addService((to_string(i) + "Usluga_" + to_string(i) + " studia paznokci"), i * 100);

	if (myfile.is_open())
	{
		myfile << n;
		myfile.close();
		cout << "Zakonczono zapis do pliku" << endl;
	}
	else cout << "Unable to open file" << endl;

	cout << endl << endl;
}

void writingtestClinic() {

	cout << "##############" << endl << endl;
	cout << "Clinic Writing" << endl << endl;

	fstream myfile;
	myfile.open("clinic.txt", std::fstream::out | std::fstream::trunc);

	Clinic c;

	srand(time(NULL));

	int iRand = rand() % 3 + 3;
	int jRand = rand() % 2 + 2;

	c.setAddress("Adres przychodni");
	c.setName("Nazwa przychodni");


	for (int i = 0; i < iRand; i++)
		c.addEquipment("Wyposazenie " + to_string(i + 1));

	for (int j = 0; j < jRand; j++)
	{
		Patient p(rand() % 100 + 1916, "Pacjent " + to_string(j + 1));

		iRand = rand() % 3 + 1;
		//Badania dla j-tego pacjenta
		for (int i = 0; i < iRand; i++)
		{
			Examination e(rand() % 31, rand() % 12, rand() % 26 + 1990); //Generuje p-losowa date
			e.setResults((double(rand() % 1000) / 100), (double(rand() % 100) / 10), (double(rand() % 300) / 10), (rand() % 2 == 1)); //Generuje p-losowe wynii
			p + e;
		}

		iRand = rand() % 2 + 1;
		//Historie dla j-tego pacjenta
		for (int i = 0; i < iRand; i++)
		{
			History h("Choroba" + to_string(i), (rand() % 2 == 1), rand() % 26 + 1990);
			p + h;
		}
		c + p;
	}

	if (myfile.is_open())
	{
		myfile << c;
		myfile.close();
		cout << "Zakonczono zapis do pliku" << endl;
	}
	else cout << "Unable to open the file" << endl;

	cout << endl << endl;
}

void readingBeautyTest() {
	cout << "#####################" << endl << endl;
	cout << "Beauty Studio Reading" << endl << endl;

	fstream myfile;
	myfile.open("beauty.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	BeautyStudio b;

	if (myfile.is_open())
	{
		myfile >> b;
		b.getInfo();
		myfile.close();
		cout << "Zakonczono odczyt" << endl;
	}
	else cout << "Unable to open file";

	cout << endl << endl;
}

void readingNailsTest() {

	cout << "######################" << endl << endl;
	cout << "NailArt Saloon Reading" << endl << endl;

	fstream myfile;
	myfile.open("nails.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	NailArtSaloon n;

	if (myfile.is_open())
	{
		cout << "Nail reading test" << endl;
		myfile >> n;
		n.getInfo();
		myfile.close();
		cout << "Zakonczono odczyt z pliku" << endl;
	}
	else cout << "Unable to open the file" << endl;

	cout << endl << endl;
}

void readingtestClinic() {
	
	cout << "##############" << endl << endl;
	cout << "Clinic Reading" << endl << endl;

	fstream myfile;
	myfile.open("clinic.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	Clinic c;

	if (myfile.is_open())
	{
		
		myfile >> c;
		c.getInfo();
		myfile.close();
		cout << "Zakonczono odczyt z pliku" << endl;
	}
	else cout << "Unable to open the file" << endl;

	cout << endl << endl;
}