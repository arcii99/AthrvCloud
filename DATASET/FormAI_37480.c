//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str);

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string to check if it is a palindrome:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input)) {
        printf("\n%s is a palindrome!\n", input);
    } else {
        printf("\n%s is not a palindrome.\n", input);
    }

    return 0;
}

int isPalindrome(char *str) {
    // Strip non-alphanumeric characters and convert to lowercase
    char stripped[MAX_LENGTH];
    int strippedIndex = 0;
    for (int i = 0; str[i] != '\0' && strippedIndex < MAX_LENGTH - 1; i++) {
        if (isalnum(str[i])) {
            stripped[strippedIndex] = tolower(str[i]);
            strippedIndex++;
        }
    }
    stripped[strippedIndex] = '\0';

    // Check if stripped string is a palindrome
    int length = strlen(stripped);
    for (int i = 0; i < length / 2; i++) {
        if (stripped[i] != stripped[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}