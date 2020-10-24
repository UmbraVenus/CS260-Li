/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/customer.h
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;
#include <cstring>

// A group of customers
class Customer
{
public:
	Customer();
	Customer(char * name, int nums, char *accomodation, char* promotion);
	Customer(Customer& aStudent);
	~Customer();

	char * getName();
    int getNums();
	char * getAccomodation();
    char * getPromotion();

    void setName(char *name);
    void setNums(int nums);
    void setAccomodation(char *accomodation);
    void setPromotion(char * promotion);

private:
	char *name;
    int nums;
    char *accomodation;
    char * promotion;

    void init(char * name, int nums, char *accomodation, char * promotion);
};

#endif
