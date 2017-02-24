#include<stdio.h>

int x = 99;

int foo(int a)
{
    return a + 1;
}

int main(void)
{
    int n;

    n = foo(1);

    printf("n = %d\n", n);

    return 0;
}
