//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert string to lowercase
char *toLower(char *str) {
    int i = 0;
    while(str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

// Function to remove spaces and special characters from the string
char *removeSpecialChar(char *str) {
    int i = 0, j = 0;

    while(str[i] != '\0') {
        if(isalpha(str[i])) {
            str[j] = tolower(str[i]);
            j++;
        }
        i++;
    }
    str[j] = '\0';
    return str;
}

// Function to check if the string is palindrome
int isPalindrome(char *str) {
    int i, j;
    int len = strlen(str);

    for(i=0, j=len-1; i<len/2; i++, j--) {
        if(str[i] != str[j]) {
            return 0; // not a palindrome
        }
    }
    return 1; // palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove spaces and special characters
    char *newStr = removeSpecialChar(str);

    // Check if palindrome
    if(isPalindrome(newStr)) {
        printf("%s is a palindrome.\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}