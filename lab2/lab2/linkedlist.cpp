#include "linkedlist.h"
#include <iostream>
#include <ostream>
using namespace std;
//implementations for the member functions of LinkedList class
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList(){
    node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    size = 0;
}

void LinkedList::add(char ch){
    cout << "...Calling add method on..." << ch << endl;
    node *newnode = new node(ch);
    if (!head)
    {
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
    size++;
}

bool LinkedList::find(char ch){
    cout << "...Calling find method on..." << ch << endl;
    node *curr = head;
    while (curr != NULL){
        if (curr->data == ch){
            return true;
        }
        if (curr->next != NULL){
            curr = curr->next;
        } else {
            return false;
        }
    }
    return false;
}

bool LinkedList::del(char ch){
    cout << "...Calling delete method on..." << ch << endl;
    node *tmp = head;
    if (LinkedList::find(ch))
    {
        if (tmp->data == ch){
            head = tmp->next;
            delete tmp;
            cout << ch << " deleted" << endl;
            return true;
        }
        else {
            while (tmp!= NULL){ 
                if (tmp->data == ch){
                    node *curr = tmp;
                    curr->prev->next = tmp->next;
                    curr->next->prev = tmp->prev;
                    delete tmp;
                    cout << ch << " deleted" << endl;
                    return true;
                }
                tmp = tmp->next;
            }
            cout << "Unable to delete character" << endl;
            return false;
        }
    }
    cout << "No character found" << endl;
    return false;
}

std::ostream& operator<<(std::ostream& out, LinkedList& list){
    LinkedList::node *curr;
    cout << endl
        << "Displaying the list: " << endl;
    for (curr = list.head; curr; curr=curr->next){
        out << curr->data << endl;
    }
    cout << endl
         << "Displaying the reversed list: " << endl;
    for (curr = list.tail; curr; curr = curr->prev)
    {
        out << curr->data << endl;
    }
    cout << endl;
    return out;
}
