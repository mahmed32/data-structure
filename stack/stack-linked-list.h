#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H 
#include "../linked-list/linked-list-no-tail.h"
class lstack
{
    public:
        lstack();
        void push(int val);
        int pop();
        int& top();
        bool empty() const;
        int size() const;
        void print() const;
    private:
        list l;
};

void lstack::print() const
{
    l.print();
}

int lstack::size() const
{
    return l.size();
}

bool lstack::empty() const
{
    return l.empty();
}

int& lstack::top()
{
    return l.front();
}

int lstack::pop()
{
   return l.pop_front();
}

void lstack::push(int val)
{
    l.push_front(val);
}

lstack::lstack()
    :
    l()
{
}

#endif


