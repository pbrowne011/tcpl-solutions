/* invert.c
 *
 * See https://patbrowne.me/posts/sal/ on why you cannot
 * invert x with this function
 */
#include <stdio.h>

unsigned int invert(unsigned x, int p, int n);
void print_uint_32(unsigned int x);
void print_case(unsigned x, int p, int n);

int main()
{
    int i, len;
    unsigned x, n, p;
    unsigned test[] = {0, ~0<<8, ~0<<12, ~0, 0xffff, 0x00ff,
                       0x7, 0xf, 1, ~0, 0xdeadbeef};
    
    len = i = 0;
    while (test[i++]!=0xdeadbeef) len++;
    
    printf("invert first 31 bits of x\n");
    for (i=0; i<len; ++i) {
        x = test[i];
        p = 31;
        n = 31;

        print_case(x, p, n);
    }
    printf("\n--------------------\n");
    
    printf("invert first 2 bytes\n");
    for (i=0; i<len; ++i) {
        x = test[i];
        p = 31;
        n = 16;
        
        print_case(x, p, n);
    }
    printf("\n--------------------\n");
    
    printf("invert last 2 bytes\n");
    for (i=0; i<len; ++i) {
        x = test[i];
        p = 15;
        n = 16;
        
        print_case(x, p, n);
    }
}

/* invert: invert bits at positions p, p-1, ..., p-(n-1) in x
 * 
 * I needed to look at compiler-generated assembly to realize that xor
 * was the correct operation
 */
unsigned int invert(unsigned x, int p, int n)
{
    if (p < 0) {
        fprintf(stderr,
                "Error: position (p=%d) less than 0\n",
                p);
        return 0;
    } else if (n < 1) {
        fprintf(stderr,
                "Error: size (%d) is not a positive number\n",
                n);
        return 0;
    } else if (p < n-1) {
        fprintf(stderr,
                "Error: position (%d) less than n - 1 (%d)\n",
                p, n-1);
        return 0;
    }
    unsigned mask = ~(~0 << n) << p-(n-1);
    return x ^ mask;
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

void print_case(unsigned x, int p, int n)
{
    printf("x:                  ");
    print_uint_32(x);
    printf("\n~x:                 ");
    print_uint_32(~x);
    printf("\ninvert(x, %2d, %2d):  ", p, n);
    print_uint_32(invert(x, p, n));
    printf("\n\n");    
}
