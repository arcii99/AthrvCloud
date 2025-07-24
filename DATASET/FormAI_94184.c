//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main(void) {
    char str[MAX_LENGTH];
    int i, len, is_palindrome = 1;
    
    printf("Enter a string (maximum length %d): ", MAX_LENGTH);
    fgets(str, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    
    // Convert string to lowercase and remove non-alphanumeric characters
    char filtered_str[MAX_LENGTH];
    int j = 0;
    for (i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            filtered_str[j++] = tolower(str[i]);
        }
    }
    filtered_str[j] = '\0';
    len = strlen(filtered_str);
    
    // Check if string is a palindrome
    for (i = 0; i < len / 2; i++) {
        if (filtered_str[i] != filtered_str[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }
    
    if (is_palindrome) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
    
    return 0;
}