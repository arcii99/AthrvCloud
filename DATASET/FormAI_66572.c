//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include <stdio.h>
#include <string.h>

// function to check if a given string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // not a palindrome
        }
    }
    return 1; // palindrome
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    // removing trailing newline character from string
    str[strcspn(str, "\n")] = 0;
    if (isPalindrome(str)) {
        printf("Wow, \"%s\" is a palindrome!\n", str);
    } else {
        printf("Sorry, \"%s\" is not a palindrome.\n", str);
    }
    return 0;
}