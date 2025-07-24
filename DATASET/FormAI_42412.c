//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// Function to check if a string is palindrome
int isPalindrome(char string[]) {
    int length = strlen(string);

    // Compare characters from the start and end of the string
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            return 0; // The string is not palindrome
        }
    }

    return 1; // The string is palindrome
}

int main() {
    char string[100];

    printf("Enter a string to check if it's a palindrome: ");
    gets(string);

    if (isPalindrome(string)) {
        printf("%s is a palindrome\n", string);
    }
    else {
        printf("%s is not a palindrome\n", string);
    }

    return 0;
}