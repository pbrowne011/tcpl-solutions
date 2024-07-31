#include <stdio.h>

int main()
{
    int c;

    // validates (crudely) that getchar() != EOF is always either 0 or 1
    // nonzero value is true, zero is false
    // does not use putchar() for formatting reasons
    
    while ((c = getchar()) != EOF) {
        printf("Value of getchar != EOF: %d (%c)\n", c != EOF, c);
    }
    printf("Value of getchar != EOF: %d (EOF)\n", c != EOF);

    return 0;
}
