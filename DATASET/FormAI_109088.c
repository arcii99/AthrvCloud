//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    str[len - 1] = '\0'; // remove newline character from fgets input
    char reverse[100];
    int i, j;

    // Convert all characters to lowercase and remove punctuation
    for (i = 0, j = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            reverse[j] = tolower(str[i]);
            j++;
        }
    }
    reverse[j] = '\0'; // add null terminator to reverse string

    len = j; // set len to length of reverse string

    // Check if reverse string is a palindrome
    for (i = 0, j = len - 1; i <= j; i++, j--)
    {
        if (reverse[i] != reverse[j])
        {
            printf("The string is not a palindrome.\n");
            return 0;
        }
    }
    printf("The string is a palindrome.\n");
    return 0;
}