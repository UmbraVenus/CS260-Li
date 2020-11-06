#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "\nCounting Even Function in Main..." << endl;
    cout << countEven(head) << endl;

    cout << "\nRemoving the all even nodes" << endl;
    cout << removeEven(head) << " removed " << endl;
    display(head);


    display(head);
    destroy(head);    
    return 0;
}
