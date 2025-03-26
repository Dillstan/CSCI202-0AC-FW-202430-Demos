#include <iostream>
#include "linkedList.h"

int main()
{
    linkedListType<int> list;
    list.insert(5);
    int p = list.front();
    p = 7;

    return 0;
}