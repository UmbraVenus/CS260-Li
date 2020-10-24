#include <iostream>
#include <cstring>
#include "songs.h"
using namespace std;

class artist{
    private:
        char *name;
        char *story;
        char *info;
        songs songlist;
        void init(char *name, char *story, char * info, songs songlist);
        
    public:
	artist();
	artist(artist& aartist);    // One single object
    artist(char *name, char *story, char * info, songs songlist);
    ~artist();

    
};
