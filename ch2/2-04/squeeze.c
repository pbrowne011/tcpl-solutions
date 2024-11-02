/* squeeze.c: remove charafters from first arg contained in second
 *
 * The function void squeeze(char s1[], char s2[]) assumes that
 * both s1 and s2 contain only ASCII characters.
 */

/* squeeze: delete all c from s
 * from pg. 74 of TCPL
 */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze: delete all characters from s2 found in s1 */
void squeeze_str(char s1[], char s2[])
{
    int i, j;
    char s2_chars[128] = {0};

    for (i = 0; s2[i] != '\0'; ++i)
        s2_chars[s2[i]]++;

    for (j = i = 0; s1[i] != '\0'; ++i)
        if (!s2_chars[s1[i]])
            s1[j++] = s1[i];
    s1[j] = '\0';
}
