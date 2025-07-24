//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 

int is_palindrome(char input_string[]) {
    char clean_string[MAX_LENGTH], reversed_string[MAX_LENGTH];
    int i, j, k;

    // Step 1: Remove non-alphanumeric characters and convert to lowercase
    k = 0;
    for (i = 0; input_string[i] != '\0'; i++) {
        if (isalpha(input_string[i]) || isdigit(input_string[i])) {
            clean_string[k++] = tolower(input_string[i]);
        }
    }

    clean_string[k] = '\0';

    // Step 2: Reverse the cleaned string
    j = 0;
    for (i = strlen(clean_string)-1; i >= 0; i--) {
        reversed_string[j++] = clean_string[i];
    }

    reversed_string[j] = '\0';

    // Step 3: Check if both strings are equal
    if (strcmp(clean_string, reversed_string) == 0) {
        return 1; // is palindrome
    }

    return 0; // is not palindrome
}

int main() {
    char input_string[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input_string, MAX_LENGTH, stdin);

    if (is_palindrome(input_string)) {
        printf("%s is a palindrome.\n", input_string);
    } else {
        printf("%s is not a palindrome.\n", input_string);
    }

    return 0;
}