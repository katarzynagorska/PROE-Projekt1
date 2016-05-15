#include"Clinic.h"
#include"Examination.h"
#include"Patient.h"
#include"History.h"
#include <string>
#include <iostream>
#include <vector>

int Clinic::number_of_clinics = 0;

//Konstruktor bez operatora
Clinic::Clinic() : HealthCareUnit()
{
	//#ifdef _DEBUG
	//	cout << "Clinic()" << endl;
	//#endif // _DEBUG

	number_of_clinics++;
}

//Destruktor
Clinic::~Clinic()
{
	//#ifdef _DEBUG
	//	cout << "~Clinic()" << endl;
	//#endif // _DEBUG
	number_of_clinics--;
}

int Clinic::numberOfClinics()
{
	return Clinic::number_of_clinics;
}

void Clinic::getInfo()
{
	cout << "----Przychodnia----" << endl;
	cout << name << endl;
	cout << address << endl;
	
	listEquipment();

	listPatients();
}

void Clinic::listPatients()
{
	cout << endl << "PACJENCI: " << endl;
	for (int i = 0; i < int(patients.size()); i++)
		cout << patients[i].getPatientInfo() << endl;
}

void Clinic::operator+(const Patient &p)
{
	for (int i = 0; i < int(patients.size()); i++)
		if (patients[i] == p)
			return;
	patients.push_back(p);
}

Patient& Clinic::operator[](int idx)
{
	if (idx > int(patients.size()) - 1)
	{
		cout << "Index out of range" << endl << endl;
		return patients[0];
	}
	else return patients[idx];
}

void Clinic::operator+=(const Clinic &c)
{
	name = name + " i " + c.name;
	for (int i = 0; i < int(c.patients.size()); i++)
	{
		patients.push_back(c.patients[i]);
	}
}

ostream & operator<<(ostream & out, Clinic & c)
{
	out << (HealthCareUnit&)c << "@"<<endl;
	for (int i = 0; i < int(c.patients.size()); i++)
		out << c.patients[i];
	out << ";";
	return out;
}

istream & operator >> (istream & is, Clinic & c)
{
	is >> ((HealthCareUnit&)c);

	string s;
	int i = 0;

	while (1) {
		Patient p;
		c.patients.push_back(p);

		is >> c.patients[i];

		i++;

		while (is.peek() == 10 || (char(is.peek()) == ';')) {
			getline(is, s); // usuniecie ze strumienia zbednych nowych lini i gwiazdki na koncu

		}
		if (s == ";") break;
	}
	return is;
}
