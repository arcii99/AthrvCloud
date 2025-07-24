//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: careful
#include <stdio.h>
#include <string.h>

// function to check if a given string is a palindrome
int isPalindrome(char str[])
{
    int len = strlen(str);
    
    // loop through the string and compare the characters from both ends
    for(int i=0; i<len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            return 0; // not a palindrome
        }
    }
    
    return 1; // palindrome
}

int main()
{
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if(isPalindrome(str))
    {
        printf("%s is a palindrome", str);
    }
    else
    {
        printf("%s is not a palindrome", str);
    }
    
    return 0;
}