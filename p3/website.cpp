/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project3/app.cpp
*/

#include "website.h"
#include <iostream>
#include <cstring>
using namespace std;

website::website() : name(nullptr), address(nullptr), summary(nullptr),
review(nullptr), rating(0)
{
}

website::website(char * name, char * address, char * summary, 
char * review, int rating)
{
    init(name, address, summary, review, rating);
}

void website::init(char * name, char * address, char * summary, 
char * review, int rating)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
    this->address = new char[strlen(address)+1];
	strcpy(this->address, address);
    this->summary = new char[strlen(summary)+1];
	strcpy(this->summary, summary);
    this->review = new char[strlen(review)+1];
	strcpy(this->review, review);
    this->rating = rating;
}

website::website(website& awebsite): name(nullptr), address(nullptr), summary(nullptr), review(nullptr), rating(0)
{
	*this = awebsite;
}

website::~website()
{
	if(this->name)
	{
		delete [] this->name;
        delete [] this->address;
        delete [] this->summary;
        delete [] this->review;

	}
	this->name = nullptr;
    this->address = nullptr;
    this->summary = nullptr;
    this->review = nullptr;
}

int website::getRating()
{
	return rating;
}

char * website::getAddress()
{
	return address;
}

char * website::getSummary()
{
	return summary;
}

char * website::getReview()
{
	return review;
}

char * website::getName()
{
	return name;
}

void website::setRating(int rating)
{
	this->rating = rating;
}

void website::setName(char * name)
{
	if(this->name)
	{
		delete [] this->name;
	}
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void website::setAddress(char * address)
{
	if(this->address)
	{
		delete [] this->address;
	}
	this->address= new char[strlen(address)+1];
	strcpy(this->address, address);
}

void website::setSummary(char * summary)
{
	if(this->summary)
	{
		delete [] this->summary;
	}
	this->summary = new char[strlen(summary)+1];
	strcpy(this->summary, summary);
}

void website::setReview(char * review)
{
	if(this->review)
	{
		delete [] this->review;
	}
	this->review = new char[strlen(review)+1];
	strcpy(this->review, review);
}


ostream& operator<< (ostream& out, website& aWebsite)
{
	out << "== [Website] " << aWebsite.name << endl;
    out << aWebsite.address << endl;
    out << aWebsite.summary << endl;
    out << aWebsite.review << endl;
    out << aWebsite.rating << endl;
    return out;
}

