#include "History.h"
#include <string>
#include<iostream>

using namespace std;

//Konstruktor bez parametru
History::History()
{
	//#ifdef _DEBUG
	//	cout << "History()" << endl;
	//#endif // _DEBUG

	illness_name = "";
	cured = false;
	date = 0;
}

//Konstruktor z parametrem
History::History(string s, bool c, int d)
{
	//#ifdef _DEBUG
	//	cout << "History(string s, bool c, int d)" << endl;
	//#endif // _DEBUG

	illness_name = s;
	cured = c;
	date = d;
}

//Destruktor
History::~History()
{
	//#ifdef _DEBUG
	//	cout << "~History()" << endl;
	//#endif // _DEBUG
}

//Ustawianie danych
void History::setName(string s)
{
	illness_name = s;
}
void History::setDate(int d)
{
	date = d;
}
void History::setCured(bool c)
{
	cured = c;
}

//Pobieranie danych
string History::getName()
{
	return illness_name;
}
bool History::getCured()
{
	return cured;
}
int History::getDate()
{
	return date;
}
string History::getHistory()
{
	return "Historia choroby: " + illness_name + (cured ? "\nWyleczono" : "\nNie wyleczono") + "\nData diagnozy: " + to_string(date) + "\n\n";
}

//Operatory
ostream& operator<<(ostream &os, History& h)
{
	os << h.illness_name << endl << h.cured << endl << h.date;
	return os;
}


istream & operator >> (istream & is,  History & h)
{
	string s;
	while (is.peek() == 10) getline(is, s);	//Przy wczytywniu kilku historii zostaje wisz¹cy znak '\n'

	is >> h.illness_name; 
	is >> h.cured;
	is >> h.date;

	return is;
}

bool History::operator==(const History &h)
{
	return ((illness_name == h.illness_name) && (cured == h.cured) && (date == h.date));
}
