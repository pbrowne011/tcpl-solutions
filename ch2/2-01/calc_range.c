/* range.c: determine ranges of basic data types in C */
#include <stdio.h>

float build_float(int sign, unsigned exp, unsigned mantissa);
double build_double(int sign, unsigned exp, unsigned long long mantissa);

int main()
{
    printf("Calculated sizes of basic data types in C on this machine.\n\n");
    printf("This program assumes a two's complement representation, which \n"
           "implies minimum and maximum representations based solely on the\n"
           "sizes of the types used for non-decimal types.\n\n");
    printf("signed char:    min %22hhd\n", 1 << (sizeof(char)*8-1));
    printf("                max %22hhd\n",
           (char)~0 ^ ((char)1 << (sizeof(char)*8-1)));
    printf("unsigned char:  min %22hhu\n", (unsigned char)0);
    printf("                max %22hhu\n", (unsigned char)~0);

    printf("short:          min %22hd\n", (short)1 << (sizeof(short)*8-1));
    printf("                max %22hd\n",
           (short)~0 ^ ((short)1 << (sizeof(short)*8-1)));
    printf("unsigned short: min %22hu\n", (unsigned short)0);
    printf("                max %22hu\n", (unsigned short)~0);

    printf("int:            min %22d\n", (int)1 << (sizeof(int)*8-1));
    printf("                max %22d\n",
           (int)~0 ^ ((int)1 << (sizeof(int)*8-1)));
    printf("unsigned int:   min %22u\n", (unsigned int)0);
    printf("                max %22u\n", (unsigned int)~0);

    printf("long:           min %22ld\n", (long)1 << (sizeof(long)*8-1));
    printf("                max %22ld\n",
           (long)~0 ^ ((long)1 << (sizeof(long)*8-1)));
    printf("unsigned long:  min %22lu\n", (unsigned long)0);
    printf("                max %22lu\n", (unsigned long)~0);

    printf("long long:      min %22lld\n",
           (long long)1 << (sizeof(long long)*8-1));
    printf("                max %22lld\n",
           (long long)~0 ^ ((long)1 << (sizeof(long long)*8-1)));
    printf("uns. long long: min %22llu\n", (unsigned long long)0);
    printf("                max %22llu\n", (unsigned long long)~0);


    printf("\n---------------------------\n");
    printf("For floats and doubles, the \"minimum value\" is the maximum\n"
           "value with the sign bit flipped. The minimum value with \n"
           "meaning is the smallest possible number that can be\n"
           "represented as a floating point number without being 0.\n\n");

    printf("To calcuate these floats, we calculate the sign bit, the \n"
           "exponent, and the mantissa. The sign bit is trivial. The exponent\n"
           "for the smallest normalized value is 1, as when this is\n"
           "subtracted from the bias, it produces the smallest possible\n"
           "exponent. An exponent of 0 produces 0. An exponent with all bits\n"
           "flipped produces NaN, so for maximum values, we turn on all bits\n"
           "except the last one. The mantissa must have all of its bits\n"
           "turned on to represent the maximum possible fraction, the last\n"
           "value of either range. For the minimum, it must be 0.\n");
    printf("\n---------------------------\n\n\n");

    printf("float:          min             %f\n", build_float(0, 1, 0));
    printf("                min (magnitude) %f\n",
           build_float(1, 0xfe, (unsigned)~0));
    printf("                max             %f\n",
           build_float(0, 0xfe, (unsigned)~0));
    printf("double:         min             %f\n", build_double(0, 1, 0));
    printf("                min (magnitude) %f\n",
           build_double(1, 0x7fe, (unsigned long long)~0));
    printf("                max             %f\n",
           build_double(0, 0x7fe, (unsigned long long)~0));
}

/* build_float: create float from sign, exp, matissa
 *
 * All values are hardcoded - floats are assumed to be 32 bits and to
 * follow IEEE 754. This implies 1 bit for sign, 8 bits for exp, and
 * 23 bits for mantissa (with 1 implied).
 */
float build_float(int sign, unsigned exp, unsigned mantissa)
{
    unsigned f = 0;
    f |= (sign & 01) << 31;
    f |= (exp & 0377) << 23;
    f |= (mantissa & 037777777);

    return *(float*)&f;
}

/* build_double: create double from sign, exp, mantissa */
double build_double(int sign, unsigned exp, unsigned long long mantissa)
{
    unsigned long long d = 0;
    d |= (unsigned long long)(sign & 0x1) << 63;
    d |= (unsigned long long)(exp & 0x7ff) << 52;
    d |= (unsigned long long)(mantissa & (unsigned long long)~0>>12);

    return *(double*)&d;
}
