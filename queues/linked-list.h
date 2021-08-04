//this file is used to implement the queue
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
class list
{
    public:
        list();
        void push_back(int data);
        int pop_front();
        bool empty()const;
        void print()const;
        ~list();
    private:
        struct node
        {
            int data;
            node* next;
        };
        node* head;
        node* tail;
};

list::~list()
{
    while(head)
    {
        node* n = head->next;
        delete head;
        head = n;
    }
}

void list::print() const
{
    if(empty())
        std::cout << "empty list" << std::endl;

    node* trav = head;
    while(trav)
    {
        std::cout << trav->data << " ";
        trav = trav->next;
    }
    std::cout << std::endl;
}

bool list::empty() const
{
    return head==nullptr;
}


int list::pop_front()
{
    if(empty())
        throw "popping from empty list";
    
    int value = head->data;
    node* n = head->next;

    delete head;
    head = n;

    return value;
}

list::list()
    :
    head(nullptr),
    tail(nullptr)
{
}

void list::push_back(int data)
{
    if(empty())//list is empty
    {
        head = new node{data, head};
        tail = head;
    }
    else
    {
        node* n = new node{data, nullptr};
        tail->next = n;
        tail = n;
    }
}

#endif
