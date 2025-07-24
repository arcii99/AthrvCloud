//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 100  // maximum size of array

/* Function to check if a string is palindrome */
bool isPalindrome(char str[]) {
    int length = 0;  // length of the string
    while ( str[length] != '\0' ) {
        length++;
    }
    // Check if the string is palindrome
    int start = 0;
    int end = length - 1;
    while ( end > start ) {
        if ( str[start++] != str[end--] ) {
            return false;
        }
    }
    return true;
}

/* Main function */
int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);  // read string from standard input
    if ( isPalindrome(str) ) {
        printf("'%s' is a palindrome\n", str);
    } else {
        printf("'%s' is not a palindrome\n", str);
    }
    return 0;
}