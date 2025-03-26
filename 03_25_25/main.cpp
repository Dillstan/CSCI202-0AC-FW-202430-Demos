#include <iostream>
#include "unorderedLinkedList.h"

// lecture activity create the ordered linked list needed for your assignment (M02 Programming Assignment 2)

int main()
{
    unorderedLinkedList<int> list;
    list.insert(5);
    list.insert(8);
    list.insert(7);
    list.insert(2381);
    list.insert(2);
    int p = list.front();
    p = 7;
    list.print(std::cout);
    std::cout << std::endl;
    list.deleteNode(2381);
    list.print(std::cout);
    std::cout << std::endl;

    return 0;
}