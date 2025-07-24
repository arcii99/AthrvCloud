//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// A function to check if a given string is palindrome or not
int isPalindrome(char str[]) {
    int l = 0;
    int h = strlen(str) - 1;
  
    // Keep comparing characters while they are same
    while (h > l) {
        if (tolower(str[l++]) != tolower(str[h--])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1000];
    printf("Welcome to the Palindrome Checker! This program will check if a given string is a palindrome or not.\n");

    // Prompt user for input
    printf("Please enter a string: ");
    fgets(input, 1000, stdin);

    // Replace the newline character with null character
    input[strcspn(input, "\n")] = 0;

    // Check if the input string is a palindrome
    if (isPalindrome(input)) {
        printf("Congratulations! The entered string is a palindrome.\n");
    } else {
        printf("Sorry, the entered string is not a palindrome.\n");
    }
    return 0;
}