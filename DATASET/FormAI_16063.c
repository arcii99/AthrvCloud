//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    char sanitized_input[100];
    int index = 0;
    int sanitized_index = 0;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    while (input[index] != '\0') {
        if (isalpha(input[index])) {
            // Sanitize alphabetic characters
            sanitized_input[sanitized_index] = tolower(input[index]);
            sanitized_index++;
        } else if (isdigit(input[index])) {
            // Sanitize numeric characters
            sanitized_input[sanitized_index] = input[index];
            sanitized_index++;
        }
        // Ignore other characters
        index++;
    }

    // Terminate sanitized_input
    sanitized_input[sanitized_index] = '\0';

    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}