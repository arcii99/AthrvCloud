//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum length of the input string

// Function to check if a string is a palindrome
// Takes two parameters: the string itself and its length
int is_palindrome(char str[], int len) {
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH]; // String entered by user
    int len; // Length of the string
    
    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    
    len = strlen(str); // Compute length of string
    
    // Call function to check if string is palindrome
    if (is_palindrome(str, len)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    
    return 0;
}