#include <iostream>
#include <string>
#include "person.hpp"
int main()
{
	Person *person = new Person();
	person->getAttributes();
	person->print();
	return 0;
}
