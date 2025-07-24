//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isPalindrome(char *input) {
    int length = strlen(input);
    char *reversedInput = malloc((length + 1) * sizeof(char));

    for (int i = length - 1; i >= 0; i--) {
        reversedInput[length - 1 - i] = input[i];
    }
    reversedInput[length] = '\0';

    int palindrome = 1;
    for (int i = 0; i < length; i++) {
        if (tolower(input[i]) != tolower(reversedInput[i])) {
            palindrome = 0;
            break;
        }
    }
    free(reversedInput);
    return palindrome;
}

int main() {
    printf("Welcome to the C Palindrome Checker!\n");
    printf("Please enter a word or phrase: ");
    char input[1000];
    fgets(input, sizeof(input), stdin);
    clearInputBuffer();

    int palindrome = isPalindrome(input);

    if (palindrome) {
        printf("\n%s is a palindrome!\n", input);
    } else {
        printf("\n%s is not a palindrome.\n", input);
    }

    return 0;
}