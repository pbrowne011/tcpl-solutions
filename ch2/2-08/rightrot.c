/* rightrot.c: implement rightrot(x,n) */
#include <limits.h>             /* CHAR_BIT */


/* rightrot: rotate x right n bits
 *
 * There is no error checking in this function - use at your own risk.
 * n should be positive, but works if zero.
 */
unsigned rightrot(unsigned x, int n)
{   
    const int bits = sizeof(unsigned) * CHAR_BIT;
    /* make undefined behavior explicit for n >= bits */
    n &= (bits-1);
    if (!n) return x;
    
    return (x >> n) | (x << bits-n);
}
