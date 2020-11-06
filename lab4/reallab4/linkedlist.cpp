#include <iostream>
#include <cstring>
#include "linkedlist.h"
using namespace std;
LinkedList::LinkedList(){
    head = nullptr;
    
}

LinkedList::~LinkedList(){
    Node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
}

void LinkedList::add(int value){
	cout << "\nAdding" << value << endl;
	append(head, value);
}

void LinkedList::append(Node *& first, int ch)
{
    if(!first)//the end of the list
    {
    first = new Node(ch);
    }
    else
    {
    //recursive call to append to the smaller list
    append(first->next, ch);
    }
}



int LinkedList::sum(){
    cout << " === Summing Iteratively" << endl;
    int sum = 0;
    Node *curr = head;
    while (curr->next!= NULL){
        sum += curr->value;
        cout << "Current Sum is ...." << sum << endl;
        curr = curr->next;
    }
    sum += curr->value;
    return sum;
}


int LinkedList::sumR(){
    cout << " === Summing Recursively" << endl;
    int first = head->value;
    if (head)
    {
        sumr += first; 
    }
    return _sumR(head->next);
}

int LinkedList::_sumR(Node* node){
    if(node->next){
        sumr += node->value;
	cout << sumr << endl;
        return _sumR(node->next);
    }else{
	sumr += node->value;
	cout << sumr << endl;
	return sumr;
}
}


ostream& operator<<(std::ostream& out, LinkedList& alist){
    LinkedList::Node * curr;

	out << endl << "Displaying the list ... " << endl;
	for(curr=alist.head; curr; curr=curr->next)
	{
		out << curr->value << endl;
	}
}
