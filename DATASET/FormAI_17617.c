//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int isPalindrome(char *str);

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    if(isPalindrome(str))
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}

int isPalindrome(char *str)
{
    int i, j;

    for(i=0, j=strlen(str)-1; i<=j; i++, j--)
    {
        if(str[i] != str[j])
            return 0;
    }

    return 1;
}