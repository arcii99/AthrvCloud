//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void) {
    char str[MAX_LENGTH];
    int i, j;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    // Remove any non-alphabetic characters and convert to lowercase
    char new_str[MAX_LENGTH];
    int len = 0;
    for (i = 0; i < MAX_LENGTH && str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            new_str[len++] = tolower(str[i]);
        }
    }
    new_str[len] = '\0';

    // Check if new_str is a palindrome
    for (i = 0, j = len - 1; i < len / 2 && j >= len / 2; i++, j--) {
        if (new_str[i] != new_str[j]) {
            printf("%s is not a palindrome.\n", str);
            return 0;
        }
    }
    printf("%s is a palindrome!\n", str);

    return 0;
}