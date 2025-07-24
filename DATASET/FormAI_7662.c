//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(char* str);

int main()
{
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    if (isPalindrome(input))
    {
        printf("%s is a palindrome!\n", input);
    }
    else
    {
        printf("%s is not a palindrome!\n", input);
    }

    return 0;
}

int isPalindrome(char* str)
{
    int len = strlen(str) - 1; // don't count the newline character
    char reversed[MAX_LENGTH];
    int i = 0;

    // reverse the string
    for (int j = len - 1; j >= 0; j--)
    {
        reversed[i] = str[j];
        i++;
    }
    reversed[i] = '\0';

    // compare the reversed string to the original
    if (strcmp(str, reversed) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}