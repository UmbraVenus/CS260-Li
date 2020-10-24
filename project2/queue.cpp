/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/queue.cpp
*/

#include "queue.h"
#include <iostream>
#include <cstring>
using namespace std;
/**
 * Queue::Queue 
 * Constructors & Destructors
 */
Queue::Queue(){
  front = nullptr;
  back = nullptr;
  size = 0;
}
Queue::~Queue(){
  destroy(front);
}
void Queue::destroy(Node * currHead){
  if(currHead)
	{
		destroy(currHead->next);
		delete currHead;
	}
}


/**
 * Queue 
 * enqueue(), this is the prompt for user to enter their own
 */
void Queue::enqueue()
{
  char currName[MAX_CHAR];
  char currNums[MAX_CHAR];
  char currAccomodation[MAX_CHAR];
  char currPromotion[MAX_CHAR];
  int nums;

  cout << " ==== Input the Group Name >> ";
  cin.getline(currName, MAX_CHAR);
    
  cout << " ==== Input the number of people >> ";
  cin.getline(currNums, MAX_CHAR);
    
	cout << " ==== Input if there is special accomodation >> ";
  cin.getline(currAccomodation, MAX_CHAR);

  cout << " ==== Would you like to receive promotions? " << endl;
  cout << " ==== Input yes/no (Case Sensitive) >> ";
  cin.getline(currPromotion, MAX_CHAR);

  nums = atoi(currNums);
  Customer newCustomer;

  newCustomer.setName(currName);
  newCustomer.setNums(nums);
  newCustomer.setAccomodation(currAccomodation);
  newCustomer.setPromotion(currPromotion);

  enqueue(newCustomer);
}

/**
 * Queue 
 * Actually adding custommer to the queue
 * @param  {Customer} acustomer : 
 */
void Queue::enqueue(Customer &acustomer){
  Node *temp = new Node;
  temp->data.setName(acustomer.getName());
  temp->data.setNums(acustomer.getNums());
  temp->data.setAccomodation(acustomer.getAccomodation());
  temp->data.setPromotion(acustomer.getPromotion());
  cout << temp->data.getName() << "  " << endl;
  cout << temp->data.getNums() << "  " << endl;
  cout << temp->data.getAccomodation() << "  " << endl;
  cout << temp->data.getPromotion() << "  " << endl;
  if (front == NULL)
  {
      front = temp;
  }
  else
  {
      back->next=temp;
  }
  back=temp;
  back->next=front;
}


/**
 * Queue 
 * Seat the customer
 * @return {bool}  : 
 */
bool Queue::dequeue()
{
  if(front==NULL)
  {
      cout<<"\nCircular Queue Empty!!!";
      return false;
  }
  if(front==back)
     {
       free(front);
       front=NULL;
       back=NULL;
       return true;
     }
     else
     {
       Node *temp = new Node;
       front = front->next;
       back->next = front;
       free(temp);
       return true;
     }
}

/**
 * Queue 
 * Display the queue
 */
void Queue::displayQueue()
{
  cout<<"\n\nCircular Queue Elements are:\n";
  Node *temp = front;
  while (temp->next != front)
  {
    cout << " ==== [Name] ==== " << temp->data.getName() << endl;
  cout << " [Size]: " << temp->data.getNums();
  cout << " [Accomodation]: " << temp->data.getAccomodation();
  cout << " [Interested?]: " << temp->data.getPromotion() << endl;
    temp = temp->next;
  }

  cout << " ==== [Name] ==== " << temp->data.getName() << endl;
  cout << " [Size]: " << temp->data.getNums();
  cout << " [Accomodation]: " << temp->data.getAccomodation();
  cout << " [Interested?]: " << temp->data.getPromotion() << endl;

}

/**
 * Queue 
 * Save to "queue.txt"
 */
void Queue::saveToQueueFile(){
  cout << endl << "saving to Queue File" << endl;
  ofstream out;
  out.open("queue.txt");

  if(!out){
    cerr << "Fail to open " << "queue.txt" << " for reading!" << endl;
		exit(1);
  }
  Node *temp = front;
  while (temp->next != front)
  {
    out << temp->data.getName() << endl;
    out << temp->data.getNums() << endl;
    out << temp->data.getAccomodation() << endl;
    out << temp->data.getPromotion() << endl;
    temp = temp->next;
  }

    out << temp->data.getName() << endl;
    out << temp->data.getNums() << endl;
    out << temp->data.getAccomodation() << endl;
    out << temp->data.getPromotion() << endl;
  out.close();
  
}
/**
 * Queue 
 * Load queue from "queue.txt"
 */
void Queue::loadFromQueueFile(){
  ifstream in;
  in.open("queue.txt");
	if(!in)
	{
		cerr << "Fail to open " << "queue.txt" << " for reading!" << endl;
		exit(1);
	}
  char currName[MAX_CHAR];
  char currNums[MAX_CHAR];
  char currAccomodation[MAX_CHAR];
  char currPromotion[MAX_CHAR];
  int nums;

  while(!in.eof()){
      in.getline(currName, MAX_CHAR);
      in.getline(currNums, MAX_CHAR);
      in.getline(currAccomodation, MAX_CHAR);
      in.getline(currPromotion, MAX_CHAR);
      nums = atoi(currNums);
      Customer newCustomer;
      newCustomer.setName(currName);
      newCustomer.setNums(nums);
      newCustomer.setAccomodation(currAccomodation);
      newCustomer.setPromotion(currPromotion);
      enqueue(newCustomer);
      cout << newCustomer.getName() << " added." << endl;
      cout << newCustomer.getNums() << " added." << endl;
      cout << newCustomer.getAccomodation() << " added." << endl;
      cout << newCustomer.getPromotion() << " added." << endl;
  }
    in.close();
    cout << "File closed" << endl;
}

/**
 * Queue 
 * see the first entry
 * @return {bool}  : 
 */
bool Queue::peekQueue(){
  if(front==NULL)
  {
      cout<<"\nCircular Queue Empty!!!";
      return false;
  }
  else
  {
      cout << front->data.getName() << endl;
      cout << front->data.getNums() << endl;
      cout << front->data.getAccomodation() << endl;
      cout << front->data.getPromotion() << endl;
      if(front->data.getPromotion()== "yes"){
        return true;
      }
      else{
        return false;
      }
  }
}

/**
 * Queue 
 * 
 * @return {int}  : size of the queue
 */
int Queue::getQueueSize(){
  if(isQueueEmpty()){
    size = 0;
  }
  else{
    Node *temp = front;
    size = 1;
    while (temp->next != front)
    {
      size++;
      temp = temp->next;
    }
  }
  return size;
}
bool Queue::isQueueEmpty(){
  if(front==NULL)
  {
      cout<<"\nCircular Queue Empty!!!";
      return true;
  }
}