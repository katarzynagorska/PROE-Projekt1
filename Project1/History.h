#pragma once
#include<string>
#include<iostream>

/**
* \class History
*
* \brief Patient's medical history record
*
* This class is patient's medical history record. It stores information
* about the name of desease, weather it was cured or no, and the date
* of diagnosis.
*
* \note Thos class was the part of the first PROE project.
*
*
*/


using namespace std;

class History
{
public:
	/// Create a History
	History();

	///Create a History with initial values
	History(string desease_name, bool cured, int date);

	~History();


	/** \brief Method for setting up History record
	* \param s name of desease
	*/
	void setName(string s);

	/** \brief Method for setting up History record
	* \param d date of diagnosis
	*/
	void setDate(int d);

	/** \brief Method for setting up History record
	* \param c information if patient was cured
	*/
	void setCured(bool c);

	/** \brief Method for getting History record
	* \return name of desease
	*/
	string getName();


	/** \brief Method for getting History record
	* \return bool cured - information if patient was cured
	*/
	bool getCured();

	/** \brief Method for getting History record
	* \return int date of diagnosis
	*/
	int getDate();

	/** \brief Method for getting History record
	* \return string representation of History record
	*/
	string getHistory();

	/** \brief Equality operator
	* \return true if two History objects are equal
	*/
	bool operator ==(const History &h);

	/** \brief Insert formatted output
	*/
	friend ostream& operator<<(ostream &os, History& h);

	/** \brief Insert formatted input
	*/
	friend istream& operator>>(istream &is, History& h);


private:
	string illness_name;	///< desease name	
	bool cured;				///< information if patient was cured	
	int date;				///< date of diagnosis	

}; 

