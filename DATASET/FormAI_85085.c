//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Declare the function to check if a string is palindrome
int is_palindrome(char *string);

int main() {
    printf("Welcome to the Palindrome Checker, my dear Watson.\n");
    printf("Please enter a word or phrase to check if it is a palindrome:\n");

    char input[100];
    int is_valid_input = 0;

    // Loop until valid input is entered by the user
    while (!is_valid_input) {
        fgets(input, 100, stdin);
        if (strlen(input) > 1) {
            is_valid_input = 1;
        } else {
            printf("Invalid input. Please enter a word or phrase.");
        }
    }

    // Remove any non-alphanumeric characters from the input string
    char processed_input[100];
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i]) || isdigit(input[i])) {
            processed_input[j] = tolower(input[i]);
            j++;
        }
    }
    processed_input[j] = '\0';

    // Check if the processed string is a palindrome
    if (is_palindrome(processed_input)) {
        printf("Congratulations, my dear Watson. '%s' is a palindrome!\n", input);
    } else {
        printf("Alas, '%s' is not a palindrome. You might want to try another word or phrase.\n", input);
    }

    return 0;
}

// Function to check if a string is palindrome
int is_palindrome(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}