#ifndef TABLE_H
#define TABLE_H
/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project3/app.cpp
*/

#include <fstream>
using namespace std;
#include "website.h"

class Table 
{
public:
	Table();
	Table(Table& aTable);
	~Table();

	void AddingPrompt();
	void add(website &aStudent);
	void loadFromFile(char * fileName);

	void retrieveCategory(website results[]);

	void modify();

	void remove();

	Table& operator= (Table& aTable);
    friend ostream& operator<< (ostream& out, Table& aTable);
	void displayCategory();
	

private:
	struct Node
	{
		Node(website& aStudent)
		{
			data = new website(aStudent);
			next = nullptr;
		};
		
		website *	data;
		Node *		next;
	};
	Node** 				aTable;
	int	INIT_CAP = 10;
	int					currCapacity;
	int 				size;

	int calculateIndex(char * key);
	void destroy();
	void destroyChain(Node *& currHead);
	void copyChain(Node * srcHead, Node *& destHead);
	void displayChain(Node * currHead);
	void getEntry(Node *currHead);
	void removeChain(Node *removeChain);
	void writeOutChain(ostream &out, Node *currHead);
};

#endif 
