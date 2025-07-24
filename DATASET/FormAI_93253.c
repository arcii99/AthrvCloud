//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkPalindrome(char *str);

int main()
{
    char str[100];
    bool isPalindrome;

    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, 100, stdin);

    // Remove trailing newline character
    str[strcspn(str, "\n")] = 0;

    isPalindrome = checkPalindrome(str);

    if (isPalindrome)
    {
        printf("%s is a palindrome!\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}

bool checkPalindrome(char *str)
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (end > start)
    {
        if (str[start++] != str[end--])
        {
            return false;
        }
    }

    return true;
}