//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(char str[], int length) {
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string:");
    fgets(str, MAX_LENGTH, stdin);

    // Remove newline character at the end
    int length = strlen(str) - 1;
    str[length] = '\0';

    if (isPalindrome(str, length)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}