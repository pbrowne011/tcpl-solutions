/* 80char.c: print all lines longer than 80 characters */

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print lines longer than 80 chars */
main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > 80)
            printf("%s", line);
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
