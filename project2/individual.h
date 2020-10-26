/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/individual.h
*/

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
using namespace std;
#include <cstring>

class Individual
{
public:
	Individual();
	Individual(char * fullName, char *email);
	Individual(Individual& aStudent);
	~Individual();

	char * getFullName();
    char *getEmail();
    void setEmail(char *email);
    void setFullName(char *name);
    friend ostream& operator<< (ostream& out, Individual& aStudent);	

private:
	char *fullName;
    char *email;

    void init(char * fullName, char *email);
};

#endif