/* detab.c: replace tabs with proper number of blank spaces
 * 
 * This program uses a tab stop every N columns.
 * If you know that N should be a power of 2, you could perform
 * col & (N-1) instead of modulus to improve efficiency.
 */
#include <stdio.h>
#define N 8

int print_char(int c, int col);
void print_spaces(int nspaces);

int main()
{
    int c;
    int col;

    col=0;
    while ((c=getchar()) != EOF)
        col = print_char(c, col);
    
    return 0;
}

int print_char(c, col)
{
    int nspaces;
    
    if (c == '\t')
        print_spaces(nspaces = (col % N));
    else
        printf("%c", c);
    
    if (c == '\n')
        col=0;
    else if (c == '\t')
        col+=(N-nspaces);
    else
        col++;

    return col;
}

void print_spaces(int nspaces)
{
    while (++nspaces<=N)
        printf("%c", ' ');
}
