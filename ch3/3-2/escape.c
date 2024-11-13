/* escape: convert characters into escape sequences 
 *
 * Assumes s has enough space to store character
 * expansions from characters in t.
 */
void escape(char s[], char t[])
{
    int i, j, l;
    char c;

    for (j = i = 0; t[i]; ++i) {
        c = t[i];
        switch(c) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t': 
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\v':
            s[j++] = '\\';
            s[j++] = 'v';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\r': 
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\f':
            s[j++] = '\\';
            s[j++] = 'f';
            break;
        case '\a':
            s[j++] = '\\';
            s[j++] = 'a';
            break;
        default:
            s[j++] = c;
        }
    }
}

/* encode: convert visible escape sequences into single characters */
void encode(char s[], char t[])
{
    int i, j, l, bs;
    char c;

    j = i = 0;
    while (t[i]) {
        c = t[i++];
        switch(c) {
        case '\\':
            c = t[i++];
            switch(c) {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            case 'v':
                s[j++] = '\v';
                break;
            case 'b':
                s[j++] = '\b';
                break;
            case 'r':
                s[j++] = '\r';
                break;
            case 'f':
                s[j++] = '\f';
                break;
            case 'a':
                s[j++] = '\a';
                break;
            default:
                s[j++] = t[i-2];
                s[j++] = c;
                break;
            }
            break;
        default:
            s[j++] = c;
            break;
        }
    }
}

