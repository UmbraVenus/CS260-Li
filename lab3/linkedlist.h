#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{private:
	struct 	Node 
	{
		Node(char ch){
			data = ch;
			next = prev = nullptr;
		}
		~Node(){
			data = 0;
			next = prev =nullptr;
		}
		char data;
		Node *next, *prev;
	};
	Node *head, *tail;
	int size;

	

public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);
	
	void print() const;
	void append(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);

	void print(Node * first) const;
	//pay attention to the passing by reference part below!
	void append(Node*& first, char ch);
	bool find(Node *&first, char ch);
	bool del(Node *&first, char ch);
};

#endif // _LINKED_LIST_
