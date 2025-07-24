//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
// C Program to Check Palindrome

#include <stdio.h>
#include <string.h>

int main()
{
    // Variable Declaration
    char string[100];
    int i, length;
    int flag = 0;
    
    // User Input
    printf("Enter a string: ");
    scanf("%s", string);
    
    // Find the length of the string
    length = strlen(string);
    
    // Check for Palindrome
    for(i=0; i<length; i++)
    {
        if(string[i] != string[length-i-1])
        {
            flag = 1;
            break;
        }
    }
    
    // Print Output
    if(flag == 1)
    {
        printf("\n%s is not a Palindrome.\n", string);
    }
    else
    {
        printf("\n%s is a Palindrome.\n", string);
    }
    
    return 0;
}