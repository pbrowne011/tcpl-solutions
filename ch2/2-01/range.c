/* range.c: determine ranges of basic data types in C
 *
 * These header files can be found in /usr/include/limits.h and
 * /usr/lib/gcc/x86_64-linux-gnu/11/include/float.h (on this machine). For the
 * current standard related to the defined macro (IEC 60559:2020), see
 * https://www.iso.org/standard/80985.html.
 */
#define __STDC_WANT_IEC_60559_BFP_EXT__
#include <limits.h>
#include <float.h>
#include <stdio.h>

// TODO: figure out the correct macros to be using
int main()
{
    printf("Sizes of basic data types in C on this machine,\n");
    printf("as defined by <limits.h> and <float.h>\n\n");
    printf("Note to self: <float.h> currently uses ISO C Standard\n");
    printf("9899:201x, which is defined in Section 5.2.4.2.2. Current\n");
    printf("standard 9899:202x defines this in Section 5.2.5.3.3.\n\n\n");
    printf("Word size on this machine: %2d\n",   __WORDSIZE);
    printf("Number of bits in char:    %2d\n",   CHAR_BIT);
    printf("Width of a short:          %2d\n",   SHRT_WIDTH);
    printf("Width of an int:           %2d\n",   INT_WIDTH);
    printf("Width of a long:           %2d\n", LONG_WIDTH);
    printf("Width of a long long:      %2d\n", LLONG_WIDTH);
    printf("Width of a float:          %2d\n",   SHRT_WIDTH);
    printf("Width of a double:         %2d\n",   INT_WIDTH);
    printf("Width of a long double:    %2d\n",   INT_WIDTH);
#ifdef __CHAR_UNSIGNED__
    printf("On this machine, the default type for `char` is UNSIGNED.\n");
#else
    printf("On this machine, the default type for `char` is SIGNED.\n");
#endif
    printf("(In C, all other types are default signed)\n\n");
    printf("char:           min %22d\n", CHAR_MIN);
    printf("                max %22d\n", CHAR_MAX);
    printf("unsigned char:  min %22u\n", 0);
    printf("                max %22u\n", UCHAR_MAX);
    printf("signed char:    min %22d\n", SCHAR_MIN);
    printf("                max %22d\n", SCHAR_MAX);

    printf("short:          min %22hd\n", SHRT_MIN);
    printf("                max %22hd\n", SHRT_MAX);
    printf("unsigned short: min %22u\n", 0);
    printf("                max %22hu\n", USHRT_MAX);

    printf("int:            min %22d\n", INT_MIN);
    printf("                max %22d\n", INT_MAX);
    printf("unsigned int:   min %22u\n", 0);
    printf("                max %22u\n", UINT_MAX);

    printf("long:           min %22ld\n", LONG_MIN);
    printf("                max %22ld\n", LONG_MAX);
    printf("unsigned long:  min %22u\n", 0);
    printf("                max %22lu\n", ULONG_MAX);

    printf("long long:      min %22lld\n", LLONG_MIN);
    printf("                max %22lld\n", LLONG_MAX);
    printf("uns. long long: min %22u\n", 0);
    printf("                max %22llu\n\n\n", ULLONG_MAX);

    printf("On x86 machines, floats and doubles have default sizes.\n");
    printf("sizeof(float):  %lu\n", sizeof(float));
    printf("sizeof(double): %lu\n", sizeof(double));
    printf("float:          min          %f\n", FLT_MIN);
    printf("                min exponent %d\n", FLT_MIN_EXP);
    printf("                max          %f\n", FLT_MAX);
    printf("                max exponent %d\n", FLT_MAX_EXP);
    printf("double:         min          %f\n", DBL_MIN);
    printf("                min exponent %d\n", DBL_MIN_EXP);
    printf("                max          %f\n", DBL_MAX);
    printf("                max exponent %d\n", DBL_MAX_EXP);
}
