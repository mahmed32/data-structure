#include "stack-linked-list.h"

int main()
{
    lstack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    std::cout << (stack.size() == 7) << std::endl;
    stack.print();
    stack.pop();
    stack.print();
    std::cout << (stack.empty() == 0) << std::endl;
    stack.pop();
    stack.pop();
    stack.print();
    return 0;
}
