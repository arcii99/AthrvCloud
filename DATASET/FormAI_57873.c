//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a string is palindrome
int isPalindrome(char string[MAX_SIZE])
{
    int length = strlen(string);
    int i, j;

    // Check if there are any non-alphanumeric characters in the string
    for(i=0; i<length; i++) {
        if(!isalnum(string[i])) {
            printf("The given string is not alphanumeric.\n");
            return 0;
        }
    }

    // Check if the string is palindrome
    for(i=0, j=length-1; i<j; i++, j--) {
        if(tolower(string[i]) != tolower(string[j])) {
            printf("The given string is not a palindrome.\n");
            return 0;
        }
    }

    printf("The given string is a palindrome.\n");
    return 1;
}

int main()
{
    char string[MAX_SIZE];

    printf("Enter a string: ");
    fgets(string, MAX_SIZE, stdin);

    // Replace the newline character at the end with null character
    string[strcspn(string, "\n")] = '\0';

    isPalindrome(string);

    return 0;
}