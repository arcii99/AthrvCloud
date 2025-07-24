//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_LENGTH 100

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    char* reverse_str = malloc(length + 1);
    int is_palindrome = 1;

    // Copy string in reverse order
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        reverse_str[j] = str[i];
    }
    reverse_str[length] = '\0';
    
    // Check if the original string and the reversed string are the same
    for (int i = 0; i < length; i++) {
        if (tolower(str[i]) != tolower(reverse_str[i])) {
            is_palindrome = 0;
            break;
        }
    }

    // Free memory allocated for reversed string
    free(reverse_str);

    return is_palindrome;
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string:");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input

    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}