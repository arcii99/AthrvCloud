//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>

int main() {
    char input[100];
    int i, j;

    printf("Enter your input: ");
    fgets(input, 100, stdin);

    // Sanitize input by removing all non-alphanumeric characters
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0'; // Terminate the sanitized input string with null character

    // Display the sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}