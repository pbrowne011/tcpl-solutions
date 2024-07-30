#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; header version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    printf("  Fahrenheit to Celsius table\n\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        // fix to align with heading
        printf("%10.0f F%10.2f C\n", fahr, celsius);
        fahr = fahr + step;
    }
}

