/* syntax.c: a basic C syntax checker
 *
 * Step 1: rudimentary syntax errors ({}, (), [])
 *
 * Note to self: need to add comment & string & char checking
 */
#include <stdio.h>
#define STACKSIZE 1000

int stack_error(int c);
int match (int char1, int char2);

int main()
{
    int i, c;
    char stack[STACKSIZE];

    i=0;
    while ((c=getchar())!=EOF) {
        if (c=='('||c=='['||c=='{')
            stack[i++]=c;
        else if ((c==')'||c==']'||c=='}') && (c-stack[--i])>2)
            return stack_error(stack[i]);
    }

    if (i)
        return stack_error(stack[i]);
}

int stack_error(int c)
{
    switch (c) {
    case '(':
        printf("Error: unbalanced parenthesis\n");
        return 1;
    case '{':
        printf("Error: unbalanced brace\n");
        return 1;
    case '[':
        printf("Error: unbalanced bracket\n");
        return 1;
    }
}

