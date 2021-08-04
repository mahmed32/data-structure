//queue implemntaion using linked list with tail pointer
#ifndef QUEUE_H
#define QUEUE_H
#include "linked-list.h"
class queue
{
    public:
        queue();
        void enqueue(int data);
        int dequeue();
        bool empty() const;
        void print() const;
    private:
        list l;
};

void queue::print() const
{
    l.print();
}

bool queue::empty() const
{
    return l.empty();
}

int queue::dequeue()
{
    return l.pop_front();
}

void queue::enqueue(int data)
{
    l.push_back(data);
}

queue::queue()
    :
    l()
{
}
#endif

