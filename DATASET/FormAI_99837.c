//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int isPalindrome(char *str);

int main()
{
    char inputStr[MAX_LENGTH];
    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a word or sentence and press enter:\n");
    fgets(inputStr, MAX_LENGTH, stdin);

    if (isPalindrome(inputStr))
    {
        printf("It's a Palindrome! You did it right!");
    }
    else
    {
        printf("Sorry, it's not a Palindrome! Keep trying!");
    }

    return 0;
}

int isPalindrome(char *str)
{
    int i, j;
    int length = strlen(str);

    // Remove space and special characters
    char filteredStr[MAX_LENGTH];
    int index = 0;
    for (i = 0; i < length; i++)
    {
        char c = tolower(str[i]);
        if (c >= 'a' && c <= 'z')
        {
            filteredStr[index++] = c;
        }
    }
    filteredStr[index] = '\0';

    // Check if it's a palindrome
    length = strlen(filteredStr);
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        if (filteredStr[i] != filteredStr[j])
        {
            return 0; // Not a palindrome
        }
    }
    return 1; // It's a palindrome
}