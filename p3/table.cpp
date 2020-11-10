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

void Table::AddingPrompt(){
	website		currWebsite;
	const int 	MAX_CHAR = 250;
	char		currName[MAX_CHAR];
    char currAddress[MAX_CHAR];
    char currSummary[MAX_CHAR];
    char currReview[MAX_CHAR];
	char currNums[MAX_CHAR];
	int currRating;

	cout << " ==== Input the Website Name (Category) >> ";
  cin.getline(currName, MAX_CHAR);
    
  cout << " ==== Input the website address >> ";
  cin.getline(currAddress, MAX_CHAR);
    
	cout << " ==== Input the website summary >> ";
  cin.getline(currSummary, MAX_CHAR);

  cout << " ==== Input the website review (in words) >> ";
  cin.getline(currReview, MAX_CHAR);

  cout << " ==== Input the website rating (on a scale of 1-5) >> ";
  cin.getline(currNums, MAX_CHAR);
  currRating = atoi(currNums);
  currWebsite.setName(currName);
    	currWebsite.setAddress(currAddress);
        currWebsite.setSummary(currSummary);
        currWebsite.setReview(currReview);
		currWebsite.setRating(currRating);
		add(currWebsite);
}

void Table::add(website& aStudent)
{
	cout << "adding " << endl;
	int index = calculateIndex(aStudent.getName());
	Node *	newNode = new Node(aStudent);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}

// Retrieve all websites based on the topic keyword supplied
void Table::retrieveCategory(website results[]){
	int 	MAX_CHAR = 250;
	char* topic;
	Node *currHead;
	int size = 6;
	results = new website[MAX_CHAR];

	cout << " ==== Input the topic >> ";
  	cin.getline(topic, MAX_CHAR);

	cout << "\nRetrieving the Category..." << endl;
	for (int i = 0; i < currCapacity; i++){
		cout << i << "Finding " << topic << endl;
		if(aTable[i]){
			cout << aTable[i]->data->getName() << "1" << endl;
			cout << aTable[i]->data->getName() << "---" << topic << "---" << endl;
			if (strcmp(aTable[i]->data->getName(),topic)==0)
			{
				cout << "Starting retrieveing" << topic << endl;
				currHead = aTable[i];
				
				for (int j = 0; currHead; j++){
					cout << j << currHead->data->getName() << endl;
					size *= 5;
					cout << "hello" << endl;
					results[j] = *currHead->data;
					currHead = currHead->next;
				}
				cout << "please" << endl;
				
				cout << "Done" << endl;
				cout << "Finished Retrieveing" << endl;
			}
			
		}
		
		cout << "666Finished Retrieveing\n" << endl;
	}
}

// Modify the review and rating for a particular topic and website match
void Table::modify(){
	int 	MAX_CHAR = 250;
	char topic[MAX_CHAR];
	char address[MAX_CHAR];

	cout << " ==== Input the topic >> ";
	cin.getline(topic, MAX_CHAR);
	cout << topic;

	int n = calculateIndex(topic);
	cout << "hello";
	getEntry(aTable[n]);
}

void Table::getEntry(Node * currHead)
{
	int 	MAX_CHAR = 10;
	char choice[MAX_CHAR];
	char review[MAX_CHAR];
	char currNums[MAX_CHAR];
	int currRating;

	if(currHead)
	{
		cout << currHead->data->getAddress() << endl;
		cout << " ==== Is this the right website address? (Enter y/n) >> ";
		cin.getline(choice, MAX_CHAR);
		if(strcmp("y", choice)==0){
			cout << " ==== Input the new website review (in words) >> ";
  			cin.getline(review, MAX_CHAR);
			cout << " ==== Input in the form of 'google.com' >> " << endl;
			cout << " ==== Input the new website rating(on a scale of 1-5)>> ";
			cin.getline(currNums, MAX_CHAR);
			currRating = atoi(currNums);
			currHead->data->setReview(review);
			currHead->data->setRating(currRating);
		}
	}
}

// Remove all websites with a 1 star rating
void Table::remove(){
	for(int i=0; i<currCapacity; i++)
	{
		removeChain(aTable[i]);
	}
}

void Table::removeChain(Node * currHead)
{
	if(currHead)
	{
		if(currHead->data->getRating() == 1){
			currHead->data->setName("removed");
			currHead->data->setAddress("removed");
			currHead->data->setSummary("removed");
			currHead->data->setReview("removed");
			currHead->data->setRating(0);
		}
		removeChain(currHead->next);
	}
}


// Only displaying matched wesbite
void Table::displayCategory(){
	int 	MAX_CHAR = 250;
	char topic[MAX_CHAR];
	Node* currHead;

	cout << " ==== Input the topic >> ";
	cin.getline(topic, MAX_CHAR);
	cout << topic;

	int n = calculateIndex(topic);
	cout << "hello";
	displayChain(aTable[n]);
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

Table& Table::operator= (Table& tableSrc)
{
	if(this == &tableSrc)
		return *this;
	if(this->aTable)
	{
		destroy();
	}
	size = tableSrc.size;
	currCapacity = tableSrc.currCapacity;
	aTable = new Node*[currCapacity];
	for(int i=0; i<currCapacity; i++)
	{
		aTable[i] = nullptr;
		copyChain(tableSrc.aTable[i], this->aTable[i]);
	}
	return *this;
}	

void Table::copyChain(Node * srcHead, Node *& destHead)
{
	if(srcHead)
	{
		destHead = new Node(*(srcHead->data));
		copyChain(srcHead->next, destHead->next);
	}
}


ostream& operator<< (ostream& out, Table& srcTable)
{
	out << endl << "Displaying the table ..." << endl;
	for(int i=0; i<srcTable.currCapacity; i++)
	{
		out << "Chain #" << i << " ... " << endl;
		srcTable.displayChain(srcTable.aTable[i]);
		out << endl;
	}
	return out;
}

void Table::displayChain(Node * currHead)
{
	if(currHead)
	{
		cout << *(currHead->data) << endl;
		displayChain(currHead->next);
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

