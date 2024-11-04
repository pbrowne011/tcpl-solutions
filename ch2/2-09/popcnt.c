/* popcnt.c: implement Kernighan's popcnt algorithm
 *
 */

/* bitcount: count 1 bits in x; original function from pg. 50 */
int bitcount(unsigned x)
{
    int b;

    for (b=0; x!=0; x>>=1)
        if (x & 01)
            b++;
    return b;
}

/* popcount: beautiful, eliminates branching, minimizes loop iterations */
int popcount(unsigned x)
{
    int b;

    for (b=0; x!=0; x&=(x-1))
        b++;
    return b;
}
