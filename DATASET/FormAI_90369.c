//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* input) {
    char* output = (char*)malloc(MAX_INPUT_LENGTH * sizeof(char));
    int i, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            // Keep numeric characters
            output[j] = input[i];
            j++;
        } else if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
            // Keep alphabetic characters
            output[j] = input[i];
            j++;
        } else if (input[i] == ' ') {
            // Replace spaces with underscores
            output[j] = '_';
            j++;
        }
    }
    output[j] = '\0';
    return output;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n"); // remove newline character from input
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized string: %s\n", sanitized_input);
    free(sanitized_input); // free dynamically allocated memory
    return 0;
}