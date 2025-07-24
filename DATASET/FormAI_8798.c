//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include<stdio.h>
#include<string.h>

/* function to check if a string is palindrome or not */
int isPalindrome(char str[])
{
    int len = strlen(str);
    int i,j;
    for(i=0,j=len-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            return 0;   /* if string does not match, return 0 */
        }
    }
    return 1;   /* if string is palindrome, return 1 */
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if(isPalindrome(str))
    {
        printf("%s is a Palindrome\n", str);
    }else{
        printf("%s is not a Palindrome\n", str);
    }
    return 0;
}