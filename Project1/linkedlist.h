#include <iostream>
#include <cstring>
#include "artist.h"
#include "songs.h"
using namespace std;

class linkedlist
{
    public:
    linkedlist();   // Singly linked List
    linkedlist(const linkedlist &alist); // Automatically sorted
    ~linkedlist();

    void addArtist(artist &aartist);   // Insert into the position of Popularity
    void addSong(artist &aartist); // Add a new song to artist's song list

    void displayArtists(); // Display all artists in list

    void loadFromFile(char *fileName);
    void saveToFile(char *fileName);

private:
    struct node
    {
        artist *data;
        node *next;
        node(artist &aartist)
        {
            data = new artist(aartist);
            next = nullptr;
        }
        ~node()
        {
            delete data;
            data = nullptr;
            next = nullptr;
        }
    };
    node *head;
    int size;
    void destroy();
};