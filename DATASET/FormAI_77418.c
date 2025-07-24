//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome
int isPalindrome(char str[])
{
    // Two pointers, one starts from the beginning and one starts from the end
    int start = 0;
    int end = strlen(str) - 1;

    // Loop until the pointers meet in the middle
    while (end > start)
    {
        // Compare the characters at the two pointers
        if (str[start++] != str[end--])
        {
            // If the characters don't match, the string is not a palindrome
            return 0;
        }
    }

    // If we get here, the string is a palindrome
    return 1;
}

int main()
{
    // Declare a string to check
    char str[100];

    // Prompt the user for input
    printf("Enter a string: ");

    // Read in the input string
    fgets(str, 100, stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = 0;

    // Check if the input is a palindrome
    if (isPalindrome(str))
    {
        printf("%s is a palindrome! Wow!\n", str);
    }
    else
    {
        printf("%s is not a palindrome. Boohoo.\n", str);
    }

    return 0;
}