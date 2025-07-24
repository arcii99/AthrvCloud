//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to check if a given string is a palindrome or not
int isPalindrome(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[MAX_LEN];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    if (isPalindrome(str))
    {
        printf("%s is a palindrome.\n", str);
    }
    else
    {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}