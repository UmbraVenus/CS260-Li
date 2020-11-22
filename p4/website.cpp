/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project4/website.cpp
*/

#include "website.h"
#include <iostream>
#include <cstring>
using namespace std;

website::website() : name(nullptr), keyword(nullptr), 
address(nullptr), summary(nullptr), review(nullptr), rating(0)
{
}

website::website(char * name,char* keyword, char * address, char * summary, 
char * review, int rating)
{
    init(name, keyword, address, summary, review, rating);
}

void website::init(char * name, char *keyword, char * address, char * summary, 
char * review, int rating)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
    this->keyword = new char[strlen(keyword)+1];
	strcpy(this->keyword, keyword);
    this->address = new char[strlen(address)+1];
	strcpy(this->address, address);
    this->summary = new char[strlen(summary)+1];
	strcpy(this->summary, summary);
    this->review = new char[strlen(review)+1];
	strcpy(this->review, review);
    this->rating = rating;
}

website::website(website& awebsite): name(nullptr), keyword(nullptr), address(nullptr), summary(nullptr), review(nullptr), rating(0)
{
	*this = awebsite;
}

website::~website()
{
	if(this->name)
	{
		delete [] this->name;
        delete[] this->keyword;
        delete[] this->address;
        delete [] this->summary;
        delete [] this->review;
	}
	this->name = nullptr;
    this->keyword = nullptr;
    this->address = nullptr;
    this->summary = nullptr;
    this->review = nullptr;
}

int website::getRating()
{
	return rating;
}

char * website::getKeyword()
{
    return keyword;
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

void website::setKeyword(char * keyword)
{
	if(this->keyword)
	{
		delete [] this->keyword;
	}
	this->keyword = new char[strlen(keyword)+1];
	strcpy(this->keyword, keyword);
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

website& website::operator= (website& aStudent)
{
	if(this == &aStudent)
	{
		return *this;
	}
	setName(aStudent.name);
    setKeyword(aStudent.keyword);
    setAddress(aStudent.address);
    setSummary(aStudent.summary);
	setReview(aStudent.review);
	setRating(aStudent.rating);
	return *this;
}

ostream& operator<< (ostream& out, website& aWebsite)
{
	out  << "Topic:     " << aWebsite.getName() << endl;
    out <<  "[Keyword]: " << aWebsite.getKeyword() << endl;
    out <<  "Adddress:  " << aWebsite.getAddress() << endl;
    out  << "Summary:   " << aWebsite.getSummary()<< endl;
    out  << "Review:    "<< aWebsite.getReview() << endl;
    out  << "Rating:    "<< aWebsite.getRating() << endl;
    return out;
}

bool operator< (website& s1, website& s2)
{
	int compareResult = strcmp(s1.getKeyword(), s2.getKeyword());
	return compareResult < 0;
}