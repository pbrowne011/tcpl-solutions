/* strpbrk.c: define any(), which searches a string for
 * any set of bytes
 */

int any(char s1[], char s2[])
{
    int i, j;
    char s2_chars[128] = {0};

    for (i = 0; s2[i] != '\0'; ++i)
        s2_chars[s2[i]]++;

    for (j = i = 0; s1[i] != '\0'; ++i)
        if (s2_chars[s1[i]])
            return i;

    return -1;
}
