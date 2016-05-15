/**
* \class Clinic
*
* \brief Class representing Clinic
*
* This class is representation of clinic. It is a Health Care Unit
* that stores patients data
*
*\note Thos class was the part of the first PROE project.
*
*/

#pragma once
#include"Patient.h"
#include"HealthCareUnit.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Clinic : public HealthCareUnit
{
public:
	///Constructs empty clinic
	Clinic();

	virtual ~Clinic();

	///Static method for returning the number of clinics constructed
	static int numberOfClinics();

	///Method that prints information about objetct to console
	void getInfo();

	///Method that prints patients list to console
	void listPatients();

	/**
	* \brief Operator for adding patients to patients list
	* \param p - Patient to be added to patients list
	*/
	void operator+(const Patient &p);
	
	/**
	* \brief Index operator for getting patient form patients list
	* \param i - index of the patient we want to get from the patients list
	* \return p - Patient from patients list [index]
	*/
	Patient& operator[](int i);

	/**
	* \brief Operator for merging two clinics
	* \param c - clinic to be merged
	*/
	void operator +=(const Clinic &c);

	/** \brief Insert formatted output
	*/
	friend ostream& operator<<(ostream &out, Clinic &c);
	/** \brief Insert formatted input
	*/
	friend istream& operator >> (istream &is, Clinic &c);

private:
	vector<Patient> patients; ///<patients list
	static int number_of_clinics; ///<information about number of clinics created
};