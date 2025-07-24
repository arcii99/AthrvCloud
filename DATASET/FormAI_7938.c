//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to check if a given string is palindrome */
int isPalindrome(char str[])
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        if (tolower(str[i++]) != tolower(str[j--]))
            return 0; // Not a palindrome
    }
    return 1; // Palindrome
}

/* Main function */
int main()
{
    char str[100];

    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing the trailing newline character from fgets
    
    if (isPalindrome(str))
        printf("Yes, the string '%s' is a palindrome.\n", str);
    else
        printf("No, the string '%s' is not a palindrome.\n", str);

    return 0;
}