#include <stdio.h>
#include <ctype.h>

/* cpio.c
 * Copy standard input to standard output, replacing each string
 * of one or more whitespace characters with a single space.
 *
 * this code was written using Claude 3.5 to help me figure out
 * how to denest some of my logic
 *
 * the idea is to use a 1-slot buffer to keep track of the character
 * before the one we're reading (was it a space?), a bit like a
 * stack for that slot
 */

int main() {
    // assign both to EOF in case 1st char is ' '
    int c, last_c = EOF;
    
    while ((c = getchar()) != EOF) {
        // first case: c is not a blank
        if (!isspace(c)) {
            putchar(c);
            last_c = c;
            continue;
        }

        // second case: c is a blank, last_c is not a blank
        if (!isspace(last_c)) {
            putchar(' ');
            last_c = ' ';
        }

        // third case (not explicit): c and last_c are blanks
        // do nothing
    }
    
    return 0;
}
