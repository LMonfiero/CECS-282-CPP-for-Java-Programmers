#include <iostream>
#include "ModernLinkedList.h"
using namespace std;

//Louis Monfiero - 016336266
int main()  {
    ModernLinkedList myList;
    myList.PushFront(2);
    myList.PushFront(1);
    myList.PushFront(0);
    myList.PrintList();
    //[0, 1, 2]

    myList.PushBack(4);
    myList.PushBack(5);
    myList.PrintList();
    //[0. 1. 2. 4. 5]
    
    myList.Insert(3, 3);
    myList.PrintList();
    //[0, 1, 2, 3, 4, 5]

    myList.RemoveAt(2);
    myList.PrintList();
    //[0, 1, 3, 4, 5]

    myList.PopBack();
    myList.PopFront();
    myList.PrintList();
    //[1, 3, 4]

    myList.Clear();
    myList.PrintList();
    cout << "\nEND!\n";
}