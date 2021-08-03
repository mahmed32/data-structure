#include <iostream>
#include "linked-list-no-tail.h"
void test(bool val) 
{
    std::cout << val << std::endl;
}

int main()
{
    //TODO:add tests to linked list class
    {
        list l;
        test(l.size() == 0);
        test(l.empty() == 1);
        l.push_front(69);
        l.print();
        test(l.empty() == 0);
        test(l.size() == 1);
        l.pop_front();
        l.print();
        test(l.size() == 0);
        l.push_front(6);
        l.push_front(5);
        l.push_front(4);
        l.push_front(3);
        l.push_front(2);
        l.push_front(1);
        l.print();
        l.push_back(7);
        l.push_back(8);
        l.push_back(9);
        l.push_back(10);
        l.print();
        test(l.front() == 1);
        test(l.back() == 10);
        l.insert(0, -1);
        l.insert(5, -1);
        l.insert(l.size() - 1, -1);
        l.print();
        l.erase(0);
        l.erase(4);
        l.erase(9);
        l.print();
        test(l.value_n_from_end(0) == 10);
        l.reverse();
        l.print();
        l.reverse();
        l.remove_value(10);
        l.print();
    }
    {
        list l(10, 0);
        test(l.size() == 10);
        l.print();
        l.pop_back();
        test(l.empty() == 0);
        l.print();
    }
    {
        list l{1,2,3,4,5};
        l.print();
        l.reverse();
        l.print();
        l.reverse();
        l.print();
    }
    return 0;
}
