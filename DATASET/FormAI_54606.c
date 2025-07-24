//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // Maximum length of input string

// Function to check if a character is an alphabet or not
int isAlphabet(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    }
    return 0;
}

// Function to convert a character to lowercase
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}

// Function to strip off all non-alphabetic characters from a string
void stripNonAlphabetic(char str[]) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (isAlphabet(str[i])) {
            str[j++] = toLower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to reverse a string
void reverseString(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a palindrome or not
int isPalindrome(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char inputStr[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(inputStr, MAX_LENGTH, stdin); // Taking input using fgets to handle white spaces.

    stripNonAlphabetic(inputStr);
    reverseString(inputStr);

    if (isPalindrome(inputStr)) {
        printf("%s is a palindrome.\n", inputStr);
    } else {
        printf("%s is not a palindrome.\n", inputStr);
    }

    return 0;
}