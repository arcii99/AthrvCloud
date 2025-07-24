//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

// function to check if a given string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            return 0; // not a palindrome
        }
    }
    return 1; // is a palindrome
}

int main() {
    char str[100]; // assuming input string will be at most 100 characters
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}