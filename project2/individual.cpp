/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/individual.cpp
*/

#include "individual.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructors and Destructors
Individual::Individual(): fullName(nullptr), email(nullptr) {}
Individual::Individual(char * fullName, char *email){
    init(fullName, email);
}
void Individual::init(char * fullName, char *email){
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);
}
Individual::Individual(Individual& aStudent):fullName(nullptr), email(nullptr){
    *this = aStudent;
}

Individual::~Individual(){
    if(this->fullName){
        delete[] this->fullName;
    }
    this->fullName = nullptr;
}

// Getters and Setters
char * Individual::getFullName(){
    return fullName;
}

char *Individual::getEmail(){
    return email;
}

void Individual::setEmail(char *email){
    if(this->email)
	{
		delete [] this->email;
	}
	this->email = new char[strlen(email)+1];
	strcpy(this->email, email);
}

void Individual::setFullName(char *fullName){
    if(this->fullName)
	{
		delete [] this->fullName;
	}
	this->fullName = new char[strlen(fullName)+1];
	strcpy(this->fullName, fullName);
}

ostream& operator<< (ostream& out, Individual& aStudent)
{
	out << aStudent.getFullName() << '\t' << aStudent.getEmail() << endl;
	return out;
}