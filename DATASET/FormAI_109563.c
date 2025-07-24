//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *string)
{
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++)
    {
        if (string[i] != string[length - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    printf("Enter a string to check if it is a palindrome: ");
    char string[100];
    fgets(string, 100, stdin);

    if (isPalindrome(string))
    {
        printf("%s is a palindrome!", string);
    }
    else
    {
        printf("%s is not a palindrome.", string);
    }

    return 0;
}