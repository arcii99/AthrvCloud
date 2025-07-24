//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 100

void clean(char *str) {
    char *dst = str;

    while (*str) {
        if (isalpha(*str)) {
            *dst++ = tolower(*str);
        }
        str++;
    }
    *dst = '\0';
}

bool is_palindrome(char *str) {
    int i, len = 0;

    while (str[len] != '\0')
        len++;

    for (i = 0; i < len / 2; i++)
        if (str[i] != str[len - i - 1])
            return false;

    return true;
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    clean(str);

    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}