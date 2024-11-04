/* test.c: test rightrot(x,n) */
#include <stdio.h>
#include "rightrot.h"

void print_uint_32(unsigned int x);
void print_case(unsigned x, int n);

int main()
{
    int i, j, len;
    unsigned x, n;
    unsigned test[] = {0, ~0, 0x1, ~0<<16, ~0<<8,
                       0x7, 0xf, 0xdeadbeef};
    
    len = i = 0;
    while (test[i++]!=0xdeadbeef) len++;
    
    for (i=0; i<len; ++i) {
        x = test[i];
        printf("x:               ");
        print_uint_32(x);
        printf("\n");

        for (j=0; j<sizeof(unsigned)*8; ++j) {
            print_case(x, j);
        }
        printf("\n\n--------------------\n");
    }
}

/* ironic: this function only works on machines with 32-bit ints */
void print_uint_32(unsigned int x)
{
    int i;
    unsigned bit = 1<<31;
    
    for (i=0; i<32; ++i) {
        printf("%c", (x<<i & bit) ? '1' : '0');
    }
}

void print_case(unsigned x, int n)
{
    printf("rightrot(x, %2d): ", n);
    print_uint_32(rightrot(x, n));
    printf("\n");    
}

