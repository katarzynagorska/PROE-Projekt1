/**
* \file  utilities.h
* \brief Provides some usefull functions.
*/

/**
* \name    Utilities
* \brief   Provides useful functions used in different headers
*/


#pragma once
#include <string>
#include <iostream>

using namespace std;

/**
* \brief Function for getting UI menu choice
* \return ch - choice (if correct)
* \return 'a' - if choice wasn't correct
*/

char getMenuChoice() {
	char ch;
	string input;

	while (cin.peek() == '\n')getline(cin, input);
	getline(cin, input);

	if (input.length() != 1) 
		ch = 'a';
	else
		ch = input.at(0);

	return ch;
}

/**
* \brief Function checking if string is double
* \param s - string to be verified
* \return true if string is representation of double number
* \return false otherwise
*/
bool is_double(string &s) {
	int comas = 0;
	if (s.empty())
		return false;
	string::const_iterator it = s.begin();

	while (it != s.end() && (isdigit(*it) || (*it == '.')))
	{
		if (*it == '.')
			comas++;
		it++;
	}
	return ((it == s.end()) && (comas < 2));
}

/**
* \brief Function checking if string is double
* \param s - string to be verified
* \return true if string is representation of integer > 0
* \return false otherwise
*/
bool is_number(const string& s)
{
	if (s.empty())
		return false;
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return it == s.end();
}