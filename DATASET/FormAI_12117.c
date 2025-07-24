//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Returns true if the input string is a palindrome
int isPalindrome(char str[]);

int main()
{
    char input[100];

    //Ask user for input
    printf("Enter a string to check if it is a palindrome: ");
    fgets(input, 100, stdin);

    // Remove newline characters from fgets input
    input[strcspn(input, "\n")] = 0;

    if(isPalindrome(input))
    {
        printf("%s is a palindrome", input);
    }
    else
    {
        printf("%s is not a palindrome", input);
    }

    return 0;
}

int isPalindrome(char str[])
{
    int len = strlen(str);
    int i,j;

    // Traverse string from both ends, comparing each character
    for(i=0, j=len-1; i<=len/2, j>=len/2; i++,j--)
    {
        if(str[i] != str[j])
        {
            return 0;
        }
    }

    return 1;
}