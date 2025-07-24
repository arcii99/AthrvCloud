//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_INPUT_LENGTH 100

int main() {

    char input[MAX_INPUT_LENGTH];
    printf("Welcome to the User Input Sanitizer program! Let's make sure your input is clean and safe to use!\n");

    while(1) {
        printf("\nPlease enter your input (maximum %d characters): ", MAX_INPUT_LENGTH-1);
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // remove newline character from input
        int i = 0;
        while (input[i] != '\0') {
            if (input[i] == '\n') {
                input[i] = '\0';
                break;
            }
            i++;
        }

        // convert input to lowercase
        i = 0;
        while (input[i] != '\0') {
            input[i] = tolower(input[i]);
            i++;
        }

        // remove any non-alphanumeric characters
        char sanitized_input[MAX_INPUT_LENGTH];
        int j = 0;
        for (i = 0; input[i] != '\0'; i++) {
            if (isalnum(input[i])) {
                sanitized_input[j++] = input[i];
            }
        }
        sanitized_input[j] = '\0';

        printf("\nYour sanitized input is: %s\n", sanitized_input);

        // prompt user to continue or exit program
        char continue_input[MAX_INPUT_LENGTH];
        printf("\nDo you want to sanitize another input? (Yes/No): ");
        fgets(continue_input, MAX_INPUT_LENGTH, stdin);

        // remove newline character from input
        i = 0;
        while (continue_input[i] != '\0') {
            if (continue_input[i] == '\n') {
                continue_input[i] = '\0';
                break;
            }
            i++;
        }

        // check if user wants to exit program
        if (strcmp(continue_input, "no") == 0 || strcmp(continue_input, "No") == 0) {
            printf("\nThanks for using the User Input Sanitizer program! Goodbye!\n");
            exit(0);
        }
    }

    return 0;
}