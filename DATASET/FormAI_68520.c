//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

int isPalindrome(char *);

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if(isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}

int isPalindrome(char *str)
{
    int len = strlen(str);
    char *rev = (char*)malloc(sizeof(char)*(len+1));
    int i, j;

    for(i=0, j=len-1; i<len; i++, j--)
        rev[i] = str[j];
    rev[i] = '\0';

    for(i=0; i<len; i++)
    {
        if(str[i] != rev[i])
        {
            free(rev);
            return 0;
        }
    }

    free(rev);
    return 1;
}