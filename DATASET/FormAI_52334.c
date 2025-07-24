//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

// Function to remove non-alphanumeric characters from the string
void removeNonAlphanumeric(char *string) {
    char *dest = string;
    while (*string != '\0') {
        if (isalnum(*string)) {
            *dest++ = tolower(*string);
        }
        string++;
    }
    *dest = '\0';
}

// Function to check if the given string is a palindrome or not
int isPalindrome(char *string) {
    int len = strlen(string);
    for (int i = 0; i < len / 2; i++) {
        if (string[i] != string[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Driver function
int main() {
    char inputString[MAX_LENGTH], originalString[MAX_LENGTH];
    
    printf("Enter a string:\n");
    fgets(inputString, MAX_LENGTH, stdin);
    
    // Copying the input string to original string
    strncpy(originalString, inputString, strlen(inputString));
    
    // Removing non-alphanumeric characters from the string
    removeNonAlphanumeric(inputString);
    
    // Checking if the resulting string is a palindrome or not
    if (isPalindrome(inputString)) {
        printf("%s is a palindrome!\n", originalString);
    } else {
        printf("%s is not a palindrome!\n", originalString);
    }
    
    return 0;
}