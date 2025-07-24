//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeNewLine(char*);

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    // Remove new line character
    removeNewLine(input);

    // Convert input to lowercase
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Remove any non-alphabetic characters
    char sanitized_input[100];
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';

    printf("Sanitized input: %s\n", sanitized_input);
    return 0;
}

// Helper function to remove new line character from input
void removeNewLine(char input[]) {
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}