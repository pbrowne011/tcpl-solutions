/* test.c: test itoa_min */
#include <stdio.h>
#include "minitoa.h"
#define MAXLINE 1000

int main()
{
    char s[MAXLINE];

    itoa(INT_MIN, s);
    printf("itoa(INT_MIN, s):    %s\n", s);
    itoa_min(INT_MIN, s);
    printf("itoa_min(INT_MIN,s): %s\n", s);
    
    return 0;
}
