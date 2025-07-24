//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int isPalindrome(char* str) {
    int len = strlen(str), i;
    char reversed[MAX_LENGTH];

    // Copy the string in reversed order
    for (i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }

    reversed[i] = '\0'; // Add the null terminator

    // Compare the original and reversed strings
    return strcmp(str, reversed) == 0;
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character, if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Convert to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    if (isPalindrome(input)) {
        printf("%s is a palindrome\n", input);
    } else {
        printf("%s is not a palindrome\n", input);
    }

    return 0;
}