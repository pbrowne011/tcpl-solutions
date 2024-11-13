#include "itob.h"

/* itob: convert n into base b character representation of s
 *
 * This implementation handles bases 2 through 16 and
 * assumes all numbers are unsigned.
 */
void itob(unsigned n, char s[], int b)
{
    int i, r, o;

    i = 0;
    do {
        r = n % b;
        if (r < 10)
            o = '0';
        else
            o = 'a' - 10;
        s[i++] = r + o;
    } while ((n /= b) > 0);

    if (b == 2) {
        s[i++] = 'b';
        s[i++] = '0';
    } else if (b == 8) {
        s[i++] = '0';
    } else if (b == 16) {
        s[i++] = 'x';
        s[i++] = '0';
    }

    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
