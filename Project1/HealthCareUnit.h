/**
* \class HealthCareUnit
*
* \brief Class representing abstract Health Care Unit
*
* This class is representation of health care unit It it an abstract class.
*
* \note Thos class is part of the second PROE project.
*
*
*/

#pragma once
#include <string>
#include <vector>

using namespace std;

class HealthCareUnit
{
public:
	///Constructor
	HealthCareUnit();
	///Destructor
	virtual ~HealthCareUnit();
	///Abstract method
	virtual void getInfo() = 0;
	///Method for every health care unit
	void listEquipment();
	/**
	* \brief Method for adding equipment to equipment list
	* \param s - name of the equipment to be added
	*/
	void addEquipment(string s);
	/**
	* \brief Method for removing equipment from equipment list
	* \param s - name of the equipment to be removed
	*/
	void removeEquipment(string eq);
	/**
	* \brief Method for asetting up address
	* \param eq - address
	*/
	void setAddress(string s);
	/**
	* \brief Method for asetting up name
	* \param s - name
	*/
	void setName(string s);
	/** \brief Insert formatted output
	*/
	friend istream& operator >> (istream& ist, HealthCareUnit& hcu);
	/** \brief Insert formatted input
	*/
	friend ostream& operator << (ostream& ost, HealthCareUnit& hcu);

protected:
	string address;				///<Address
	string name;				///<Name
	vector <string>equipment;	///<List of equipment
};

