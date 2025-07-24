//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, j, len, pal = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str) - 1; // Subtract 1 to exclude newline character

    // Convert all characters in string to lowercase for case-insensitive matching
    for (i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }

    // Check if string is a palindrome
    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (str[i] != str[j])
        {
            pal = 0;
            break;
        }
    }

    // Print result
    if (pal)
    {
        printf("The string is a palindrome\n");
    }
    else
    {
        printf("The string is not a palindrome\n");
    }

    return 0;
}