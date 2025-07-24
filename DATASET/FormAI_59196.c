//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome
int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[100];
    
    // Prompt the user to enter a string
    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, 100, stdin);
    
    // Remove the newline character at the end of the string
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    
    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }
    
    return 0;
}