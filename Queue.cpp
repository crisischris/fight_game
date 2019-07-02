/******************************************************************************
** Author: Chris Nelson 
** Date: 05.16.2019 
** Description: This is the Queue class.  This class creates a circular linked 
** Queue structure for the user to manipulate 
******************************************************************************/

#include<iostream>
#include"Queue.hpp"
#include"Helper.hpp"
#include"Character.hpp"

Queue::Queue()
{
  head = NULL;
}

Queue::~Queue()
{
		if(!isEmpty())
	{
		QueueNode* nodePtr = head;

		for(int i = 0; i < queueCounter; i++)
		{
			QueueNode* garbage = nodePtr;
		  nodePtr = nodePtr->next;
			delete garbage->Char;
 			delete garbage;
		}
	}
}


//****************************************************************************
//this funciton returns the value of the first item
//****************************************************************************

Character* Queue::getFront()
{
	QueueNode* nodePtr = head;
	if(!isEmpty())
	{
		return head->Char; 
	}
  else
	{
 		Helper::printMessage("Your list is empty GET!",1);	
	}
	
}


//****************************************************************************
//this funciton adds a node to the tail of the list
//****************************************************************************

void Queue::addBack(Character* charIn)
{
	if(isEmpty())
	{
		head = new QueueNode(charIn);
		QueueNode* currList = head;
		currList->prev = NULL;
  	currList->next = NULL;
		queueCounter++;
	}
	else
	{
	  QueueNode* nodePtr = head;
		for(int i = 1; i < queueCounter; i++)
		{
			nodePtr = nodePtr->next;
		}
		//we've found the last node
 	 	QueueNode* currList;
		currList = new QueueNode(charIn);
 	  currList->prev = nodePtr;
		nodePtr->next = currList;
 	 	currList->next = NULL;
		queueCounter++;
	}
}



//****************************************************************************
//this funciton moves the head node to the tail node
//****************************************************************************

void Queue::moveHeadtoTail()
{
	QueueNode* nodePtr = head;
	//there is only one object in queue
	if(queueCounter != 1)
	{
		for(int i = 1; i < queueCounter; i++)
		{
			nodePtr = nodePtr->next;
		}
		//we've found the last node

		QueueNode* newTail = head;
		head = newTail->next;
		nodePtr->next = newTail;
		head->prev = NULL;
		newTail->next = NULL;
	}
}

//****************************************************************************
//this funciton adds a node to the list
//****************************************************************************

void Queue::addFront(Character* charIn)
{
	if(head == NULL)
	{
		head = new QueueNode(charIn);
		QueueNode* currList = head;
		currList->prev = NULL;
		currList->next = NULL;
		queueCounter++;
	}
	else
	{
		QueueNode* currList = head;

		head = new QueueNode(charIn);
		head->next = currList;
	  currList->prev = head;	
		head->prev = NULL;
		queueCounter++;
	}
}

//****************************************************************************
//this funciton removes a node to the head of the list
//****************************************************************************

void Queue::removeFront()
{
	QueueNode* nodePtr = head;

	if(queueCounter == 1)
	{
		delete nodePtr;
		head = NULL;
		queueCounter--;
	}
	//we have at least one item in our list
  else if(queueCounter > 1)
	{
		QueueNode* tempPtr = head->next;	
  	//first item of the list
		head = tempPtr; 
		head->prev = NULL;
		delete nodePtr;
		queueCounter--;
	}
	else
	{
 		Helper::printMessage("Your list is empty REMOVE!",1);	
	}
	
}

//****************************************************************************
//this funciton displays the list from head to tail
//****************************************************************************

void Queue::printQueue()
{
	QueueNode* nodePtr = head;
	if(isEmpty())
	{
		Helper::printMessage("Empty list",0);
	}
  for(int i = 0; i < queueCounter; i++)
	{
		std::cout << nodePtr->Char->getName() << " -> ";
		nodePtr = nodePtr->next;
		
	}
}

//****************************************************************************
//this funciton determines of the Queue is empty.  returns true if so
//****************************************************************************

bool Queue::isEmpty()
{
	if(queueCounter == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}





int Queue::getSize()
{
	return queueCounter;
}
