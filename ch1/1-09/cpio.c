#include <stdio.h>

/* cpio.c
 * copy standard input to standard output, replacing each string
 * of one or more blanks with a single blank
 *
 * chose to use a separate function, though those are introduced
 * in Chapter 2, as it improves readability
 */

int is_space(int c)
{
    return ((c == ' ') || (c == '\t') || (c == '\n')
            || (c == '\v') || (c == '\r'));
}

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (!is_space(c)) {
            putchar(c);
            continue;
        }

        putchar(' ');
        
        while (is_space(c = getchar()))
            ;

        if (c == EOF)
            break;
        putchar(c);
    }
    return 0;
}
