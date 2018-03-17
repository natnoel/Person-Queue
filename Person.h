//File name:	Person.h
//Name:			Tan Shi Terng Leon
//Declaration:	This is my own work
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;

class Person
{
	friend ostream& operator<< (ostream&, const Person&);	// Prints name and sex of
															// a person
	public:
			Person ();							// Do nothing
			Person (const char [], const char);
			Person (const Person&);
			
			char getSex () const;				// Returns sex
			Person& operator= (const Person&);	// Copys name and sex to "this" person
			
	private:
			char name [MAX];					// Name of the person
			char sex;							// Sex ofthe person
};

