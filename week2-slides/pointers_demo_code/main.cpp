
#include <iostream>

using namespace std;

// this variable holds a value
int x = 1000;

// This is a pointer. It points to the address of some data
int * myPointer = 0;

// This is a pointer to a block of reserved memory on the HEAP. This is great. But we need to remember to delete it before the program quits.
int * myInts = new int[100];


int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 100 ; i++) {
        
        myInts[i]=i;
        
    }
    
    myPointer = &x;

    cout << "The memory address of x is " << &x << endl;
    cout << "The memory addres of myPointer is " << myPointer << endl;
    cout << "The data stored at the memory address referenced by myPointer is " << * myPointer << endl;
    cout << "The data stored at the 9th index of myInts is " << myInts[9] << endl;
    
    // Make sure you do this when you are finished with your memory!!!
    delete [] myInts;
    
    return 0;
}
