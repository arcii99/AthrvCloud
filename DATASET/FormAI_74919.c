//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN 100 // Maximum input length

void sanitizeInput(char* input) {
    int i, j = 0;
    char sanitized[MAX_INPUT_LEN];
    for (i = 0; input[i] != '\0'; ++i) {
        if (isalpha(input[i]) || isdigit(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';
    strcpy(input, sanitized);
}

int main() {
    char input[MAX_INPUT_LEN];

    printf("Welcome to the User Input Sanitizer program!\n\n");
    printf("Enter your input (up to 100 characters):\n");

    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character

    sanitizeInput(input);

    printf("\nSanitized input: %s\n", input);

    return 0;
}