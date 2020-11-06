/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project3/app.cpp
*/

#include "table.h"

Table::Table() : size(0)
{
	currCapacity = INIT_CAP;
	aTable = new Node*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aTable[i] = nullptr;
	}
}

Table::Table(Table& aTable) : aTable(nullptr), size(0)
{
	*this = aTable;
}

Table::~Table()
{
	destroy();
}

void Table::destroy()
{
	for(int i=0; i<currCapacity; i++)
	{
		destroyChain(aTable[i]);
	}
	if(aTable)
		delete [] aTable;
}

void Table::destroyChain(Node *& currHead)
{
	if(currHead)
	{
		destroyChain(currHead->next);
		delete currHead->data;
		delete currHead;
		currHead = nullptr;
	}
}
/*
void Table::add(website& aStudent)
{
	int 	index = calculateIndex(aStudent.getName());	
	Node *	newNode = new Node(aStudent);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}
*/

/*
A naive hashing function that only adds the ASCII value of each char in the
key field and mods the capacity of the table. i.e. "abc" and "cba" will result 
in the same index since it doesn't consider position value.
*/
int Table::calculateIndex(char * key)
{
	int hashingResult;

	//version 1
	hashingResult = 0;
	for(int i=0; i<strlen(key); i++)
	{
		hashingResult += key[i];
	}

	//version 2
	hashingResult = 0;
	int	keyLength = strlen(key);
	for(int i=0; i<keyLength; i++)
	{
		hashingResult += key[i];
	}

	//version 3
	hashingResult = 0;
	for(; *key != '\0'; key++)
	{
		hashingResult += *key;
	}	

	return hashingResult % currCapacity;
}


void Table::copyChain(Node * srcHead, Node *& destHead)
{
	if(srcHead)
	{
		destHead = new Node(*(srcHead->data));
		copyChain(srcHead->next, destHead->next);
	}
}

ostream& operator<< (ostream& out, Table& srcTable)
{
	out << endl << "Displaying the table ..." << endl;
	for(int i=0; i<srcTable.currCapacity; i++)
	{
		out << "Chain #" << i << " ... " << endl;
		srcTable.displayChain(out, srcTable.aTable[i]);
		out << endl;
	}
	return out;
}

void Table::displayChain(ostream& out, Node * currHead)
{
	if(currHead)
	{
		out << *(currHead->data) << endl;
		displayChain(out, currHead->next);
	}
}

void Table::loadFromFile(char * fileName)
{
	ifstream 	in;
	website		currStudent;
	const int 	MAX_CHAR = 101;
	char		currName[MAX_CHAR];
	float		currGpa;

	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	in.get(currName, MAX_CHAR, ';');
	while(!in.eof())
	{
		in.get();
		in >> currGpa;
		in.ignore(MAX_CHAR, '\n');
		
		currStudent.setName(currName);
		
		
		in.get(currName, MAX_CHAR, ';');
	}
	in.close();
}

