//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 50 // maximum length of user input

int main()
{
    char input[MAX_INPUT];
    char sanitized[MAX_INPUT];
    int i, j, k = 0;

    printf("Enter a string with special characters, digits, and whitespaces: ");
    fgets(input, MAX_INPUT, stdin); // get user input

    // sanitize the input by removing special characters, digits, and whitespaces
    for(i = 0; input[i] != '\0'; i++) {
        // ignore white spaces
        if(input[i] == ' ') {
            continue;
        }
        // check if character is alphanumeric
        if(isalnum(input[i])) {
            sanitized[k++] = tolower(input[i]); // convert to lower case and add to sanitized string
        }
    }
    sanitized[k] = '\0'; // append null character at the end of sanitized string

    printf("Sanitized input: %s", sanitized); // print sanitized input

    return 0;
}