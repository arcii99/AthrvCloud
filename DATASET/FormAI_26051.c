//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>

/**
 * A function to check if a string is a palindrome or not.
 * @param string The string to check.
 * @return 1 if it is a palindrome, 0 otherwise.
 */
int is_palindrome(char *string) {
    int length = strlen(string);
    
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char string[100];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(string, sizeof(string), stdin);

    // Remove the newline character from the string.
    string[strcspn(string, "\n")] = 0;

    if (is_palindrome(string)) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }
    
    return 0;
}