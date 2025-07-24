//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// function to check if given letter is alphabet or digit
int isAlphaNumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// function to remove special characters and convert to lowercase
void preprocessString(char *string) {
    int length = strlen(string);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isAlphaNumeric(string[i])) {
            string[j++] = tolower(string[i]);
        }
    }
    string[j] = '\0';
}

// function to check if given string is palindrome or not
int isPalindrome(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length/2; i++) {
        if (string[i] != string[length-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char string[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);
    preprocessString(string);
    if (isPalindrome(string)) {
        printf("Given string is palindrome\n");
    } else {
        printf("Given string is not palindrome\n");
    }
    return 0;
}