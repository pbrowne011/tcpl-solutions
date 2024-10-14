/* chist.c
 * print a horizontal histogram of the frequencies of different
 * characters (digits 0-9, whitespace, other)
 */

#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    for (int i = 0; i < 10; i++) {
        printf("%5d | ", i);
        while (ndigit[i] > 0) {
            printf("x");
            --ndigit[i];
        }
        printf("\n");
    }

    /* print space chars */
    printf("space | ");
    while (nwhite > 0) {
        printf("x");
        --nwhite;
    }
    printf("\n");

    /* print other chars */
    printf("other | ");
    while (nother > 0) {
        printf("x");
        --nother;
    }
    printf("\n");

    return 0;
}
    
