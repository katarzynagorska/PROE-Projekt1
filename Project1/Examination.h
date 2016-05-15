/**
* \class Examination
*
* \brief Class representing Examination data
*
* This class is representation of examination record
* it stores the date of examination and the results
*
* \note Thos class is part of the first PROE project.
*
*
*/


#pragma once
#include<iostream>
#include<string>

using namespace std;

class Examination
{
public:
	///Constructs empty examination
	Examination();
	/**
	* \brief Constructs examination with initial date
	* \param d -day
	* \param m -month
	* \param y -year
	*/
	Examination(int d, int m, int y);

	/**
	* \brief Constructs examination with initial results
	* \param tsh -tsh level
	* \param ft3 -ft3 level
	* \param ft4 -ft4 level
	* \param aT - anty-TSH presence
	*/
	Examination(double tsh, double ft3, double ft4, bool aT);

	~Examination();

	/**
	* \brief Method for setting up examination date
	* \param d -day
	* \param m -month
	* \param y -year
	*/
	void setDate(int d, int m, int y);
	/**
	* \brief Method for setting up examination date
	* \param tsh -tsh level
	* \param ft3 -ft3 level
	* \param ft4 -ft4 level
	* \param aT - anty-TSH presence
	*/
	void setResults(double tsh, double ft3, double ft4, bool aT);

	/**
	* \brief Method for getting examination date
	* \return examination date
	*/
	string getDate();

	/**
	* \brief Method for getting examination results
	* \return examination results
	*/
	string getResults();

	/**
	* \brief Method for getting examination record
	* \return examination record
	*/
	string getExamination();

	/**
	* \brief Equality operator
	* \return true if examinations are equal
	* \return false otherwise
	*/
	bool operator==(const Examination &exam);

	/** \brief Insert formatted output
	*/
	friend ostream& operator<<(ostream &out, Examination &e);
	/** \brief Insert formatted input
	*/
	friend istream& operator >> (istream &is, Examination &e);

private:
	int day;		///<examination date: day
	int month;		///<examination date: month
	int year;		///<examination date: year

	double TSH;		///<examination results: TSH
	double FT3;		///<examination results: FT3
	double FT4;		///<examination results: FT4
	bool antyTSH;	///<examination results: anty-TSH
};

