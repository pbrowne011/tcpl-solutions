/* test escape and encode */
#include <stdio.h>
#include "escape.h"
#define MAXLINE 1000            /* maximum input line */

int get_line(char line[], int maxline);

int main()
{
    char s[MAXLINE], t[MAXLINE];

    while (get_line(t, MAXLINE)) {
        printf("escape(s,t)\n--------\n");
        escape(s, t);
        printf("%s%s\n", t, s);
        printf("encode(t,s)\n--------\n");
        encode(t, s);
        printf("%s\n%s\n", s, t);
    }
    
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
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
