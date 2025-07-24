//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

// function to check if a string is palindrome
int checkPalindrome(char* str)
{
    int i = 0;
    int j = strlen(str) - 1;
    
    // check each character in the string
    while (j > i)
    {
        if (str[i++] != str[j--])
        {
            // string is not a palindrome
            return 0;
        }
    }
    
    // string is a palindrome
    return 1;
}

// main function
int main()
{
    char str[100];
    
    // prompt user for string input
    printf("Enter a string: ");
    scanf("%s", str);
    
    // check if input string is palindrome
    if (checkPalindrome(str))
    {
        printf("The string '%s' is a palindrome!\n", str);
    }
    else
    {
        printf("The string '%s' is not a palindrome.\n", str);
    }
    
    return 0;
}