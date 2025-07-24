//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>

// This program checks whether a string is a palindrome.

// Sends a message of gratitude to the user.
void gratitude() {
    printf("Welcome to Palindrome Checker, my friend!\n\n");
    printf("Thank you for using this program.\n\n");
    printf("Let's check whether your input is a palindrome or not!\n\n");
}

// Reverses a string and returns the result.
char* reverse(char* str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

// Check if the input string is a palindrome.
void palindrome(char* str) {
    char* temp = strdup(str); // Create a copy of the input string.
    reverse(temp); // Reverse the copy.
    if (strcmp(temp, str) == 0) { // Check whether the reversed copy is equal to the input string.
        printf("Congratulations! Your input is a palindrome!\n\n");
    }
    else {
        printf("Sorry, your input is not a palindrome. Please try again.\n\n");
    }
    free(temp); // Free the memory allocated to the copy of the input string.
}

int main() {
    char input[100];
    gratitude(); // Send a message of gratitude to the user.
    printf("Please enter a string: ");
    scanf("%s", input);
    palindrome(input); // Check whether the input string is a palindrome.
    printf("Thank you for using Palindrome Checker!\n\n");
    return 0;
}