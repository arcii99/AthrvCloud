//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

int isPalindrome(char *string);

int main() {
    char string[MAX_STRING_LENGTH];
    printf("Welcome to the Palindrome Checker!\n\n");
    printf("Please enter a word or a phrase: ");
    fgets(string, MAX_STRING_LENGTH, stdin);
    string[strcspn(string, "\n")] = 0; // remove trailing newline

    if (isPalindrome(string)) {
        printf("\n%s is a palindrome!\n", string);
    } else {
        printf("\n%s is not a palindrome.\n", string);
    }

    printf("\nThank you for using the Palindrome Checker!\n");
    return 0;
}

int isPalindrome(char *string) {
    int i, j;
    for (i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            return 0;
        }
    }
    return 1;
}