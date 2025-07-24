//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is valid alphanumeric character
int isAlphanumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

// Function to convert a character to lowercase
char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

// Function to check if a string is palindrome
int isPalindrome(char* str) {
    int i, j, len;

    // Get the length of the string
    len = strlen(str);

    // Initialize variables
    i = 0;
    j = len - 1;

    // Loop through the string and compare the characters
    while (i < j) {
        // Skip non-alphanumeric characters
        while (!isAlphanumeric(str[i]) && i < j)
            i++;

        while (!isAlphanumeric(str[j]) && i < j)
            j--;

        // Convert characters to lower-case for comparison
        if (toLower(str[i]) != toLower(str[j]))
            return 0;

        // Increment/decrement counters
        i++;
        j--;
    }

    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character

    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}