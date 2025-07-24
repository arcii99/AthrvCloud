//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
bool isAlphanumeric(char c) {
    return isalnum(c) != 0;
}

// Function to check if a character is equal to its reverse
bool isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Function to convert all characters to lowercase
void toLower(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str[100];
    int i, j;
    bool palindrome = true;

    // Get user input
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Check if the string is a palindrome
    toLower(str);
    j = strlen(str) - 1;
    for (i = 0; i < strlen(str); i++) {
        if (!isAlphanumeric(str[i])) {
            continue;
        }
        while (!isAlphanumeric(str[j])) {
            j--;
        }
        if (i >= j) {
            break;
        }
        if (str[i] != str[j]) {
            palindrome = false;
            break;
        }
        j--;
    }

    // Output the result
    if (palindrome) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    return 0;
}