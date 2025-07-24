//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: lively
#include <stdio.h>
#include <string.h>

/* This is a fun little program that checks if a word or phrase is a palindrome. */

int main() {

    char str[100]; // This is where we'll store the user's input
    int i, j, len, flag = 0; // Variables we'll use later

    printf("Welcome to the Palindrome Checker!\n\n");
    printf("Please enter a word or phrase: ");
    scanf("%[^\n]s", str); // %[^\n]s ensures we can take in spaces

    len = strlen(str); // Get the length of the input string

    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (str[i] != str[j]) { // If the two end characters don't match
            flag = 1; // Set a flag so we know it's not a palindrome
            break; // Stop the loop
        }
    }

    if (flag) {
        printf("\nSorry, but '%s' is not a palindrome.\n", str);
    } else {
        printf("\nCongratulations, '%s' is a palindrome!\n", str);
    }

    return 0; // End the program
}