/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/app.cpp
*/

#include <iostream>
#include <cstring>
#include "customer.h"
#include "individual.h"
#include "queue.h"
#include "stack.h"

using namespace std;

int mainMenu();

const int MAX_CHAR = 250;
const char choice1[] = "1. Add group to queue.";   // Add at back
const char choice2[] = "2. Seat the front queue and get interest in promotions."; // Seat at front
const char choice3[] = "3. Peek the information of next group.";
const char choice4[] = "4. Display the number of waiting groups.";
const char choice5[] = "5. Handing out promotional materials in database.";
const char choice6[] = "6. Display all customers contacted for promotions.";

int main(){
    
    Queue Line;
    Stack PromoteStack;
    Stack ContactedStack;

    char queueFile[] = "queue.txt";
    char stackFile[] = "stack.txt";
    char contacted[] = "contacted.txt";

    Line.loadFromQueueFile();
    PromoteStack.loadFromStackFile(stackFile);
    ContactedStack.loadFromStackFile(contacted);

    Line.displayQueue();
    PromoteStack.displayStack();

    int choice = mainMenu();

    while (choice > 0)
    {
        switch (choice)
        {
            cout << "--------------------" << endl;
            case 1: 
            {
                cout << choice1 << endl;
                Line.enqueue();
                Line.saveToQueueFile();
                Line.displayQueue();
                break;
            }
            case 2: 
            {
                cout << choice2 << endl;
                if (Line.peekQueue()){
                    PromoteStack.push();
                    PromoteStack.saveToStackFile(stackFile);
                }
                Line.dequeue();
                Line.saveToQueueFile();
                break;
            }
			case 3:
            {
                cout << choice3 << endl;
                Line.peekQueue();
                break;
            }
			case 4: 
            {
                cout << choice4 << endl << endl;
                cout << "size: " << Line.getQueueSize() << endl;
                break;
            }
			case 5: 
            {
                cout << choice5 << endl;
                Individual *newIndividual = new Individual;
                newIndividual = PromoteStack.pop();
                ContactedStack.push(*newIndividual);
                break;
            }
            case 6: 
            {
                cout << choice6 << endl;
                ContactedStack.displayStack();
                break;
            }
            case 7: //exit
            {
                cout << "\n ==== You have chosen to Exit ==== " << endl;
                cout << "\n ==== Thank you so much for using this app! ==== " << endl;
                cout << "\n ==== Have a good one! :) ====\n" << endl;
                exit(1);
            }
            default: //input a positive integer outside of 1-6
            {
                cout << "\n!!!Please input a number from 1 to 6 in the menu.!!!\n" << endl;
                break;
            }
        }
        
        // PromoteStack.displayStack();
		choice = mainMenu();
	}
	cout << "\n!!!!Boom! Your program exploded!!!!\n" << endl;
    return 0;
}

int mainMenu()
{
	cout << "====== Welcome to The Restaurant ======\n";

	cout << "\n ====== $$$ Menu options $$$ ====== \n"; //menu options
	cout << "\n ====== $$$ Case Sensitive $$$ ====== \n"; //menu options
    cout << choice1 << endl;
    cout << choice2 << endl;
    cout << choice3 << endl;
    cout << choice4 << endl;
    cout << choice5 << endl;
    cout << choice6 << endl;
	cout << "7. Exit the program" << endl;

	int selection;
	cout << "\n ==== Enter 1-7 to make your selection ==== " << endl;
	cout << " ==== >> " << endl;
	cin >> selection;
	//cin only gets the first component, use getline to get everything
	cin.ignore(1000, '\n');
	return selection;
}