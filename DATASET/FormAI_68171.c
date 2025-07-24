//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a string is a palindrome */
int is_palindrome(char *str) {

    int len = strlen(str);
    int i, j;

    /* Make all characters lowercase */
    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    /* Check if the string is a palindrome */
    for (i = 0, j = len - 1; i <= j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {

    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    /* Remove the newline character from input string */
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }

    /* Check if the string is a palindrome */
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}