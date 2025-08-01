//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: recursive
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end)
{
    if (start == end)
        return 1;

    if (str[start] != str[end])
        return 0;

    if (start < end + 1)
        return isPalindrome(str, start + 1, end - 1);

    return 1;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str, 0, strlen(str) - 1))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}