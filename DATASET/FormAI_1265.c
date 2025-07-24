//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main() {
    char str[100];

    // Prompt user to enter a string
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove newline character from input
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[--len] = '\0';
    }

    // Check if string is palindrome
    if (isPalindrome(str)) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }

    return 0;
}