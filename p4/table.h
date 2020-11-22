/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project4/table.h
*/

#ifndef TABLE_H
#define TABLE_H
#include "website.h"
#include <fstream>

class Table 
{
public:
	Table();
	Table(Table& aTable);
	~Table();

    void addingPrompt();
    void add(website &aStudent);
    bool remove(char * key, website& aStudent);
	/*
	bool retrieve(char * key, Student& aStudent);
	int getSize();
	*/
	Table& operator= (Table& aTable);
	friend ostream& operator<< (ostream& out, Table& aTable);

	void loadFromFile(char * fileName);
	
private:
	struct Node
	{
		Node(website& aStudent)
		{
			data = new website(aStudent);
			left = right = nullptr;
		};
		
		website *	data;
		Node *		left;
		Node *		right;
	};

	Node *	root;
	int 	size;

	void add(Node *& currRoot, website& aStudent);
	bool remove(Node *& currRoot, char * key, website& aStudent);
	void deleteNode(Node *& target);
	void destroy(Node *& currRoot);
	void copy(Node * srcRoot, Node *& destRoot);
    void display(ostream &out, Node *currRoot);
    void displayPreorder(ostream &out, Node *currRoot);
    void displayInorder(ostream& out, Node * currRoot);
	void displayPostorder(ostream& out, Node * currRoot);
	void loadFromArray(website * studentList, int first, int last);
};

#endif 
