#include <iostream>
#include "array.h"

int main()
{
    {
        array<int> arr;
        arr.push(1);
        arr.push(2);
        arr.push(3);
        arr.push(4);
        arr.push(5);
        arr.push(6);
        arr.push(7);
        arr.push(8);
        arr.push(9);
        arr.push(10);
        std::cout << (arr.cap() == 10) << std::endl;
        arr.push(11);
        arr.push(12);
        arr.push(13);
        arr.push(14);
        std::cout << (arr.find(13) == 12) << std::endl;
        std::cout << (arr.size() == 14) << std::endl;
        std::cout << (arr.cap() == 20) << std::endl;
        std::cout << (arr.isEmpty() == 0) << std::endl;
        std::cout << (arr.at(7) == 8) << std::endl;
        arr.at(7) = 69;
        std::cout << (arr.at(7) == 69) << std::endl;
        arr.print();
        arr.insert(3, 0);
        arr.print();
        arr.prepend(0);
        arr.print();
        arr.pop();
        arr.print();
        arr.del(4);
        arr.print();
        arr.remove(0);
        arr.print();
        arr.resize(5);
        arr.print();
        std::cout << arr.size() << std::endl;
        std::cout << arr.cap() << std::endl;
    }
    {
        array<int> arr(10, 0);
        arr.print();
        std::cout << (arr.cap() == 20) << std::endl;
    }
    {
        array<int> arr{1,2,3,4,5,6,7};
        arr.print();
        std::cout << (arr.size() == 7) << std::endl;
        std::cout << (arr.cap() == 14) << std::endl;
    }
    return 0;
}
