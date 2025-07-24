//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX 100

// Declaration of functions
int isPalindrome(char str[]);
void printResult(int isPalin);

int main(void) {
    char str[MAX];

    printf("Welcome to the Palindrome Checker! This is a multiplayer game, so grab a friend and let's get started!\n");

    // Loop for each player's turn
    for (int i = 1; i <= 2; i++) {
        printf("\nPlayer %d, please enter a string to check if it's a palindrome:\n", i);
        fgets(str, MAX, stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove newline character at the end of string input
        int isPalin = isPalindrome(str);
        printResult(isPalin);
    }

    printf("\nThanks for playing the Palindrome Checker!\n");

    return 0;
}

// Function to check if string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to print result based on if string is palindrome or not
void printResult(int isPalin) {
    if (isPalin) {
        printf("This is a palindrome!\n");
    } else {
        printf("This is not a palindrome.\n");
    }
}