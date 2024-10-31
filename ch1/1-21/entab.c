/* entab.c: repaces spaces with minimum spaces and tabs combination
 *
 * This program assumtes a tab stop every N columns. Unlike detab.c,
 * it uses a buffer to store lines.
 *
 * It might be smarter to do this as a stream, as you don't have to recopy
 * memory every time you insert tabs. However, you'd have to use more global
 * state to track your relative and actual position on a line (column number,
 * first spaces position).g
 *
 * I cheated by including string.h.
 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define N 4

int get_line(char line[], int maxline);
void entab(char line[], int length);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len=get_line(line, MAXLINE)) > 0) {
        entab(line, len);
        printf("%s", line);
    }
}

/* get_line: same function as my_getline from rmblank.c */
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

/* entab: a bit convoluted, may need to refactor */
void entab(char s[], int len)
{
    int i, j, sp;
    char t[len];

    i=0;
    j=0;
    sp=0;
    while (s[i]) {
        if ((s[i]!=' ') && (sp)) {
            while (((i-sp)/N)<(i/N)) t[j++]='\t', sp-=N;
            while (sp-->0) t[j++] = ' ';
            t[j++]=s[i++];
            sp=0;
        } else if (s[i] == ' ') {
            i++;
            sp++;
        } else {
            t[j++]=s[i++];
        }
    }
    t[j]='\0';
    strcpy(s,t);
}

