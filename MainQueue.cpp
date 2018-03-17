//File name:	MainQueue.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	This is my own work
#include "Queue.h"
#include <fstream>

bool fileToQueue (ifstream&, char [], Queue&);	// Inserts into queue from file
void dequeueAll (Queue&);						// Dequeues the queue until it is empty
void line ();									// Prints a line

int main ()
{
	Queue q;
	ifstream qfile;
	char fileName [MAX];

	cout<<"Enter file name: ";
	cin.getline (fileName, MAX);
	line ();
	
	try
	{
		cout<<"Testing of empty queue..."<<endl;
		
		if (q.isEmpty ())					// Checks if queue is empty
			cout<<"Queue empty"<<endl;
		else
			throw exception ();
	}
	catch (exception e)						// Dequeues the queue if it is not empty
	{										// until it is empty
		cout<<"Queue not empty!"<<endl;
		dequeueAll (q);
	}
	
	line ();
	
	try
	{
		if (!fileToQueue (qfile, fileName,q))	// Checks if error opening file
			throw exception ();
			
		line ();
		
		cout<<"Printing of q as an object ..."<<endl;
		
		if (q.isEmpty ())						// Checks if queue is empty before printing
			cout<<"Empty queue";
		else
			cout<<q;	  	  	  	  	  	  // Prints out list of persons in the queue
			
		cout<<endl;
		line ();
		
		cout<<"Testing of dequeue operation"<<endl;
		
		if (q.isEmpty ())						// Checks if queue is empty before dequeuing
			cout<<"Empty Queue"<<endl;
		else
			dequeueAll (q);						// Dequeues all elements if it is not empty
	}
	catch (exception e)							// Skips to here is error opening file
	{
		cout<<"Error opening file: "<<fileName<<endl;
	}

	return 0;
}

// Inserts into queue from file
bool fileToQueue (ifstream& infile, char title [], Queue& q)
{
	try
	{
		infile.open (title);
		if (!infile)
			throw exception ();
		
		char name [MAX];
		char sex;
		
		while (infile>>sex)	// Gets sex
		{
			infile.get();				// Deals with the space/tab
			infile.getline (name, MAX);	// Gets the name
			
			Person ps (name, sex);		// Creates a person object
			q.enqueue (ps);				// Enqueues the person
			
			// Displaying the person enqueued
			switch (sex)
			{
				case 'M':	cout<<"Gentleman ";
							break;
							
				default:	cout<<"Lady ";
			}
			
			cout<<name<<" inserted into queue"<<endl;
		}
			
		infile.close ();
		return true;
	}
	catch (exception e)	// If error opening file
	{
		cout<<"Unable to open "<<title<<endl;
		return false;
	}
}

// Dequeues the queue until it is empty
void dequeueAll (Queue& q)
{
	while (!q.isEmpty ())
	{
		cout<<q.dequeue ()<<" was deleted"<<endl;
	}
}

// Prints a line
void line ()
{
	cout<<"---------------------------------------------"<<endl;
}

