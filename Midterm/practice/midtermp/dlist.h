#ifndef DLIST_H
#define DLIST_H
//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>


struct node
{
    int data;
    node * previous;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
/* place your prototype here */
int count(node *head);
// recursively compute and return the number of nodes in the doublylinked list.
void insert(node *&head, int newInt, int position);
// recursively insert newInt at index “position” where index starts from 0
void insert(node *currHead, int newInt, int currPosition, int position);

int remove(node *&head, int position);
// recursively remove the integer at index “position” and return it.
int remove(node *currHead, int currPosition, int position);

#endif
