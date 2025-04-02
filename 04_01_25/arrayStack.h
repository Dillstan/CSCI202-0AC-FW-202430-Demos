#ifndef ASTACK_H
#define ASTACK_H
#include "stackADT.h"
#include <stdexcept>

template <class t>
class arrayStack : public stackADT<t>
{
public:
    const static int DEFAULT_STACK_SIZE = 100;
    arrayStack(int = DEFAULT_STACK_SIZE);
    arrayStack(const arrayStack<t> &);
    const arrayStack<t> &operator=(const arrayStack<t> &);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const t &);
    t top() const;
    t pop();
    ~arrayStack();

private:
    int maxStackSize;
    int stacktop;
    t **list;
    void copyStack(const arrayStack<t> &);
};

template <class t>
arrayStack<t>::arrayStack(int max)
{
    if (max <= 0)
    {
        max = DEFAULT_STACK_SIZE;
    }
    maxStackSize = max;
    stacktop = 0;
    list = new t *[maxStackSize];
}

template <class t>
arrayStack<t>::arrayStack(const arrayStack<t> &othStack)
{
    stacktop = 0;
    list = nullptr;
    copyStack(othStack);
}

template <class t>
const arrayStack<t> &arrayStack<t>::operator=(const arrayStack<t> &othStack)
{
    if (this != &othStack)
    {
        copyStack(othStack);
    }
    return *this;
}

template <class t>
bool arrayStack<t>::isEmptyStack() const
{
    return stacktop == 0;
}

template <class t>
bool arrayStack<t>::isFullStack() const
{
    return stacktop == maxStackSize;
}

template <class t>
void arrayStack<t>::copyStack(const arrayStack<t> &othStack)
{
    if (!isEmptyStack())
    {
        initializeStack();
    }
    delete[] this->list;
    this->maxStackSize = othStack.maxStackSize;
    this - stacktop = othStack.stacktop;
    this->list = new t *[this->maxStackSize];
    for (int i = 0; i < this->stacktop; i++)
    {
        this->list[i] = new t(*(othStack.list[i]));
    }
}
template <class t>
void arrayStack<t>::initializeStack()
{
    if (!isEmptyStack())
    {
        for (int i = 0; i < stacktop; i++)
        {
            delete list[i];
        }
    }
    stacktop = 0;
}

#endif