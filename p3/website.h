/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project3/app.cpp
*/

#ifndef WEBSITE_H
#define WEBSITE_H

#include <iostream>
using namespace std;
#include <cstring>

class website
{
public:
	website();
	website(char * name, char * address, char * summary, 
    char * review, int rating);
	website(website& aWebsite);
	~website();

	
	void setName(char * name);
    void setAddress(char *address);
    void setSummary(char *summary);
    void setReview(char *review);
    void setRating(int rating);

    char * getName();
    char * getAddress();
    char * getSummary();
    char * getReview();
    int getRating();

	website& operator= (website& aWebsite);
	friend ostream& operator<< (ostream& out, website& aWebsite);	

private:
	char *	name;
    char * address;
    char * summary;
    char * review;
    int rating;

    void init(char * name, char * address, char * summary, 
    char * review, int rating);
};

#endif