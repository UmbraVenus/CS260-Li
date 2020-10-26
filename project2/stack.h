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

	void push();
	void push(Individual &anIndividual);
	bool pop(Individual &anIndividual); // pop the first and print
	void promoted();

	bool peekStack();
	int getStackSize();
	bool isStackEmpty();

	void loadFromStackFile(char * fileName);
	void saveToStackFile(char * fileName);

    friend ostream& operator<< (ostream& out, Stack& aStack);

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
