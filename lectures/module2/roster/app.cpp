#include <iostream>
using namespace std;
#include "student.h"
#include "list.h"

int main()
{
	List	cs260;
	char	fileName[] = "roster.txt";

	cs260.loadFromFile(fileName);
	cout << cs260 << endl;

	List	cs260B(cs260);
	cout << "A copy of cs260 list: " << endl;
	cout << cs260B << endl;

	List	cs260C = cs260;
	cout << "Another copy of cs260 list: " << endl;

	cout << cs260C << endl;
	return 0;
}
