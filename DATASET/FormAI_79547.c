//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* str);

int main() {
    char input_string[100];
    printf("Enter the string to check for palindrome:\n");
    fgets(input_string, 100, stdin);

    if (is_palindrome(input_string)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}

int is_palindrome(char* str) {
    // Remove all non-alphanumeric characters from the string
    char cleaned_string[100];
    int k = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            cleaned_string[k++] = str[i];
        }
    }
    cleaned_string[k] = '\0';

    // Check if the cleaned string is a palindrome
    int cleaned_len = strlen(cleaned_string);
    for (int i = 0; i < cleaned_len / 2; i++) {
        if (cleaned_string[i] != cleaned_string[cleaned_len - i - 1]) {
            return 0;
        }
    }
    return 1;
}