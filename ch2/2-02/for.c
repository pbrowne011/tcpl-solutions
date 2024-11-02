/* for.c: rewrite for loop on pg. 41
 */
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    
    while (get_line(line, MAXLINE) > 0)
        printf("%s", line);
}

int get_line(char s[], int lim)
{
    int c, i;

    /* Rewrite loop with if/else and break statements
     *
     * Could also be rewritten using a while loop, or
     * using some other variable j to store i and
     * setting i >= lim-1 to break the loop (if you
     * didn't "know" about break statements yet
     */
    for (i=0; i<lim-1; ++i) {
        c=getchar();
        if (c==EOF)
            break;
        else if (c=='\n')
            break;
        else
            s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
