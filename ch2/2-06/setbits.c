/* setbits.c */
#include <stdio.h>

unsigned int setbits(unsigned x, int p, int n, unsigned y);
void print_uint_32(unsigned int x);
void print_case(unsigned x, int p, int n, unsigned y);

int main()
{
    int i, len;
    unsigned x, y, n, p;
    unsigned test[][2] = {{0, ~0},
                          {~0<<8, 0},
                          {~0<<12, ~0},
                          {0xffff, 0x00ff},
                          {0x7, 0xf},
                          {1, ~0},
                          {0xdeadbeef, 0xdeadbeef}};
    
    len = i = 0;
    while (test[i++][0]!=0xdeadbeef) len++;
    
    printf("replace x with y\n");
    for (i=0; i<len; ++i) {
        x = test[i][0];
        y = test[i][1];
        p = 31;
        n = 32;

        print_case(x, p, n, y);
    }
    printf("\n--------------------\n");
    
    printf("swap out first 2 bytes\n");
    for (i=0; i<len; ++i) {
        x = test[i][0];
        y = test[i][1];
        p = 31;
        n = 16;
        
        print_case(x, p, n, y);
    }
    printf("\n--------------------\n");
    
    printf("swap out last 2 bytes\n");
    for (i=0; i<len; ++i) {
        x = test[i][0];
        p = 15;
        n = 16;
        y = test[i][1];

        print_case(x, p, n, y);
    }
}

/* setbits: set bits at positions p, p-1, ..., p-(n-1) in x to bits in y */
unsigned int setbits(unsigned x, int p, int n, unsigned y)
{
    if (p < n-1) {
        fprintf(stderr,
                "Error: position (%d) smaller than number of bits -1 (%d)\n",
                p, n-1);
        return 0;
    }
    unsigned mask = ~(~0 << n) << p-(n-1);
    return (x & ~mask) | (y & mask);
}

/* ironic: this function only works on machines with 32-bit ints */
void print_uint_32(unsigned int x)
{
    int i;
    unsigned mask = 1<<31;
    
    for (i=0; i<32; ++i) {
        printf("%c", (x<<i & mask) ? '1' : '0');
    }
}

void print_case(unsigned x, int p, int n, unsigned y)
{
    printf("x:                      ");
    print_uint_32(x);
    printf("\ny:                      ");
    print_uint_32(y);
    printf("\nsetbits(x, %2d, %2d, y):  ", p, n);
    print_uint_32(setbits(x, p, n, y));
    printf("\n\n");    
}
