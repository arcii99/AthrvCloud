//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// Function to check if char array s is a palindrome
int isPalindrome(char s[]) {
    int i, j;
    int len = strlen(s);

    // Loop through each pair of characters in s
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (s[i] != s[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main() {
    char input[100];

    // Ask for user input
    printf("Please enter a string to check for palindromicity: ");
    scanf("%s", input);

    // Check if input is a palindrome
    if (isPalindrome(input)) {
        printf("Yes, '%s' is a palindrome!\n", input);
    } else {
        printf("No, '%s' is not a palindrome.\n", input);
    }

    return 0;
}