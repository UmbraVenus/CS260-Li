#include "dlist.h"
#include <iostream>
using namespace std;

//put the implmenetation of the required functions here
int nums = 0;
int countEven(node *curr)
{
    cout << " === Counting the Doubly Linked List EVEN nodes" << endl;
    if (!curr->next){
        cout << curr->data << endl;
        if(curr->data % 2 == 0){
            ++nums;
        }
        cout << "Counting " << nums  << " even. " << endl;
        cout << "=== Finished Counting" << endl;
        return nums;
    }else{
        cout << curr->data << endl;
        if(curr->data % 2 == 0){
            ++nums;
        }
        cout << "Counting " << nums  << " even. " << endl;
        return countEven(curr->next);
    }
}

int removeEven(node *&Head){
    if (!Head){
        cout << "No LIST!!!! Error!!!!!!!" << endl;
        return 0;
    }
    
        removeEven(Head, 0);
    
}

int removeEven(node *currHead, int nums){
    if (!currHead){
        cout << "End of Linked List" << endl;
        cout << "Removed " << nums << "nodes." << endl;
        return nums;
    }
if (currHead->data %2 == 0 && !currHead->previous){
        currHead->next->previous = NULL;
	
	cout << "Removing " << currHead->data  << " even. " << endl;
        return removeEven(currHead->next,nums);
}
    if (!currHead->next){
        if(currHead->data % 2 == 0){
            cout << "Removing " << currHead->data  << " even. " << endl;
            currHead->previous->next = NULL;
            ++nums;
            delete (currHead);
        }
        cout << "=== Finished Removing" << nums << " Even Nodes" << endl;
        return nums;
    }
    else{	
		if(currHead->data %2 == 0){
			node *temp = currHead;
			cout << "Removing " << currHead->data  << " even. " << endl;
                        currHead->previous->next = temp->next;
                        currHead->next->previous = temp->previous;
                        ++nums;
                        delete (currHead);
		}
        	return removeEven(currHead->next, nums);
	
    }
}


