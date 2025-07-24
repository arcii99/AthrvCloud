//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool isPalindrome(char string[], int length);

int main() {
    char string[MAX_LENGTH];
    int length;

    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);

    // Remove trailing newline character
    length = strlen(string);
    if (string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }
    length = strlen(string);

    if (isPalindrome(string, length)) {
        printf("You've entered a palindrome!");
    } else {
        printf("Sorry, that's not a palindrome.");
    }

    return 0;
}

bool isPalindrome(char string[], int length) {
    int i, j;

    // Ignore case sensitivity
    for (i = 0; i < length; i++) {
        string[i] = tolower(string[i]);
    }

    // Check palindrome
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            return false;
        }
    }
    return true;
}