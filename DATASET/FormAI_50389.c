//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove non-alphabetic characters from the input string
    char cleanStr[100];
    int cleanLen = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            cleanStr[cleanLen++] = str[i];
        }
    }
    cleanStr[cleanLen] = '\0';

    if (isPalindrome(cleanStr)) {
        printf("The string %s is a palindrome.\n", str);
    } else {
        printf("The string %s is not a palindrome.\n", str);
    }

    return 0;
}