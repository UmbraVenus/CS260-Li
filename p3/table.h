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

    void add( website& aStudent);

/*
	
	
	bool remove();
	bool   retrieve(char   *  topic_keyword,   website   all_matches[],   int & num_found);
	int getSize();
	
	


    1.Constructor
2.Destructor (deallocate the hash table)

// Where topic is the key
3.Insert  a  new  website  by  topic (add  website’s  information  into  the  hash table)

4.Retrieve (retrieve all websites based on the topic keyword supplied)

5.Edit (modify the review and rating for a particular topic and website match)

6.Remove (remove all websites with a 1-star rating)

7.Display (only displaying matches, based on the topic keyword)

8.Display all

*/

	void loadFromFile(char * fileName);


    friend ostream& operator<< (ostream& out, Table& aTable);

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
	const static int	INIT_CAP = 10;
	int					currCapacity;
	int 				size;

	int calculateIndex(char * key);
	void destroy();
	void destroyChain(Node *& currHead);
	void copyChain(Node * srcHead, Node *& destHead);
	void displayChain(ostream& out, Node * currHead);
	void writeOutChain(ostream& out, Node * currHead);
};

#endif 
