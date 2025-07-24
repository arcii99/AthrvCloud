//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to remove non-alphanumeric characters and converts
 all letters to lowercase */
void clean_string(char* str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char)str[i])) {
            str[j++] = tolower((unsigned char)str[i]);
        }
    }
    str[j] = '\0';
}

/* Function to check whether a given string is a palindrome or not */
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Return false if characters don't match
        }
    }
    return 1; // Return true if string is a palindrome
}

int main() {
    char str[100]; // User input string
    printf("Enter a string: ");
    fgets(str, 100, stdin); // Read in input string

    // Remove non-alphanumeric characters and convert letters to lowercase
    clean_string(str);

    // Check if string is a palindrome
    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    }
    else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}