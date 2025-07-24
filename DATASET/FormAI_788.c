//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LENGTH 100

bool isPalindrome(char str[]);

int main()
{
    char str[MAX_STR_LENGTH];

    //Get user input
    printf("Enter a string: ");
    fgets(str, MAX_STR_LENGTH, stdin);

    //Remove newline character from input
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    //Convert string to lowercase
    for(int i=0; str[i]; i++)
        str[i] = tolower(str[i]);

    //Check if string is a palindrome
    if(isPalindrome(str))
        printf("%s is a palindrome.", str);
    else
        printf("%s is not a palindrome.", str);

    return 0;
}

bool isPalindrome(char str[])
{
    int length = strlen(str);

    for(int i=0; i<length/2; i++)
    {
        if(str[i] != str[length-i-1])
            return false;
    }

    return true;
}