#include "dlist.h"
#include <iostream>
using namespace std;
//put the implmenetation of the required functions here
/* place your prototype here */
// recursively compute and return the number of nodes in the doublylinked list.
int nums = 0;
int count(node *curr){
    cout << " === Counting the Doubly Linked List nodes" << endl;
    if (!curr->next){
        cout << curr->data << endl;
        ++nums;
        cout << "Counting" << nums << endl;
        cout << "=== Finished Counting" << endl;
        return nums;
    }else{
        ++nums;
        cout << curr->data << endl;
        cout << "Counting" << nums << endl;
        return count(curr->next);
    }
}

// recursively insert newInt at index “position” where index starts from 0
void insert(node *&head, int newInt, int position){
    cout << "=== Calling insert Recursively..." << endl;
    if(!head || position < 0){
        cout << "Error Inserting" << endl;
    }
    else{
        return insert(head, newInt, 0, position);
    }
}

void insert(node *currHead, int newInt, int currPosition, int position){
    if(!currHead){
        cout << "Finished Inserting" << endl;
    }
    if (currPosition == position){
        node * newNode = new node;
	newNode->data = newInt;
		newNode->next = currHead;
		newNode->previous = currHead->previous;
		if(currHead->previous)
		{
			currHead->previous->next = newNode;
		}
		currHead->previous = newNode;
        cout << newInt << "inserted at " << currPosition << endl;
    }
else{

    insert(currHead->next, newInt, ++currPosition, position);
}
}

// recursivelyremove the integer at index “position” and return it.
int remove(node *&head, int position){
    if (position < 0){
        cout << "Invalid Position" << endl;
    }
    else{
        remove(head, 0, position);
    }
}

int remove(node *currHead, int currPosition, int position){
    int datanum;
    if(!currHead){
        cout << "End of Linked List" << endl;
        cout << "Error" << endl;
        return 0;
    }
    if(currPosition==position){
        cout << "Found at " << position << endl;
        node *temp = currHead;
        if(currHead->next){
            currHead->previous->next = temp->next;
            currHead->next->previous = temp->previous;
        }
        else{
            currHead->previous->next = nullptr;
        }
        datanum = currHead->data;
        cout << "Removing " << currHead->data << endl;
        delete (currHead);
        return datanum;
    }
    return remove(currHead->next, ++currPosition, position);
}
