#include <iostream>
#include <cstring>
using namespace std;

class songs
{
    public:
    songs();
    songs(songs &aSongs); // Singly Linked List by popularity
    ~songs();

    void lowerM(int M); // see if any songs' views is less than M

    void displaySongs();
    
    private:
    struct song // One single "song" object
    {
        char *title;
        float length;
        int views, likes;
        song *next;
        void init(char *atitle, float alength, int aviews, int alikes);
        void setViews(int aviews);
        void setLikes(int alikes);
        int getViews();
        int getLikes();
        ~song();
    };
    song *head;
    int size;
    void insert(song *asong); // Append to the right position
};