//File name:	Queue.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	This is my own work
#include "Queue.h"

int Queue::size = 0;	// Sets the initial size of the queue to zero

// Prints out the whole queue
ostream& operator<< (ostream& os, const Queue& q)
{
	q.displayQueue ();
	return os;
}

// Creates an empty queue
Queue::Queue ()
{
	head = NULL;
	tail = NULL;
}

// Enqueues a person into the queue by taking care of the "Ladies first features"
void Queue::enqueue (const Person& ps)
{
	size++;		// Increases the size by one each time a person is added
	
	if (ps.getSex () == 'M' || isEmpty ())	// If queues is empty or person is a male
		addTail (ps);						// we just add to the back of the queue
		
	else									// If person is a lady and queue is not empty
	{	 
		NodePtr pSuc = head;
		
		while (pSuc != NULL && pSuc -> p.getSex () == 'F')	// Finding the successor node
			pSuc = pSuc -> next;
			
		if (pSuc == NULL)				// If node goes to the back
			addTail (ps);
		else
		{
			NodePtr pNew = new Node;
			pNew -> p = ps;
			
			pNew -> next = pSuc;				// Fills pNew's next and prev pointers
			pNew -> prev = pSuc -> prev;
			if (pSuc -> prev != NULL)			// If not at the start of the list
				pSuc -> prev -> next = pNew;
			else								// If adding at head of the list
				head = pNew;
			pSuc -> prev = pNew;
		}
			
	}
}

// Dequeues a person from the queue
Person Queue::dequeue ()
{
	size--;				// Decrements the size of the queue
	
	NodePtr pDel = head;
	head = head -> next;
	
	if (head == NULL)
		tail = NULL;
	else
		head -> prev = NULL;
	
	Person ps (pDel -> p);
	delete pDel;
	
	return ps;
}

// Returns the size of the queue
int Queue::getSize () const
{
	return size;
}

// Returns true if queue is empty, false otherwise
bool Queue::isEmpty () const
{
	return (size == 0);
}

// Adds a node to the tail of the queue
void Queue::addTail (const Person& ps)
{
	NodePtr pNew = new Node;
	pNew -> p = ps;
	pNew -> next = NULL;
	pNew -> prev = tail;
	
	if (tail == NULL)
		head = pNew;
	else
		tail -> next = pNew;
	
	tail = pNew;
}

// Prints the whole queue
void Queue::displayQueue () const
{
	NodePtr pCur = head;
	
	while (pCur != NULL)
	{
		cout<<pCur -> p<<endl;
		pCur = pCur -> next;
	}
}

