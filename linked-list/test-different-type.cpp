#include <iostream>

template<typename type>
struct node
{
    type data;
    node<type>* next;
};

int main()
{
    node<int>* head = new node<int>{1, new node<int>{2, new node<int>{3, nullptr}}};

    node<int>* trav = head;
    while(trav)
    {
        std::cout << trav->data << std::endl;
        trav = trav->next;
    }

    trav = head;
    while(head)
    {
        head = trav->next;
        delete trav;
        trav = head;
    }
}
