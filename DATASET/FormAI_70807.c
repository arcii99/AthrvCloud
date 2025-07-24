//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void removeSpacesAndPunctuation(char *str) {
    char *dst = str;
    while (*str) {
        if (!ispunct((unsigned char)*str) && !isspace((unsigned char)*str)) {
            *(dst++) = tolower((unsigned char)*str);
        }
        str++;
    }
    *dst = '\0';
}

int isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char input[MAX_LENGTH], processed[MAX_LENGTH];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove spaces and punctuation
    removeSpacesAndPunctuation(input);
    strcpy(processed, input);

    // Check if palindrome
    int result = isPalindrome(processed);

    // Print result
    printf("\"%s\" is %s a palindrome.\n", input, (result == 1) ? "" : "not");

    return 0;
}