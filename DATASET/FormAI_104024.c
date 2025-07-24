//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[50];
    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a word or phrase: ");
    fgets(str, sizeof(str), stdin); // Using fgets to read input to handle spaces

    // Remove new line character from input
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    // Convert input to lowercase and remove non-alphabetic characters
    char cleanStr[50];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            cleanStr[j] = tolower(str[i]);
            j++;
        }
    }
    cleanStr[j] = '\0';

    // Check if input is a palindrome
    int isPalindrome = 1;
    int cleanLen = strlen(cleanStr);
    for (int i = 0; i < cleanLen/2; i++) {
        if (cleanStr[i] != cleanStr[cleanLen-i-1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("Congratulations, the input \"%s\" is a palindrome!\n", str);
    } else {
        printf("Sorry, the input \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}