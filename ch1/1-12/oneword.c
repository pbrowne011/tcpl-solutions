#include <stdio.h>

int main()
{
    // use anonymous enum instead of preprocessor
    enum { OUT, IN };
    int c, state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        } else {
            state = IN;
            putchar(c);
        }
    }

    return 0;
}
