#include <stdio.h>

/* function prototypes */
int sum3(int a, int b, int c);
void print_prompt(void);

int main(void) {
    int y = sum3(10, 15, 20);
    printf("sum3 result: %d\n", y);
    print_prompt();
    return 0;
}

int sum3(int a, int b, int c) {
    int result = a + b + c;
    return result;
}

void print_prompt(void) {
    printf("Please enter a number from 1-3:\n");
}
