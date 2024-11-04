/* lower.c: implement lower(c) with a conditional */

/* lower_cond: convert c to lower case; ASCII only
 *
 * lower_cond(c) should have error checking to make sure that c is a character
 * and not another integer with undefined behavior. See
 * https://nullprogram.com/blog/2023/02/11/ for arguments referring to functions
 * like islower()
 */
int lower_cond(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + ('a'-'A')) : (c);
}

/* lower: convert c to lower case; ASCII only
 *
 * lower(c) is implemented in the C standard library and can be found in the
 * header file <ctype.h> as tolower(c).
 */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
