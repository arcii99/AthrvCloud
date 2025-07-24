//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int isPalindrome(char *str);

int main()
{
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0;

    if (isPalindrome(str))
    {
        printf("%s is a Palindrome!\n", str);
    }
    else
    {
        printf("%s is not a Palindrome.\n", str);
    }
    return 0;
}

int isPalindrome(char *str)
{
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
    }
    return 1;
}