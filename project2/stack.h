/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/stack.h
*/

#ifndef STACK_H
#define STACK_H
#include "individual.h"
#include <fstream>

class Stack 
{
public:
	Stack();
	Stack(Stack& aStack);
	~Stack();

	void create_new();
	void push();
	void push(Individual &anIndividual);
	Individual* pop(); // pop the first and print

	bool peekStack();
	int getStackSize();
	bool isStackEmpty();

	void loadFromStackFile(char * fileName);
	void saveToStackFile(char * fileName);

    void displayStack();

private:
	Individual**			aStack;
	int	INIT_CAP = 5;
	int	GROWTH_FACTOR = 3;
	int					currCapacity;
	int 				top;

	void destroy();
	void expand();
};

#endif 
