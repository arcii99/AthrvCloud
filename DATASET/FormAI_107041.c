//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome
int isPalindrome(char str[])
{
    int length = strlen(str);
    
    for(int i=0; i<length/2; i++)
    {
        if(str[i] != str[length-i-1])
        {
            // If the characters at i and length-i-1 position do not match, then the string is not palindrome
            return 0;
        }
    }
    
    // Otherwise string is palindrome
    return 1;
}
 
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str); // Read input string from user
 
    // Call isPalindrome function to check if the input string is a palindrome
    if(isPalindrome(str) == 1)
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }
 
    return 0;
}