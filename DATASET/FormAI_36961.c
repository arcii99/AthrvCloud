//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

int main() {

    char input[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove trailing newline character
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    // Convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Remove any non-alphanumeric characters
    char sanitized_input[MAX_INPUT_SIZE];
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';

    printf("Your sanitized input is: %s\n", sanitized_input);

    return 0;
}