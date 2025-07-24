//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if a given string is a palindrome
int isPalindrome(char* str) {
    // Remove any spaces and punctuation from the string
    char cleanStr[MAX_LENGTH];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if(isalnum(str[i])) {
            cleanStr[j++] = tolower(str[i]);
        }
    }
    cleanStr[j] = '\0';

    // Check if the string is a palindrome
    int len = strlen(cleanStr);
    for(int i = 0; i < len/2; i++) {
        if(cleanStr[i] != cleanStr[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string (up to %d characters): ", MAX_LENGTH);
    fgets(str, MAX_LENGTH, stdin);

    if(isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}