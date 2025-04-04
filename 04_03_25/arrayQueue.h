#ifndef ARRAYQ_H
#define ARRAYQ_H
#include "queueADT.h"

template <class t>
class arrayQueue : public queueADT<t>
{
public:
    const static int DEFAULT_QUEUE_SIZE = 100;
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t &queueElement);
    t dequeue();
    arrayQueue(int size = DEFAULT_QUEUE_SIZE);
    arrayQueue(const arrayQueue<t> &);
    const arrayQueue<t> &operator=(const arrayQueue<t> &);
    ~arrayQueue();

private:
    t **list;
    int maxQueueSize;
    int queueFront;
    int queueRear;
    void copyQueue(const arrayQueue<t> &);
};

template <class t>
bool arrayQueue<t>::isEmptyQueue() const
{
    return queueFront == queueRear;
}

template <class t>
bool arrayQueue<t>::isFullQueue() const
{
    return queueRear + 1 == queueFront;
}

template <class t>
void arrayQueue<t>::initializeQueue()
{
    for (this->queueFront; !isEmptyQueue(); this->queueFront = (++this->queueFront) % maxQueueSize)
    {
        delete list[this->queueFront];
    }
    this->queueFront = this->maxQueueSize - 1;
    this->queueRear = this->maxQueueSize - 1;
}

template <class t>
t arrayQueue<t>::front() const
{
    if (this->isEmptyQueue())
    {
        throw std::out_of_range("Cannot view an item in an empty queue.")
    }
    return *(list[queueFront + 1]);
}

template <class t>
t arrayQueue<t>::back() const
{
    if (this->isEmptyQueue())
    {
        throw std::out_of_range("Cannot view an item in an empty queue.")
    }
    return *(list[queueRear]);
}

template <class t>
void arrayQueue<t>::enqueue(const t &queueElement)
{
    if (this->isFullQueue())
    {
        throw std::overflow_error("Cannot add to a full queue.");
    }
    this->queueRear = (this->queueRear + 1) % maxQueueSize;
    list[queueRear] = new t(queueElement);
}

template <class t>
t arrayQueue<t>::dequeue()
{
    if (this->isEmptyQueue())
    {
        throw std::out_of_range("Cannot remove from an empty queue.");
    }
    this->queueFront = (this->queueFront + 1) % maxQueueSize;
    t returnItem(*(list[this->queueFront]));
    delete list[queueFront];
    list[queueFront] = nullptr;
    return returnItem;
}

template <class t>
arrayQueue<t>::arrayQueue(int size)
{
    if (size <= 0)
    {
        size = DEFAULT_QUEUE_SIZE;
    }
    this->maxQueueSize = size;
    this->list = new t *[this->maxQueueSize];
    this->count = 0;
    for (int i = 0; i < maxQueueSize; i++)
    {
        this->list[i] = nullptr;
    }
    this->queueFront = maxQueueSize - 1;
    this->queueRear = maxQueueSize - 1;
}

template <class t>
arrayQueue<t>::arrayQueue(const arrayQueue<t> &othQueue)
{
    this->queueFront = maxQueueSize - 1;
    this->queueRear = maxQueueSize - 1;
    this->list = nullptr;
    copyQueue(othQueue);
}

template <class t>
void arrayQueue<t>::copyQueue(const arrayQueue<t> &othQueue)
{
    this->initializeQueue();
    delete[] this->list;
    this->maxQueueSize = othQueue.maxQueueSize;
    this->list = new t *[this->maxQueueSize];
    this->queueFront = othQueue.queueFront;
    this->queueRear = othQueue.queueRear;
    for (int i = queueFront + 1; i != queueRear; i = (i + 1) % maxQueueSize)
    {
        this->list[i] = new t(*(othQueue.list[i]));
    }
}

template <class t>
const arrayQueue<t> &arrayQueue<t>::operator=(const arrayQueue<t> &othQueue)
{
    if (this != &othQueue)
    {
        copyQueue(othQueue);
    }
    return *this;
}

template <class t>
arrayQueue<t>::~arrayQueue()
{
    initializeQueue();
    delete[] list;
    list = nullptr;
}

#endif