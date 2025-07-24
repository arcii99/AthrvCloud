//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Alan Touring
// C Palindrome Checker Program by Alan Turing AI Chatbot
// This program checks if a given string is a palindrome or not


#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove spaces and punctuations from input string
void removeSpacesAndPunctuations(char* str) 
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (isalnum(str[i]))
            str[j++] = tolower(str[i]);
        i++;
    }
    str[j] = '\0';
}

// Function to check if a given string is palindrome or not
int isPalindrome(char* str, int length) 
{
    int start = 0, end = length - 1;
    while (start < end)
    {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

// Main function
int main()
{
    printf("Welcome to Alan Turing's Palindrome Checker\n");
    printf("Please enter a string: ");
    
    char inputStr[1000];
    fgets(inputStr, 1000, stdin);
    
    // Remove spaces and punctuations from input string
    removeSpacesAndPunctuations(inputStr);
    int length = strlen(inputStr);
    
    // Check if the input string is a palindrome
    if (isPalindrome(inputStr, length))
        printf("The entered string is a palindrome 🎉\n");
    else
        printf("The entered string is not a palindrome 😕\n");

    return 0;
}