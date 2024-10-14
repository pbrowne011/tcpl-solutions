#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */

/* declare function */
float ftoc(float fahr);

int main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
        fahr = fahr + step;
    }

    return 0;
}

float ftoc(float fahr)
{
    float celsius;
    celsius = (5.0/9.0) * (fahr-32);
    return celsius;
}

