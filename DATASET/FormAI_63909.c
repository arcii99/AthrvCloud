//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Interoperable Palindrome Checker in C

// Function to remove white spaces and convert all characters to lowercase
void removeWhiteSpaceAndConvertToLowercase(char *str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to check if a string is a palindrome or not
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char inputStr[1000];
    printf("Enter a string: ");
    fgets(inputStr, 1000, stdin);
    removeWhiteSpaceAndConvertToLowercase(inputStr);
    if (isPalindrome(inputStr)) {
        printf("%s is a palindrome\n", inputStr);
    } else {
        printf("%s is not a palindrome\n", inputStr);
    }
    return 0;
}