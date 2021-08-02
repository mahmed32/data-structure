#ifndef LINKED_LIST_NO_TAIL_H
#define LINKED_LIST_NO_TAIL_H
#include <iostream>
#include <initializer_list>
class list
{
private:
    struct node
    {
        int value;
        node* next;
    };
public:
   list(size_t initSize = 0, int initValue = 0);
   list(std::initializer_list<int> l);
   ~list();
   size_t size() const;
   bool empty() const;
   int& value_at(int index) const;
   void push_front(int value);
   int pop_front();
   void push_back(int value);
   int pop_back();
   int& front() const;
   int& back() const;
   void insert(int index, int value);
   void erase(int index);
   int& value_n_from_end(int n) const;
   void reverse();
   int remove_value(int value); //return -1 if not found
   void print() const;
private:
    node* head;
    size_t length;
};

list::~list()
{
    while(head)
    {
        node* after = head->next;
        delete head;
        head = after;
    }
}

void list::print() const
{
    if(!head)
        std::cout << "empty list" << std::endl;
    else
    {
        node* trav = head;
        while(trav)
        {
            std::cout << trav->value << " ";
            trav = trav->next;
        }
        std::cout << std::endl;
    }
}


int list::remove_value(int value)
{
    if(!head)
        throw "removing from an empty list";

    int i = 0;
    node* trav = head;
    while(trav)
    {
        if(trav->value == value)
            break;
        trav = trav->next;
        i++;
    }
    if(i == length)
        return -1;

    erase(i);
    return i;
}

void list::reverse()
{
    if(length == 0)
        throw "reverse an empty list";
    node* l = nullptr;
    node* r = head;
    node* store = r->next;
    while(store)
    {
        r->next = l;
        l = r;
        r = store;
        store = r->next;
    }
    r->next = l;
    head = r;
}


int& list::value_n_from_end(int n) const
{
    return value_at(length - n - 1);
}

void list::erase(int index)
{
    if(index < 0 || index >= length)
        throw "out of bound";
    if(length == 0)
        throw "earase from an empty list";

    if(index == 0)
        pop_front();
    else if(index == length - 1)
        pop_back();
    else
    {
        node* trav = head;
        for(int i = 0; i < index - 1; i++)
            trav = trav->next;

        node* afterTarget = trav->next->next;
        delete trav->next;
        trav->next = afterTarget;
        length--;
    }
}

void list::insert(int index, int value)
{
    if(index < 0 || index > length)
        throw "out of bound";

    if(length == 0)
        push_front(value);
    else if(index == 0)
        push_front(value);
    else if(index == length)
        push_back(value);
    else
    {
        node* trav = head;
        for(int i = 0; i < index - 1;i++)
            trav = trav->next;

        trav->next = new node{value, trav->next};
        length++;
    }
}
int& list::back() const
{
    if(!head)
        throw "request and elment from empty list";

    node* trav = head;
    while(trav->next)
        trav = trav->next;

    return trav->value;
}

int& list::front() const
{
    if(!head)
        throw "request an element from empty list";

    return head->value;
}

int list::pop_back()
{
    if(!head)
        throw "popping from empty list";
    
    int value;
    if(length == 1)
    {
        value = head->value;
        delete head;
        head = nullptr;
    }
    else
    {
        node* trav = head;
        while(trav->next->next)
            trav = trav->next;
        
        value = trav->next->value;
        delete trav->next;
        trav->next = nullptr;
    }
    length--;
    return value;
}

void list::push_back(int value)
{
    if(!length)
    {
        head = new node{value, head};
    }
    else //not empty list
    {
        node* trav = head;
        while(trav->next)
            trav = trav->next;
        trav->next = new node{value, nullptr};
    }
    length++;
}

int list::pop_front()
{
    if(!head)
        throw "popping from empty list";

    node* next = head->next;
    int value = head->value;

    delete head;
    head = next;

    length--;

    return value;
}

void list::push_front(int value)
{
    head = new node{value, head};
    length++;
}

int& list:: value_at(int index) const
{
    if(index < 0 || index >= length)
        throw "out of bound";
    if(!head)
        throw "request element from an empty list";

    node* trav = head;
    for(int i = 0; i < index; i++)
        trav = trav->next;

    return trav->value;
}

bool list::empty() const
{
    return length == 0;
}

size_t list::size() const
{
    return length;
}

list::list(size_t initSize , int initValue )
    :
    head(nullptr),
    length(0)
{
    //pushing front initSize elements with initValue
    int i = 0;
    while(i < initSize)
    {
        push_front(initValue);
        i++;
    }
}

list::list(std::initializer_list<int> l)
    :
    head(nullptr),
    length(0)
{
    //copy the list into an array then go back from the last element in the array and
    //push it in front of the list
    int i = 0;
    int* arr = new int[l.size()]();

    for(auto elem : l)
    {
        arr[i] = elem;
        i++;
    }

    for(i--; i >= 0; i--)
    {
        push_front(arr[i]);
    }

    delete [] arr;
}
#endif        
