//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: future-proof
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int i;

    printf("Please enter your input: ");
    fgets(input, 100, stdin);

    // Sanitize input
    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {    // If character is an alphabet
            input[i] = tolower(input[i]);    // Convert to lowercase
        } else if (isdigit(input[i])) {    // If character is a digit
            input[i] = '*';    // Replace with '*'
        } else if (ispunct(input[i])) {    // If character is a punctuation mark
            input[i] = ' ';    // Replace with space
        }
    }

    printf("Sanitized input: %s", input);

    return 0;
}