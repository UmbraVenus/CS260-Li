#include "dlist.h"
#include <iostream>
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "\nCounting Function in Main..." << endl;
    cout << count(head) << endl;
    cout << "\nInserting number 3 at Position 1" << endl;
    insert(head, 3, 1);
    display(head);
    cout << "\nRemoving the int at Position 1" << endl;
    cout << remove(head, 1) << " removed " << endl;
    display(head);
    cout << "\nInserting number 5 at Position 3" << endl;
    insert(head, 5, 3);
    display(head);
    destroy(head);    
    return 0;
}
