//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str)
{
    // Initialize variables
    int start = 0;
    int end = strlen(str) - 1;
    
    // Loop through characters until they meet in the middle
    while (start < end)
    {
        // If characters at both ends are not the same, then string is not a palindrome
        if (*(str+start) != *(str+end))
            return 0;
        
        start++;
        end--;
    }
    
    // If loop completes without returning, the string is a palindrome
    return 1;
}

int main()
{
    char str[50];
    
    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Check if input is a palindrome
    if (isPalindrome(str))
        printf("%s is a palindrome!\n", str);
    else
        printf("%s is not a palindrome.\n", str);
    
    return 0;
}