#include <stdio.h>

struct mystruct {
    int x;
    int y;
    int *xp;
    int *yp;
};

int main(void) {
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(usigned) = %lu\n", sizeof(unsigned));
    printf("sizeof(long) = %lu\n", sizeof(long));
    printf("sizeof(long long) = %lu\n", sizeof(long long));
    printf("sizeof(int *) = %lu\n", sizeof(int *));
    printf("sizeof(float) = %lu\n", sizeof(float));
    printf("sizeof(double) = %lu\n", sizeof(double));
    printf("sizeof(struct mystruct) = %lu\n", sizeof(struct mystruct));
    return 0;
}
