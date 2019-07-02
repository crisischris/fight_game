#ifndef   QUEUE_HPP
#define   QUEUE_HPP 

#include"Character.hpp"
#include<string>

class Queue 
{
  public:
	Queue();
	~Queue();
	bool isEmpty();
  void addBack(Character*);
  void addFront(Character*);
  Character* getFront();
	void removeFront();
	void printQueue();
	void moveHeadtoTail();
  int getSize();



  protected:
  struct QueueNode 
  {
 		Character* Char;
		QueueNode* next;
		QueueNode* prev;
  	QueueNode(Character* inChar, QueueNode* inNext = NULL)
		{
			Char = inChar;	
			next = inNext;
		}
	};
	QueueNode* head;
	int queueCounter = 0;

  private:


};
#endif

