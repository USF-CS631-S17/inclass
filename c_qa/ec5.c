/* Use a global variable to find and print the maximum of 3 numbers */
#include <stdio.h>

/* global variable holding the maximum value */

int find_max(int a, int b, int c) {
    int max = a;

    if (b > max) {
        if (c > b) {
            max = c;
        } else {
            max = b;
        }
    } else if (c > max) {
        max = c;
    }

    return max;
}

void print_max(int max) {
    printf("The maximum number is: %d\n", max);
}

int main(void) {
    int max;
    
    max = find_max(4, 3, 7);
    print_max(max);

    return 0;
}
