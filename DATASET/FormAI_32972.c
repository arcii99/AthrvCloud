//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check whether the input string is a palindrome or not
int isPalindrome(char str[])
{
    int len = strlen(str);
    int i = 0, j = len - 1;
  
    while (i < j) {
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Welcome to the Palindrome Checker!\n");
    printf("This program will check if a string is palindrome or not.\n");
    printf("Enter your string to check: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
  
    // Checking if the input string is a palindrome or not
    if (isPalindrome(str)) {
        printf("\nYes, \"%s\" is a palindrome.", str);
    }
    else {
        printf("\nSorry, \"%s\" is not a palindrome.", str);
        printf("\nBut don't worry, let me help you make it a palindrome.\n");
      
        // Reversing the input string and appending it to the original string
        int len = strlen(str);
        for (int i = len - 1; i >= 0; i--) {
            str[len++] = str[i];
        }
        str[len] = '\0';
        printf("\nHere is your new palindrome string: \"%s\"", str);
    }
  
    return 0;
}