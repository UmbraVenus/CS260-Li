/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/queue.h
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "customer.h"
#include <fstream>

class Queue 
{
public:
	Queue();
	~Queue();

	const int MAX_CHAR = 250;

	void enqueue();
	void enqueue(Customer &acustomer);
	bool dequeue();

	bool peekQueue();	// return true if interested in promotions
	int getQueueSize();
	bool isQueueEmpty();

	void loadFromQueueFile();
	void saveToQueueFile();

	void displayQueue();

private:
	struct Node
	{
		Customer data;
		Node * next;
	};
	Node *front, *back;
	int size;
	void destroy(Node *currHead);
};

#endif 
