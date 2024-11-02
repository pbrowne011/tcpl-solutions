/* htoi.c: convert string of hexadecimal digits into int
 *
 * htoi() assumes that all hexadecimal values are positive.
 */
#include <stdio.h>

int ishex(char c);

unsigned long htoi(char s[])
{
    int i;
    unsigned long n;

    n = i = 0;
    if (s[1] && (s[1]=='x' || s[1]=='X'))
        i = 2;
    for (i; ishex(s[i]); ++i) {
        n*=16;
        if (s[i]>='0' && s[i]<='9')
            n += (s[i]-'0');
        else if (s[i]>='A' && s[i]<='F')
            n += (s[i]-'A'+10);
        else
            n += (s[i]-'a'+10);
    }

    return n;
}

int ishex(char c)
{
    int d, h;
    
    d = (c >= '0' && c <= '9');
    h = (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
    return (d || h);
}
