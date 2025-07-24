//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alpha-numeric
int isAlphaNum(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

// Function to check if a character is a letter
int isLetter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}

int main()
{
    char str[100], revStr[100];

    // Get input from the user
    printf("Enter string: ");
    fgets(str, 100, stdin);

    int len = strlen(str);
    int j = 0;

    // Reverse the string
    for (int i = len - 1; i >= 0; i--)
    {
        if (isAlphaNum(str[i]))
        {
            revStr[j] = tolower(str[i]);
            j++;
        }
    }
    revStr[j] = '\0';

    // Check if the original string and the reversed string are the same
    int isPalindrome = 1;
    len = strlen(revStr);
    for (int i = 0; i < len / 2; i++)
    {
        if (revStr[i] != revStr[len - i - 1])
        {
            isPalindrome = 0;
            break;
        }
    }

    // Print the result
    if (isPalindrome)
        printf("%s is a palindrome!\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}