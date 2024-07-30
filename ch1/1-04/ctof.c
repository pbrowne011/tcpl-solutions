#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = -20, -10, ..., 100 */
int main()
{
    /* in this program, it still makes sense to use floating point
       to cancel out the 5.0*/
    float celsius, fahr;
    int lower, upper, step;

    lower = -20;
    upper = 100;
    step = 10;

    printf("  Celsius to Fahrenheit table\n\n");
    
    celsius = lower;
    while (celsius <= upper) {
        fahr = ((9.0/5.0)*celsius) + 32.0;
        printf("%10.0f C %9.0f F\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
