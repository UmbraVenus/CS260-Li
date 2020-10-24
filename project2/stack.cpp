/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/stack.cpp
*/

#include "stack.h"
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_CHAR = 250;

/**
 * Constructor & Destructor
 * @param  {0 []} undefined  : 
 * @return {Stack::Stack()}  : 
 */
Stack::Stack() : top(0)
{
	currCapacity = INIT_CAP;
	aStack = new Individual*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aStack[i] = nullptr;
	}
}
Stack::Stack(Stack& aStack) : aStack(nullptr), top(0)
{
	*this = aStack;
}
Stack::~Stack()
{
	destroy();
}
void Stack::destroy()
{
	for(int i=0; i<top; i++)
	{
		if(aStack[i])
			delete aStack[i];
	}
	if(aStack)
		delete [] aStack;
}

void Stack::push()
{
	char currName[MAX_CHAR];
  	char currEmail[MAX_CHAR];

  	cout << " ==== Input Your Name >> ";
  	cin.getline(currName, MAX_CHAR);
    
  	cout << " ==== Input the number of people >> ";
  	cin.getline(currEmail, MAX_CHAR);

	Individual *newIndividual = new Individual;

	newIndividual->setFullName(currName);
	newIndividual->setEmail(currEmail);

	push(*newIndividual);
}

void Stack::push(Individual &anIndividual){
	if(currCapacity == top)
	{
		expand();
	}
	aStack[top] = new Individual(anIndividual);	
	top++;
}

void Stack::expand()
{
	currCapacity *= GROWTH_FACTOR;
	Individual ** tempStack = new Individual*[currCapacity];
	for(int i=0; i<top; i++)
	{
		tempStack[i] = aStack[i]; //only copy the pointers
	}
	delete [] aStack;
	aStack = tempStack;
}

Individual* Stack::pop()
{
	if(!top==0){
		Individual *anIndividual = new Individual;
		anIndividual = aStack[top - 1];
		delete aStack[top - 1];
		top--;
		return anIndividual;
	}
	
}

void Stack::displayStack()
{
	cout << endl << "Displaying the stack ..." << endl;
	for(int i=0; i< top; i++)
	{
		cout << aStack[i]->getFullName() << endl;
		cout << "==== " << aStack[i]->getEmail() << endl;
	}
}

void Stack::loadFromStackFile(char * fileName)
{
	ifstream 	in;
	char		currName[MAX_CHAR];
	char currEmail[MAX_CHAR];
	Individual *newIndividual = new Individual;

	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	while(!in.eof()){
      in.getline(currName, MAX_CHAR);
      in.getline(currEmail, MAX_CHAR);
      
	  newIndividual->setFullName(currName);
	  newIndividual->setEmail(currEmail);
	  push(*newIndividual);
	  cout << newIndividual->getFullName() << " added." << endl;
	  cout << newIndividual->getEmail() << " added." << endl;
  }
	in.close();
	cout << "File closed" << endl;
}

void Stack::saveToStackFile(char * fileName)
{
	ofstream	out;
	
	out.open(fileName);
	if(!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for(int i=0; i<top; i++)
	{
		out << aStack[i]->getFullName() << endl;
		out << aStack[i]->getEmail() << endl;
	}
	out.close();
}
	
