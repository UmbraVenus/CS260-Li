#include "list.h"

List::List() : head(nullptr), tail(nullptr), size(0){}

List::List(const List& aList) : head(nullptr), tail(nullptr), size(0)
{
	*this = aList;
}

List::~List()
{
	destroy();
}

void List::destroy()
{
	Node * curr = head;
	while(curr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
	size = 0;
}


void List::append(const Student& aStudent)
{
	Node * newNode = new Node(aStudent);
	if(!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}

const List& List::operator= (const List& aList)
{
	if(this == &aList)
		return *this;
	destroy();
	size = aList.size;

	if(!aList.head)
	{
		head = tail = nullptr;
		return * this;
	}
	
	Node * newNode = new Node(*(aList.head->data));
	head = tail = newNode;

	Node * nextSrc = aList.head->next;
	Node * nextDes = head;
	while(nextSrc)
	{
		newNode = new Node(*(nextSrc->data));
		nextDes->next = newNode;
		newNode->prev = nextDes;
		nextSrc = nextSrc->next;
		nextDes = nextDes->next;
	}
	tail = nextDes;
	return *this;
}	

ostream& operator<< (ostream& out, const List& aList)
{
	List::Node * curr;

	out << endl << "Displaying the list ... " << endl;
	for(curr=aList.head; curr; curr=curr->next)
	{
		out << *(curr->data) << endl;
	}

	cout << endl << "Displaying the list in reverse ... " << endl;
	for(curr=aList.tail; curr; curr=curr->prev)
	{
		out << *(curr->data) << endl;
	}
	return out;
}

void List::loadFromFile(const char * fileName)
{
	ifstream 	in;
	Student		currStudent;
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
		currStudent.setGpa(currGpa);
		append(currStudent);
		in.get(currName, MAX_CHAR, ';');
	}
	in.close();
}

void List::saveToFile(const char * fileName) const
{
	ofstream	out;
	
	out.open(fileName);
	if(!out)
	{
		cerr << "Fail to open " << fileName << " for writing!" << endl;
		exit(1);
	}

	for(Node * curr=head; curr; curr=curr->next)
	{
		out << curr->data->getName() << ';' << curr->data->getGpa() << endl;
	}
	out.close();
}
	
