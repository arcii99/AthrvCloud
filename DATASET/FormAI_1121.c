//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: retro
#include <stdio.h>
#include <string.h>

int checkPalindrome(char str[]);

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int result = checkPalindrome(str);
    if (result == 1)
        printf("\n%s is a palindrome!\n", str);
    else
        printf("\n%s is not a palindrome.\n", str);
    return 0;
}

int checkPalindrome(char str[])
{
    int len = strlen(str);
    char temp[100];
    for (int i = 0; i < len; i++)
        temp[i] = str[len - 1 - i];
    temp[len] = '\0';
    if (strcmp(str, temp) == 0)
        return 1;
    else
        return 0;
}