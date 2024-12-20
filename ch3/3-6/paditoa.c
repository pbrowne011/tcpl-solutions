/* paditoa: add left padding to string conversions */
#include "paditoa.h"

void reverse(char s[]);

/* itoa_pad: convert n to at minimum c characters in s */
void itoa_pad(int n, char s[], int c)
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
    while (i < c)               /* pad string */
        s[i++] = ' ';
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
