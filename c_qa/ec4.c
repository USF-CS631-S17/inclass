/* Use a global variable to find and print the maximum of 3 numbers */
#include <stdio.h>

/* global variable holding the maximum value */
int max;

void find_max(int a, int b, int c) {
    max = a;

    if (b > max) {
        if (c > b) {
            max = c;
        } else {
            max = b;
        }
    } else if (c > max) {
        max = c;
    }
}

void print_max(void) {
    printf("The maximum number is: %d\n", max);
}

int main(void) {
    find_max(4, 3, 7);
    print_max();

    return 0;
}
