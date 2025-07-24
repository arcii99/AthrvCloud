//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to remove all non-alphanumeric characters from a string
void removeNonAlphaNumeric(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char str[MAX_LENGTH];
    int len;

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove all non-alphanumeric characters from the string
    removeNonAlphaNumeric(str);

    // Check if the resulting string is a palindrome
    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}