//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char user_input[50];

    // Print a greeting message
    printf("Welcome to the Retro Style User Input Sanitizer!\n");

    // Prompt the user for input
    printf("\nEnter a string to be sanitized: ");
    scanf("%[^\n]", user_input);

    // Loop through each character in the input and
    // sanitize any character that is not a letter or digit
    for (int i = 0; i < strlen(user_input); i++) {
        if (!isalnum(user_input[i])) {
            user_input[i] = '-';
        }
    }

    // Print the sanitized input
    printf("\nThe sanitized input is: %s\n\n", user_input);

    // Return 0 to indicate successful completion
    return 0;
}