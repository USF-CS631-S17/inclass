#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE_MAX_STR_LEN 64

struct value_st {
    char arg[VALUE_MAX_STR_LEN];
    unsigned int normalized;
    char bin_str_literal[VALUE_MAX_STR_LEN];
    char bin_str_human[VALUE_MAX_STR_LEN];
};


int dec_str_to_unsigned(struct value_st *v_st_p)
{
    int i;
    int len;
    int d;
    unsigned int x = 0;
    int factor = 10;

    len = strlen(v_st_p->arg);
    
    for (i = 0; i < len; i++) {
        x = x * factor;
        d = v_st_p->arg[i] - '0';
        x = x + d;
    }        

    v_st_p->normalized = x;
    
    return 0;
}

int unsigned_to_binary_literal(struct value_st *v_st_p)
{
    int si; int i;
    unsigned int x;
    int b; char bchar;
    v_st_p->bin_str_literal[0] = '0';
    v_st_p->bin_str_literal[1] = 'b';

    si = 1;
    si = si + 32;

    x = v_st_p->normalized;
    
    for (i = 0; i < 32; i++) {
        /*
        b = x & 0b1;
        if (b == 0) {
            bchar = '0';
        } else {
            bchar = '1';
        }
        v_st_p->bin_str_literal[si] = bchar;
        */
        
        v_st_p->bin_str_literal[si] = (x & 0b1) ? '1' : '0';
        x = x >> 1;
        si = si - 1;
    }

    v_st_p->bin_str_literal[2 + 32 + 1] = '\0';
    
    return 0;
}

void print_converted_values(struct value_st *v_st_p) {
    printf("x = %d\n", v_st_p->normalized);
    printf("%s (base 2)\n", v_st_p->bin_str_literal);
    return;
}

int main(int argc, char *argv[])
{
    int i;
    int x;
    struct value_st v_st;

    /*
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    */
    
    strncpy(v_st.arg, argv[1], VALUE_MAX_STR_LEN - 1);

    if (dec_str_to_unsigned(&v_st) < 0) {
        printf("dec_str_to_unsigned() failed\n");
        exit(-1);
    }

    if (unsigned_to_binary_literal(&v_st) < 0) {
        printf("unsigned_to_binary_literal() failed\n");
        exit(-1);
    }

    print_converted_values(&v_st);
        
    return 0;
}

    
