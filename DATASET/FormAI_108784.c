//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

/* Function to check if a given string is palindrome or not */
int isPalindrome(char str[])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1]) // Check if the first and last characters match
        {
            return 0; // If not return 0 to indicate that the string is not a palindrome
        }
    }
    return 1; // If all characters match, return 1 to indicate that the string is a palindrome
}

int main()
{
    char str[100]; // Declare a character array to hold the input string
    int result;
    
    printf("Enter the string to check if it is palindrome or not: ");
    scanf("%s", str); // Read input string from user
    
    result = isPalindrome(str);
    
    if (result == 1) 
    {
        printf("\n%s is a palindrome.", str);
    } 
    else 
    {
        printf("\n%s is not a palindrome.", str);
    }

    return 0; // Indicates that the program executed successfully
}