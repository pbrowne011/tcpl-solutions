/* atof.c: implementations of atof() */
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, exp, pw;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skipe white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') { /* scientific notation */
        if (s[i+1] == '-') {
            exp = 10.0;
            ++i;
        } else {
            exp = 0.1;
        }
        pw = atof(&s[++i]);
        while (pw--)
            power *= exp;
    }
    return sign * val / power;
}

/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
    double atof(char s[]);

    return (int) atof(s);
}
