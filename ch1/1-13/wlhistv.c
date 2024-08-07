/* wlhist.c
 * print a vertical histogram of the different word lengths of
 * input words
 */

#include <stdio.h>

#define IN 1      /* inside a word  */
#define OUT 0     /* outside a word */
#define MAX 20    /* max word length */

int main()
{
    int c, l, ml = 0, state = OUT;
    int wl[MAX];

    for (int i = 0; i < MAX; i++)
        wl[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (l > MAX)
                    l = MAX;
                ++wl[l];
                l = 0;
            }
            state = OUT;
        } else {
            state = IN;
            ++l;
        }
    }

    /* find tallest bar */
    for (int i = 0; i < MAX; i++) {
        if (wl[i] > ml)
            ml = wl[i];
    }

    /* top of graph */
    for (ml; ml > 0; --ml) {
        for (int i = 0; i < MAX; i++)
            if (wl[i] >= ml)
                printf("  x ");
            else
                printf("    ");
        printf("\n");
    }

                 
    
    /* bottom of graph */
    int line_len = (1 + 3)*MAX+1;

    for (int i = 0; i < line_len; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < MAX-1; i++)
        printf(" %2d ", i+1);
    printf(" %2d+\n", MAX);

    return 0;
}
    
