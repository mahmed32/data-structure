//queue implemntation using array with fixed max_size
#ifndef QUEUE_A_H
#define QUEUE_A_H
#include <iostream>
class aqueue
{
    public:
        aqueue(size_t max_size);
        ~aqueue();
        void enqueue(int data);
        int dequeue();
        bool empty() const;
        bool full() const;
        void print() const;
    private:
        size_t r_index, w_index, max_size;
        int* arr;
};

void aqueue::print() const
{
    if(empty())
    {
        std::cout << "empty container" << std::endl;
        return;
    }
        
    size_t i = r_index;
    if(w_index > r_index)
    {
        while(i < w_index)
        {
            std::cout << arr[i] << " ";
            i++;
        }
    }
    else
    {
        while(i<max_size)
        {
            std::cout << arr[i] << " ";
            i++;
        }
        i = 0;
        while(i < w_index)
        {
            std::cout << arr[i] << " ";
            i++;
        }
    }
    std::cout << std::endl;
}


bool aqueue::full() const
{
    return (r_index - w_index == 1) || (r_index == 0 && w_index == max_size-1);
}

bool aqueue::empty() const
{
    return r_index == w_index;
}

int aqueue::dequeue()
{
    if(empty())
        throw "request an element form an empty container";

    int val = arr[r_index];
    r_index = (++r_index)%max_size;
    return val;
}

void aqueue::enqueue(int data)
{
    if(full())
        throw "adding element to a full container";

    arr[w_index] = data;
    w_index = (++w_index)%max_size;
}

aqueue::~aqueue()
{
    delete [] arr;
}

aqueue::aqueue(size_t max_size)
    :
    r_index(0),
    w_index(0),
    max_size(max_size)
{
    arr = new int[max_size]();
}

#endif
