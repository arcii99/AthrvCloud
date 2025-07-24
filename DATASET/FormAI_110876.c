//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int i, len, flag = 0;

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", string);

    // Find length of the string
    len = strlen(string);

    // Check if the string is palindrome
    for(i=0;i<len;i++)
    {
        if(string[i] != string[len-i-1])
        {
            flag = 1;
            break;
        }
    }

    // Print whether the string is palindrome or not
    if(flag == 1)
    {
        printf("%s is not a palindrome\n", string);
    }    
    else
    {
        printf("%s is a palindrome\n", string);
    }

    return 0;
}