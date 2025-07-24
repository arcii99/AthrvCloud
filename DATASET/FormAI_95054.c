//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(const char *str) {
    int len = strlen(str);
    char str_copy[len+1];

    // Copy input string and convert to lowercase
    for (int i = 0; i < len; i++) {
        str_copy[i] = tolower(str[i]);
    }

    // Add terminating character to copy
    str_copy[len] = '\0';

    // Check if string is a palindrome
    for (int i = 0, j = len-1; i < j; i++, j--) {
        if (str_copy[i] != str_copy[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];

    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    if (is_palindrome(input)) {
        printf("%s is a palindrome!", input);
    } else {
        printf("%s is not a palindrome.", input);
    }

    return 0;
}