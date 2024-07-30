#include <stdio.h>

/*
 * List of escape characters specified in K&R
 * \a    alert (bell)
 * \b    backspace
 * \f    formfeed
 * \n    newline
 * \r    carriage return
 * \t    horizontal tab
 * \v    vertical tab
 * \\    backslash
 * \?    question mark
 * \'    single quote
 * \"    double quote
 * \000  octal number
 * \x00  hexadecimal number
 *
 * The progam below tests each character out, as well as some others
 */

int main(int argc, char** argv)
{
    // when compiled to assembly, certain characters are replaced
    // with octal: \a and \v
    printf("Alert character: hello\aworld");
    printf("\n\n");

    printf("Backspace character: hello\bworld");
    printf("\n\n");

    printf("Formfeed character: hello\fworld");
    printf("\n\n");

    printf("Newline character: hello\nworld");
    printf("\n\n");

    printf("Carriage return character: hello\rworld");
    printf("\n\n");

    // this tab was only replaced with a space
    // not sure why, maybe rounds to fourth character?
    printf("Horizontal tab character: hello\tworld");
    printf("\n\n");

    printf("Vertical tab character: hello\vworld");
    printf("\n\n");

    printf("Normal charcters: \\ \? \' \"");
    printf("\n\n");

    // octal number must be 3 digits
    // 8 ** 3 = 512 (9 bits vs. 8)
    //
    // these numbers are useful for permission bits and when
    // dealing with signal flags
    printf("Octal number (0o145): \145");
    printf("\n\n");

    // both this and the octal number are replaced with the char
    // representation when compiled to assembly
    printf("Hexadecimal number (0x65): \x65");
    printf("\n\n");

    printf("Odd characters...\n");

    printf("Unescaped question mark |?|\n");
    printf("Unescaped single quote |'|\n");

    // the compiler provides a warning for these two
    // "warning: unknown escape sequence: \g"
    printf("Other escaped characters: \g \z\n");

    return 0;
}
