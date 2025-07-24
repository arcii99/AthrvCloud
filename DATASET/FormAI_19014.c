//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: lively
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];

    printf("Welcome to the Palindrome Checker!\n\n");
    printf("Please enter a word or phrase to check if it is a palindrome: ");
    scanf("%s", str);
    
    // Convert string to lowercase
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    // Check if string is a palindrome
    if (isPalindrome(str)) {
        printf("\n%s is a palindrome!\n", str);
    } else {
        printf("\n%s is not a palindrome.\n", str);
    }

    printf("\nThank you for using the Palindrome Checker!\n");

    return 0;
}