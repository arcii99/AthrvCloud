//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <string.h>

void checkPalindrome(char []);

int main()
{
    char str[100];

    printf("Enter a string:\n");
    fgets(str, 100, stdin);

    // Remove newline character from input
    str[strcspn(str, "\n")] = 0;

    checkPalindrome(str);

    return 0;
}

void checkPalindrome(char str[])
{
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < len/2; i++, j--)
    {
        if (str[i] != str[j])
        {
            printf("%s is not a palindrome.\n", str);
            return;
        }
    }

    printf("%s is a palindrome!\n", str);
}