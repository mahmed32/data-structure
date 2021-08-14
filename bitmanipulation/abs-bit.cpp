#include<bits/stdc++.h>

int abs_bit(int x)
{
    int mask = x >> 31;
    return (x ^ mask) - mask;
}


int main()
{
    std::cout << (abs_bit(-2) == 2) << '\n';
    std::cout << (abs_bit(0) == 0) << '\n';
    std::cout << (abs_bit(1) == 1) << '\n';
    return 0;
}
