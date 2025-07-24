//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

int is_palindrome(char str[MAX_STR_LEN]) {
    int len = strlen(str);
    char rev_str[MAX_STR_LEN];
    int i;

    // Reversing the string
    for (i = 0; i < len; i++) {
        rev_str[i] = str[len - i - 1];
    }
    rev_str[len] = '\0';

    // Checking if reversed string is same as original string
    for (i = 0; i < len; i++) {
        if (tolower(str[i]) != tolower(rev_str[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_STR_LEN];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}