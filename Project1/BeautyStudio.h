/**
* \class BeautyStudio
*
* \brief Class representing BeautyStudio
*
* This class is representation of beauty studio. It it a health Care Unit
* that has beauticians and price for services.
*
* \note Thos class is part of the second PROE project.
*
*
*/

#pragma once
#include "HealthCareUnit.h"

class BeautyStudio : public HealthCareUnit
{
public:

	BeautyStudio();
	virtual ~BeautyStudio();

	///Method that prints information about objetct to console
	virtual void getInfo();

	/** \brief Function for adding beautician to the list of workers
	*  \param b - Beautician to be addesd to workers list
	*/
	void addBeautician(string b);

	/** \brief Function for removing beautician from the list of workers
	*  \param b - Beautician to be removed from the workers list
	*/
	void removeBeautician(string b);

	///Function for printing workers list to console
	void listBeauticians();

	/** \brief Function for setting up service price
	*  \param price - New service price value
	*/
	void setPrice(int price);

	///Function for printing service price to console
	void getPrice();

	/** \brief Insert formatted output
	*/
	friend ostream& operator << (ostream& ost, BeautyStudio& bs);

	/** \brief Insert formatted input
	*/
	friend istream& operator >> (istream& ist, BeautyStudio& bs);

protected:
	vector<string> beautician;	///<list of workers
	int price;					///<service price
};

