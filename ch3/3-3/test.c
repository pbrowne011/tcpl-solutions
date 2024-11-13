/* test.c: test expand(s1,s2) */
#include <stdio.h>
#include "expand.h"
#define MAXLINE 1000

int main()
{
    int i;
    char *tests[] = {"a-z", "a-b-c", "a-z0-9", "-a-z", /* K&R cases */
            "", "-", "abcdefg", "---", "a-b-c-d-e", "a-z-", "q"}; /* custom
                                                                   * cases */
    char s[MAXLINE];

    for (i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
        expand(tests[i], s);
        printf("s1: %s\ns2: %s\n\n", tests[i], s);
    }
    
    return 0;
}
