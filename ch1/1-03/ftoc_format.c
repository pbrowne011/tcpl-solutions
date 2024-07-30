#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; unique formatting version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        // edit printf formatting
        //
        // this one is rather useless, %3f means "at least 3 chars wide"
        // printf("%3f %f\n", fahr, celsius);
        // note: for %<n>f to be useful here (with no decimal
        // point), n > 8
        printf("%10f %12f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

