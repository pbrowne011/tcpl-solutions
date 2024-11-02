/* uncomment.c: remove comments from a C source file
 *
 * This code has a large if-else with ugly branching to handle cases
 */
#include <stdio.h>

int main()
{
    int sl, ml, str;            /* strs, single line and multi-line comments */
    int c;
    char token[2];

    sl=ml=str=0;
    token[0]='\0';              /* note to self: token="aa" is ub */
    
    while ((c=getchar())!=EOF) {
        token[0]=token[1];
        token[1]=c;
        if (ml || sl) {
            if (ml && token[0]=='*' && token[1]=='/')
                ml=0;
            else if (c=='\n')
                sl=0;
        } else if (token[0]=='/' && !str) {
            if (c=='*')
                ml=1;
            else if (c=='/')
                sl=1;
        } else {
            if (token[0])
                printf("%c", token[0]);
            if (c=='"' && (token[0]!='\\'))
                str=!str;
        }
    }
}
