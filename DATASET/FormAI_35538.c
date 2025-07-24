//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(char *string) {
    int length = strlen(string);
    char *reverseString = (char *)malloc((length + 1) * sizeof(char));
    int i = 0;
    for (i = 0; i < length; i++) {
        reverseString[length - 1 - i] = string[i];
    }
    reverseString[length] = '\0';
    bool isPal = strcmp(string, reverseString) == 0 ? true : false;
    free(reverseString);
    return isPal;
}

// Main function to test the isPalindrome function
int main() {
    char userInput[50];
    printf("Enter a string to check if it is a palindrome: \n");
    fgets(userInput, 50, stdin);
    // Remove newline character from input
    if (userInput[strlen(userInput) - 1] == '\n') {
        userInput[strlen(userInput) - 1] = '\0';
    }
    bool isPal = isPalindrome(userInput);
    if (isPal) {
        printf("%s is a palindrome", userInput);
    } else {
        printf("%s is not a palindrome", userInput);
    }
    return 0;
}