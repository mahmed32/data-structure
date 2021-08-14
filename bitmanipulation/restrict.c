#include <stdio.h>

void myFunction(int* x)
{
    *x = 2;
}

int main()
{
    int x = 23;
    int* __restrict y = &x;
    myFunction(y);
    printf("%d ",x);
    return 0;
}
