#include<stdio.h>

int count_zeros_a(int *a, int len);
int count_zeros_index_a(int *a, int len);
int count_zeros_fixed_a(int *a, int len);

int count_zeros_c(int *a, int len)
{
    int i;
    int count = 0;

    for (i = 0; i < len; i++) {
        if (*a == 0) {
            count += 1;
        }
        a = a + 1;
    }

    return count;
}

int main(void)
{
    int a[] = {0, 1, 0, 99, 0, 1};
    int len = 6;
    int count;

    count = count_zeros_c(a, len);
    printf("count_zeros_c({0, 1, 0, 99, 0, 1}, %d) = %d\n", len, count);

    count = count_zeros_a(a, len);
    printf("count_zeros_a({0, 1, 0, 99, 0, 1}, %d) = %d\n", len, count);

    count = count_zeros_index_a(a, len);
    printf("count_zeros_index_a({0, 1, 0, 99, 0, 1}, %d) = %d\n", len, count);

    count = count_zeros_fixed_a(a, len);
    printf("count_zeros_fixed_a({0, 1, 0, 99, 0, 1}, %d) = %d\n", len, count);    

    return 0;
}
    
    
