//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void check_palindrome(char *str)
{
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            printf("%s is not a palindrome.\n", str);
            return;
        }
    }
    printf("%s is a palindrome.\n", str);
}

int main()
{
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    check_palindrome(str);
    return 0;
}