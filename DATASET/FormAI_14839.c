//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void stripPunctuation(char *str) {
    char *p = str;
    while (*p) {
        if (ispunct(*p)) {
            memmove(p, p + 1, strlen(p));
        } else {
            p++;
        }
    }
}

void toLowerCase(char *str) {
    char *p = str;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
}

int isPalindrome(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LENGTH], sanitized[MAX_LENGTH];
    int i;

    printf("Welcome to the Palindrome Checker 3000!\n");
    printf("Please enter a word or phrase: ");
    
    // Take user input
    fgets(input, MAX_LENGTH, stdin);
    stripPunctuation(input);
    toLowerCase(input);

    // Copy sanitized input to new string
    strcpy(sanitized, input);

    // Print input in reverse order
    printf("Your input in reverse order is: ");
    for (i = strlen(input) - 1; i >= 0; i--) {
        putchar(input[i]);
    }
    printf("\n");

    if (isPalindrome(sanitized)) {
        printf("Congratulations! \"%s\" is a palindrome!\n", sanitized);
    } else {
        printf("Sorry, \"%s\" is not a palindrome.\n", sanitized);
    }

    return 0;
}