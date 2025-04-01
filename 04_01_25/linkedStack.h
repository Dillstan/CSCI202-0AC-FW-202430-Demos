#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "stackADT.h"
#include "node.h"
#include <stdexcept>
template <class t>
class linkedStack : public stackADT<t>
{
public:
    linkedStack(int = 100);
    linkedStack(const linkedStack<t> &);
    const linkedStack<t> &operator=(const linkedStack<t> &);
    void initialize stack();
    bool isFullStack() const;
    bool isEmptyStack() const;
    void push(const t &);
    t top() const;
    t pop();
    ~linkedStack();

private:
    void copyStack(const linkedStack<t> &);
    node<t> *stackTop;
    int count;
    int maxCount;
};

#endif