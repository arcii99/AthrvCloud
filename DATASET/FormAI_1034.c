//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// This function removes non-alphabetic characters and converts
// all letters to lowercase
void cleanString(char *str) {
    int i = 0, j = 0;
    char c;

    while ((c = str[i++]) != '\0') {
        if (isalpha(c)) {
            str[j++] = tolower(c);
        }
    }

    str[j] = '\0';
}

// This function checks whether a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // not a palindrome
        }
    }

    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Clean the string and remove non-alphabetic characters
    cleanString(str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}