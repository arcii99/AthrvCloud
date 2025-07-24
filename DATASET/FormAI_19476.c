//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char*);

int main() {
    char word[100];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(word, sizeof(word), stdin);

    if (is_palindrome(word)) {
        printf("'%s' is a palindrome.\n", word);
    } else {
        printf("'%s' is not a palindrome.\n", word);
    }

    return 0;
}

bool is_palindrome(char* string) {
    int length = strlen(string) - 1;
    int i, j;

    for (i = 0, j = length - 1; i <= length/2; i++, j--) {
        if (string[i] != string[j]) {
            return false;
        }
    }

    return true;
}