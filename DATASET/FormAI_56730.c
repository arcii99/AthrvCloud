//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int is_palindrome(char *str);

int main() {
    char input[BUFFER_SIZE];
    printf("Enter the string to check if it's a palindrome: ");
    fgets(input, BUFFER_SIZE, stdin);

    if (is_palindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}

int is_palindrome(char *str) {
    // Remove whitespace and make all characters lowercase
    char clean_str[BUFFER_SIZE];
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            clean_str[j] = tolower(str[i]);
            j++;
        }
        i++;
    }
    clean_str[j] = '\0';

    // Check if string is a palindrome
    int start = 0;
    int end = strlen(clean_str) - 1;

    while (end > start) {
        if (clean_str[start] != clean_str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}