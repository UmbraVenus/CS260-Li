/*
    Name:       Shijie Ren
    Instructor: Li Liang
    Class:      CS260
    Assignment: Project4/table.cpp
*/

#include "table.h"

Table::Table() : root(nullptr), size(0)
{
}

Table::Table(Table& aTable) : root(nullptr), size(0)
{
	*this = aTable;
}

Table::~Table()
{
	destroy(root);
}

void Table::destroy(Node *& currRoot)
{
	if(currRoot)
	{
		destroy(currRoot->left);
		destroy(currRoot->right);
		delete currRoot->data;
		delete currRoot;
		currRoot = nullptr;
	}
}

void Table::addingPrompt(){
	website		currWebsite;
	const int 	MAX_CHAR = 101;
	char		currName[MAX_CHAR];
    char currKeyword[MAX_CHAR];
    char currAddress[MAX_CHAR];
    char currSummary[MAX_CHAR];
    char currReview[MAX_CHAR];
	char currNums[MAX_CHAR];
	int currRating;

	cout << " ==== Input the Website Name (Topic) >> ";
    cin.getline(currName, MAX_CHAR);

    cout << " ==== Input the Website Keyword (Key) >> ";
    cin.getline(currKeyword, MAX_CHAR);
    
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
    currWebsite.setKeyword(currKeyword);
    currWebsite.setAddress(currAddress);
    currWebsite.setSummary(currSummary);
    currWebsite.setReview(currReview);
	currWebsite.setRating(currRating);
	add(currWebsite);
}

void Table::add(website& aStudent)
{
	add(this->root, aStudent);
	size++;
}

void Table::add(Node *& currRoot, website& aStudent)
{
	if(!currRoot)
	{
		currRoot = new Node(aStudent);
	}
	else if(aStudent < *(currRoot->data))
	{
		add(currRoot->left, aStudent);
	}
	else
	{
		add(currRoot->right, aStudent);
	}
}

Table& Table::operator= (Table& tableSrc)
{
	if(this == &tableSrc)
		return *this;
	if(this->root)
	{
		destroy(this->root);
	}
	size = tableSrc.size;
	copy(tableSrc.root, this->root);
	return *this;
}	

void Table::copy(Node * srcRoot, Node *& destRoot)
{
	if(srcRoot)
	{
		destRoot = new Node(*(srcRoot->data));
		copy(srcRoot->left, destRoot->left);
		copy(srcRoot->right, destRoot->right);
	}
	else
	{
		destRoot = nullptr;
	}
}

ostream& operator<< (ostream& out, Table& srcTable)
{
	out << endl << "Displaying the tree ..." << endl;
	srcTable.display(out, srcTable.root);
	return out;
}

void Table::display(ostream& out, Node * currRoot)
{
	//out << endl << "Pre-order showing the tree ..." << endl;
	//displayPreorder(out, currRoot);
    out << endl;
    out << endl << "In-order showing the tree ..." << endl;
    out << endl;
    displayInorder(out, currRoot);
	//out << endl << "Post-order showing the tree ..." << endl;
	//displayPostorder(out, currRoot);
}	

void Table::displayPreorder(ostream& out, Node * currRoot)
{
	if(currRoot)
	{
		out << *(currRoot->data) << endl;
		displayPreorder(out, currRoot->left);
		displayPreorder(out, currRoot->right);
	}
}
void Table::displayInorder(ostream& out, Node * currRoot)
{
	if(currRoot)
	{
		displayInorder(out, currRoot->left);
		out << *(currRoot->data) << endl;
		displayInorder(out, currRoot->right);
	}
}
void Table::displayPostorder(ostream& out, Node * currRoot) 
{
	if(currRoot)
	{
		displayPostorder(out, currRoot->left);
		displayPostorder(out, currRoot->right);
		out << *(currRoot->data) << endl;
	}
}

void Table::loadFromFile(char * fileName)
{
	cout << "Loading" << endl;
	ifstream in;
	website		currWebsite;
	const int 	MAX_CHAR = 101;
	char		currName[MAX_CHAR];
    char currKeyword[MAX_CHAR];
    char currAddress[MAX_CHAR];
    char currSummary[MAX_CHAR];
    char currReview[MAX_CHAR];
	char currNums[MAX_CHAR];
	int currRating;
    website *tempArray;
    int index = 0;
    int numberOfRecords;

    in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

    in >> numberOfRecords;
    in.ignore(MAX_CHAR, '\n');
    tempArray = new website[numberOfRecords];

    while(!in.eof()){
        in.getline(currName, MAX_CHAR);
        in.getline(currKeyword, MAX_CHAR);
        in.getline(currAddress, MAX_CHAR);
        in.getline(currSummary, MAX_CHAR);
        in.getline(currReview, MAX_CHAR);
	    in.getline(currNums, MAX_CHAR);
	    currRating = atoi(currNums);
	  
	  	currWebsite.setName(currName);
        currWebsite.setKeyword(currKeyword);
        currWebsite.setAddress(currAddress);
        currWebsite.setSummary(currSummary);
        currWebsite.setReview(currReview);
		currWebsite.setRating(currRating);
		cout << "Adddiiiing" << endl;
		add(currWebsite);
      
        cout << currWebsite.getName() << " added." << endl;
        cout << currWebsite.getKeyword() << endl;
        cout << currWebsite.getAddress() << endl;
        cout << currWebsite.getSummary() << endl;
		cout << currWebsite.getReview() << endl;
		cout << currWebsite.getRating() << endl;
    }
    in.close();
}

void Table::loadFromArray(website * studentList, int first, int last)
{
	int mid;
	if(first <= last)
	{
		mid = (first + last) / 2;
		add(studentList[mid]);
		loadFromArray(studentList, first, mid-1);
		loadFromArray(studentList, mid+1, last);	
	}
}



bool Table::remove(char * key, website& aStudent)
{
	return remove(this->root, key, aStudent);
}

bool Table::remove(Node *& currRoot, char * key, website& aStudent)
{
	if(!currRoot)
	{
		return false;
	}
	int temp = strcmp(key, currRoot->data->getName());
	if(temp == 0)
	{
		aStudent = *(currRoot->data);
		deleteNode(currRoot);
		size--;
		return true;
	}
	else if(temp < 0)
	{
		return remove(currRoot->left, key, aStudent);
	}
	else
	{
		return remove(currRoot->right, key, aStudent);
	}
}

void Table::deleteNode(Node *& target)
{
	//target node is a leaf
	if(!target->left && !target->right)
	{
		delete target->data;
		delete target;
		target = nullptr;
	}
	//target node only has left child
	else if(!target->right)
	{
		Node * temp = target;
		target = target->left;
		delete temp->data;
		delete temp;
	}
	//target node only has right child
	else if(!target->left)
	{
		Node * temp = target;
		target = target->right;
		delete temp->data;
		delete temp;
	}	
	//target node has two children
	else
	{
		//find the inorder successor of target node	
		Node * prev = nullptr;
		Node * curr = target->right; 	//start with the right child
		if(!curr->left)					//the right child is the inorder successor
		{
			target->right = curr->right;
		}
		else
		{
			while(curr->left)
			{
				prev = curr;
				curr = curr->left; 			//then go all the way to the left
			}
			prev->left = curr->right;
		}
		delete target->data;
		target->data = curr->data;
		delete curr;
		return;
	}
}