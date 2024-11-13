/* test.c: test itob(n,s,b) */
#include <stdio.h>
#include "itob.h"
#define MAXLINE 1000

int main()
{
    int i, j;
    char s[MAXLINE];
    unsigned tests[] = {1, 10, 50, 100, INT_MAX,
                        2, 8, 16, 256, 1024};
    int      bases[] = {2, 8, 10, 16};

    for (i = 0; i < sizeof(bases)/sizeof(bases[0]); ++i) {
        for (j = 0; j < sizeof(tests)/sizeof(tests[0]); ++j) {
            itob(tests[j], s, bases[i]);
            printf("itob(%d,s,%2d): %35s\n", tests[j], bases[i], s);
        }
    }
    
    return 0;
}
