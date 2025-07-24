//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: light-weight
#include<stdio.h>
#include<string.h>

int isPalindrome(char *str) // Function to check if a string is a palindrome
{
    int len = strlen(str);
    int i, j;

    for(i=0, j=len-1; i<j; i++, j--)
    {
        if(str[i]!=str[j])
            return 0;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if(isPalindrome(str))
        printf("%s is a Palindrome", str);
    else
        printf("%s is not a Palindrome", str);

    return 0;
}