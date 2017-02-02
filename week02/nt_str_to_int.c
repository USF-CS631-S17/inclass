#include <stdio.h>
#include <string.h>

int str_to_int(char *s)
{
    int i;
    int len;
    int d;
    int x = 0;
    int factor = 10;

    len = strlen(s);
    
    for (i = 0; i < len; i++) {
        x = x * factor;
        d = s[i] - '0';
        x = x + d;
    }        

    return x;
}

int main(int argc, char *argv[])
{
    int i;
    int x;
    
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    x = str_to_int(argv[1]);
    printf("x = %d\n", x);
    
    return 0;
}

    
