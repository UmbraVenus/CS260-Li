/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project3/app.cpp
*/

#include <iostream>
#include <cstring>
#include "table.h"
#include "website.h"

using namespace std;

int mainMenu();

const int MAX_CHAR = 1000;
const char choice1[] = "1. Insert a new website by topic ";  
const char choice2[] = "2. Only displaying matched wesbite  ";
const char choice3[] = "3. Modify the review and rating for a particular topic and website match ";
const char choice4[] = "4. Remove all websites with a 1 star rating ";
const char choice5[] = "5. Retrieve all websites based on the topic keyword supplied ";
const char choice6[] = "6. Display all stored websites ";

int main(){

    cout << "Enetering" << endl;
    Table webs;
    website* results;
    char fileName[] = "website.txt";
    cout << "Enetering" << endl;
    webs.loadFromFile(fileName);
    cout << "Enetering" << endl;
    cout << webs << endl;

    int choice = mainMenu();

    while (choice > 0)
    {
        switch (choice)
        {
            cout << "--------------------" << endl;
            cout << "You have chosen: " << endl;
            case 1:
            {
                // Insert a new website by topic
                cout << choice1 << endl;
                webs.AddingPrompt();
                break;
            }
            case 5: 
            {
                // Retrieve all websites based on the topic keyword supplied
                cout << choice2 << endl;
                webs.retrieveCategory(results);
                break;
            }
			case 3:
            {
                // Modify the review and rating for a particular topic and website match
                cout << choice3 << endl;
                webs.modify();
                break;
            }
			case 4: 
            {
                // Remove all websites with a 1 star rating
                cout << choice4  << endl;
                webs.remove();
                break;
            }
			case 2: 
            {
                
                // Only displaying matched wesbite
                cout << choice5 << endl;
                webs.displayCategory();
                break;
            }
            case 6: 
            {
                // Display all stored websites
                cout << choice6 << endl;
                cout << webs << endl;
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
		choice = mainMenu();
	}
	cout << "\n!!!!Boom! Your program exploded!!!!\n" << endl;
    return 0;
}

int mainMenu()
{
	cout << "====== Welcome to The Website Selector ======\n";

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
    char c[MAX_CHAR];
    cout << "\n ==== Enter 1-7 to make your selection ==== " << endl;
    cout << " ==== >> " << endl;
    cin.getline(c, MAX_CHAR);
    //cin only gets the first component, use getline to get everything
    selection = atoi(c);
    return selection;
}