//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[100];
    printf("Enter a word or phrase: ");
    fgets(input, 100, stdin);

    // Remove newline character from input string
    input[strcspn(input, "\n")] = 0;

    if (is_palindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    return 0;
}