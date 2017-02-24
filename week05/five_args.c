#include<stdio.h>

int foo(a0, a1, a2, a3, a4)
{
    return a0 + a1 + a2 + a3 + a4;
}

int main(void)
{
    int t;

    t = foo(0, 1, 2, 3, 4);

    printf("t = %d\n", t);

    return 0;
}

