//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void convertToLowercase(char* string);
int isPalindrome(char* string, int length);

int main() {
    char input[MAX_STRING_LENGTH];
    
    printf("Enter a string: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    
    // Remove newline character from fgets function
    input[strcspn(input, "\n")] = 0;
    
    // Convert string to lowercase
    convertToLowercase(input);
    
    int isPal = isPalindrome(input, strlen(input));
    
    if (isPal) {
        printf("%s is a palindrome!\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    
    return 0;
}

void convertToLowercase(char* string) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
}

int isPalindrome(char* string, int length) {
    int i;
    for (i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}