/* fold.c: fold input lines longer than N characters
 *
 * With long lines, the program splits across multiple lines. With lines with no
 * blanks or tabs before the column, it cuts them off, as opposed to printing on
 * the next line.
 *
 * I attempted to keep this program simple: no more than 2 layers of
 * indentation, including function definition.
 *
 * For a program that folds along characters separated by blanks, similar to M-q
 * in Emacs, see pilcrow.c (from https://clc-wiki.net/wiki/K%26R2_solutions).
 */
#include <stdio.h>
#define MAXLINE 1000
#define LINEFOLD 70

int get_line(char line[], int maxline);
int fold(char line[], char next[], int idx);
int is_blank(char c);

int main()
{
    int idx;
    char line[MAXLINE], next[MAXLINE];
    
    next[0] = '\0';
    while (get_line(line, MAXLINE) > 0) {
        idx=0;
        while (idx=fold(line, next, idx)) printf("%s", next);
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

/* fold: fold line, store printable string in next */
int fold(char s[], char t[], int idx)
{
    int i, j;
    
    i=0;
    j=idx;
    while (i<LINEFOLD && s[j])
        t[i++] = s[j++];

    idx += i;
    if (!i || t[0]=='\n') {
        t[0]='\0';
        return 0;
    } else if (i>0 && t[i-1]!='\n') {
        t[i++]='\n';
    }
    
    t[i]='\0';
    return idx;
}

int is_blank(char c)
{
    return (c == ' ' || c == '\t');
}
