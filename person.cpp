/***************************************
 * implementation for person
 *
***************************************/
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "person.hpp"
std::vector<std::string> *setAttributes();
std::string getFirst(std::string);
std::string getValue(std::string);
std::string nts(int);
Person::Person()
{
	attributes = new std::vector<std::string>;
}

Person::~Person()
{
	delete attributes;
}

std::vector <std::string> *Person::getAttributes()
{
	attributes = setAttributes();
	return attributes;
}

std::vector<std::string> *setAttributes()
{ 
	std::vector<std::string> *attributes = new std::vector<std::string>;
	//generating name
	std::srand(time(NULL));
	int number = std::rand() % 2;
	if(number == 0)
		attributes->push_back("Female");
	else
		attributes->push_back("Male");
	attributes->push_back(getFirst(attributes->at(0)));
	attributes->push_back(getValue("lastNames.txt"));
		
	//get random number for email
	number = std::rand() %4044;
	std::string email = attributes->at(2) +"." + attributes->at(1) + nts(number) + "@gmail.com";
	attributes->push_back(email);

	//get ssn
	number = std::rand() % 888423;
	attributes->push_back(nts(number));
	return attributes;

}

std::string getFirst(std::string gender)
{
	if(!gender.compare("Female"))
		return getValue("femaleNames.txt");
	return getValue("maleNames.txt");

}

std::string getValue(std::string fileName)
{
	int number;
	std::string line =" ";
	std::ifstream file;
	file.open(fileName);
	std::srand(time(NULL));

	if(!fileName.compare("femaleNames.txt"))
		number = std::rand() % 4275;
	else if(!fileName.compare("maleNames.txt"))
		number = std::rand() % 1219;
	else 
		number = std::rand() % 2500;

	for(int i = 0 ; i < number; i ++)
		std::getline(file,line);
	return line;
}

std::string nts(int number)
{
	std::ostringstream ss;
	ss << number;
	return ss.str();
}
void Person::print()
{
	std::cout << "Gender: " << attributes->at(0) << std::endl;
	std::cout << "First Name: " << attributes->at(1) << std::endl;
	std::cout << "Last Name: " << attributes->at(2) << std::endl;
	std::cout << "Email: " << attributes->at(3) << std::endl;
	std::cout << "SSN: " << attributes->at(4) << std::endl;
}

