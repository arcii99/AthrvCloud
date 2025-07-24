//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
/* A Ken Thompson style User Input Sanitizer program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Maximum length of user input */
#define MAX_INPUT_LENGTH 1024

/* Function to sanitize user input */
void sanitizeInput(char* input) {
    int i, j;
    char sanitized[MAX_INPUT_LENGTH];
    bool spaceFlag = true;

    /* Initialize sanitized string to empty */
    memset(sanitized, 0, sizeof(sanitized));

    /* Iterate through user input string */
    for (i = 0, j = 0; i < strlen(input); i++) {
        /* Ignore whitespace at the beginning and end of input */
        if (isspace(input[i]) && (j == 0 || i == strlen(input) - 1)) {
            continue;
        }

        /* Remove leading/trailing spaces and reduce multiple spaces to single space */
        if (isspace(input[i]) && spaceFlag) {
            continue;
        } else if (isspace(input[i])) {
            spaceFlag = true;
            sanitized[j++] = ' ';
        } else {
            spaceFlag = false;
            sanitized[j++] = input[i];
        }
    }

    /* Copy sanitized string back into input */
    strncpy(input, sanitized, strlen(sanitized) + 1);
}

/* Main function to test input sanitization */
int main() {

    char input[MAX_INPUT_LENGTH];

    /* Get user input */
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* Remove newline character from input */
    input[strcspn(input, "\n")] = 0;

    /* Sanitize user input */
    sanitizeInput(input);

    /* Display sanitized input */
    printf("\nSanitized input: %s\n", input);

    return 0;
}