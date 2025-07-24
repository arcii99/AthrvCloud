//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // Maximum length of the input string

int isPalindrome(char *input, int length);
// Function declarations

int main()
{
    char input[MAX_LENGTH]; // Input string
    
    printf("Enter a string to check if it's a Palindrome: ");
    fgets(input, MAX_LENGTH, stdin); // Reading input string
    
    // Removing whitespace characters from the input string
    for(int i=0; i<strlen(input); i++)
    {
        if(isspace(input[i]))
        {
            for(int j=i; j<strlen(input); j++)
            {
                input[j] = input[j+1];
            }
            i--;
        }
    }
    
    int length = strlen(input) - 1; // Length of the input string
    
    if(isPalindrome(input, length))
    {
        printf("The input string is a Palindrome.\n");
    }
    else
    {
        printf("The input string is not a Palindrome.\n");
    }
    
    return 0;
}

int isPalindrome(char *input, int length)
{
    // Base case
    if(length <= 1)
    {
        return 1;
    }
    
    // Recursive case
    if(input[0] == input[length-1])
    {
        return isPalindrome(input+1, length-2);
    }
    else
    {
        return 0;
    }
}