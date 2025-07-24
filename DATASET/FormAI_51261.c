//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
/* Linus Torvalds-style Palindrome Checker in C */

#include<stdio.h>
#include<string.h>

//Function to check if given string is palindrome
int isPalindrome(char* str)
{
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            //Not a palindrome
            return 0;
        }
    }
    //Palindrome
    return 1;
}

int main()
{
    char input[100];
    printf("Enter string to check if it's a palindrome: ");
    scanf("%s", input);
    if(isPalindrome(input))
    {
        printf("Yes, '%s' is a palindrome.\n", input);
    }
    else
    {
        printf("No, '%s' is not a palindrome.\n", input);
    }
    return 0;
}