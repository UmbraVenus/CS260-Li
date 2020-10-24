#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>
#include <cstring>
using namespace std;

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList& list);
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);

private:
	struct node 
	{
		node(char ch){
			data = ch;
			prev = next = nullptr;
		}
		~node(){
			data = 0;
			prev = next = nullptr;
		}
		char data;
		node *prev;
		node *next;
	};
	node *head, *tail;
	int size;
};

#endif // _LINKED_LIST_
