/**
* \class Patient
*
* \brief Class representing patient data
*
* This class is representation of patient record
* It stores patient's the examinations and medical history
*
* \note Thos class is part of the first PROE project.
*
*
*/

#pragma once
#include"Examination.h"
#include"History.h"
#include <string>
#include <vector>

using namespace std;

class Patient {
public:
	///Constructor
	Patient();
	/**
	* \brief Constructs patient with initial name and date of birth
	* \param d - date of birth
	* \param s - parient name
	*/
	Patient(int d, string s);
	/**
	* \brief Copying constructor
	* \param p - patient to be copied
	*/
	Patient(const Patient &p);
	///Destructor
	~Patient();

	/**
	* \brief Method for getting patient's name
	* \return patient name
	*/
	string getName();
	/**
	* \brief Method for getting patient's date of birth
	* \return patient date of birth
	*/
	int getDate();
	/**
	* \brief Method for getting patient's personal data
	* \return patient's personal data
	*/
	string getPatient();
	/**
	* \brief Method for getting patient's examinations 
	* \return patient's examinations
	*/
	string viewExaminations();
	/**
	* \brief Method for getting patient's medical history
	* \return patient's medical history
	*/
	string viewHistory();
	/**
	* \brief Method for getting patient's information
	* \return patient's information
	*/
	string getPatientInfo();
	/**
	* \brief Method for setting up patients name
	* \param s - patients name
	*/
	void setName(string s);
	/**
	* \brief Method for setting up patients name
	* \param d - patients date of birth
	*/
	void setDate(int d);


	/**
	* \brief Equality operator
	* \param p - patient to be compared
	* \return true if examinations are equal
	* \return false otherwise
	*/
	bool operator==(const Patient &p);
	/**
	* \brief Assignment operator
	* \param p - pastient to be assigned
	*/
	void operator=(const Patient &p);

	/**
	* \brief Operator for adding examinations
	* \param e - examination to be added to patients examination list
	*/
	void operator+(const Examination &e);
	/**
	* \brief Operator for adding medical history record
	* \param h -  medical history record to be added to  medical history record list
	*/
	void operator+(const History &h);

	/**
	* \brief Operator for removing medical history record
	* \param h -  medical history record to be removed from  medical history record list
	*/
	void operator-(const History &h);

	///Insert formatted output
	friend ostream& operator<<(ostream &out, Patient &p);

	///Insert formatted input
	friend istream& operator>>(istream &is, Patient &p);

private:
	int date;								///<Date of birth
	string name;							///<Name of patient

	vector<Examination> examinations;		///Examiantions storage
	vector<History> histories;				///History storage
};