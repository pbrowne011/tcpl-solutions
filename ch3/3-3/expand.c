#include <string.h>

/* expand: expand shorthand in s1 into complete lists in s2*/
void expand(char s1[], char s2[])
{
    int c, d, i, j;
    
    i = j = 0;
    if (s1[i] == '-' && s1[i+1])           /* leading - */
        s2[j++] = s1[i++];
    while (s1[i]) {
        if (s1[i++] == '-' && i > 1) {
            c = s1[i-2], d = s1[i];
            while (d && c < d)
                s2[j++] = c++;
            if (d)
                s2[j] = d;
            else
                s2[++j] = '-';     /* trailing - */
        } else if (s1[i] && s1[i] != '-') {
            s2[j++] = s1[i-1];
        }
    }

    if (i) i--;
    s2[j++] = s1[i];          /* add last character */        
    s2[j] = '\0';
}

/* Some other functions from Chapter 3 are in the source code
 * below for reference.
 */

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /=2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
