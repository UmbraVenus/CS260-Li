#include <iostream>
#include <cstring>
#include "linkedlist.h"

using namespace std;
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList(){
    Node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    size = 0;
}

void LinkedList::print() const
{
    cout << endl << "printing..." << endl;
//invoke recursive private member function
    print(head);
}

void LinkedList::print(Node * first) const
{
    if (first)
    {
    cout << first->data << endl;
    //recursive call to print the rest of the list
    print(first->next);
    }
}

void LinkedList::add(char ch){
    cout << "\nAdding " << ch << endl;
    append(head, ch);
}

void LinkedList::append(Node *& first, char ch)
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

bool LinkedList::find(char ch){
    find(head, ch);
}

bool LinkedList::find(Node *&first, char ch){
    if(first != NULL){
        if(first->data == ch){
            return true;
        }
        if (first->next != NULL){
            find(first->next, ch);
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
    return false;
}



bool LinkedList::del(char ch){
    Node *tmp = head;
    if (head->data == ch)
    {
        head = tmp->next;
        delete tmp;
        return true;
    } else{
        del(head->next, ch);
    }
}

bool LinkedList::del(Node *&first, char ch){
    if (find(ch)){
        Node *curr = first;
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete first;
        return true;
    }  
    else{
        if (first->next){
            first = first->next;
            del(ch);
        }
        else{
            return false;
        }
    }
}

/*
bool LinkedList::del(char ch){
    cout << "...Calling delete method on... " << ch << endl;
    Node *tmp = head;
    if (find(ch)){
        if (head->data == ch)
        {
            head = tmp->next;
            delete tmp;
            cout << ch << " deleted" << endl;
            return true;
        }
    }
    else{
        if (tmp->next!=NULL){
            
            if(tmp->data == ch){
                Node *curr = tmp;
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                delete tmp;
                cout << endl << ch << " deleted" << endl;
            }
            else{
                tmp = tmp->next;
                del(ch);
            }
        }
        else{
            return false;
        }
    }
}
*/

