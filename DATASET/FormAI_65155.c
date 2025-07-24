//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 128

// Function to sanitize user input
void sanitizeInput(char *input) {
    // Remove leading and trailing whitespace
    char *start = input;
    char *end = input + strlen(input) - 1;
    while (isspace(*start)) {
        start++;
    }
    while (isspace(*end) && end >= start) {
        end--;
    }
    *(end + 1) = '\0';
    
    // Remove any non-alphanumeric characters
    char *temp = input;
    while (*temp) {
        if (!isalnum(*temp)) {
            memmove(temp, temp + 1, strlen(temp));
        } else {
            temp++;
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}