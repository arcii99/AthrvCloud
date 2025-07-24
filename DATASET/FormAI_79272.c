//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100], sanitized[100];
    printf("Welcome to the User Input Sanitizer program!\n");
    printf("Please enter some text that may contain naughty characters:\n");
    scanf("%[^\n]", input);
    printf("\n");
    printf("Let's see what you entered:\n");
    printf("%s\n", input);
    printf("\n");

    for (int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case '!' :
                printf("Remove the exclamation mark\n");
                sanitized[i] = ' ';
                break;
            case '@' :
                printf("Convert the at symbol to a -\n");
                sanitized[i] = '-';
                break;
            case '#' :
                printf("Replace the hashtag with a * \n");
                sanitized[i] = '*';
                break;
            case '$' :
                printf("Replace the dollar sign with a +\n");
                sanitized[i] = '+';
                break;
            case '%' :
                printf("Replace the percent sign with a / \n");
                sanitized[i] = '/';
                break;
            default :
                sanitized[i] = input[i];
                break;
        }
    }
    printf("Here is your sanitized text:\n");
    for (int i = 0; i < strlen(sanitized); i++) {
        printf("%c", sanitized[i]);
    }
    printf("\nThank you for using the User Input Sanitizer!\n");

    return 0;
}