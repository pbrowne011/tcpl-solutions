// a single line comment
#include <stdio.h>
/* a
 * multi-line
 * comment
 */

int main()
{
    char *str1 = "Hello world";
    char *str2 = "// A little trickier";
    char *str3 = "/* how about this?";
    char *str4 = "and a comment close later... */";
    char *str5 = "A legal \
        multi-line string";
    char *str6 = "A string \"with quotes\"";

    return 0;
}
