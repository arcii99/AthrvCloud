//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, len, mid;
    int isPalindrome = 1;
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    len = strlen(str);
    mid = len/2;
    
    // Convert all letters to lowercase
    for(i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
    
    // Check for palindrome
    for(i = 0; i < mid; i++)
    {
        if(str[i] != str[len - i - 1])
        {
            isPalindrome = 0;
            break;
        }
    }
    
    if(isPalindrome)
    {
        printf("%s is a palindrome.", str);
    }
    else
    {
        printf("%s is not a palindrome.", str);
    }
    
    return 0;
}