//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *string) {
    int length = strlen(string);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        while (!isalnum(string[i]) && i < j) {
            i++;
        }
        while (!isalnum(string[j]) && i < j) {
            j--;
        }

        if (tolower(string[i]) != tolower(string[j])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char string[100];

    printf("Enter a string: ");
    fgets(string, 100, stdin);

    if (isPalindrome(string)) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }

    return 0;
}