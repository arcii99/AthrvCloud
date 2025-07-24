//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Function to remove punctuations and spaces from the given string
void normalize_string(char *str)
{
    int i, j = 0;
    char ch;
    for(i = 0; str[i]; i++)
    {
        ch = tolower(str[i]);
        if(isalpha(ch))
            str[j++] = ch;
    }
    str[j] = '\0';
}

// Function to check if the given string is a palindrome or not
int is_palindrome(char *str)
{
    int i, len = strlen(str);
    for(i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

// Main function to initialize the program and interact with the user
int main()
{
    char str[100];
    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, 100, stdin);

    normalize_string(str);

    if(is_palindrome(str))
        printf("Yes, \"%s\" is a palindrome!\n", str);
    else
        printf("Sorry, \"%s\" is not a palindrome.\n", str);

    return 0;
}