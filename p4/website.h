/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project4/website.h
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
	website(char * name, char * keyword, char * address, char * summary, 
    char * review, int rating);
	website(website& aWebsite);
	~website();

	
	void setName(char * name);
    void setKeyword(char *keyword);
    void setAddress(char *address);
    void setSummary(char *summary);
    void setReview(char *review);
    void setRating(int rating);

    char * getName();
    char *getKeyword();
    char *getAddress();
    char * getSummary();
    char * getReview();
    int getRating();

    website& operator= (website& aStudent);
	friend ostream& operator<< (ostream& out, website& aWebsite);	

private:
	char *	name;
    char *keyword;
    char *address;
    char * summary;
    char * review;
    int rating;

    void init(char * name, char * keyword, char * address, char * summary, 
    char * review, int rating);
};
bool operator< (website& student1, website& student2);

#endif