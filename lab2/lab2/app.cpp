#include <iostream>
#include "linkedlist.h"

using namespace std;

void find(LinkedList& list, char ch)
{
	if (list.find(ch))
		cout << "found ";
	else
		cout << "did not find ";
	cout << ch << endl;
}

int main()
{
	LinkedList	list;

	list.add('x');
	list.add('y');
	list.add('z');
	cout << list;
	find(list, 'y');

	list.del('y');
	cout << list;
	find(list, 'y');

	list.del('x');
	cout << list;
	find(list, 'y');

	list.del('z');
	cout << list;
	find(list, 'y');
	return 0;
}
