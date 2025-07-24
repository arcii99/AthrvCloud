//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int isPalindrome(char str[]);

int main()
{
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input string
    
    if (isPalindrome(str))
    {
        printf("%s is a palindrome!\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }
    
    return 0;
}

int isPalindrome(char str[])
{
    int length = strlen(str);
    int start = 0, end = length - 1;
    
    while (start < end)
    {
        // Ignore non-alphabetic characters at front of string
        while (!isalpha(str[start]) && start < end)
        {
            start++;
        }
        // Ignore non-alphabetic characters at end of string
        while (!isalpha(str[end]) && end > start)
        {
            end--;
        }
        // Compare alphabetic characters at front and end of string
        if (tolower(str[start]) != tolower(str[end]))
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}