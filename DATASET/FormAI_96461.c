//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // define max length of the input string

// function to remove all non-alphanumeric characters from a string
void removeNonAlphaNumeric(char* str) {
    int len = strlen(str);
    char temp[MAX_LENGTH];
    int j = 0;

    // copy only alphanumeric characters to temp array
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            temp[j] = str[i];
            j++;
        }
    }

    // terminate string with null character
    temp[j] = '\0';

    // copy back to original string
    strcpy(str, temp);
}

// function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    int i = 0;
    int j = len - 1;

    // loop until i and j meet in the middle
    while (i < j) {
        if (str[i] != str[j]) {
            return 0; // not a palindrome
        }
        i++;
        j--;
    }

    return 1; // palindrome
}

int main() {
    char inputString[MAX_LENGTH];

    printf("Welcome to the C Palindrome Checker!\n\n");
    printf("Please enter a string to check for palindrome property: ");

    // read input string from user
    fgets(inputString, MAX_LENGTH, stdin);

    // remove non-alphanumeric characters from input string
    removeNonAlphaNumeric(inputString);

    // check if input string is a palindrome
    if (isPalindrome(inputString)) {
        printf("\nYes! The input string \"%s\" is a palindrome!\n", inputString);
    }
    else {
        printf("\nNo! The input string \"%s\" is not a palindrome!\n", inputString);
    }

    printf("\nThank you for using the C Palindrome Checker.\n");

    return 0;
}