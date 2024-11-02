/* test.c: test htoi() */
#include <stdio.h>
#include "htoi.h"

int main()
{
    int i, len;
    char *test[] = {"0", "a", "0xffff", "0XFFFF",
                    "000000", "FFFF", "0xdeadbeef",
                    "0XFADCAFE", "12345678", "0x100000",
                    NULL};

    len=i=0;
    while (test[i++]) ++len;

    printf("       hex        decimal\n");
    for (i=0; i<len; ++i)
        printf("%10s %14lu\n", test[i], htoi(test[i]));
    
}
