/**
* \file  application.h
* \brief Provides functions for main program.
*/

/**
* \name    Application
* \brief   Provides functions for running application with console UI.
*
*/

#pragma once

#include "testBeautyStudios.h"
#include "testNailArtSaloon.h"
#include "testClinic.h"
#include "testPolymorphism.h"
#include "testReadWrite.h"
#include <iostream>
#include <string>


void displayMenuApp();

///Function for UI 
void runApp()
{
	cout << "--------------------------------------------------------------------" << endl;
	cout << "-------------** Katarzyna Gorska - Projekt 2. - PROE **------------" << endl;
	cout << "--------------------------------------------------------------------" << endl << endl;
	
	char ch;

	while (1)
	{
		displayMenuApp();		
		ch = getMenuChoice();

		cout << endl;


		switch (ch)
		{
		case 48:
			return;
		case 49:
			testBeauty();
			break;
		case 50:
			testNails();
			break;
		case 51:
			testClinic();
			break;
		case 52:
			testPoly();
			break;
		case 53:
			testRW();
			break;
		default:
			cout << endl << "Wpisz poprawna wartosc"<< endl;
			break;
		}
	}
}

///Function for displaying application menu
void displayMenuApp()
{
	cout << "Menu aplikacji:" << endl;
	cout << "1 - Test BeautyStudio" << endl;
	cout << "2 - Test NailArtSaloon" << endl;
	cout << "3 - Test Clinic" << endl;
	cout << "4 - Test polimorfizmu" << endl;
	cout << "5 - Test zapisu i odczytu" << endl;
	cout << "0 - Wyjscie z aplikacji" << endl;
	cout << endl;
}

