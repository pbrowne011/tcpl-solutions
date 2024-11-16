/* patterrn.c: implement strrindex(s,t), which returns the
 * rightmost occurrence of t in s
 */
#include <stdio.h>
#define MAXLINE 1000            /* maximum input line length */

int get_line(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";        /* pattern to search for */

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int i, found = 0;

    while (get_line(line, MAXLINE) > 0) {
        if ((i = strrindex(line, pattern)) >= 0)
            found++;
        printf("%3d\t%s", i, line);
    }

    return found;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, r;

    r = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            r = i;
    }
    return r;
}
    
