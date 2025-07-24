//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {

    // Welcome message
    printf("Welcome to the Palindrome Checker!\n\n");

    // Get user input
    printf("Please enter a string to check if it is a palindrome:\n");
    char input[100];
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Initialize variables
    int length = strlen(input);
    int isPalindrome = 1;

    // Check if string is a palindrome
    for (int i = 0; i < length / 2; i++) {
        if (input[i] != input[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    // Output result to user
    if (isPalindrome) {
        printf("\nThe string '%s' is a palindrome!\n", input);
    } else {
        printf("\nThe string '%s' is not a palindrome.\n", input);
    }

    // Thank you message
    printf("\nThank you for using the Palindrome Checker!\n");

    return 0;
}