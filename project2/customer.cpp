/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project2/customer.cpp
*/

#include "customer.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructors and Destructors
Customer::Customer(): name(nullptr),nums(0),accomodation(nullptr), promotion(nullptr)
{
}

Customer::Customer(char * name, int nums, char *accomodation, char* promotion){
    init(name, nums, accomodation, promotion);
}

void Customer::init(char * name, int nums, char *accomodation, char* promotion){
    this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
    this->nums = nums;
    this->accomodation = new char[strlen(accomodation)+1];
	strcpy(this->accomodation, accomodation);
    this->promotion = new char[strlen(promotion)+1];
	strcpy(this->promotion, promotion);
}

Customer::Customer(Customer& aStudent): name(nullptr),nums(0),accomodation(nullptr), promotion(nullptr) {
    *this = aStudent;
}

Customer::~Customer(){
    if(this->name)
	{
		delete [] this->name;
	}
	this->name = nullptr;
    if(this->accomodation)
	{
		delete [] this->accomodation;
	}
	this->accomodation = nullptr;
}

// Getters and Setters
char * Customer::getName(){
    return name;
}
int Customer::getNums(){
    return nums;
}
char * Customer::getAccomodation(){
    return accomodation;
}
char * Customer::getPromotion(){
    return promotion;
}

void Customer::setName(char *name){
    if(this->name)
	{
		delete [] this->name;
	}
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}
void Customer::setNums(int nums){
    this->nums = nums;
}
void Customer::setAccomodation(char *accomodation){
    if(this->accomodation)
	{
		delete [] this->accomodation;
	}
	this->accomodation = new char[strlen(accomodation)+1];
	strcpy(this->accomodation, accomodation);
}
void Customer::setPromotion(char* promotion){
    if(this->promotion)
	{
		delete [] this->promotion;
	}
	this->promotion = new char[strlen(promotion)+1];
	strcpy(this->promotion, promotion);
}
