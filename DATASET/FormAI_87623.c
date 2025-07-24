//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH], original[MAX_LENGTH];

    printf("Enter a word or sentence: ");
    fgets(str, MAX_LENGTH, stdin);

    int i = 0, j = 0;

    // remove spaces and punctuation
    while (str[i]) {
        if (isalnum(str[i])) {
            original[j++] = tolower(str[i]);
        }
        i++;
    }
    original[j] = '\0';

    // check if original string is a palindrome
    int length = strlen(original), isPalindrome = 1;

    for (i = 0; i <= length / 2; i++) {
        if (original[i] != original[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}