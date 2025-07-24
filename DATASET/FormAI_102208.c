//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    printf("Please enter your input:\n");
    fgets(input, MAX_SIZE, stdin); // read user input

    // Remove any trailing newline characters
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Remove any whitespace characters from the beginning of the input
    while (*input == ' ') {
        memmove(input, input + 1, strlen(input));
    }

    // Remove any whitespace characters from the end of the input
    int len = strlen(input);
    while (len > 0 && input[len - 1] == ' ') {
        input[--len] = '\0';
    }

    printf("Sanitized input: %s\n", input);
    return 0;
}