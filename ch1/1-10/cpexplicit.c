#include <stdio.h>

/* cpexplicit.c
 * copies standard input to standard output, replacing escape characters
 * with their C representation
 */

int is_escape(int c)
{
    return ((c == '\a') || (c == '\b') || (c == '\f') || (c == '\n')
            || (c == '\r') || (c == '\t') || (c == '\v') || (c == '\\')
            || (c == '\'') || (c == '\"'));
}

// the book only asks for these three common escape characters
int is_escape_tcpl(int c)
{
    return ((c == '\t') || (c == '\b') || (c == '\\'));
}

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }

    return 0;
}
