/* minitoa: handle largest negative number (int)
 *
 * In a two's complement number representation, the largest negative
 * number has a larger magnitude than the largest positive number by 1.
 * The program on pg. 64 (modified here), when handling the sign,
 * converts INT_MIN to a positive number by flipping the sign. In two's
 * complement, this is done by flipping the bits and adding one. Say an
 * int is 8 bits (for ease of representation).
 *
 * --------------------------
 * INT_MIN    1 0 0 0 0 0 0 0
 * flip       0 1 1 1 1 1 1 1
 * add 1      ? ? ? ? ? ? ? ?
 * --------------------------
 * 
 * Taking the negative of INT_MIN causes integer overflow, which is
 * undefined behavior in C. The best way to handle this is to detect
 * if n == INT_MIN and handle that representation separately.
 *
 * Note that itoa() prints the '(' character on my machine (x86-64,
 * compiled using gcc version 11.4.0), not sure why though...
 */
#include "minitoa.h"

void reverse(char s[]);

/* itoa_min: convert n to characters in s, handle INT_MIN */
void itoa_min(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        if (n == INT_MIN)       /* handle as INT_MAX */
            n = -(n+1);
        else
            n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    if (sign == INT_MIN)        /* add 1 to first digit */
        s[0]++;
    s[i] = '\0';
    reverse(s);
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)         /* record sign */
        n = -n;                 /* make n positive */
    i = 0;
    do {                        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
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
