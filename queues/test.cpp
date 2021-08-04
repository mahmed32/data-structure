#include "queue.h"
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    std::cout << (q.empty() == 0) << std::endl;
    return 0;
}
