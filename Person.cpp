//File name:	Person.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	This is my own work
#include "Person.h"

// Prints a the name and sex of a person
ostream& operator<< (ostream& os, const Person& ps)
{
	os<<"P ("<<ps.name<<", "<<ps.sex<<")";
	
	return os;
}

Person::Person ()
{
	  // Do nothing
}

// Constuctor
Person::Person (const char name[], const char sex)
{
	strcpy (this -> name, name);
	this -> sex = sex;
}

// Copy constructor
Person::Person (const Person& ps)
{
	strcpy (this -> name, ps.name);
	this -> sex = ps.sex;
}

// Returns sex
char Person::getSex () const
{
	return sex;
}

// Copys name and sex from ps to "this" person
Person& Person::operator= (const Person& ps)
{
	strcpy (this -> name, ps.name);
	this -> sex = ps.sex;
	
	return *this;
}

