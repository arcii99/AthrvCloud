//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Define a function to check whether a given string is a palindrome
int is_palindrome(char str[]) {
    int n = strlen(str);
    // Initialize two pointers, one at the start and one at the end of the string
    int i = 0, j = n - 1;
    while (i < j) {
        // If the characters at the two pointers are not the same, then the string is not a palindrome
        if (str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    // If the loop completes, then the string is a palindrome, so return 1
    return 1;
}

int main() {
    // Define a string to check whether it is a palindrome
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    // Call the is_palindrome function to check whether the string is a palindrome
    if (is_palindrome(str)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}