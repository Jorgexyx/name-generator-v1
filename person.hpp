/************************************** 
 * file: person.hpp
 * Author: Jorge Bautista
 * Purpose: This class
 * 	    represents a person 
 * 	    for the name generator 
 * 	    challenge
 *************************************/
#include <string>
#include <vector>
class Person
{
	public:
		Person();
		~Person();
		std::vector<std::string> *getAttributes();
		void print();
	private:
		std::vector <std::string> *attributes;
};
