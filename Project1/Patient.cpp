#include"Patient.h"
#include"History.h"
#include"Examination.h"
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

//Konstruktor bez parametrów
Patient::Patient()
{
	/*#ifdef _DEBUG
	cout << "Patient()" << endl;
	#endif // DEBUG*/

	date = 0;
	name = "";

}

//Konstruktor z parametrami
Patient::Patient(int d, string s)
{
	/*#ifdef _DEBUG
	cout << "Patient(int d, string s)" << endl;
	#endif // DEBUG*/

	date = d;
	name = s;
}

//Konstruktor kopiuj¹cy
Patient::Patient(const Patient &p)
{
	/*#ifdef _DEBUG
	cout << "Patient(const Patient &p)" << endl;
	#endif // DEBUG*/
	histories = p.histories;
	examinations = p.examinations;
	date = p.date;
	name = p.name;
}

//Destruktor
Patient::~Patient()
{
	/*#ifdef _DEBUG
	cout << "~Patient()" << endl;
	#endif // DEBUG

	delete[]history;*/
}

//Sprawdzanie danych pacjenta
string Patient::getName()
{
	return name;
}
int Patient::getDate()
{
	return date;
}
string Patient::getPatient()
{
	return name + " ur. " + to_string(date);
}
string Patient::viewHistory()														//dok
{
	string s;
	for (int i = 0; i < int(histories.size()); i++)
		s += histories[i].getHistory();

	if (s.empty())
		s = "Brak zapisow w historii\n";

	return s;
}
//Ustawianie danych pacjenta
void Patient::setDate(int d)
{
	date = d;
}
void Patient::setName(string s)
{
	name = s;
}
string Patient::viewExaminations()
{
	string s;
	if (examinations.size() == 0)
		s += "Brak badan do wyswietlenia\n";
	else
	{
		for (int i = 0; i < int(examinations.size()); i++)
		{
			s += examinations[i].getExamination();
		}
	}
	return s;
}

string Patient::getPatientInfo()
{
	return  getPatient() + "\n\n\n" + viewHistory() + "\n\n" + viewExaminations();

}


//Operator porównania
bool Patient::operator==(const Patient &p)
{
	if ((!(date == p.date)) || (!(name == p.name)))
		return false;

	if (!(examinations.size() == p.examinations.size())) //Jezeli roznia sie liczba badania to !=
		return false;

	if (!(histories.size() == p.histories.size())) //Jezeli roznia sie liczba badania to !=
		return false;



	for (int i = 0; i < int(histories.size()); i++)
		if (!(histories[i] == p.histories[i]))
			return false;

	for (int i = 0; i < int(examinations.size()); i++)
		if (!(examinations[i] == p.examinations[i]))
			return false;

	return true;
}

//Operator przypiasania
void Patient::operator=(const Patient &p)
{
	name = p.name;
	date = p.date;
	examinations = p.examinations;
	histories = p.histories;
}

//Operator dwuargumentowy realizujacy dodawanie badan do pacjenta

void Patient::operator+(const Examination &e)
{
	for (int i = 0; i < int(examinations.size()); i++)
		if (examinations[i] == e)
			return;
	examinations.push_back(e);
}

void Patient::operator+(const History &h)												//dok - spr czy takiego juz nie ma
{
	for (int i = 0; i < int(histories.size()); i++)
	{
		if (histories[i] == h)
			return;
	}
	histories.push_back(h);
}

void Patient::operator-(const History &h)
{
	int idx = -1;
	for (int i = 0; i < int(histories.size()); i++)
		if (histories[i] == h)
			idx = i;
	if (idx >= 0)
		histories.erase(histories.begin() + idx);
}

ostream & operator<<(ostream & out, Patient & p)
{
	out << p.name << endl << to_string(p.date)<< endl;

	for (int i = 0; i < int(p.histories.size()); i++)
		out << p.histories[i] << endl;
	out << "*"<<endl;

	for (int i = 0; i < int(p.examinations.size()); i++)
		out << p.examinations[i] << endl;
	out << "/" << endl;
	return out;
}

istream & operator >> (istream & is, Patient & p)
{
	string s;
	getline(is, s);
	p.name = s;
	
	getline(is, s);
	p.date = stoi(s);


	int i = 0;
	
	while (1) {
		History h;
		p.histories.push_back(h);
	
		is >> p.histories[i];

		i++;
		
		while (is.peek() == 10 || (char(is.peek()) == '*')) {
			getline(is, s); // usuniecie ze strumienia zbednych nowych lini i gwiazdki na koncu
			
		}

		if (s == "*") break;
	}

	i = 0;
	
	while (1) {
		Examination e;
		p.examinations.push_back(e);

		is >> p.examinations[i];
		i++;

		while (is.peek() == 10 || (char(is.peek()) == '/')) {
			getline(is, s); // usuniecie ze strumienia zbednych nowych lini i /
		}

		if (s == "/") break;
	}
	return is;
}
