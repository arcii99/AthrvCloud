//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>

int checkPalindrome(char *string)
{
    int length = strlen(string);
    char temp[length];

    // copying the original string to temp variable in reverse order
    for(int i=0; i<length; i++)
    {
        temp[i] = string[length-i-1];
    }

    // comparing original string with its reverse
    for(int i=0; i<length; i++)
    {
        if(string[i] != temp[i])
        {
            return 0; // not a palindrome
        }
    }

    return 1; // palindrome
}

int main()
{
    // taking input from user
    char input[100];
    printf("Enter a string to check palindrome: ");
    scanf("%s", input);

    // calling checkPalindrome function
    int result = checkPalindrome(input);

    // printing result
    if(result == 1)
    {
        printf("\n%s is a palindrome.\n", input);
    }
    else
    {
        printf("\n%s is not a palindrome.\n", input);
    }

    return 0;
}