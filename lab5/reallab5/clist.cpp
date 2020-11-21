#include "clist.h"
using namespace std;
// Write your functions in this file.
int count(node *head){
    node* temp = head;
   int result = 0;
   if (head != NULL){
      do {
         temp = temp->next;
         result++;
      } while (temp != head);
   }
   return result;
}

int countR(node *head)
{
    if (!head){
        cout << "Can't count! Error!" << endl;
        return 0;
    }
    countR(head->next, head, 1);
}

int countR(node *curr, node *head, int nums){
    if (curr == head){
        cout << "End of Linked List" << endl;
        return nums;
    }
    else{
        nums++;
        return countR(curr->next, head, nums);
    }
}

int sum(node *head){
    node *temp = head;
    int result = 0;
    if(head!=NULL){
        do {
            temp = temp->next;
            result += temp->data;
        } while (temp != head);
    }
    return result;
}


int sumR(node *head){
    if (!head){
        cout << "Can't count! Error!" << endl;
        return 0;
    }
    sumR(head->next, head, head->data);
}

int sumR(node *curr, node *head, int nums){
    if (curr == head){
        cout << "End of Linked List" << endl;
        return nums;
    }
    else{
        nums += curr->data;
        return sumR(curr->next, head, nums);
    }
}