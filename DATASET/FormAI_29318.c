//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to check if a given string is palindrome or not
int isPalindrome(char *str)
{
    int len = strlen(str);
    for(int i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
            return 0;
    }
    return 1;
}

int main()
{
    char input[100];
    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a string: ");
    scanf("%s", input);
    if(isPalindrome(input))
        printf("%s is a palindrome!\n",input);
    else
        printf("%s is not a palindrome\n",input);
    return 0;
}