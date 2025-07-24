//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome(char *);

int main() {
    char input[1000];

    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, 1000, stdin);

    if (palindrome(input)) {
        printf("Given string is a Palindrome.\n");
    } else {
        printf("Given string is not a Palindrome.\n");
    }

    return 0;
}

/*
 * Function to check if the given string is a palindrome or not.
 */
int palindrome(char *str) {
    int i, len = strlen(str);
    char *start = str, *end = str + len - 2; /* Pointer to the beginning and end of the string respectively */

    /* Convert all characters to lowercase */
    for (i = 0; i < len; i++) {
        *(str + i) = tolower(*(str + i));
    }

    /* Check if the string is palindrome */
    while (end > start) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}