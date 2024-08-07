/* wlhist.c
 * print a horizontal histogram of the different word lengths of
 * input words
 */

#include <stdio.h>

#define IN 1      /* inside a word  */
#define OUT 0     /* outside a word */
#define MAX 20    /* max word length */

int main()
{
    int c, l, state = OUT;
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

    for (int i = 0; i < MAX; i++) {
        if (i == MAX-1)
            printf("%2d+ | ", MAX);
        else
            printf("%2d  | ", i+1);

        while (wl[i] > 0) {
            printf("x");
            --wl[i];
        }
        printf("\n");
    }

    return 0;
}
    
