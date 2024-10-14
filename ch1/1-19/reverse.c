/* reverse.c: reverse input one line at a time
 * note that this leaves newlines as they are, so the output
 * is typically shifted down one line
 */

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line */

int my_getline(char line[], int maxline);
void reverse(char s[], int len);

/* print reversed input lines */
main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

/* my_getline: read a line into s, return length
 *             stdlib has a default getline definition
 */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: take a string and reverse its characters */
void reverse(char s[], int len)
{
    int i, j;
    char c;

    i = 0;
    j = len-1;
    while (i < j) {
        c = s[i];
        s[i++] = s[j];
        s[j--] = c;
    }
}
