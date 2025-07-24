//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
// C Program to check if a given string is palindrome or not

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the given string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        // Convert all the characters to lowercase
        str[i] = tolower(str[i]);
    }
    int i = 0, j = len-1;
    while(i <= j) {
        if(str[i++] != str[j--]) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    if(isPalindrome(str)) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }
    return 0;
}