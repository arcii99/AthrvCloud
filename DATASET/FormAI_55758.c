//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

void clear_input_buffer() {
    char ch; 
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    printf("Welcome to the User Input Sanitizer program! Enter any text and watch it get sanitized!\n");

    char input[MAX_INPUT_LENGTH+1];

    do {
        printf("\nInput: ");
        fgets(input, sizeof(input), stdin);

        // remove newline character from input
        if (input[strlen(input)-1] == '\n') input[strlen(input)-1] = '\0';

        // check if input is longer than MAX_INPUT_LENGTH and flush input buffer if necessary
        if (strlen(input) > MAX_INPUT_LENGTH) {
            printf("Input exceeded length limit of %d characters. Please try again.\n", MAX_INPUT_LENGTH);
            clear_input_buffer();
            continue;
        }

        // sanitize input by removing forbidden characters
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '"' || input[i] == '\'') {
                input[i] = '_';
            }
        }

        // print sanitized input
        printf("Sanitized input: %s\n", input);

    } while (strcmp(input, "exit") != 0);

    printf("Goodbye!\n");
    return 0;
}