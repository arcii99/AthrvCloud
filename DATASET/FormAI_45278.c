//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include<stdio.h>
#include<string.h>

// Function to check if the string is a palindrome
int isPalindrome(char str[])
{
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(str[i] != str[len-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    char str[100];

    printf("\n**************************************************\n");
    printf("**** Welcome to the Palindrome Checker Program ****\n");
    printf("**************************************************\n\n");

    printf("Please enter a string to check if it is a Palindrome:\n");
    scanf("%[^\n]s", str);

    printf("\n********************************************************\n");

    if(isPalindrome(str))
        printf("Congratulations! The string is a Palindrome!\n");
    else
        printf("Sorry, the string is not a Palindrome!\n");

    printf("********************************************************\n\n");

    return 0;
}