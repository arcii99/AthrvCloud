//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function checks if a given string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

// This main function prompts the user to input a string
// and then checks if it is a palindrome
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    // Remove the newline character produced by fgets
    str[strcspn(str, "\n")] = 0;
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}