//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[100];
    printf("Welcome to the Input Sanitizer program!\n");
    printf("Please enter your input: ");
    fgets(input, sizeof(input), stdin);

    // Let's check if our user has entered a dangerous input or not.
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++, j++) {
        if ((input[i] == '/') && (input[i+1] == '/')) {
            printf("\n\nWarning: You cannot enter a comment in your input!\n\n");
            return EXIT_FAILURE;
        }
        else if ((input[i] == '/') && (input[i+1] == '*')) {
            printf("\n\nWarning: You cannot enter a multi-line comment in your input!\n\n");
            return EXIT_FAILURE;
        }
        else if ((input[i] == '<') && (input[i+1] == '>')) {
            printf("\n\nWarning: You cannot enter a script tag in your input!\n\n");
            return EXIT_FAILURE;
        }
        else {
            input[j] = input[i]; // Let's sanitize out any unwanted characters
        }
    }

    input[j] = '\0'; // Let's complete the string with a null character

    // Let's print out our sanitized input for the user
    printf("\n\nYour sanitized input is: %s\n\n", input);

    return EXIT_SUCCESS;
}