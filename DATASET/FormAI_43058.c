//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 256

void sanitize_input(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        // Convert to lowercase
        input[i] = tolower(input[i]);

        // Check for non-alphanumeric characters
        if (!isalnum(input[i])) {
            // Replace with space
            input[i] = ' ';
        }
        i++;
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter some text: ");
    fgets(input, MAX_LENGTH, stdin);

    sanitize_input(input);

    printf("Sanitized text: %s", input);

    return 0;
}