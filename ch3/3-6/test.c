/* test.c: test paditoa(n,s,c) */
#include <stdio.h>
#include "paditoa.h"
#define MAXLINE 1000

int main()
{
    int i, j;
    char s[MAXLINE];
    unsigned tests[] = {1, 10, 50, 100, INT_MAX,
                        2, 8, 16, 256, 1024};
    int       pads[] = {2, 5, 10, 14, 30};

    for (i = 0; i < sizeof(pads)/sizeof(pads[0]); ++i) {
        for (j = 0; j < sizeof(tests)/sizeof(tests[0]); ++j) {
            itoa_pad(tests[j], s, pads[i]);
            printf("itoa_pad(%d,s,%2d): \"%s\"\n",
                   tests[j], pads[i], s);
            if (strlen(s) < pads[i])
                printf("FAIL: strlen(s) = %2ld\tpad size = %2d\n----------\n",
                       strlen(s), pads[i]);
        }
    }
    
    return 0;
}
