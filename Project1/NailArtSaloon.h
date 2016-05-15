/**
* \class NailArtSaloon
*
* \brief Class representing Nail Art Saloon
*
* This class is representation of nail art saloon. It it a beauty studio
* that has special service list.
*
* \note Thos class is part of the second PROE project.
*
*/

#pragma once
#include "BeautyStudio.h"
#include <map>


using namespace std;
class NailArtSaloon : public BeautyStudio
{
public:
	///Constructor
	NailArtSaloon();
	///Destructor
	virtual ~NailArtSaloon();

	///Method for printing saloon's info to console
	void getInfo();
	/**
	* \brief Method for adding service to service list
	* \param service - name of service to be addedc
	* \param price - cost of added service
	*/
	void addService(string service, int price);

	/**
	* \brief Method for removing service from service list
	* \param service - name of service to be removed
	*/
	void removeService(string service);
	///Method for printing service list to console
	void listService();

	///Method for updating mean price for all services
	void updateMeanPrice();

	///Insert formatted output
	friend ostream& operator << (ostream& ost, NailArtSaloon& nas);
	///Insert formatted input 
	friend istream& operator >> (istream &is, NailArtSaloon&nas);


protected:
	map<string,int> service;	///<List of services
};

