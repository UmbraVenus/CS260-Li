#include <iostream>
#include <cstring>
#include "songs.h"
using namespace std;

songs::songs(): head(nullptr), size(0) {}

songs::songs(songs &aSongs): head(nullptr), size(0) {
    *this = aSongs;
}

songs::~songs(){
    if(this->head)
    {
        delete this->head;
    }
    this->head = nullptr;
}

songs::song::~song(){
    if(this->title)
    {
        delete[] this->title;
    }
    this->title = nullptr;
}

void songs::song::init(char *atitle, float alength, int aviews, int alikes)
{
    this->title = new char[strlen(atitle) + 1];
    strcpy(this->title, atitle);
    this->length = alength;
    this->views = aviews;
    this->likes = alikes;
    this->next = nullptr;
}

void songs::song::setViews(int aviews){
    this->views = aviews;
}
void songs::song::setLikes(int alikes){
    this->likes = alikes;
}
int songs::song::getViews(){
    return this->views;
}
int songs::song::getLikes(){
    return this->likes;
}

void songs::insert(song *asong){
    songs::song *pre = new songs::song;
    songs::song *cur = new songs::song;
    songs::song *temp = new songs::song;
    cur = head;
    while (asong->views <= head->views) // Insert according to popularity
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = temp;
    temp->next = cur;
}

void songs::lowerM(int M){
    songs::song *pre = new songs::song;
    songs::song *cur = new songs::song;
    cur = head;
    while (cur->views < M){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    delete cur;
}

void songs::displaySongs(){
    songs::song *temp = new songs::song;
    temp = head;
    while (temp != NULL)
    {
        cout << "\n===     " << temp->title << " ===\n";
        cout << "[Length] :" << temp->length << endl;
        cout << "[Views]  :" << temp->views << endl;
        cout << "[Likes]  :" << temp->likes << endl;
    }
}