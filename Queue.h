//File name:	Queue.h
//Name:			Tan Shi Terng Leon
//Declaration:	This is my own work
#include "Person.h"

class Queue
{
	friend ostream& operator<< (ostream& os, const Queue&);	  // Prints out the whole queue
	
	public:
			Queue ();						// Constructor
			
			void enqueue (const Person&);	// Enqueues a person into the queue
			Person dequeue ();				// Dequeues a person from the queue
			
			int getSize () const;			// Returns the size of the queue
			bool isEmpty () const;	  	  	  	  // Checks if the queue is empty
			
	private:
			struct Node;
			typedef Node* NodePtr;			// Pointer to a node in the queue
			
			struct Node						// A node in the queue
			{
				Person p;
				NodePtr next, prev;
			};
			
			NodePtr head, tail;				// Head and tail pointers of the queue
			static int size;				// Size of the queue
			
			void addTail (const Person&);	// Add a person at the tail of the queue
			void displayQueue () const;		// Prints the whole queue
};

