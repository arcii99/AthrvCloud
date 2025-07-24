//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Palindrome Checker!\n\n");

    char input[100];
    printf("Please enter a word or phrase to check:\n");
    fgets(input, 100, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    // Convert to lowercase
    char* lowercase = (char*)malloc(strlen(input) + 1);
    for (int i = 0; i < strlen(input); i++) {
        lowercase[i] = tolower(input[i]);
    }
    lowercase[strlen(input)] = '\0';

    // Reverse the string
    char* reverse = (char*)malloc(strlen(input) + 1);
    for (int i = strlen(input) - 1, j = 0; i >= 0; i--, j++) {
        reverse[j] = lowercase[i];
    }
    reverse[strlen(input)] = '\0';

    if (strcmp(lowercase, reverse) == 0) {
        printf("Congratulations, \"%s\" is a palindrome!\n", input);
    } else {
        printf("Sorry, \"%s\" is not a palindrome.\n", input);
    }

    free(lowercase);
    free(reverse);

    printf("\nThanks for using the Palindrome Checker!\n");

    return 0;
}