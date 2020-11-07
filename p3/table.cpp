/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project3/app.cpp
*/

#include "table.h"

Table::Table() : size(0)
{
	currCapacity = INIT_CAP;
	aTable = new Node*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aTable[i] = nullptr;
	}
}

Table::Table(Table& aTable) : aTable(nullptr), size(0)
{
	*this = aTable;
}

Table::~Table()
{
	destroy();
}

void Table::destroy()
{
	for(int i=0; i<currCapacity; i++)
	{
		destroyChain(aTable[i]);
	}
	if(aTable)
		delete [] aTable;
}

void Table::destroyChain(Node *& currHead)
{
	if(currHead)
	{
		destroyChain(currHead->next);
		delete currHead->data;
		delete currHead;
		currHead = nullptr;
	}
}


void Table::add(website& aStudent)
{
	cout << "adding " << endl;
	int index = calculateIndex(aStudent.getName());
	cout << aStudent.getName() << " added." << endl;
	Node *	newNode = new Node(aStudent);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}


/*
A naive hashing function that only adds the ASCII value of each char in the
key field and mods the capacity of the table. i.e. "abc" and "cba" will result 
in the same index since it doesn't consider position value.
*/
int Table::calculateIndex(char * key)
{
	int hashingResult;

	hashingResult = 0;
	for(; *key != '\0'; key++)
	{
		hashingResult += *key;
	}	

	return hashingResult % currCapacity;
}


/*
void Table::copyChain(Node * srcHead, Node *& destHead)
{
	if(srcHead)
	{
		destHead = new Node(*(srcHead->data));
		copyChain(srcHead->next, destHead->next);
	}
}
*/

ostream& operator<< (ostream& out, Table& srcTable)
{
	out << endl << "Displaying the table ..." << endl;
	for(int i=0; i<srcTable.currCapacity; i++)
	{
		out << "Chain #" << i << " ... " << endl;
		srcTable.displayChain(out, srcTable.aTable[i]);
		out << endl;
	}
	return out;
}

void Table::displayChain(ostream& out, Node * currHead)
{
	if(currHead)
	{
		out << (*currHead->data).getName() << endl;
		out << (*currHead->data).getAddress() << endl;
		out << (*currHead->data).getSummary() << endl;
		out << (*currHead->data).getReview() << endl;
		out << (*currHead->data).getRating() << endl;
		
		displayChain(out, currHead->next);
	}
}

void Table::loadFromFile(char * fileName)
{
	cout << "Loading" << endl;
	ifstream in;
	website		currWebsite;
	const int 	MAX_CHAR = 250;
	char		currName[MAX_CHAR];
    char currAddress[MAX_CHAR];
    char currSummary[MAX_CHAR];
    char currReview[MAX_CHAR];
	char currNums[MAX_CHAR];
	int currRating;

	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	while(!in.eof()){
      in.getline(currName, MAX_CHAR);
      in.getline(currAddress, MAX_CHAR);
      in.getline(currSummary, MAX_CHAR);
      in.getline(currReview, MAX_CHAR);
	  in.getline(currNums, MAX_CHAR);
	  currRating = atoi(currNums);
	  
	  	currWebsite.setName(currName);
    	currWebsite.setAddress(currAddress);
        currWebsite.setSummary(currSummary);
        currWebsite.setReview(currReview);
		currWebsite.setRating(currRating);
		cout << "Adddiiiing" << endl;
		add(currWebsite);
      
      cout << currWebsite.getName() << " added." << endl;
	  cout << currWebsite.getAddress() << endl;
		cout << currWebsite.getSummary() << endl;
		cout << currWebsite.getReview() << endl;
		cout << currWebsite.getRating() << endl;
  }

/*
	in.get(currName, MAX_CHAR, ';');
    in.get(currAddress, MAX_CHAR, ';');
    in.get(currSummary, MAX_CHAR, ';');
    in.get(currReview, MAX_CHAR, ';');
    while (!in.eof())
    {
		in.get();
		in >> currRating;
		in.ignore(MAX_CHAR, '\n');
		
		currWebsite.setName(currName);
        currWebsite.setAddress(currAddress);
        currWebsite.setSummary(currSummary);
        currWebsite.setReview(currReview);
		currWebsite.setRating(currRating);
		cout << "Adddiiiing" << endl;
		add(currWebsite);

		in.get(currName, MAX_CHAR, ';');
        in.get(currAddress, MAX_CHAR, ';');
        in.get(currSummary, MAX_CHAR, ';');
        in.get(currReview, MAX_CHAR, ';');
	}
	*/
	in.close();
}

