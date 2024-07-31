#include <stdio.h>

/* countspace.c
 * count all tab, blank, and newline characters in a file */

int main()
{
    long count = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if ((c == '\t') || (c == '\n') || (c == ' '))
            count++;
    }

    printf("Space count: %ld\n", count);
    return 0;
}
