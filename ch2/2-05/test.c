/* test.c: test any()
 *
 * This test code does not require allocating memory
 * for modifiable strings, but it was easier to copy
 * 2-04/test.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strpbrk.h"
#define MAXLINE 1000
#define ARRAYSIZE 200

int get_line(char line[], int maxline);

int main()
{
    int i, len;
    char line[MAXLINE], *test[ARRAYSIZE][2];

    /* get testing input */
    for (i = 0; i < ARRAYSIZE; i++) {
        test[i][0] = malloc(MAXLINE * sizeof(char));
        test[i][1] = malloc(MAXLINE * sizeof(char));
        if (!test[i][0] || !test[i][1]) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }
    
    i = 0;
    while ((len=get_line(line, MAXLINE)) > 0) {
        strcpy(test[i][0], line);
        get_line(line, MAXLINE);
        strcpy(test[i][1], line);
        get_line(line, MAXLINE);
        ++i;
    }

    test[i][0] = NULL;
    
    len=i=0;
    while (test[i++][0]) ++len;

    
    for (i=0; i<len; ++i) {
        printf("s1:          %s\n", test[i][0]);
        printf("s2:          %s\n", test[i][1]);    
        printf("any(s1, s2): %d\n\n", any(test[i][0], test[i][1]));
    }

    for (int j = 0; j < i; j++) {
        free(test[j][0]);
        free(test[j][1]);
    }
}

/* get_line: get standard input with no newline character ('\n') */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}
