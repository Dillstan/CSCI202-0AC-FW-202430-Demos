#include <iostream>
#include "arrayQueue.h"
#include "linkedQueue.h"
#include "fakePriorityQueue.h"
#include <cstdlib>

// lecture activity change fakePriorityQueue to do priority insert.
// Modify enqueue to do an ordered insert where ties always insert after.

int main()
{
    arrayQueue<int> q(6);
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(rand() % 50 + 1);
    }
    arrayQueue<int> qCpy = q;
    try
    {
        q.enqueue(6);
    }
    catch (const std::overflow_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    int x = q.dequeue();
    q.enqueue(x);
    x = qCpy.dequeue();
    qCpy.enqueue(x);
    while (!q.isEmptyQueue())
    {
        x = q.dequeue();
        std::cout << x << std::endl;
        x = qCpy.dequeue();
        std::cout << x << std::endl;
    }
    std::cout << std::endl
              << std::endl;
    linkedQueue<int> lq;
    for (int i = 0; i < 5; i++)
    {
        lq.enqueue(rand() % 50 + 1);
    }
    linkedQueue<int> lqCpy = lq;
    while (!lq.isEmptyQueue())
    {
        x = lq.dequeue();
        std::cout << x << std::endl;
        x = lqCpy.dequeue();
        std::cout << x << std::endl;
    }

    fakePriorityQueue<int> pq;

    for (int i = 0; i < 20; i++)
    {
        x = rand() % 6 + 1;
        lq.enqueue(x);
        pq.enqueue(x);
    }

    std::cout << "regular queue: " << std::endl;
    while (!lq.isEmptyQueue())
    {
        std::cout << lq.dequeue() << std::endl;
    }
    std::cout << std::endl
              << std::endl;
    std::cout << "priority queue: " << std::endl;
    while (!pq.isEmptyQueue())
    {
        std::cout << pq.dequeue() << std::endl;
    }
}