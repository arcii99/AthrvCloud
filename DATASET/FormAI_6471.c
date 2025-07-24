//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100] = "Welcome to the Exciting World of C String Manipulation!";

    printf("Original String: %s\n", str);

    // UPPERCASE
    printf("\n*** UPPERCASE ***\n");

    for (int i=0; i<strlen(str); i++) {
        str[i] = toupper(str[i]);
    }

    printf("Uppercase String: %s\n", str);

    // LOWERCASE
    printf("\n*** LOWERCASE ***\n");

    for (int i=0; i<strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    printf("Lowercase String: %s\n", str);

    // REPLACE CHARACTERS
    printf("\n*** REPLACE CHARACTERS ***\n");

    char old_char = 'o';
    char new_char = '*';

    for (int i=0; i<strlen(str); i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }

    printf("Replaced String: %s\n", str);

    // REVERSE STRING
    printf("\n*** REVERSE STRING ***\n");

    char temp;

    for (int i=0, j=strlen(str)-1; i<j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed String: %s\n", str);

    // COUNT OCCURRENCES OF A CHARACTER
    printf("\n*** COUNT OCCURRENCES ***\n");

    char ch = 'i';
    int count = 0;

    for (int i=0; i<strlen(str); i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    printf("Number of occurrences of '%c': %d\n", ch, count);

    // REMOVE WHITESPACE
    printf("\n*** REMOVE WHITESPACE ***\n");

    int len = strlen(str);

    for (int i=0; i<len; i++) {
        if (str[i] == ' ') {
            for (int j=i; j<len; j++) {
                str[j] = str[j+1];
            }
            i--;
            len--;
        }
    }

    printf("Whitespace removed: %s\n", str);

    return 0;
}