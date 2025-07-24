//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>

// Define a function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // A palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = 0;

    if (isPalindrome(str)) {
        printf("Yes, '%s' is a palindrome!", str);
    } else {
        printf("No, '%s' is not a palindrome.", str);
    }

    return 0;
}