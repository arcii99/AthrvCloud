//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void removePunctuations(char str[])
{
    int len = strlen(str);

    // Traverse through all characters in the string
    for (int i = 0; i < len; i++)
    {
        // Check whether the character is punctuation or not
        if (ispunct(str[i]))
        {
            // Shift all characters after the current one to the left
            for (int j = i; j < len - 1; j++)
            {
                str[j] = str[j + 1];
            }

            // Decrease the length of the string by 1
            len--;
            i--;
        }
    }
}

void toLowercase(char str[])
{
    int len = strlen(str);

    // Traverse through all characters in the string
    for (int i = 0; i < len; i++)
    {
        // Convert uppercase letters to lowercase
        str[i] = tolower(str[i]);
    }
}

int isPalindrome(char str[])
{
    int len = strlen(str);

    // Check if the string is empty or null
    if (len == 0 || str == NULL)
    {
        return 0;
    }

    // Check if the string has only one character
    if (len == 1)
    {
        return 1;
    }

    // Remove all punctuations from the string and convert to lowercase
    removePunctuations(str);
    toLowercase(str);

    // Traverse through half of the string
    for (int i = 0; i < len/2; i++)
    {
        // Compare the left and right characters
        if (str[i] != str[len-1-i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove trailing newline character from input string
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}