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
    Node *newNode;
    if(!head){
        head = newNode;
        head->value = value;
    }
    else
    {
        newNode->next = head;
        newNode->value = value;
        head = newNode;
    }
}

int LinkedList::sum(){
    cout << " === Summing Iteratively" << endl;
    int sum = 0;
    Node *curr = head;
    while (curr->next){
        sum += curr->value;
        cout << "Current Sum is ...." << sum << endl;
        curr = curr->next;
    }
    sum += curr->value;
    return sum;
}

int LinkedList::sumR(){
    cout << " === Summing Recursively" << endl;
    if (!head){
        cout << "No LIST!!!! Error!!!!!!!" << endl;
        return 0;
    }
    return _sumR(head);
}
int LinkedList::_sumR(Node* node){
    int sumr;
    if (node == head)
    {
        sumr = head->value;
    }
    if(node->next){
        sumr += node->value;
        return _sumR(node->next);
    }else{
        sumr += node->value;
        return sumr;
    }
}

ostream& operator<<(std::ostream& out, LinkedList& alist){
    LinkedList::Node * curr;

	out << endl << "Displaying the list ... " << endl;
	for(curr=aList.head; curr; curr=curr->next)
	{
		out << *(curr->value) << endl;
	}
}