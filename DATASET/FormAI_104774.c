//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < len / 2 && j > len / 2 - 1; i++, j--) {
        if (tolower(str[i]) != tolower(str[j]))
            return false;
    }

    return true;
}

int main() {
    char *str;
    int len;

    printf("Enter a word or phrase: ");
    scanf("%ms", &str);
    len = strlen(str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    free(str);

    return 0;
}