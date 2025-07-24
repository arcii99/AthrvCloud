//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
// Welcome to the Palindrome Checker 3000!

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main() {
    char original[MAX_LENGTH];
    char reversed[MAX_LENGTH];
    int length, mid, i, j;

    printf("Welcome to the Palindrome Checker 3000!\n");
    printf("Please enter a word or phrase: ");
    fgets(original, MAX_LENGTH, stdin);

    // Remove the newline character at the end
    original[strcspn(original, "\n")] = 0;

    length = strlen(original);
    mid = length / 2;

    // Reverse the original string
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = original[i];
    }
    reversed[length] = '\0';

    // Compare the two strings
    if (strcmp(original, reversed) == 0) {
        printf("The input is a palindrome!\n");
    } else {
        printf("The input is not a palindrome.\n");
    }
    return 0;
}