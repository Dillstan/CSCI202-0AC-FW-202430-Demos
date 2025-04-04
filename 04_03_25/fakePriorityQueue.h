#ifndef PQUEUE_H
#define PQUEUE_H

#include "linkedQueue.h"

template <class t>
class fakePriorityQueue : public linkedQueue<t>
{
public:
    void enqueue(const t &);
};

template <class t>
void fakePriorityQueue<t>::enqueue(const t &queueElement)
{
    node<t> *newNode;
    newNode = new node<t>;
    newNode->data = new t(queueElement);
    newNode->link = nullptr;
    
    if (this->isEmptyQueue())
    {
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        //start at the front
        node<t>* current = this->queueFront;
        node<t>* previous = nullptr;
        while (current != nullptr)
        {
            // if new is higher priority than current, place before
            if (*(newNode->data) > *(current->data))
            {
                //if previous is null, then it is the new front
                if(previous == nullptr)
                    this->queueFront = newNode;
                //else place between previous and current
                else
                    previous->link = newNode;
                
                //either way the new node will be before the current
                newNode->link = current;
                return;
            }
            //if current is the same as the new node put new after the current
            else if(*(current->data) == *(newNode->data))
            {
                newNode->link = current->link;
                current->link = newNode;

                if (current == this->queueRear)
                {
                    this->queueRear = newNode;
                }
                return;
            }

            //else, go to next node
            previous = current;
            current = current->link;
        } 

        //if it is not equal to any in list, set as rear
        this->queueRear->link = newNode;
        this->queueRear = newNode;
    }
}

#endif