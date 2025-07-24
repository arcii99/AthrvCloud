//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

int check_palindrome(char string[]);
char remove_special_chars(char string[]);

int main(void) {
    char string[MAX_STRING_LENGTH];
    
    printf("Enter a string: ");
    fgets(string, MAX_STRING_LENGTH, stdin);

    remove_special_chars(string);

    if (check_palindrome(string)) {
        printf("The string is a palindrome\n");
    }
    else {
        printf("The string is not a palindrome\n");
    }

    return 0;
}

int check_palindrome(char string[]) {
    int length = strlen(string) - 1; // Subtract 1 for the newline character
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (tolower(string[start]) != tolower(string[end])) {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

char remove_special_chars(char string[]) {
    int i, j;
    int length = strlen(string);

    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(string[i])) {
            string[j++] = tolower(string[i]);
        }
    }

    string[j] = '\0';

    return *string;
}