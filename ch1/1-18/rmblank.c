/* rmblank.c: remove blank lines */

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line */

int my_getline(char line[], int maxline);
void rmblank(char line[], int len);

/* print blankless lines */
main()
{
    int len;                    /* current line length */
    char line[MAXLINE];         /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0) {
        rmblank(line, len);
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

/* rmblank: remove blank spaces */
void rmblank(char s[], int len)
{
    int i;

    i = len;
    while ((i>0 && (s[i-1]==' ' || s[i-1]=='\t')) || (i==1 && s[0]=='\n')) {
        s[i-1] = s[i];
        --i;
    }
}
