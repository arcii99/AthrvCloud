//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    // Define variables
    char input[100];
    int i, j = 0;

    // Get user input
    printf("Enter your string: ");
    fgets(input, 100, stdin);

    // Sanitize user input
    for (i = 0; input[i] != '\0'; ++i) {

        // Remove non-alphanumeric characters
        if (isalnum(input[i])) {
            input[j++] = input[i];
        }

        // Convert uppercase to lowercase
        if (isupper(input[i])) {
            input[j++] = tolower(input[i]);
        }

    }

    // Terminate the sanitized string
    input[j] = '\0';

    // Print the sanitized string
    printf("Your sanitized input is: %s\n", input);

    return 0;
}