//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;
    int len = strlen(str);
    // Loop from the start and end of the string to check the characters
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome!
}

int main() {
    char str[100];
    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);
    // Remove the newline character from the end of the input string
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str)) {
        printf("%s is a palindrome!", str);
    } else {
        printf("%s is not a palindrome.", str);
    }

    return 0;
}